#include "GameLoop.h"
#include "LoadMedia.h"

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
                handleGameModesMenuEvents(&e);
            }
            else if(gControlsButton.isClicked()) {
                handleControlsMenuEvents(&e);
            }
            else if(gOptionsButton.isClicked()) {
                handleOptionsMenuEvents(&e);
            }
            else {
                gPlayButton.handleEvents(&e);
                gControlsButton.handleEvents(&e);
                gOptionsButton.handleEvents(&e);
                gExitButton.handleEvents(&e);
            }
        }
        //Clears the game window
        SDL_RenderClear(gRenderer);

        if(gPlayButton.isClicked()) {
            if(gBackButton.isClicked()) {
                gPlayButton.unclick();
                gBackButton.unclick();
            }
            else if(gClassicGameModeButton.isClicked()) {
                startClassicGame();
            }
            else if(gSurvivalGameModeButton.isClicked()) {
                startSurvivalGame();
            }
            else {
                showGameModesMenu();
            }
        }
        else if(gControlsButton.isClicked()) {
            showControlsMenu();
            if(gBackButton.isClicked()) {
                gControlsButton.unclick();
                gBackButton.unclick();
            }
        }
        else if(gOptionsButton.isClicked()) {
            showOptionsMenu();
            if(gBackButton.isClicked()) {
                gOptionsButton.unclick();
                gBackButton.unclick();
            }
        }
        else if(gExitButton.isClicked()) {
            isRunning = false;
            showMainMenu();
        }
        else {
            showMainMenu();
        }

        //Updates game window
        SDL_RenderPresent(gRenderer);
    }
}

void GameLoop::showMainMenu() {
    gMenuBackground.render(0, 0);
    gPlayButton.render();
    gControlsButton.render();
    gOptionsButton.render();
    gExitButton.render();
}

void GameLoop::showGameModesMenu() {
    gMenuBackground.render(0, 0);
    gClassicGameModeButton.render();
    gSurvivalGameModeButton.render();
    gBackButton.render();
}

void GameLoop::showControlsMenu() {
    gMenuBackground.render(0, 0);
    gControlsMenuText[0].render((SCREEN_WIDTH - gControlsMenuText[0].getWidth())/2,
                                (SCREEN_HEIGHT - gControlsMenuText[0].getHeight())/2 - gControlsMenuText[0].getHeight());
    gControlsMenuText[1].render((SCREEN_WIDTH - gControlsMenuText[1].getWidth())/2,
                                (SCREEN_HEIGHT - gControlsMenuText[1].getHeight())/2);
    gControlsMenuText[2].render((SCREEN_WIDTH - gControlsMenuText[2].getWidth())/2,
                                (SCREEN_HEIGHT - gControlsMenuText[2].getHeight())/2 + gControlsMenuText[1].getHeight());
    gBackButton.render();
}

void GameLoop::showOptionsMenu() {
    gMenuBackground.render(0, 0);
    gBackButton.render();
}

void GameLoop::handleGameModesMenuEvents(SDL_Event *e) {
    gClassicGameModeButton.handleEvents(e);
    gSurvivalGameModeButton.handleEvents(e);
    gBackButton.handleEvents(e);
}

void GameLoop::handleControlsMenuEvents(SDL_Event *e) {
    gBackButton.handleEvents(e);
}

void GameLoop::handleOptionsMenuEvents(SDL_Event *e) {
    gBackButton.handleEvents(e);
}

void GameLoop::startClassicGame() {
    gMenuBackground.render(0, 0);
}

void GameLoop::startSurvivalGame() {

}
