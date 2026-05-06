#include "vacuum_core/game/GameLogic.h"
#include "vacuum_core/util/Exception.h"

#include <cmath>
#include <memory>

namespace vacuum_core::game {

GameLogic::GameLogic(config::GameConfig cfg,
                     std::shared_ptr<environment::Environment> env)
    : config_(std::move(cfg)), env_(std::move(env))
{
    if (!env_) {
        throw util::VacuumException("GameLogic: environment required");
    }

    world_ = std::make_unique<world::WorldManager>();

    for (const auto& spec : config_.obstacles) {
        uint32_t id = world_->nextId();
        if (spec.shape == "circle") {
            world_->addObstacle(std::make_unique<world::CircleObstacle>(
                id, spec.center, spec.radius));
        } else if (spec.shape == "rectangle") {
            world_->addObstacle(std::make_unique<world::RectangleObstacle>(
                id, spec.center, spec.width, spec.height));
        }
    }

    world_->setStation(std::make_unique<world::Station>(
        world_->nextId(), config_.station_pos, config_.station_radius));

    factory_ = std::make_unique<world::TrashFactory>(
        config_.trash_types,
        config_.trash_radius_min,
        config_.trash_radius_max);
}

void GameLogic::start()
{
    std::lock_guard<std::mutex> lock(mutex_);
    started_ = true;
    finished_ = false;
    elapsed_ = 0.0;
    spawn_timer_ = 0.0;
    winner_.clear();
    capacity_used_.clear();
    scores_.clear();
    unload_count_.clear();
    collected_per_type_.clear();
    world_->clearTrash();
}

void GameLogic::registerRobot(const std::string& robot_id)
{
    std::lock_guard<std::mutex> lock(mutex_);
    capacity_used_.try_emplace(robot_id, 0u);
    scores_.try_emplace(robot_id, 0);
    unload_count_.try_emplace(robot_id, 0u);
}

bool GameLogic::isRunning() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return started_ && !finished_;
}

bool GameLogic::isFinished() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return finished_;
}

bool GameLogic::canSpawnAt(const geometry::Point2d& p, double radius) const
{
    // We don't lock the world manager here; it locks itself.
    // Check static map occupancy with a small buffer.
    const int samples = 8;
    for (int i = 0; i < samples; ++i) {
        const double a = 2.0 * M_PI * i / samples;
        const double x = p.x + radius * std::cos(a);
        const double y = p.y + radius * std::sin(a);
        if (env_->isOccupied(x, y)) return false;
    }
    if (env_->isOccupied(p.x, p.y)) return false;
    if (world_->positionBlocked(p, radius)) return false;
    return true;
}

bool GameLogic::spawnOneTrash()
{
    // Must not hold our mutex while calling into world_ (which locks internally)
    auto check = [this](const geometry::Point2d& pos, double radius) {
        return !canSpawnAt(pos, radius);
    };
    const uint32_t id = world_->nextId();
    auto trash = factory_->createRandom(
        id,
        env_->getWidth(),
        env_->getHeight(),
        check);
    if (!trash) return false;
    world_->addTrash(std::move(trash));
    return true;
}

int GameLogic::spawnInitialTrash(int count)
{
    int spawned = 0;
    for (int i = 0; i < count; ++i) {
        if (spawnOneTrash()) ++spawned;
    }
    return spawned;
}

void GameLogic::tick(double dt)
{
    std::unique_lock<std::mutex> lock(mutex_);
    if (!started_ || finished_) return;

    elapsed_ += dt;
    spawn_timer_ += dt;

    const bool should_spawn = (spawn_timer_ >= config_.spawn_interval_sec);
    if (should_spawn) {
        spawn_timer_ = 0.0;
    }

    // Check end condition (duel-mode aware).
    if (config_.mode == "duel") {
        if (elapsed_ >= config_.duel_time_limit_sec) {
            // Decide winner by unload count, then capacity_used, then id ordering.
            int best = -1;
            std::string best_id;
            for (const auto& [id, c] : unload_count_) {
                if (static_cast<int>(c) > best) {
                    best = c;
                    best_id = id;
                } else if (static_cast<int>(c) == best && id < best_id) {
                    best_id = id;
                }
            }
            winner_ = best > 0 ? best_id : std::string{"draw"};
            finished_ = true;
        }

        for (const auto& [id, c] : unload_count_) {
            if (static_cast<int>(c) >= config_.duel_goal_count) {
                winner_ = id;
                finished_ = true;
                break;
            }
        }
    }

    // Spawn outside the lock to avoid deadlock with WorldManager mutex.
    if (should_spawn) {
        lock.unlock();
        spawnOneTrash();
    }
}

CollectResult GameLogic::tryCollect(const std::string& robot_id,
                                    const geometry::Point2d& robot_pos,
                                    double robot_radius)
{
    std::lock_guard<std::mutex> lock(mutex_);
    return tryCollectLocked(robot_id, robot_pos, robot_radius);
}

CollectResult GameLogic::tryCollectLocked(const std::string& robot_id,
                                          const geometry::Point2d& robot_pos,
                                          double robot_radius)
{
    CollectResult result;
    auto it = capacity_used_.find(robot_id);
    if (it == capacity_used_.end()) {
        capacity_used_[robot_id] = 0;
        it = capacity_used_.find(robot_id);
    }
    result.capacity_max = config_.max_capacity;
    result.capacity_used = it->second;

    if (!started_ || finished_) return result;
    if (it->second >= config_.max_capacity) return result;

    auto picked = world_->pickupNearest(robot_pos, robot_radius);
    if (!picked) return result;

    ++it->second;
    collected_per_type_[picked->type]++;

    result.success = true;
    result.type = picked->type;
    result.score_value = picked->score_value;
    result.trash_id = picked->id;
    result.capacity_used = it->second;
    result.position = picked->position;
    result.color = picked->color;
    result.radius = picked->radius;
    return result;
}

UnloadResult GameLogic::tryUnload(const std::string& robot_id,
                                  const geometry::Point2d& robot_pos)
{
    std::lock_guard<std::mutex> lock(mutex_);
    return tryUnloadLocked(robot_id, robot_pos);
}

UnloadResult GameLogic::tryUnloadLocked(const std::string& robot_id,
                                        const geometry::Point2d& robot_pos)
{
    UnloadResult result;
    if (!started_ || finished_) return result;
    if (!world_->isAtStation(robot_pos, config_.robot_radius)) return result;

    auto it = capacity_used_.find(robot_id);
    if (it == capacity_used_.end() || it->second == 0) return result;

    const int gained = static_cast<int>(it->second) * 10; // 10 pts per item unloaded
    scores_[robot_id] += gained;
    unload_count_[robot_id] += 1;
    it->second = 0;

    result.success = true;
    result.score_gained = gained;
    result.capacity_used = 0;
    return result;
}

GameSnapshot GameLogic::snapshot() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    GameSnapshot s;
    if (!started_) s.phase = "WAITING";
    else if (finished_) s.phase = winner_.empty() ? "DRAW" : "WON";
    else s.phase = "RUNNING";
    s.elapsed_seconds = elapsed_;
    s.winner = winner_;

    int total = 0;
    for (const auto& [id, sc] : scores_) total += sc;
    s.score = total;

    for (const auto& [t, c] : collected_per_type_) {
        s.collected.push_back({t, c});
    }
    s.active_trash = world_->listTrash();
    s.capacity_used = capacity_used_;
    s.per_robot_score = scores_;
    s.unload_count = unload_count_;
    return s;
}

} // namespace vacuum_core::game
