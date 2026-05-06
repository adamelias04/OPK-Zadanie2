#pragma once

#include <memory>
#include <mutex>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

#include "vacuum_core/config/GameConfig.h"
#include "vacuum_core/environment/Environment.h"
#include "vacuum_core/world/WorldManager.h"

namespace vacuum_core::game {

struct CollectResult {
    bool success{false};
    std::string type;
    int score_value{0};
    uint32_t trash_id{0};
    uint32_t capacity_used{0};
    uint32_t capacity_max{0};
    geometry::Point2d position{};
    world::Color color{};
    double radius{0.0};
};

struct UnloadResult {
    bool success{false};
    int score_gained{0};
    uint32_t capacity_used{0};
};

struct TrashCount {
    std::string type;
    uint32_t count;
};

struct GameSnapshot {
    std::string phase;   // "WAITING", "RUNNING", "WON", "DRAW"
    double elapsed_seconds{0.0};
    int score{0};
    std::string winner;
    std::vector<TrashCount> collected;
    std::vector<world::WorldManager::TrashView> active_trash;
    std::unordered_map<std::string, uint32_t> capacity_used;
    std::unordered_map<std::string, int> per_robot_score;
    std::unordered_map<std::string, uint32_t> unload_count;
};

// Holds game state independent of ROS.
// Thread-safe: external nodes call tryCollect / tryUnload / tick concurrently.
class GameLogic {
public:
    GameLogic(config::GameConfig cfg,
              std::shared_ptr<environment::Environment> env);

    void start();
    void tick(double dt);

    CollectResult tryCollect(const std::string& robot_id,
                             const geometry::Point2d& robot_pos,
                             double robot_radius);

    UnloadResult tryUnload(const std::string& robot_id,
                           const geometry::Point2d& robot_pos);

    void registerRobot(const std::string& robot_id);

    // Game-mode-agnostic query
    GameSnapshot snapshot() const;

    const config::GameConfig& config() const { return config_; }
    world::WorldManager& world() { return *world_; }
    const world::WorldManager& world() const { return *world_; }

    bool isRunning() const;
    bool isFinished() const;

    // Spawns one new trash if possible; returns whether it succeeded.
    bool spawnOneTrash();
    // Spawns N trash (used at startup).
    int spawnInitialTrash(int count);

private:
    CollectResult tryCollectLocked(const std::string& robot_id,
                                   const geometry::Point2d& robot_pos,
                                   double robot_radius);
    UnloadResult tryUnloadLocked(const std::string& robot_id,
                                 const geometry::Point2d& robot_pos);
    bool canSpawnAt(const geometry::Point2d& p, double radius) const;

    config::GameConfig config_;
    std::shared_ptr<environment::Environment> env_;
    std::unique_ptr<world::WorldManager> world_;
    std::unique_ptr<world::TrashFactory> factory_;

    mutable std::mutex mutex_;
    double elapsed_{0.0};
    double spawn_timer_{0.0};
    bool started_{false};
    bool finished_{false};
    std::string winner_;

    // per-robot state
    std::unordered_map<std::string, uint32_t> capacity_used_;
    std::unordered_map<std::string, int> scores_;
    std::unordered_map<std::string, uint32_t> unload_count_;

    std::unordered_map<std::string, uint32_t> collected_per_type_;
};

} // namespace vacuum_core::game
