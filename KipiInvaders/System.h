#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <SDL.h>
#include <windows.h>
#include <SDL_ttf.h>

class System {
public:
    //FPS
    static const int AVG_FPS;
    static const int TIME_PER_FRAME;

    static const int LEFT_X_BORDER;
    static const int RIGHT_X_BORDER;

    static SDL_Window* window;
    static SDL_Renderer* renderer;

    static const int SCREEN_WIDTH;
    static const int SCREEN_HEIGHT;

    //Font
    static TTF_Font* font;
};

#endif // SYSTEM_H_INCLUDED
