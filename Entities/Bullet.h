#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include <SDL.h>
#include "../System/System.h"

class Bullet
{
    public:
        Bullet(int speed, int pos_x, int pos_y, int direction);
        ~Bullet();

        void SetTexture(SDL_Texture *texture);

        void SetDirection(int direction);
        int GetDirection();

        void Update();
        void Render();

        bool isHitTheWall();

    private:
        SDL_Rect rect;
        SDL_Texture *texture;
        int movementSpeed;
        int direction;
};

#endif // BULLET_H_INCLUDED
