#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include <SDL2/SDL.h>
#include "../System/System.h"

class Bullet
{
    public:
        Bullet(int speed, int xPos, int yPos, int direction);

        void SetTexture(SDL_Texture *texture);

        void SetDirection(int direction);
        int GetDirection();

        void Update();
        void Render();

        bool hasHitTheWall();
        SDL_Rect rect;

    private:
        SDL_Texture *texture;
        int movementSpeed;
        int direction;
};

#endif // BULLET_H_INCLUDED
