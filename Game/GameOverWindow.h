#ifndef GAMEOVERWINDOW_H_INCLUDED
#define GAMEOVERWINDOW_H_INCLUDED

#include <SDL2/SDL.h>
#include "../System/System.h"
#include "../GUI/Link.h"
#include "../GUI/Label.h"
#include "../level_management/LevelManager.h"
#include "Game.h"
#include "RankList.h"
#include "NameSelectionWindow.h"

class GameOver
{
    public:
        static void Init();
        static void Show();

    private:
        static SDL_Texture *backgroundTexture;
        static Label titleText;
        static Label topPlayersText;
        static Label scoreText;
        static Label navigationHintText;

        static bool isActive;

        static Link NewGameButton;
        static Link ExitButton;

        static void RenderEverything();
};

#endif // GAMEOVERWINDOW_H_INCLUDED
