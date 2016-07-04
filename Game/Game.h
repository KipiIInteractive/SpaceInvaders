#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "../level_management/LevelManager.h"
#include "../Entities/AliensManager.h"
#include "../Entities/Player.h"
#include "../Entities/BulletsManager.h"

class Game
{
    public:
        static void StartGame();
        static void Init();
        static SDL_Rect Pannel;

    private:
        static void RenderEverything();
        static bool isRunning;
        static SDL_Texture *background;
        static SDL_Texture *borderTexture;
        static SDL_Rect leftBorder;
        static SDL_Rect rightBorder;
        static void GetPlayerInput();
        static int framesAfterShooting;
};

#endif // GAME_H_INCLUDED
