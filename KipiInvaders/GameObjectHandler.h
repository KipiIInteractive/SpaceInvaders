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

    static void resetEnemies();
    static void resetPlayer();
    static void resetUFO();
    static void resetBullets();
    static void resetBarriers();

    static int getRemainingEnemies();
};

#endif // GAMEOBJECTHANDLER_H_INCLUDED
