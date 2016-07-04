#ifndef GAMEOBJECTGENERATOR_H_INCLUDED
#define GAMEOBJECTGENERATOR_H_INCLUDED

#include "Resources.h"

class GameObjectGenerator {
public:
    static bool enemiesGenerated;

    static void generateEnemies();
    static void generatePlayer();
};

#endif // GAMEOBJECTGENERATOR_H_INCLUDED
