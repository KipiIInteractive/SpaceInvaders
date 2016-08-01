#include "MenuHandler.h"

void MenuHandler::showMainMenu() {
    gGameBackground.render(0, 0);
    gPlayButton.render();
    gControlsButton.render();
    gRankingButton.render();
    gExitButton.render();
}

void MenuHandler::showGameModesMenu() {
    gGameBackground.render(0, 0);
    gClassicGameModeButton.render();
    gSurvivalGameModeButton.render();
    gBackButton.render();
}

void MenuHandler::showControlsMenu() {
    gGameBackground.render(0, 0);
    gControlsMenuText[0].render((System::SCREEN_WIDTH - gControlsMenuText[0].getWidth())/2,
                                (System::SCREEN_HEIGHT - gControlsMenuText[0].getHeight())/2 - gControlsMenuText[0].getHeight());
    gControlsMenuText[1].render((System::SCREEN_WIDTH - gControlsMenuText[1].getWidth())/2,
                                (System::SCREEN_HEIGHT - gControlsMenuText[1].getHeight())/2);
    gControlsMenuText[2].render((System::SCREEN_WIDTH - gControlsMenuText[2].getWidth())/2,
                                (System::SCREEN_HEIGHT - gControlsMenuText[2].getHeight())/2 + gControlsMenuText[1].getHeight());
    gBackButton.render();
}

void MenuHandler::showRankingMenu() {
    gGameBackground.render(0, 0);
    gRankingMenuSign.render((System::SCREEN_WIDTH - gRankingMenuSign.getWidth())/2,
                            gRankingMenuSign.getHeight());
    int freeSpaceHeight = gBackButton.getY() - 2*gRankingMenuSign.getHeight();
    p1NameTexture.render(/* x = */ 200,
                         /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p1NameTexture.getHeight() - 9*(p1NameTexture.getHeight()/2))/2);
    p1ScoreTexture.render(/* x = */ System::SCREEN_WIDTH - p1ScoreTexture.getWidth() - 200,
                          /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p1NameTexture.getHeight() - 9*(p1ScoreTexture.getHeight()/2))/2);
    p2NameTexture.render(/* x = */ 200,
                         /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p2NameTexture.getHeight() - 9*(p2NameTexture.getHeight()/2))/2 + p1NameTexture.getHeight() + p1NameTexture.getHeight()/2);
    p2ScoreTexture.render(/* x = */ System::SCREEN_WIDTH - p2ScoreTexture.getWidth() - 200,
                          /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p2ScoreTexture.getHeight() - 9*(p2ScoreTexture.getHeight()/2))/2 + p1ScoreTexture.getHeight() + p1ScoreTexture.getHeight()/2);
    p3NameTexture.render(/* x = */ 200,
                         /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p3NameTexture.getHeight() - 9*(p3NameTexture.getHeight()/2))/2 + 2*p2NameTexture.getHeight() + 2*p2NameTexture.getHeight()/2);
    p3ScoreTexture.render(/* x = */ System::SCREEN_WIDTH - p3ScoreTexture.getWidth() - 200,
                          /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p3ScoreTexture.getHeight() - 9*(p3ScoreTexture.getHeight()/2))/2 + 2*p2ScoreTexture.getHeight() + 2*p2ScoreTexture.getHeight()/2);
    p4NameTexture.render(/* x = */ 200,
                         /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p4NameTexture.getHeight() - 9*(p4NameTexture.getHeight()/2))/2 + 3*p3NameTexture.getHeight() + 3*p3NameTexture.getHeight()/2);
    p4ScoreTexture.render(/* x = */ System::SCREEN_WIDTH - p4ScoreTexture.getWidth() - 200,
                          /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p4ScoreTexture.getHeight() - 9*(p4ScoreTexture.getHeight()/2))/2 + 3*p3ScoreTexture.getHeight() + 3*p3ScoreTexture.getHeight()/2);
    p5NameTexture.render(/* x = */ 200,
                         /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p5NameTexture.getHeight() - 9*(p5NameTexture.getHeight()/2))/2 + 4*p4NameTexture.getHeight() + 4*p4NameTexture.getHeight()/2);
    p5ScoreTexture.render(/* x = */ System::SCREEN_WIDTH - p5ScoreTexture.getWidth() - 200,
                          /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p5ScoreTexture.getHeight() - 9*(p5ScoreTexture.getHeight()/2))/2 + 4*p4ScoreTexture.getHeight() + 4*p4ScoreTexture.getHeight()/2);
    p6NameTexture.render(/* x = */ 200,
                         /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p6NameTexture.getHeight() - 9*(p6NameTexture.getHeight()/2))/2 + 5*p5NameTexture.getHeight() + 5*p5NameTexture.getHeight()/2);
    p6ScoreTexture.render(/* x = */ System::SCREEN_WIDTH - p6ScoreTexture.getWidth() - 200,
                          /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p6ScoreTexture.getHeight() - 9*(p6ScoreTexture.getHeight()/2))/2 + 5*p5ScoreTexture.getHeight() + 5*p5ScoreTexture.getHeight()/2);
    p7NameTexture.render(/* x = */ 200,
                         /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p7NameTexture.getHeight() - 9*(p7NameTexture.getHeight()/2))/2 + 6*p6NameTexture.getHeight() + 6*p1NameTexture.getHeight()/2);
    p7ScoreTexture.render(/* x = */ System::SCREEN_WIDTH - p7ScoreTexture.getWidth() - 200,
                          /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p7ScoreTexture.getHeight() - 9*(p7ScoreTexture.getHeight()/2))/2 + 6*p6ScoreTexture.getHeight() + 6*p6ScoreTexture.getHeight()/2);
    p8NameTexture.render(/* x = */ 200,
                         /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p8NameTexture.getHeight() - 9*(p8NameTexture.getHeight()/2))/2 + 7*p7NameTexture.getHeight() + 7*p7NameTexture.getHeight()/2);
    p8ScoreTexture.render(/* x = */ System::SCREEN_WIDTH - p8ScoreTexture.getWidth() - 200,
                          /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p8ScoreTexture.getHeight() - 9*(p8ScoreTexture.getHeight()/2))/2 + 7*p7ScoreTexture.getHeight() + 7*p7ScoreTexture.getHeight()/2);
    p9NameTexture.render(/* x = */ 200,
                         /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p9NameTexture.getHeight() - 9*(p9NameTexture.getHeight()/2))/2 + 8*p8NameTexture.getHeight() + 8*p8NameTexture.getHeight()/2);
    p9ScoreTexture.render(/* x = */ System::SCREEN_WIDTH - p9ScoreTexture.getWidth() - 200,
                          /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p9ScoreTexture.getHeight() - 9*(p9ScoreTexture.getHeight()/2))/2 + 8*p8ScoreTexture.getHeight() + 8*p8ScoreTexture.getHeight()/2);
    p10NameTexture.render(/* x = */ 200,
                          /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p10NameTexture.getHeight() - 9*(p10NameTexture.getHeight()/2))/2 + 9*p9NameTexture.getHeight() + 9*p9NameTexture.getHeight()/2);
    p10ScoreTexture.render(/* x = */ System::SCREEN_WIDTH - p10ScoreTexture.getWidth() - 200,
                           /* y = */ 2*gRankingMenuSign.getHeight()
                                    + (freeSpaceHeight - 10*p10ScoreTexture.getHeight() - 9*(p10ScoreTexture.getHeight()/2))/2 + 9*p9ScoreTexture.getHeight() + 9*p9ScoreTexture.getHeight()/2);
    gBackButton.render();
}

void MenuHandler::showPauseMenu() {
    gGameBackground.render(0, 0);
    gResumeButton.render();
    gMainMenuButton.render();
}

void MenuHandler::showGameOverMenu() {
    gGameBackground.render(0, 0);
    gGameOverMenuText.render((System::SCREEN_WIDTH - gGameOverMenuText.getWidth())/2,
                             (System::SCREEN_HEIGHT - gGameOverMenuText.getHeight())/2 - 4*gNewGameButton.getHeight());
    gNewGameButton.render();
    gMainMenuButton.render();
}

void MenuHandler::showSubmitNameAndScoreMenu() {
    gGameBackground.render(0, 0);
    gGameOverMenuText.render((System::SCREEN_WIDTH - gGameOverMenuText.getWidth())/2,
                             gSubmitMenuInputField.getY() - gSubmitMenuText.getHeight() - gFinalScoreText.getHeight() - 50 - gGameOverMenuText.getHeight() - 60);
    if(gFinalScoreDigits.loadFromRenderedText("" + to_string(player->getScore()), {255, 255, 255, 255})) {
        gFinalScoreText.render((System::SCREEN_WIDTH - gFinalScoreText.getWidth() - gFinalScoreDigits.getWidth())/2,
                                gSubmitMenuInputField.getY() - gSubmitMenuText.getHeight() - gFinalScoreText.getHeight() - 50);
        gFinalScoreDigits.render((System::SCREEN_WIDTH - gFinalScoreText.getWidth() - gFinalScoreDigits.getWidth())/2 + gFinalScoreText.getWidth(),
                                 gSubmitMenuInputField.getY() - gSubmitMenuText.getHeight() - gFinalScoreText.getHeight() - 50);
    }
    gSubmitMenuText.render((System::SCREEN_WIDTH - gSubmitMenuText.getWidth())/2,
                           gSubmitMenuInputField.getY() - gSubmitMenuText.getHeight() - 10);
    gSubmitMenuInputField.render();
    gSubmitButton.render();
}

void MenuHandler::handleMainMenuEvents(SDL_Event *e) {
    gPlayButton.handleEvents(e);
    if(gPlayButton.nextButtonIsToBeActivated()) {
        gControlsButton.setIsActive(true);
    }
    else if(gPlayButton.previousButtonIsToBeActivated()) {
        gExitButton.setIsActive(true);
    }
    gControlsButton.handleEvents(e);
    if(gControlsButton.nextButtonIsToBeActivated()) {
        gRankingButton.setIsActive(true);
    }
    else if(gControlsButton.previousButtonIsToBeActivated()){
        gPlayButton.setIsActive(true);
    }
    gRankingButton.handleEvents(e);
    if(gRankingButton.nextButtonIsToBeActivated()) {
        gExitButton.setIsActive(true);
    }
    else if(gRankingButton.previousButtonIsToBeActivated()) {
        gControlsButton.setIsActive(true);
    }
    gExitButton.handleEvents(e);
    if(gExitButton.nextButtonIsToBeActivated()) {
        gPlayButton.setIsActive(true);
    }
    else if(gExitButton.previousButtonIsToBeActivated()){
        gRankingButton.setIsActive(true);
    }
}

void MenuHandler::handleGameModesMenuEvents(SDL_Event *e) {
    gClassicGameModeButton.handleEvents(e);
    if(gClassicGameModeButton.nextButtonIsToBeActivated()) {
        gSurvivalGameModeButton.setIsActive(true);
    }
    else if(gClassicGameModeButton.previousButtonIsToBeActivated()) {
        gBackButton.setIsActive(true);
    }
    gSurvivalGameModeButton.handleEvents(e);
    if(gSurvivalGameModeButton.nextButtonIsToBeActivated()) {
        gBackButton.setIsActive(true);
    }
    else if(gSurvivalGameModeButton.previousButtonIsToBeActivated()) {
        gClassicGameModeButton.setIsActive(true);
    }
    gBackButton.handleEvents(e);
    if(gBackButton.nextButtonIsToBeActivated()) {
        gClassicGameModeButton.setIsActive(true);
    }
    else if(gBackButton.previousButtonIsToBeActivated()) {
        gSurvivalGameModeButton.setIsActive(true);
    }
}

void MenuHandler::handleControlsMenuEvents(SDL_Event *e) {
    gBackButton.handleEvents(e);
}

void MenuHandler::handleRankingMenuEvents(SDL_Event *e) {
    gBackButton.handleEvents(e);
}

void MenuHandler::handlePauseMenuEvents(SDL_Event *e) {
    gResumeButton.handleEvents(e);
    if(gResumeButton.nextButtonIsToBeActivated() || gResumeButton.previousButtonIsToBeActivated()) {
        gMainMenuButton.setIsActive(true);
    }
    gMainMenuButton.handleEvents(e);
    if(gMainMenuButton.nextButtonIsToBeActivated() || gMainMenuButton.previousButtonIsToBeActivated()) {
        gResumeButton.setIsActive(true);
    }
}

void MenuHandler::handleGameOverMenuEvents(SDL_Event *e) {
    gNewGameButton.handleEvents(e);
    if(gNewGameButton.nextButtonIsToBeActivated() || gNewGameButton.previousButtonIsToBeActivated()) {
        gMainMenuButton.setIsActive(true);
    }
    gMainMenuButton.handleEvents(e);
    if(gMainMenuButton.nextButtonIsToBeActivated() || gMainMenuButton.previousButtonIsToBeActivated()) {
        gNewGameButton.setIsActive(true);
    }
}

void MenuHandler::handleSubmitNameAndScoreMenuEvents(SDL_Event *e) {
    gSubmitMenuInputField.handleEvents(e);
    gSubmitButton.handleEvents(e);
    if(gSubmitButton.nextButtonIsToBeActivated() || gSubmitButton.previousButtonIsToBeActivated()) {
        gSubmitButton.setIsActive(true);
    }
    else if(gSubmitButton.hasBeenPressed() && !gSubmitMenuInputField.enterHasBeenPressed()) {
        gSubmitButton.setHasBeenPressed(false);
    }
}

bool MenuHandler::updateRankingMenu(list<string>& pNames, list<int>& pScores) {
    bool success = true;
    SDL_Color color = {255, 0, 0, 255};
    int lineNum = 0;
    list<string>::iterator it = pNames.begin();
    list<int>::iterator it2 = pScores.begin();
    for(; it != pNames.end(); it++, it2++) {
        if(lineNum == 0) {
            if(!p1NameTexture.loadFromRenderedText("1. " + (*it), color)) {
                success = false;
            }
            if(!p1ScoreTexture.loadFromRenderedText(to_string((*it2)), color)) {
                success = false;
            }
        }
        else if(lineNum == 1) {
            if(!p2NameTexture.loadFromRenderedText("2. " + (*it), color)) {
                success = false;
            }
            if(!p2ScoreTexture.loadFromRenderedText(to_string((*it2)), color)) {
                success = false;
            }
        }
        else if(lineNum == 2) {
            if(!p3NameTexture.loadFromRenderedText("3. " + (*it), color)) {
                success = false;
            }
            if(!p3ScoreTexture.loadFromRenderedText(to_string((*it2)), color)) {
                success = false;
            }
        }
        else if(lineNum == 3) {
            if(!p4NameTexture.loadFromRenderedText("4. " + (*it), color)) {
                success = false;
            }
            if(!p4ScoreTexture.loadFromRenderedText(to_string((*it2)), color)) {
                success = false;
            }
        }
        else if(lineNum == 4) {
            if(!p5NameTexture.loadFromRenderedText("5. " + (*it), color)) {
                success = false;
            }
            if(!p5ScoreTexture.loadFromRenderedText(to_string((*it2)), color)) {
                success = false;
            }
        }
        else if(lineNum == 5) {
            if(!p6NameTexture.loadFromRenderedText("6. " + (*it), color)) {
                success = false;
            }
            if(!p6ScoreTexture.loadFromRenderedText(to_string((*it2)), color)) {
                success = false;
            }
        }
        else if(lineNum == 6) {
            if(!p7NameTexture.loadFromRenderedText("7. " + (*it), color)) {
                success = false;
            }
            if(!p7ScoreTexture.loadFromRenderedText(to_string((*it2)), color)) {
                success = false;
            }
        }
        else if(lineNum == 7) {
            if(!p8NameTexture.loadFromRenderedText("8. " + (*it), color)) {
                success = false;
            }
            if(!p8ScoreTexture.loadFromRenderedText(to_string((*it2)), color)) {
                success = false;
            }
        }
        else if(lineNum == 8) {
            if(!p9NameTexture.loadFromRenderedText("9. " + (*it), color)) {
                success = false;
            }
            if(!p9ScoreTexture.loadFromRenderedText(to_string((*it2)), color)) {
                success = false;
            }
        }
        else if(lineNum == 9) {
            if(!p10NameTexture.loadFromRenderedText("10. " + (*it), color)) {
                success = false;
            }
            if(!p10ScoreTexture.loadFromRenderedText(to_string((*it2)), color)) {
                success = false;
            }
        }
        lineNum++;
    }
    return success;
}
