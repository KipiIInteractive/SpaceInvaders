#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "../System/System.h"
#include "BulletsManager.h"
#include "../Game/Game.h"
#include <SDL.h>

class Player
{
    public:
        static void Init();
        static void Render();
        static void Move(int direction);
        static void Shoot();
        static SDL_Rect rect;

    private:
        static SDL_Texture *texture;
        static int movementSpeed;
};

#endif // PLAYER_H_INCLUDED
