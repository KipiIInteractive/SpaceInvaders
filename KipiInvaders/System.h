#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <SDL.h>
#include <windows.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

class System {
public:
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    static const int SCREEN_WIDTH;
    static const int SCREEN_HEIGHT;

    //FPS
    static const int AVG_FPS;
    static const int TIME_PER_FRAME;

    //Font
    static TTF_Font* font;

    //Music
    static Mix_Music* music;
};

#endif // SYSTEM_H_INCLUDED
