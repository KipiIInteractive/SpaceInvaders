#include "GameLoop.h"

Uint8 startTime = 0;

void GameLoop::run() {
    bool isRunning = true;
    bool isPaused = false;
    bool playerHasSeenTheRanking = false;
    SDL_Event e;
    srand(time(NULL));
    while(isRunning) {
        startTime = SDL_GetTicks();
        while(SDL_PollEvent(&e) != 0) {

            if(e.type == SDL_QUIT) {
                isRunning = false;
            }

            if(gPlayButton.hasBeenPressed()) {
                if(gBackButton.hasBeenPressed()) {
                    gPlayButton.setHasBeenPressed(false);
                    gBackButton.setHasBeenPressed(false);
                }
                else if(gClassicGameModeButton.hasBeenPressed()) {
                    if(isPaused) {
                        MenuHandler::handlePauseMenuEvents(&e);
                        if(gResumeButton.hasBeenPressed()) {
                            isPaused = false;
                            gResumeButton.setHasBeenPressed(false);
                        }
                        else if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p) {
                            isPaused = false;
                        }
                    }
                    else {
                        if(GameHandler::gameOver) {
                            if(RankingSystem::playerIsEligible() && !gSubmitButton.hasBeenPressed()) {
                                MenuHandler::handleSubmitNameAndScoreMenuEvents(&e);
                                if(gSubmitButton.hasBeenPressed()) {
                                    RankingSystem::addPlayerToRankList(gSubmitMenuInputField.getInput());
                                    gSubmitMenuInputField.resetInput();
                                    MenuHandler::updateRankingMenu(RankingSystem::playerNames, RankingSystem::playerScores);
                                }
                            }
                            else if(!playerHasSeenTheRanking) {
                                if(!gBackButton.isActive()) {
                                    gBackButton.setIsActive(true);
                                }
                                MenuHandler::handleRankingMenuWithPlayerScoreEvents(&e);
                                if(gBackButton.hasBeenPressed()) {
                                    playerHasSeenTheRanking = true;
                                    gBackButton.setHasBeenPressed(false);
                                }
                            }
                            else {
                                MenuHandler::handleGameOverMenuEvents(&e);
                                if(gNewGameButton.hasBeenPressed()) {
                                    gNewGameButton.setHasBeenPressed(false);
                                    GameHandler::resetClassicGame();
                                    if(gSubmitButton.hasBeenPressed()) {
                                        gSubmitButton.setHasBeenPressed(false);
                                    }
                                    playerHasSeenTheRanking = false;
                                    GameHandler::gameOver = false;
                                }
                                else if(gMainMenuButton.hasBeenPressed()) {
                                    gClassicGameModeButton.setHasBeenPressed(false);
                                    gPlayButton.setHasBeenPressed(false);
                                    gMainMenuButton.setHasBeenPressed(false);
                                    GameHandler::needToResetClassicGame = true;
                                    if(gSubmitButton.hasBeenPressed()) {
                                        gSubmitButton.setHasBeenPressed(false);
                                    }
                                    playerHasSeenTheRanking = false;
                                    GameHandler::gameOver = false;
                                }
                            }
                        }
                        else if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p) {
                            isPaused = true;
                        }
                        else {
                            GameHandler::handleClassicGameEvents(&e);
                        }
                    }
                }
                else if(gSurvivalGameModeButton.hasBeenPressed()) {
                    if(isPaused) {
                        MenuHandler::handlePauseMenuEvents(&e);
                        if(gResumeButton.hasBeenPressed()) {
                            isPaused = false;
                            gResumeButton.setHasBeenPressed(false);
                        }
                    }
                    else {
                        if(GameHandler::gameOver) {
                            if(RankingSystem::playerIsEligible() && !gSubmitButton.hasBeenPressed()) {
                                MenuHandler::handleSubmitNameAndScoreMenuEvents(&e);
                                if(gSubmitButton.hasBeenPressed()) {
                                    RankingSystem::addPlayerToRankList(gSubmitMenuInputField.getInput());
                                    MenuHandler::updateRankingMenu(RankingSystem::playerNames, RankingSystem::playerScores);
                                }
                            }
                            else if(!playerHasSeenTheRanking) {
                                if(!gBackButton.isActive()) {
                                    gBackButton.setIsActive(true);
                                }
                                MenuHandler::handleRankingMenuWithPlayerScoreEvents(&e);
                                if(gBackButton.hasBeenPressed()) {
                                    playerHasSeenTheRanking = true;
                                    gBackButton.setHasBeenPressed(false);
                                }
                            }
                            else {
                                MenuHandler::handleGameOverMenuEvents(&e);
                                if(gNewGameButton.hasBeenPressed()) {
                                    gNewGameButton.setHasBeenPressed(false);
                                    GameHandler::resetSurvivalGame();
                                    if(gSubmitButton.hasBeenPressed()) {
                                        gSubmitButton.setHasBeenPressed(false);
                                    }
                                    playerHasSeenTheRanking = false;
                                    GameHandler::gameOver = false;
                                }
                                else if(gMainMenuButton.hasBeenPressed()) {
                                    gClassicGameModeButton.setHasBeenPressed(false);
                                    gPlayButton.setHasBeenPressed(false);
                                    gMainMenuButton.setHasBeenPressed(false);
                                    GameHandler::needToResetSurvivalGame = true;
                                    if(gSubmitButton.hasBeenPressed()) {
                                        gSubmitButton.setHasBeenPressed(false);
                                    }
                                    playerHasSeenTheRanking = false;
                                    GameHandler::gameOver = false;
                                }
                            }
                        }
                        else if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p) {
                            isPaused = true;
                        }
                        else {
                            GameHandler::handleSurvivalGameEvents(&e);
                        }
                    }
                }
                else {
                    if(!gBackButton.isActive() && !gSurvivalGameModeButton.isActive()) {
                        gClassicGameModeButton.setIsActive(true);
                    }
                    MenuHandler::handleGameModesMenuEvents(&e);
                }
            }
            else if(gControlsButton.hasBeenPressed()) {
                if(!gBackButton.isActive()) {
                    gBackButton.setIsActive(true);
                }
                MenuHandler::handleControlsMenuEvents(&e);
                if(gBackButton.hasBeenPressed()) {
                    gControlsButton.setHasBeenPressed(false);
                    gBackButton.setHasBeenPressed(false);
                }
            }
            else if(gRankingButton.hasBeenPressed()) {
                if(!gBackButton.isActive()) {
                    gBackButton.setIsActive(true);
                }
                MenuHandler::handleRankingMenuEvents(&e);
                if(gBackButton.hasBeenPressed()) {
                    gRankingButton.setHasBeenPressed(false);
                    gBackButton.setHasBeenPressed(false);
                }
            }
            else {
                MenuHandler::handleMainMenuEvents(&e);
            }
        }
        //Clears the game window
        SDL_RenderClear(System::renderer);

        if(gPlayButton.hasBeenPressed()) {
            if(gClassicGameModeButton.hasBeenPressed()) {
                if(isPaused) {
                    MenuHandler::showPauseMenu();
                }
                else if(GameHandler::gameOver) {
                    if(RankingSystem::playerIsEligible() && !gSubmitButton.hasBeenPressed()) {
                        MenuHandler::showSubmitNameAndScoreMenu();
                    }
                    else if(!playerHasSeenTheRanking) {
                        MenuHandler::showRankingMenuWithPlayerScore();
                    }
                    else {
                        MenuHandler::showGameOverMenu();
                    }
                }
                else {
                    if(GameHandler::needToResetClassicGame) {
                        GameHandler::resetClassicGame();
                        GameHandler::needToResetClassicGame = false;
                    }
                    GameHandler::startClassicGame();
                }
            }
            else if(gSurvivalGameModeButton.hasBeenPressed()) {
                if(isPaused) {
                    MenuHandler::showPauseMenu();
                }
                else if(GameHandler::gameOver) {
                    if(RankingSystem::playerIsEligible() && !gSubmitButton.hasBeenPressed()) {
                        MenuHandler::showSubmitNameAndScoreMenu();
                    }
                    else if(!playerHasSeenTheRanking) {
                        MenuHandler::showRankingMenuWithPlayerScore();
                    }
                    else {
                        MenuHandler::showGameOverMenu();
                    }
                }
                else{
                    if(GameHandler::needToResetSurvivalGame) {
                        GameHandler::resetSurvivalGame();
                        GameHandler::needToResetSurvivalGame = false;
                    }
                    GameHandler::startSurvivalGame();
                }
            }
            else {
                MenuHandler::showGameModesMenu();
            }
        }
        else if(gControlsButton.hasBeenPressed()) {
            MenuHandler::showControlsMenu();
        }
        else if(gRankingButton.hasBeenPressed()) {
            MenuHandler::showRankingMenu();
        }
        else if(gExitButton.hasBeenPressed()) {
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
