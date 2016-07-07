#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include <SDL.h>
#include "Direction.h"
#include "Texture.h"
#include "EnemyResources.h"

class Bullet
{
    private:
        SDL_Rect rect;
        Texture texture;
        int speed;
        Direction direction;
        bool collided;
    public:
        Bullet(Texture texture, Direction direction, int speed);
        ~Bullet();

        bool loadBulletFromFile(string path);

        int GetX();
        int GetY();
        int GetWidth();
        int GetHeight();

        void SetX(int value);
        void SetY(int value);
        void SetWidth(int value);
        void SetHeight(int value);

        void SetDirection(Direction direction);
        Direction GetDirection();

        void update();

        bool hasCollided();
        bool hasCollidedWithEnemy();
        bool hasCollidedWithPlayer();

        void checkCollision();

        void render();

        void SetSpeed(int speed);
};

#endif // BULLET_H_INCLUDED
