#ifndef GAMEOBJECTRENDERER_H_INCLUDED
#define GAMEOBJECTRENDERER_H_INCLUDED

#include "EnemyResources.h"
#include "BulletResources.h"

class GameObjectRenderer {
public:
    static void renderEnemies();
    static void renderPlayer();
    static void renderBullets();
};

#endif // GAMEOBJECTRENDERER_H_INCLUDED
