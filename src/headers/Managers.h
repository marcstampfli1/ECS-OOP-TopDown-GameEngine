#pragma once
#include <unordered_map>
#include <unordered_set>
#include <string>

#include "../../graphicslib/src/Shader.h"
#include "../../graphicslib/src/Window.h"
#include "../../graphicslib/src/Mesh.h"
#include "../../graphicslib/src/Texture.h"

#include "Entity.h"
#include "Components.h"
#include "Behaviours.h"
#include "Systems.h"
#include "Events.h"

#include <memory>
#include <vector>
#include <algorithm>
#include <typeindex>

class EventBus {
public:

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

    EventBus() = default;
protected:
    // Maps each event type to a list of handler functions.
    std::unordered_map<std::type_index, std::vector<std::function<void(const Event&)>>> subscribers;
};
    
class EntityManager : public std::enable_shared_from_this<EntityManager>{
public:

    void setSize(Entity entity, const Size& size);
    const Size* getSize(Entity entity);

    void setBehaviour(Entity entity, std::shared_ptr<EntityBehaviour> behaviour);
    const std::shared_ptr<EntityBehaviour> getBehaviour(Entity entity);

    void setType(Entity entity, EntityType type);
    const EntityType* getType(Entity entity);

    Position* getPosition(Entity entity);
    Velocity* getVelocity(Entity entity);
    Health* getHealth(Entity entity) ;

    void setPosition(Entity entity, const Position& position);
    void setVelocity(Entity entity, const Velocity& velocity);
    void setHealth(Entity entity, const Health& health);

    Entity createEntity();

    void destroyEntity(Entity entity);
    
    bool entityExists(Entity entity) const;

    const std::unordered_set<Entity> getEntitiesByType(EntityType type) const;

    const std::unordered_set<Entity> getAllEntities() const;

    void setPlayer(Entity entity);

    Entity getPlayer();


    EntityManager() = default;






protected:

    std::shared_ptr<EntityManager> getSharedPtr() {
        return shared_from_this(); 
    }

    Entity player;
    std::unordered_map<Entity, Position> positionComponents;
    std::unordered_map<Entity, Velocity> velocityComponents;
    std::unordered_map<Entity, Health> healthComponents;
    std::unordered_map<Entity, Size> sizeComponents;
    std::unordered_map<Entity, std::shared_ptr<EntityBehaviour>> behaviours;
    std::unordered_map<Entity, EntityType> typeComponents;
    std::unordered_set<Entity> activeEntities;
    std::unordered_map<EntityType, std::unordered_set<Entity>> activeEntitiesByType;
    Entity nextEntityID = 0;
};

class Renderer {
public:

    void render();

    void initialize(std::shared_ptr<EntityManager> em);

    Window& getWindow();

    Renderer() = default;

protected:

    Window window;
    
    std::unordered_map<Entity, Shader*> shaderComponents;
    std::unordered_map<Entity, Texture*> textureComponents;
    std::unordered_map<Entity, std::unique_ptr<Mesh>> meshComponents;

    std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
    std::unordered_map<std::string, std::shared_ptr<Shader>> shaders;
    std::vector<Entity> sortedDrawEntities;

    void updateEntityRectangles();
    void sortEntitiesByYValue();
    
    std::shared_ptr<EntityManager> entityManager;
};

class SystemManager {
    public:
        void update(float dt);
        void initialize(std::shared_ptr<EntityManager> em, std::shared_ptr<EventBus> eb);
        
        DamageSystem damageSystem;
        MovementSystem movementSystem;
        StatusSystem statusSystem;
        CollisionSystem collisionSystem;
    
        SystemManager() = default; 
    
    };