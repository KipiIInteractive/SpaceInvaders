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
#include "WinWindow.h"

#include "../GUI/Label.h"
#include <string>

#define NUMBER_OF_BARRIERS 3

class Game
{
    public:
        static string currentGameMode;

        static void StartClassicGame();
        static void StartSurvivalGame();
        static void Init();
        static SDL_Rect Pannel;
        static Barrier *barriers[NUMBER_OF_BARRIERS];
        static int pScore;
        static bool isRunning;
        static void PreClassicGameStartInitializations();
        static void PreSurvivalGameStartInitializations();

    private:
        static Label ScoreText;
        static Label LevelText;
        static Label LivesText;

        static int LevelRenderTimeInSeconds;

        static void RenderEverything();
        static SDL_Texture *background;
        static SDL_Texture *borderTexture;
        static SDL_Rect leftBorder;
        static SDL_Rect rightBorder;
        static void GetPlayerInput();
        static int timeInSecondsAfterPlayerShooting;
        static FPS_Controller *fps;
};

#endif // GAME_H_INCLUDED
