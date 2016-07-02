#include "GameLoop.h"
#include "LoadMedia.h"

void GameLoop::run() {
    bool isRunning = true;
    SDL_Event e;
    //Main Game Loop
    while(isRunning) {
        //Handles events when they occur
        while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT) {
                isRunning = false;
            }
        }
        //Clears the game window
        SDL_RenderClear(gRenderer);

        gMenuBackground.render(0, 0);

        //Updates game window
        SDL_RenderPresent(gRenderer);
    }
}
