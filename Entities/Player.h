#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "../System/System.h"
#include "BulletsManager.h"
#include "../Game/Game.h"
#include <SDL2/SDL.h>

class Player
{
    public:
        static void Init();
        static void Render();
        static void Move(int direction);
        static void Shoot();

        static SDL_Rect rect;

        static void DecreaseLives();
        static int lives;
        static bool isDead;

    private:
        static int respawnTimeInSeconds;
        static SDL_Texture *aliveTexture;
        static SDL_Texture *deadTexture;
        static int movementSpeed;
};

#endif // PLAYER_H_INCLUDED
