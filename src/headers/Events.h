#pragma once
#include "Entity.h"
#include <typeindex>
#include <functional>
#include <unordered_map>
#include <vector>

enum class EventType {
    Touching, 
    Notification,
    Executable,
};
    
class Event {
public:
    virtual ~Event() = default;
};

class DamageEvent : public Event {
public:
    Entity source;
    Entity target;
    float damageAmount;
    EventType type;

    DamageEvent(Entity source, Entity target, float damage, EventType type) : source(source), target(target), damageAmount(damage), type(type) {}
};

// The EventBus allows subscribing to and publishing events.


class StatusAppliedEvent : public Event {
public:
    Entity source;
    Entity target;
    EventType type; 
    float interval;
    std::function<bool()> condition;

    float timeSinceLastTick = 0.0f;
    

    StatusAppliedEvent(Entity source, Entity target, EventType t, float interval, std::function<bool()> condition) 
        : source(source), target(target), type(t), interval(interval), condition(condition) {}
};