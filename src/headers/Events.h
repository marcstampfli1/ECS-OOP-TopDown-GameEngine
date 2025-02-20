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
class EventBus {
public:
    // Subscribe to an event type with a handler function.

    template<typename EventTemplate>
    void subscribe(std::function<void(const EventTemplate&)> handler) {
        // Use the event type's runtime type information as a key.
        auto& handlers = subscribers[std::type_index(typeid(EventTemplate))];
        // Wrap the handler so that it accepts a base Event reference.
        // When an event is published, this wrapper casts it back to EventType.
        handlers.push_back([handler](const Event& event) {
            handler(static_cast<const EventTemplate&>(event));
        });
    };

    template<typename EventTemplate>
    void publish(const EventTemplate& event) const {
        auto it = subscribers.find(std::type_index(typeid(EventTemplate)));
        if (it != subscribers.end()) {
            // Call each subscribed handler with the event.
            for (const auto& handler : it->second) {
                handler(event);
            }
        }
    }

private:
    // Maps each event type to a list of handler functions.
    std::unordered_map<std::type_index, std::vector<std::function<void(const Event&)>>> subscribers;
};


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