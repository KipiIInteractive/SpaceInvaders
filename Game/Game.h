#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "../Entities/BulletsManager.h"
#include "../Entities/AliensManager.h"
#include "../sounds_management/SoundManager.h"
#include "../level_management/LevelManager.h"
#include "../fps_conroller/FPS_Controller.h"

#include "../Entities/Player.h"
#include "../Entities/Barrier.h"
#include "../Entities/UFO.h"

#include "GameOverWindow.h"
<<<<<<< HEAD
=======
#include "WinWindow.h"
<<<<<<< HEAD
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
=======

#include "../GUI/Label.h"
>>>>>>> ecbd78b... The UFO feature is added. On launch Start Menu is shown with options to
#include <string>

class Game
{
    public:
        static void StartGame();
        static void Init();
        static void FreeCurrentLevel();
        static SDL_Rect Pannel;
        static Barrier *barriers[];
        static int score;
        static bool isRunning;
<<<<<<< HEAD
=======
        static void PreStartInitializations();
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

    private:
        static Label ScoreText;
        static Label LevelText;
        static Label LivesText;

        static int framesToShowTheLevelNumber;

        static void RenderEverything();
        static SDL_Texture *background;
        static SDL_Texture *borderTexture;
        static SDL_Rect leftBorder;
        static SDL_Rect rightBorder;
        static void GetPlayerInput();
        static int framesAfterShooting;
        static FPS_Controller *fps;
};

#endif // GAME_H_INCLUDED
