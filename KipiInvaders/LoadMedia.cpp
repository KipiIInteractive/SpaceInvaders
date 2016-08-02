#include "LoadMedia.h"

//Game Borders
Texture gLeftBorder;
Texture gRightBorder;

//Game Background
Background gGameBackground;

//Menu Buttons
Button gPlayButton;
Button gControlsButton;
Button gRankingButton;
Button gExitButton;
Button gClassicGameModeButton;
Button gSurvivalGameModeButton;
Button gBackButton;
Button gResumeButton;
Button gMainMenuButton;
Button gNewGameButton;
Button gSubmitButton;

//Menu Text
Texture gControlsMenuText[3];
Texture gGameOverMenuText;
Texture gSubmitMenuText;
Texture gFinalScoreText;
Texture gFinalScoreDigits;
Texture gRankingMenuSign;
Texture p1NameTexture;
Texture p1ScoreTexture;
Texture p2NameTexture;
Texture p2ScoreTexture;
Texture p3NameTexture;
Texture p3ScoreTexture;
Texture p4NameTexture;
Texture p4ScoreTexture;
Texture p5NameTexture;
Texture p5ScoreTexture;
Texture p6NameTexture;
Texture p6ScoreTexture;
Texture p7NameTexture;
Texture p7ScoreTexture;
Texture p8NameTexture;
Texture p8ScoreTexture;
Texture p9NameTexture;
Texture p9ScoreTexture;
Texture p10NameTexture;
Texture p10ScoreTexture;

//Menu Input Fields
InputField gSubmitMenuInputField;

//Bullet
Texture gBulletTexture;

//Enemies
Texture gAliensTexture;
SDL_Rect gCrab1Clip;
SDL_Rect gCrab2Clip;
SDL_Rect gJellyfish1Clip;
SDL_Rect gJellyfish2Clip;
SDL_Rect gSquid1Clip;
SDL_Rect gSquid2Clip;
Texture gUFOTexture;
Texture gAlienDestroyedTexture;

//Player
Texture gPlayerTexture;
Texture gPlayerDestroyedTexture;

//Score
Texture gScoreDigitsTexture;
Texture gScoreSignTexture;

//Player Lives
Texture gLivesDigitsTexture;
Texture gLivesSignTexture;

//Current classic level texture
Texture gClassicLevelSignTexture;
Texture gClassicLevelDigitTexture;

//Survival
Texture gSurvivalLevelSignTexture;

// Sound effects
Mix_Chunk* gPlayerExplosionSound = NULL;
Mix_Chunk* gAlienExplosionSound = NULL;
Mix_Chunk* gLaserSound = NULL;
Mix_Chunk* gUFOSound = NULL;

bool LoadMedia::load() {
    bool success = true;

    //Game Background
    if(!(gGameBackground.loadBackgroundFromFile("./images/gameBackground.png"))) {
        success = false;
    }
    else {
        gGameBackground.setBackgroundClip(0, 0, System::SCREEN_WIDTH, System::SCREEN_HEIGHT);
    }

    System::font = TTF_OpenFont("./fonts/invaders.ttf",45);
    if(System::font == NULL) {
        success = false;
        cout << TTF_GetError() << endl;
    }
    else {
        //Menu Buttons
        SDL_Color color = {255, 0, 0, 0};
        if(!gPlayButton.loadButtonFromText("Play", color)) {
            success = false;
        }
        else {
            gPlayButton.setIsActive(true);
            gPlayButton.setDimensions((System::SCREEN_WIDTH - gPlayButton.getWidth())/2,
                                      (System::SCREEN_HEIGHT - gPlayButton.getHeight())/2,
                                      gPlayButton.getWidth(),
                                      gPlayButton.getHeight());
        }

        if(!gControlsButton.loadButtonFromText("Controls", color)) {
            success = false;
        }
        else {
            gControlsButton.setDimensions((System::SCREEN_WIDTH - gControlsButton.getWidth())/2,
                                          (System::SCREEN_HEIGHT - gControlsButton.getHeight())/2 + gPlayButton.getHeight(),
                                          gControlsButton.getWidth(),
                                          gControlsButton.getHeight());

            if(!gControlsMenuText[0].loadFromRenderedText("Left arrow key: Move left", color)) {
                success = false;
            }

            if(!gControlsMenuText[1].loadFromRenderedText("Right arrow key: Move right", color)) {
                success = false;
            }

            if(!gControlsMenuText[2].loadFromRenderedText("Space bar: Fire laser", color)) {
                success = false;
            }
        }

        if(!gRankingButton.loadButtonFromText("Ranking", color)) {
            success = false;
        }
        else {
            gRankingButton.setDimensions((System::SCREEN_WIDTH - gRankingButton.getWidth())/2,
                                         (System::SCREEN_HEIGHT - gRankingButton.getHeight())/2 + gPlayButton.getHeight() + gControlsButton.getHeight(),
                                         gRankingButton.getWidth(),
                                         gRankingButton.getHeight());
        }

        if(!gExitButton.loadButtonFromText("Exit", color)) {
            success = false;
        }
        else {
            gExitButton.setDimensions((System::SCREEN_WIDTH - gExitButton.getWidth())/2,
                                      (System::SCREEN_HEIGHT - gExitButton.getHeight())/2 + gPlayButton.getHeight() + gControlsButton.getHeight() + gRankingButton.getHeight(),
                                      gExitButton.getWidth(),
                                      gExitButton.getHeight());
        }

        if(!gClassicGameModeButton.loadButtonFromText("Classic", color)) {
            success = false;
        }
        else {
            gClassicGameModeButton.setDimensions((System::SCREEN_WIDTH - gClassicGameModeButton.getWidth())/2,
                                      (System::SCREEN_HEIGHT - gClassicGameModeButton.getHeight())/2,
                                      gClassicGameModeButton.getWidth(),
                                      gClassicGameModeButton.getHeight());
        }

        if(!gSurvivalGameModeButton.loadButtonFromText("Survival", color)) {
            success = false;
        }
        else {
            gSurvivalGameModeButton.setDimensions((System::SCREEN_WIDTH - gSurvivalGameModeButton.getWidth())/2,
                                      (System::SCREEN_HEIGHT - gSurvivalGameModeButton.getHeight())/2 + gClassicGameModeButton.getHeight(),
                                      gSurvivalGameModeButton.getWidth(),
                                      gSurvivalGameModeButton.getHeight());
        }

        if(!gBackButton.loadButtonFromText("Back", color)) {
            success = false;
        }
        else {
            gBackButton.setDimensions((System::SCREEN_WIDTH - gBackButton.getWidth())/2,
                                      System::SCREEN_HEIGHT - gBackButton.getHeight(),
                                      gBackButton.getWidth(),
                                      gBackButton.getHeight());
        }

        if(!gResumeButton.loadButtonFromText("Resume", color)) {
            success = false;
        }
        else {
            gResumeButton.setIsActive(true);
            gResumeButton.setDimensions((System::SCREEN_WIDTH - gResumeButton.getWidth())/2,
                                        (System::SCREEN_HEIGHT - gResumeButton.getHeight())/2,
                                        gResumeButton.getWidth(),
                                        gResumeButton.getHeight());
        }

        if(!gMainMenuButton.loadButtonFromText("Main Menu", color)) {
            success = false;
        }
        else {
            gMainMenuButton.setDimensions((System::SCREEN_WIDTH - gMainMenuButton.getWidth())/2,
                                          System::SCREEN_HEIGHT - gMainMenuButton.getHeight(),
                                          gMainMenuButton.getWidth(),
                                          gMainMenuButton.getHeight());
        }

        //Game Over Menu
        if(!gNewGameButton.loadButtonFromText("New Game", color)) {
            success = false;
        }
        else {
            gNewGameButton.setIsActive(true);
            gNewGameButton.setDimensions((System::SCREEN_WIDTH - gNewGameButton.getWidth())/2,
                                          (System::SCREEN_HEIGHT - gNewGameButton.getHeight())/2,
                                          gNewGameButton.getWidth(),
                                          gNewGameButton.getHeight());
        }

        TTF_Font* gameOverFont = TTF_OpenFont("./fonts/invaders.ttf",70);
        if(gameOverFont == NULL) {
            success = false;
            cout << TTF_GetError() << endl;
        }
        else {
            if(!gGameOverMenuText.loadFromRenderedText("Game Over!", color, gameOverFont)) {
                success = false;
            }
        }

        //Submit Name And Score Menu
        if(!gFinalScoreText.loadFromRenderedText("Final Score: ", color)) {
            success = false;
        }

        if(!gSubmitMenuText.loadFromRenderedText("Submit your name:", color)) {
            success = false;
        }

        if(!gSubmitMenuInputField.loadFromFile("./images/inputField.jpg")) {
           success = false;
        }
        else {
            gSubmitMenuInputField.setHeight(gSubmitMenuInputField.getHeight() + 5);
            gSubmitMenuInputField.setPosition((System::SCREEN_WIDTH - gSubmitMenuInputField.getWidth())/2,
                                              (System::SCREEN_HEIGHT - gSubmitMenuInputField.getHeight())/2);
        }

        if(!gSubmitButton.loadButtonFromText("Submit", color)) {
            success = false;
        }
        else {
            gSubmitButton.setIsActive(true);
            gSubmitButton.setDimensions((System::SCREEN_WIDTH - gSubmitButton.getWidth())/2,
                                        gSubmitMenuInputField.getY() + gSubmitButton.getHeight() + 10,
                                        gSubmitButton.getWidth(),
                                        gSubmitButton.getHeight());
        }

        //Ranking Menu
        if(!gRankingMenuSign.loadFromRenderedText("Ranking:", color)) {
            success = false;
        }

        int lineNum = 0;
        list<string>::iterator it = RankingSystem::playerNames.begin();
        list<int>::iterator it2 = RankingSystem::playerScores.begin();
        for(; it != RankingSystem::playerNames.end(); it++, it2++) {
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
    }

    //Bullets
    if(!gBulletTexture.loadFromFile("./images/bullet.png")) {
        success = false;
    }

    //Aliens
    if(!gAliensTexture.loadFromFile("./models/aliens.png")) {
        success = false;
    }
    else {
        gSquid1Clip.x = 0;
        gSquid1Clip.y = 0;
        gSquid1Clip.w = gAliensTexture.getWidth()/2;
        gSquid1Clip.h = gAliensTexture.getHeight()/3;

        gSquid2Clip.x = gSquid1Clip.w;
        gSquid2Clip.y = 0;
        gSquid2Clip.w = gAliensTexture.getWidth()/2;
        gSquid2Clip.h = gAliensTexture.getHeight()/3;

        gCrab1Clip.x = 0;
        gCrab1Clip.y = gSquid1Clip.h;
        gCrab1Clip.w = gAliensTexture.getWidth()/2;
        gCrab1Clip.h = gAliensTexture.getHeight()/3;

        gCrab2Clip.x = gCrab1Clip.w;
        gCrab2Clip.y = gSquid2Clip.h;
        gCrab2Clip.w = gAliensTexture.getWidth()/2;
        gCrab2Clip.h = gAliensTexture.getHeight()/3;

        gJellyfish1Clip.x = 0;
        gJellyfish1Clip.y = (2*gAliensTexture.getHeight())/3;
        gJellyfish1Clip.w = gAliensTexture.getWidth()/2;
        gJellyfish1Clip.h = gAliensTexture.getHeight()/3;

        gJellyfish2Clip.x = gJellyfish1Clip.w;
        gJellyfish2Clip.y = (2*gAliensTexture.getHeight())/3;
        gJellyfish2Clip.w = gAliensTexture.getWidth()/2;
        gJellyfish2Clip.h = gAliensTexture.getHeight()/3;
    }

    if(!gAlienDestroyedTexture.loadFromFile("./models/alienExplosion.png")) {
        success = false;
    }

    if(!gUFOTexture.loadFromFile("./models/UFO.png")) {
        success = false;
    }

    //Borders
    if(!gLeftBorder.loadFromFile("./images/border.jpg")) {
        success = false;
    }
    else {
        gLeftBorder.setHeight(System::SCREEN_HEIGHT);
        gLeftBorder.setWidth(10);
    }

    if(!gRightBorder.loadFromFile("./images/border.jpg")) {
        success = false;
    }
    else {
        gRightBorder.setHeight(System::SCREEN_HEIGHT);
        gRightBorder.setWidth(10);
    }

    //Player
    if(!gPlayerTexture.loadFromFile("./models/player.png")) {
        success = false;
    }

    if(!gPlayerDestroyedTexture.loadFromFile("./models/playerExplosion.png")) {
        success = false;
    }

    //Score
    if(!gScoreSignTexture.loadFromRenderedText("Score:", {255, 255, 255, 200})) {
        success = false;
    }

    //Lives
    if(!gLivesSignTexture.loadFromRenderedText("Lives:", {255, 255, 255, 200})) {
        success = false;
    }

    //Current lvl
    if(!gClassicLevelSignTexture.loadFromRenderedText("Level ", {255, 255, 255, 200})) {
        success = false;
    }

    if(!gSurvivalLevelSignTexture.loadFromRenderedText("Survival", {255, 255, 255, 200})) {
        success = false;
    }

    //Sound Effects
    gLaserSound = Mix_LoadWAV("./sounds/laser.wav");
    if(gLaserSound == NULL) {
        success = false;
    }

    gPlayerExplosionSound = Mix_LoadWAV("./sounds/playerExplosion.wav");
    if(gPlayerExplosionSound == NULL) {
        success = false;
    }

    gAlienExplosionSound = Mix_LoadWAV("./sounds/alienExplosion.wav");
    if(gAlienExplosionSound == NULL) {
        success = false;
    }

    gUFOSound = Mix_LoadWAV("./sounds/UFO.wav");
    if(gUFOSound == NULL) {
        success = false;
    }

    return success;
}
