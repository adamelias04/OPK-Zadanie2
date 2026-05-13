#include "core/world/WorldManager.h"

#include <cmath>

namespace core::world {

// Pridá prekážku do zoznamu, volá sa pri inicializácii hry.
void WorldManager::addObstacle(std::unique_ptr<Obstacle> obs)
{
    std::lock_guard<std::mutex> lock(mutex_);
    obstacles_.push_back(std::move(obs));
}

// Vráti true ak niektorá prekážka pretína daný bod s polomerom.
bool WorldManager::isObstacleAt(const geometry::Point2d& p, double radius) const
{
    std::lock_guard<std::mutex> lock(mutex_);
    for (const auto& obs : obstacles_) {
        if (obs->intersects(p, radius)) {
            return true;
        }
    }
    return false;
}

// Vráti zoznam všetkých prekážok ako const pointery (len na čítanie).
std::vector<const Obstacle*> WorldManager::obstacles() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    std::vector<const Obstacle*> out;
    out.reserve(obstacles_.size());
    for (const auto& o : obstacles_) {
        out.push_back(o.get());
    }
    return out;
}

// Nastaví stanicu, volá sa raz pri inicializácii hry.
void WorldManager::setStation(std::unique_ptr<Station> st)
{
    std::lock_guard<std::mutex> lock(mutex_);
    station_ = std::move(st);
}

// Vráti const pointer na stanicu (nullptr ak nie je nastavená).
const Station* WorldManager::station() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return station_.get();
}

// Vráti true ak daný bod s polomerom pretína stanicu.
bool WorldManager::isAtStation(const geometry::Point2d& p, double radius) const
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (!station_) {
        return false;
    }
    return station_->intersects(p, radius);
}

// Vráti ďalšie unikátne ID a inkrementuje počítadlo.
uint32_t WorldManager::nextId()
{
    std::lock_guard<std::mutex> lock(mutex_);
    return next_id_++;
}

// Pridá trash do mapy podľa jeho ID.
void WorldManager::addTrash(std::unique_ptr<Collectible> trash)
{
    std::lock_guard<std::mutex> lock(mutex_);
    const uint32_t id = trash->id();
    trash_.emplace(id, std::move(trash));
}

// Vytvorí hodnotovú kópiu dát trashu posielateľnú cez ROS.
WorldManager::TrashView WorldManager::toView(const Collectible& c)
{
    return TrashView{
        c.id(),
        c.type(),
        c.position(),
        c.radius(),
        c.color(),
        c.scoreValue()
    };
}

// Nájde najbližší trash v dosahu robota, vymaže ho z mapy a vráti jeho kópiu.
std::optional<WorldManager::TrashView>
WorldManager::pickupNearest(const geometry::Point2d& p, double radius)
{
    std::lock_guard<std::mutex> lock(mutex_);

    uint32_t best_id = 0;
    double best_dist = std::numeric_limits<double>::max();
    const Collectible* best = nullptr;

    for (const auto& [id, t] : trash_) {
        if (!t->intersects(p, radius)) continue;
        const double dx = t->position().x - p.x;
        const double dy = t->position().y - p.y;
        const double d = std::sqrt(dx * dx + dy * dy);
        if (d < best_dist) {
            best_dist = d;
            best_id = id;
            best = t.get();
        }
    }

    if (!best) {
        return std::nullopt;
    }

    TrashView view = toView(*best);
    trash_.erase(best_id);
    return view;
}

// Vráti kópie všetkého trashu na mape, používa sa pre game_state topic.
std::vector<WorldManager::TrashView> WorldManager::listTrash() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    std::vector<TrashView> out;
    out.reserve(trash_.size());
    for (const auto& [id, t] : trash_) {
        out.push_back(toView(*t));
    }
    return out;
}

// Vráti počet trashu aktuálne na mape.
size_t WorldManager::trashCount() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return trash_.size();
}

// Vymaže všetok trash, volá sa pri reštarte hry.
void WorldManager::clearTrash()
{
    std::lock_guard<std::mutex> lock(mutex_);
    trash_.clear();
}

// Vráti true ak je pozícia blokovaná prekážkou, stanicou alebo existujúcim trashom.
bool WorldManager::positionBlocked(const geometry::Point2d& p, double radius) const
{
    std::lock_guard<std::mutex> lock(mutex_);
    for (const auto& o : obstacles_) {
        if (o->intersects(p, radius)) return true;
    }
    if (station_ && station_->intersects(p, radius)) return true;
    for (const auto& [id, t] : trash_) {
        if (t->intersects(p, radius)) return true;
    }
    return false;
}

} // namespace core::world
