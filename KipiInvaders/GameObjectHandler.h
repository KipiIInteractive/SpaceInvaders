#ifndef GAMEOBJECTHANDLER_H_INCLUDED
#define GAMEOBJECTHANDLER_H_INCLUDED

#include "EnemyResources.h"
#include "GameResources.h"
#include "BulletResources.h"
#include "PlayerResources.h"

class GameObjectHandler {
public:
    static void updateEnemies();
    static void updatePlayer();
    static void updateBullets();

    static void changeEnemiesShootingSpeed();

    static int getRemainingEnemies();
};

#endif // GAMEOBJECTHANDLER_H_INCLUDED
