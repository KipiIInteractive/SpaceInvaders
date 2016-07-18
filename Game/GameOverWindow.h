#ifndef GAMEOVERWINDOW_H_INCLUDED
#define GAMEOVERWINDOW_H_INCLUDED

#include <SDL.h>
#include <iostream>
#include "../System/System.h"
#include "../GUI/Link.h"
#include "../level_management/LevelManager.h"
#include "Game.h"

class GameOver
{
    public:
        static void Init();
        static void Show();
        static void Free();

    private:
        static SDL_Texture *background_texture;
        static bool isActive;
        static Link NewGameButton;
        static void CreateTheButtonsEffects();
        static void CreateTheButtonsActions();
};

#endif // GAMEOVERWINDOW_H_INCLUDED
