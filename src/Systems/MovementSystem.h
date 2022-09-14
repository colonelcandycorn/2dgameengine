#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include "../ECS/ECS.h"
#include "../Components/TransformComponent.h"
#include "../Components/RigidBodyComponent.h"

class MovementSystem: public System {
	public:
		MovementSystem() {
		//TODO: Specify RequireComponent<TransformComponent>();
            RequireComponent<TransformComponent>();
            RequireComponent<RigidBodyComponent>();
		}

		void Update(double deltaTime) {
		//TODO:
        for (auto entity : GetSystemEntites()) {
            auto& transformComponent = entity.GetComponent<TransformComponent>();
            const auto rigidBodyComponent = entity.GetComponent<RigidBodyComponent>();

            transformComponent.position.x += rigidBodyComponent.velocity.x * deltaTime;
            transformComponent.position.y += rigidBodyComponent.velocity.y * deltaTime;

            Logger::Log("Entity Id " + std::to_string(entity.GetId()) + " Position is x: " + std::to_string(transformComponent.position.x) + " y: " + std::to_string(transformComponent.position.y));
        }

		//for (auto entity: GetEntities()) {}
		//Update entity position based on its velocity
		// every frame of the game loop.
		}
};

#endif
