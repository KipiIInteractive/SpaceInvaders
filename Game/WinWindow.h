#ifndef WINWINDOW_H_INCLUDED
#define WINWINDOW_H_INCLUDED

#include <SDL2/SDL.h>
#include "../System/System.h"
#include "../GUI/Label.h"
#include "../GUI/Link.h"
#include "Game.h"
#include "NameSelectionWindow.h"

class WinWindow
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
        static void RenderEverything();
};

#endif // WINWINDOW_H_INCLUDED
