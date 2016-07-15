#ifndef GAMEOBJECTRENDERER_H_INCLUDED
#define GAMEOBJECTRENDERER_H_INCLUDED

#include "EnemyResources.h"
#include "BulletResources.h"
#include "PlayerResources.h"
#include "BarrierResources.h"

class GameObjectRenderer {
public:
    static void renderEnemies();
    static void renderPlayer();
    static void renderBullets();
    static void renderBarriers();
};

#endif // GAMEOBJECTRENDERER_H_INCLUDED
