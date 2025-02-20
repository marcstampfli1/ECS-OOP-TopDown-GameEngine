/*#pragma once
#include "Entity.h"
#include <functional>
#include <memory>

class Status {
public:
    // Optionally, you might store a source if needed.
    Entity source; // For example, the enemy applying the effect.
    Entity target;
    float interval;               // How often the effect should trigger.
    float timeSinceLastTick = 0;  // Accumulated time since the last tick.
    // Condition returns true as long as the effect should remain active.
    std::function<bool()> condition;  

    // Constructor: no duration, just an interval and a condition.
    Status(Entity source, Entity target, float interval, std::function<bool()> condition)
        : source(source), target(target), interval(interval), condition(condition) {}

    virtual void applyEffect() = 0; // Each effect defines its own behavior.
    virtual ~Status() = default;
};

class EnemyTouchingPlayerStatus : public Status {
public:
    float damageAmount;

    EnemyTouchingPlayerStatus(Entity source, Entity target, float interval, std::function<bool()> condition, float damage)
        : Status(source, target, interval, condition), damageAmount(damage) {}

    void applyEffect() override;
};
*/
    