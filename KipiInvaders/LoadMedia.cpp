#include "LoadMedia.h"

//Background
Background gMenuBackground;

//Menu Buttons
Button gPlayButton;
Button gControlsButton;
Button gOptionsButton;
Button gExitButton;
Button gClassicGameModeButton;
Button gSurvivalGameModeButton;
Button gBackButton;

//Menu Text
Texture gControlsMenuText[3];

//Music used
Mix_Music* gMusic = NULL;


//Font used
TTF_Font* gFont = NULL;

bool LoadMedia::load() {
    bool success = true;

    //Menu Background
    if(!gMenuBackground.loadBackgroundFromFile("images/menuBackground.png")) {
        success = false;
    }
    else {
        gMenuBackground.setBackgroundClip(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    }

    gFont = TTF_OpenFont("fonts/earthorbiter.ttf",50);
    if(gFont == NULL) {
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
            gPlayButton.setDimensions((SCREEN_WIDTH - gPlayButton.getWidth())/2,
                                      (SCREEN_HEIGHT - gPlayButton.getHeight())/2,
                                      gPlayButton.getWidth(),
                                      gPlayButton.getHeight());
        }

        if(!gControlsButton.loadButtonFromText("Controls", color)) {
            success = false;
        }
        else {
            gControlsButton.setDimensions((SCREEN_WIDTH - gControlsButton.getWidth())/2,
                                          (SCREEN_HEIGHT - gControlsButton.getHeight())/2 + gPlayButton.getHeight(),
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

        if(!gOptionsButton.loadButtonFromText("Options", color)) {
            success = false;
        }
        else {
            gOptionsButton.setDimensions((SCREEN_WIDTH - gOptionsButton.getWidth())/2,
                                         (SCREEN_HEIGHT - gOptionsButton.getHeight())/2 + gPlayButton.getHeight() + gControlsButton.getHeight(),
                                         gOptionsButton.getWidth(),
                                         gOptionsButton.getHeight());
        }

        if(!gExitButton.loadButtonFromText("Exit", color)) {
            success = false;
        }
        else {
            gExitButton.setDimensions((SCREEN_WIDTH - gExitButton.getWidth())/2,
                                      (SCREEN_HEIGHT - gExitButton.getHeight())/2 + gPlayButton.getHeight() + gControlsButton.getHeight() + gOptionsButton.getHeight(),
                                      gExitButton.getWidth(),
                                      gExitButton.getHeight());
        }

        if(!gClassicGameModeButton.loadButtonFromText("Classic", color)) {
            success = false;
        }
        else {
            gClassicGameModeButton.setDimensions((SCREEN_WIDTH - gClassicGameModeButton.getWidth())/2,
                                      (SCREEN_HEIGHT - gClassicGameModeButton.getHeight())/2,
                                      gClassicGameModeButton.getWidth(),
                                      gClassicGameModeButton.getHeight());
        }

        if(!gSurvivalGameModeButton.loadButtonFromText("Survival", color)) {
            success = false;
        }
        else {
            gSurvivalGameModeButton.setDimensions((SCREEN_WIDTH - gSurvivalGameModeButton.getWidth())/2,
                                      (SCREEN_HEIGHT - gSurvivalGameModeButton.getHeight())/2 + gClassicGameModeButton.getHeight(),
                                      gSurvivalGameModeButton.getWidth(),
                                      gSurvivalGameModeButton.getHeight());
        }

        if(!gBackButton.loadButtonFromText("Back", color)) {
            success = false;
        }
        else {
            gBackButton.setDimensions((SCREEN_WIDTH - gBackButton.getWidth())/2,
                                      SCREEN_HEIGHT - gBackButton.getHeight(),
                                      gBackButton.getWidth(),
                                      gBackButton.getHeight());
        }
    }

    return success;
}
