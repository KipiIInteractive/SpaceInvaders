#include "GameLoop.h"

void GameLoop::run() {
    bool isRunning = true;
    SDL_Event e;
    while(isRunning) {
        //Handles events when they occur
        while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT) {
                isRunning = false;
            }

            if(gPlayButton.isClicked()) {
                if(gBackButton.isClicked()) {
                    MenuHandler::returnToPreviousMenu(gPlayButton);
                }
                else if(gClassicGameModeButton.isClicked()) {
                    GameHandler::handleClassicGameEvents(&e);
                }
                else if(gSurvivalGameModeButton.isClicked()) {
                    GameHandler::handleSurvivalGameEvents(&e);
                }
                else {
                    MenuHandler::handleGameModesMenuEvents(&e);
                }
            }
            else if(gControlsButton.isClicked()) {
                MenuHandler::handleControlsMenuEvents(&e);
                if(gBackButton.isClicked()) {
                    MenuHandler::returnToPreviousMenu(gControlsButton);
                }
            }
            else if(gOptionsButton.isClicked()) {
                MenuHandler::handleOptionsMenuEvents(&e);
                if(gBackButton.isClicked()) {
                    MenuHandler::returnToPreviousMenu(gOptionsButton);
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
                GameHandler::startClassicGame();
            }
            else if(gSurvivalGameModeButton.isClicked()) {
                GameHandler::startSurvivalGame();
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
