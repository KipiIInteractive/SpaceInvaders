#include "MenuHandler.h"

void MenuHandler::showMainMenu() {
    gMenuBackground.render(0, 0);
    gPlayButton.render();
    gControlsButton.render();
    gRankingButton.render();
    gExitButton.render();
}

void MenuHandler::showGameModesMenu() {
    gMenuBackground.render(0, 0);
    gClassicGameModeButton.render();
    gSurvivalGameModeButton.render();
    gBackButton.render();
}

void MenuHandler::showControlsMenu() {
    gMenuBackground.render(0, 0);
    gControlsMenuText[0].render((System::SCREEN_WIDTH - gControlsMenuText[0].getWidth())/2,
                                (System::SCREEN_HEIGHT - gControlsMenuText[0].getHeight())/2 - gControlsMenuText[0].getHeight());
    gControlsMenuText[1].render((System::SCREEN_WIDTH - gControlsMenuText[1].getWidth())/2,
                                (System::SCREEN_HEIGHT - gControlsMenuText[1].getHeight())/2);
    gControlsMenuText[2].render((System::SCREEN_WIDTH - gControlsMenuText[2].getWidth())/2,
                                (System::SCREEN_HEIGHT - gControlsMenuText[2].getHeight())/2 + gControlsMenuText[1].getHeight());
    gBackButton.render();
}

void MenuHandler::showRankingMenu() {
    gMenuBackground.render(0, 0);
    gBackButton.render();
}

void MenuHandler::showPauseMenu() {
    gMenuBackground.render(0, 0);
    gResumeButton.render();
    gMainMenuButton.render();
}

void MenuHandler::showGameOverMenu() {
    gMenuBackground.render(0, 0);
    gGameOverMenuText.render((System::SCREEN_WIDTH - gGameOverMenuText.getWidth())/2,
                             (System::SCREEN_HEIGHT - gGameOverMenuText.getHeight())/2 - 4*gNewGameButton.getHeight());
    gNewGameButton.render();
    gMainMenuButton.render();
}

void MenuHandler::handleMainMenuEvents(SDL_Event *e) {
    gPlayButton.handleEvents(e);
    gControlsButton.handleEvents(e);
    gRankingButton.handleEvents(e);
    gExitButton.handleEvents(e);
}

void MenuHandler::handleGameModesMenuEvents(SDL_Event *e) {
    gClassicGameModeButton.handleEvents(e);
    gSurvivalGameModeButton.handleEvents(e);
    gBackButton.handleEvents(e);
}

void MenuHandler::handleControlsMenuEvents(SDL_Event *e) {
    gBackButton.handleEvents(e);
}

void MenuHandler::handleRankingMenuEvents(SDL_Event *e) {
    gBackButton.handleEvents(e);
}

void MenuHandler::handlePauseMenuEvents(SDL_Event *e) {
    gResumeButton.handleEvents(e);
    gMainMenuButton.handleEvents(e);
}

void MenuHandler::handleGameOverMenuEvents(SDL_Event *e) {
    gNewGameButton.handleEvents(e);
    gMainMenuButton.handleEvents(e);
}
