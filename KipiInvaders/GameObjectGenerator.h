#ifndef GAMEOBJECTGENERATOR_H_INCLUDED
#define GAMEOBJECTGENERATOR_H_INCLUDED

#include "GameResources.h"
#include "EnemyResources.h"
#include "BulletResources.h"
#include "PlayerResources.h"
#include "BarrierResources.h"

class GameObjectGenerator {
public:
    static bool enemiesGenerated;
    static bool UFOGenerated;
    static bool playerGenerated;
    static bool barriersGenerated;

    static void generateEnemies();
    static void generateAdditionalHordes();
    static void generatePlayer();
    static void generateBullets();
    static void generateBarriers();
};

#endif // GAMEOBJECTGENERATOR_H_INCLUDED
