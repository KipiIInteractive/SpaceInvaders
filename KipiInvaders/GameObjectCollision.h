#ifndef GAMEOBJECTCOLLISION_H_INCLUDED
#define GAMEOBJECTCOLLISION_H_INCLUDED

#include "EnemyResources.h"
#include "BulletResources.h"

class GameObjectCollision {
public:
    static void checkEnemyCollision();
    static void checkPlayerCollision();
    static void checkBulletCollision();
};

#endif // GAMEOBJECTCOLLISION_H_INCLUDED
