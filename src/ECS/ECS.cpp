#include "ECS.h"
#include "../Logger/Logger.h"
//TODO: Implement functions for ECS

/////////////////////////////////////////////////
// System
// Process Entities with a specific signature
/////////////////////////////////////////////////

void System::AddEntityToSystem(Entity entity) {
    entities.push_back(entity);
}

void System::RemoveEntityFromSystem(Entity entity) {
    entities.erase(std::remove_if(entities.begin(),
                                          entities.end(),
                                          [&entity] (Entity currentEntity) {
                                               return entity == currentEntity;
                                          }), entities.end());
}

std::vector <Entity> System::GetSystemEntites() const {
    return entities;
}

const Signature &System::GetComponentSignature() const {
    return componentSignature;
}

/////////////////////////////////////////////////
// REGISTRY
/////////////////////////////////////////////////

Entity Registry::CreateEntity() {
    int entityId;
    entityId = numEntities++;

    Entity entity(entityId);
    entitiesToBeAdded.insert(entity);

    Logger::Log("Entity created with Id = " + std::to_string(entityId));

    return entity;
}

void Registry::Update() {
    //Add entities that are waiting to be added

    //Remove entities that are waiting to be killed
}