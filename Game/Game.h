#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "../level_management/LevelManager.h"
#include "../Entities/AliensManager.h"
#include "../Entities/Player.h"
#include "../Entities/Barrier.h"
#include "../Entities/BulletsManager.h"
#include "../fps_conroller/FPS_Controller.h"
#include "../GUI/Label.h"
#include <string>

class Game
{
    public:
        static void StartGame();
        static void Init();
        static SDL_Rect Pannel;
        static Barrier *barriers[];
        static int score;

    private:
        static Label ScoreText;

        static void RenderEverything();
        static bool isRunning;
        static SDL_Texture *background;
        static SDL_Texture *borderTexture;
        static SDL_Rect leftBorder;
        static SDL_Rect rightBorder;
        static void GetPlayerInput();
        static int framesAfterShooting;
        static FPS_Controller *fps;
};

#endif // GAME_H_INCLUDED
