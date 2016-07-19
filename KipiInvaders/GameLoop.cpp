#include "GameLoop.h"

Uint8 startTime = 0;

void GameLoop::run() {
    bool isRunning = true;
    bool isPaused = false;
    SDL_Event e;
    srand(time(NULL));
    while(isRunning) {
        startTime = SDL_GetTicks();
        while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT) {
                isRunning = false;
            }

            if(gPlayButton.isClicked()) {
                if(gBackButton.isClicked()) {
                    gPlayButton.unclick();
                    gBackButton.unclick();
                }
                else if(gClassicGameModeButton.isClicked()) {
                    if(isPaused) {
                        MenuHandler::handlePauseMenuEvents(&e);
                        if(gResumeButton.isClicked()) {
                            isPaused = false;
                            gResumeButton.unclick();
                        }
                        else if(gMainMenuButton.isClicked()) {
                            gClassicGameModeButton.unclick();
                            gPlayButton.unclick();
                            gMainMenuButton.unclick();
                            isPaused = false;
                            GameHandler::resetGame();
                        }
                        else if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p) {
                            isPaused = false;
                        }
                    }
                    else {
                        if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p) {
                            isPaused = true;
                        }
                    }
                }
                else if(gSurvivalGameModeButton.isClicked()) {
                    if(isPaused) {
                        MenuHandler::handlePauseMenuEvents(&e);
                        if(gResumeButton.isClicked()) {
                            isPaused = false;
                            gResumeButton.unclick();
                        }
                        else if(gMainMenuButton.isClicked()) {
                            gSurvivalGameModeButton.unclick();
                            gPlayButton.unclick();
                            gMainMenuButton.unclick();
                            isPaused = false;
                        }
                    }
                    else {
                        if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p) {
                            isPaused = true;
                        }
                    }
                }
                else {
                    MenuHandler::handleGameModesMenuEvents(&e);
                }
            }
            else if(gControlsButton.isClicked()) {
                MenuHandler::handleControlsMenuEvents(&e);
                if(gBackButton.isClicked()) {
                    gControlsButton.unclick();
                    gBackButton.unclick();
                }
            }
            else if(gRankingButton.isClicked()) {
                MenuHandler::handleRankingMenuEvents(&e);
                if(gBackButton.isClicked()) {
                    gRankingButton.unclick();
                    gBackButton.unclick();
                }
            }
            else {
                MenuHandler::handleMainMenuEvents(&e);
            }
        }
        //Clears the game window
        SDL_RenderClear(System::renderer);

        if(gPlayButton.isClicked()) {
            if(gClassicGameModeButton.isClicked()) {
                if(isPaused) {
                    MenuHandler::showPauseMenu();
                }
                else {
                    GameHandler::startClassicGame();
                }
            }
            else if(gSurvivalGameModeButton.isClicked()) {
                if(isPaused) {
                    MenuHandler::showPauseMenu();
                }
                else {
                    GameHandler::startSurvivalGame();
                }
            }
            else {
                MenuHandler::showGameModesMenu();
            }
        }
        else if(gControlsButton.isClicked()) {
            MenuHandler::showControlsMenu();
        }
        else if(gRankingButton.isClicked()) {
            MenuHandler::showRankingMenu();
        }
        else if(gExitButton.isClicked()) {
            isRunning = false;
            MenuHandler::showMainMenu();
            GameHandler::shutdownGame();
        }
        else {
            MenuHandler::showMainMenu();
        }
        //Updates game window
        SDL_RenderPresent(System::renderer);

        if(SDL_GetTicks() - startTime < System::TIME_PER_FRAME) {
            SDL_Delay(System::TIME_PER_FRAME - (SDL_GetTicks() - startTime));
        }
    }
}
