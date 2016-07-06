#include "GameLoop.h"

void GameLoop::run() {
    bool isRunning = true;
    bool isPaused = false;
    SDL_Event e;
    srand(time(NULL));
    while(isRunning) {
        //Handles events when they occur
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
                    }
                    else {
                        GameHandler::handleClassicGameEvents(&e);
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
                        GameHandler::handleSurvivalGameEvents(&e);
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
            else if(gOptionsButton.isClicked()) {
                MenuHandler::handleOptionsMenuEvents(&e);
                if(gBackButton.isClicked()) {
                    gOptionsButton.unclick();
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
        else if(gOptionsButton.isClicked()) {
            MenuHandler::showOptionsMenu();
        }
        else if(gExitButton.isClicked()) {
            isRunning = false;
            MenuHandler::showMainMenu();
        }
        else {
            MenuHandler::showMainMenu();
        }
        //Updates game window
        SDL_RenderPresent(System::renderer);
    }
}
