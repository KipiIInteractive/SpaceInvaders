#include "LoadMedia.h"

//Game Borders
Texture gLeftBorder;
Texture gRightBorder;

//Background
Background gMenuBackground;

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

//Menu Text
Texture gControlsMenuText[3];

//Bullet
Texture gBulletTexture;

//Enemies
Texture gCrabTexture;
Texture gJellyfishTexture;
Texture gUFOTexture;

//Player
Texture gPlayerTexture;

//Score
Texture gScoreDigitsTexture;
Texture gScoreSignTexture;

//Player Lives
Texture gLivesDigitsTexture;
Texture gLivesSignTexture;

bool LoadMedia::load() {
    bool success = true;

    //Menu Background
    if(!(gMenuBackground.loadBackgroundFromFile("./images/menuBackground.png"))) {
        success = false;
    }
    else {
        gMenuBackground.setBackgroundClip(0, 0, System::SCREEN_WIDTH, System::SCREEN_HEIGHT);
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
    }

    //Bullets
    if(!gBulletTexture.loadFromFile("./images/bullet.png")) {
        success = false;
    }

    //Aliens
    if(!gCrabTexture.loadFromFile("./models/crab.jpg")) {
        success = false;
    }

    if(!gJellyfishTexture.loadFromFile("./models/jellyfish.jpg")) {
        success = false;
    }

    if(!gUFOTexture.loadFromFile("./models/UFO.jpg")) {
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

    //Score
    if(!gScoreSignTexture.loadFromRenderedText("Score:", {255, 255, 255, 200})) {
        success = false;
    }

    //Lives
    if(!gLivesSignTexture.loadFromRenderedText("Lives:", {255, 255, 255, 200})) {
        success = false;
    }

    return success;
}
