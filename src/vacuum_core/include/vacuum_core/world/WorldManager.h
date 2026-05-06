#pragma once

#include <memory>
#include <mutex>
#include <optional>
#include <unordered_map>
#include <vector>

#include "vacuum_core/world/Collectible.h"
#include "vacuum_core/world/Obstacle.h"
#include "vacuum_core/world/Station.h"

namespace vacuum_core::world {

class WorldManager {
public:
    WorldManager() = default;

    WorldManager(const WorldManager&) = delete;
    WorldManager& operator=(const WorldManager&) = delete;

    void addObstacle(std::unique_ptr<Obstacle> obs);
    bool isObstacleAt(const geometry::Point2d& p, double radius) const;
    std::vector<const Obstacle*> obstacles() const;

    void setStation(std::unique_ptr<Station> st);
    const Station* station() const;
    bool isAtStation(const geometry::Point2d& p, double radius) const;

    uint32_t nextId();
    void addTrash(std::unique_ptr<Collectible> trash);
    bool removeTrash(uint32_t id);

    // Returns copy of the trash that was removed, or nullopt
    struct TrashView {
        uint32_t id;
        std::string type;
        geometry::Point2d position;
        double radius;
        Color color;
        int score_value;
    };

    std::optional<TrashView> pickupNearest(const geometry::Point2d& p, double radius);
    std::vector<TrashView> listTrash() const;
    size_t trashCount() const;
    void clearTrash();

    // For spawn collision checks (map is handled separately by caller)
    bool positionBlocked(const geometry::Point2d& p, double radius) const;

private:
    static TrashView toView(const Collectible& c);

    mutable std::mutex mutex_;
    std::vector<std::unique_ptr<Obstacle>> obstacles_;
    std::unique_ptr<Station> station_;
    std::unordered_map<uint32_t, std::unique_ptr<Collectible>> trash_;
    uint32_t next_id_{1};
};

} // namespace vacuum_core::world
