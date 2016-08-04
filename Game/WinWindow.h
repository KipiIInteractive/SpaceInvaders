#ifndef WINWINDOW_H_INCLUDED
#define WINWINDOW_H_INCLUDED

#include <SDL.h>
#include "../System/System.h"
#include "../GUI/Label.h"
#include "../GUI/Link.h"
#include "Game.h"

class WinWindow
{
    public:
        static void Init();
        static void Show();

    private:
        static SDL_Texture *background_texture;

        static Label text_title;
        static Label text_score;
        static Label text_navigation_hint;

        static bool isActive;
        static void RenderEverything();
};

#endif // WINWINDOW_H_INCLUDED
