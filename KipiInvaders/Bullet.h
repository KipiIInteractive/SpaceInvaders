#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include <SDL.h>
#include "GameObject.h"
#include "EnemyResources.h"
#include "PlayerResources.h"

class Bullet : public GameObject {
    private:
        bool collided;
        bool collidedWithBarrier;
    public:
        Bullet(Texture& texture, Direction direction, int speed);

        void update();

        bool hasCollided();
        void setHasCollided(bool b);
        bool hasCollidedWithEnemy();
        bool hasCollidedWithPlayer();
        bool hasCollidedWithBarrier();
        void setHasCollidedWithBarrier(bool b);

        void checkCollision();
};

#endif // BULLET_H_INCLUDED
