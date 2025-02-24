#pragma once
#include "Entity.h"
#include "Components.h"
#include <typeindex>
#include <functional>
#include <unordered_map>
#include <vector>
#include <memory>
    
class Event {
public:
    
};

class StatusEvent : public Event {
public:
    ~StatusEvent() = default;
};

class StatusAppliedEvent : public StatusEvent {
public:
    Entity target;
    float interval;
    std::function<bool()> condition;
    float timeSinceLastTick = 0.0f;
    std::shared_ptr<Event> event;

    StatusAppliedEvent(Entity source, Entity target, float interval, std::function<bool()> condition) 
        : target(target), interval(interval), condition(condition) {}
};

class StatusRemovedEvent : public StatusEvent {
public:
    Entity target;
    StatusAppliedEvent status;
};