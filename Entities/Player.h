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
        static void Free();
        static void Render();
        static void Move(int direction);
        static void Shoot();
        static SDL_Rect rect;

        static void Die();
        static int lives;
        static bool isDead;

    private:
        static int framesToBeDead;
        static SDL_Texture *texture;
        static SDL_Texture *texture_dead;
        static int movementSpeed;
};

#endif // PLAYER_H_INCLUDED
