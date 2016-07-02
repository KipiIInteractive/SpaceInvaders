#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

//Loading SDL libs
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

//Loading standard libs
#include <string>
#include <windows.h>.
#include <cstdlib>
#include <iostream>

using namespace std;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern SDL_Window* gWindow;

extern SDL_Renderer* gRenderer;

extern TTF_Font* gFont;

extern Mix_Music* gMusic;

#endif // MAIN_H_INCLUDED
