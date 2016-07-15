#ifndef GAMEOBJECTCOLLISION_H_INCLUDED
#define GAMEOBJECTCOLLISION_H_INCLUDED

#include "EnemyResources.h"
#include "BulletResources.h"
#include "PlayerResources.h"
#include "BarrierResources.h"

class GameObjectCollision {
public:
    static void checkEnemyCollision();
    static void checkAndHandlePlayerCollision();
    static void checkBulletCollision();

    static void handleEnemyCollision();
    static vector<Bullet*>::iterator handleBulletCollision(vector<Bullet*>::iterator it);
};

#endif // GAMEOBJECTCOLLISION_H_INCLUDED
