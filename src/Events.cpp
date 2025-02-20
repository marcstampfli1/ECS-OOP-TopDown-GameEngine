#include "headers/Events.h"
#include "headers/ResourceManager.h"

extern ResourceManager& rm;

/*void DamageEvent::process() {
    if (rm.healthComponents.find(target) != rm.healthComponents.end()) {
        rm.healthComponents[target].currentHealth -= damageAmount;
    }
}

template<typename Event>
void EventBus::subscribe(std::function<void(const Event&)> handler) {
    // Use the event type's runtime type information as a key.
    auto& handlers = subscribers[std::type_index(typeid(Event))];
    // Wrap the handler so that it accepts a base Event reference.
    // When an event is published, this wrapper casts it back to EventType.
    handlers.push_back([handler](const Event& event) {
        handler(static_cast<const Event&>(event));
    });
};

template<typename Event>
void EventBus::publish(const Event& event) const {
    auto it = subscribers.find(std::type_index(typeid(Event)));
    if (it != subscribers.end()) {
        // Call each subscribed handler with the event.
        for (const auto& handler : it->second) {
            handler(event);
        }
    }
}*/