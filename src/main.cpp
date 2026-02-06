#include <iostream>
#include "entity/Entity.h"
#include "components/TransformComponent.h"

int main()
{
    Entity entity;
    TransformComponent transform;
    entity.add_component(&transform);

    
    TransformComponent* p_transform = entity.get_component<TransformComponent>();
    if (p_transform) {
        std::cout << "we have player transform here\n";
    }
    else {
        std::cout << "failed to get player transform\n";
    }
    std::cin.get();
    return 0;
}