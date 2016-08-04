#ifndef GAMEOVERWINDOW_H_INCLUDED
#define GAMEOVERWINDOW_H_INCLUDED

#include <SDL.h>
<<<<<<< HEAD
#include <iostream>
#include "../System/System.h"
#include "../GUI/Link.h"
=======
#include "../System/System.h"
#include "../GUI/Link.h"
#include "../GUI/Label.h"
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
#include "../level_management/LevelManager.h"
#include "Game.h"
#include "RankList.h"
#include "NameSelectionWindow.h"

class GameOver
{
    public:
        static void Init();
        static void Show();
<<<<<<< HEAD
        static void Free();

    private:
        static SDL_Texture *background_texture;
        static bool isActive;
        static Link NewGameButton;
        static void CreateTheButtonsEffects();
        static void CreateTheButtonsActions();
=======

    private:
        static SDL_Texture *background_texture;
        static Label text_title;
        static Label text_title_top_players;
        static Label text_score;
        static Label text_navigation_hint;

        static bool isActive;

        static Link NewGameButton;
        static Link ExitButton;

        static void RenderEverything();
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
};

#endif // GAMEOVERWINDOW_H_INCLUDED
