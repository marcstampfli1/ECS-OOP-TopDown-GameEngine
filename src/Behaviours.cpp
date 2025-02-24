#include "headers/Behaviours.h"
#include "headers/Entity.h"
#include "headers/Components.h"
#include "headers/Systems.h"
#include "headers/Managers.h"

#include <windows.h>
#include <iostream>
#include <cmath>

void EntityBehaviour::initialize(std::shared_ptr<EntityManager> em) {
    entityManager = em;
}

