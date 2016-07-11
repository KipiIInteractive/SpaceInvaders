#ifndef GAMEOBJECTGENERATOR_H_INCLUDED
#define GAMEOBJECTGENERATOR_H_INCLUDED

#include "GameResources.h"
#include "EnemyResources.h"
#include "BulletResources.h"
#include "PlayerResources.h"

class GameObjectGenerator {
public:
    static bool enemiesGenerated;
    static bool UFOGenerated;
    static bool playerGenerated;

    static void generateEnemies();
    static void generatePlayer();
    static void generateBullets();
};

#endif // GAMEOBJECTGENERATOR_H_INCLUDED
