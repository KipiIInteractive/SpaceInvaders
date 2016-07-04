#include "InitSDL.h"

bool InitSDL::init() {
    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        cout << SDL_GetError() << endl;
        success = false;
    }
    else {
        System::window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, System::SCREEN_WIDTH, System::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(System::window == NULL) {
            cout << SDL_GetError() << endl;
            success = false;
        }
        else {
            System::renderer = SDL_CreateRenderer(System::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(System::renderer == NULL) {
                cout << SDL_GetError() << endl;
                success = false;
            }

            SDL_SetRenderDrawColor(System::renderer, 255, 255, 255, 255);

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
