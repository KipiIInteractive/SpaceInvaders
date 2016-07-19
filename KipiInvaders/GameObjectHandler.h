#ifndef GAMEOBJECTHANDLER_H_INCLUDED
#define GAMEOBJECTHANDLER_H_INCLUDED

#include "EnemyResources.h"
#include "GameResources.h"
#include "BulletResources.h"
#include "PlayerResources.h"
#include "BarrierResources.h"

class GameObjectHandler {
public:
    static bool playedUFOSound;

    static void updateEnemies();
    static void updatePlayer();
    static void updateBullets();
    static void updateBarriers();

    static void changeEnemiesShootingSpeed();
    static void changeEnemiesMovementSpeed();
    static void changeEnemiesBulletSpeed();

    static int getRemainingEnemies();
};

#endif // GAMEOBJECTHANDLER_H_INCLUDED
