#ifndef GAMEOBJECTCOLLISION_H_INCLUDED
#define GAMEOBJECTCOLLISION_H_INCLUDED

#include "EnemyResources.h"
#include "BulletResources.h"

class GameObjectCollision {
public:
    static void checkEnemyCollision();
    static void checkPlayerCollision();
    static void checkBulletCollision();

    static void handleEnemyCollision();
    static void handlePlayerCollision();
    static list<Bullet*>::iterator handleBulletCollision(list<Bullet*>::iterator it);
};

#endif // GAMEOBJECTCOLLISION_H_INCLUDED
