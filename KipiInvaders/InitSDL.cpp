#include "InitSDL.h"

//SCREEN RESOLUTION
const int SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN)-100;
const int SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN)-100;

//Stores the game window
SDL_Window* gWindow = NULL;

//Used for rendering onto the window
SDL_Renderer* gRenderer = NULL;

bool InitSDL::init() {
    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        cout << SDL_GetError() << endl;
        success = false;
    }
    else {
        gWindow = SDL_CreateWindow("Kipi Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL) {
            cout << SDL_GetError() << endl;
            success = false;
        }
        else {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(gRenderer == NULL) {
                cout << SDL_GetError() << endl;
                success = false;
            }

            SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);

            //Different image format initialization
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags)) {
                cout << IMG_GetError() << endl;
                success = false;
            }

            //Fonts init
            if(TTF_Init() == -1) {
                cout << TTF_GetError() << endl;
                success = false;
            }

            //Music init
            if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
                cout << Mix_GetError() << endl;
                success = false;
            }
        }
    }

    return success;
}
