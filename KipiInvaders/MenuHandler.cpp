#include "MenuHandler.h"

void MenuHandler::showMainMenu() {
    gMenuBackground.render(0, 0);
    gPlayButton.render();
    gControlsButton.render();
    gOptionsButton.render();
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

void MenuHandler::showOptionsMenu() {
    gMenuBackground.render(0, 0);
    gBackButton.render();
}

void MenuHandler::showPauseMenu() {
    gMenuBackground.render(0, 0);
    gResumeButton.render();
    gMainMenuButton.render();
}

void MenuHandler::handleMainMenuEvents(SDL_Event *e) {
    gPlayButton.handleEvents(e);
    gControlsButton.handleEvents(e);
    gOptionsButton.handleEvents(e);
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

void MenuHandler::handleOptionsMenuEvents(SDL_Event *e) {
    gBackButton.handleEvents(e);
}

void MenuHandler::handlePauseMenuEvents(SDL_Event *e) {
    gResumeButton.handleEvents(e);
    gMainMenuButton.handleEvents(e);
}
