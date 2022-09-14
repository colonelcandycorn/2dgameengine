//
// Created by sarah on 9/11/22.
//

#ifndef RIGIDBODYCOMPONENT_H
#define RIGIDBODYCOMPONENT_H

#include <glm/glm.hpp>

struct RigidBodyComponent {
    glm::vec2 velocity;

    RigidBodyComponent(glm::vec2 velocity = glm::vec2 (0.0, 0.0)) : velocity(velocity) {};
};

#endif //INC_2DGAMEENGINE_RIGIDBODYCOMPONENT_H
