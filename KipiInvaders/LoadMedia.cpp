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

//Current level texture
Texture gLevelSignTexture;
Texture gLevelDigitTexture;

// Sound effects
Mix_Chunk* gPlayerExplosionSound = NULL;
Mix_Chunk* gAlienExplosionSound = NULL;
Mix_Chunk* gLaserSound = NULL;
Mix_Chunk* gUFOSound = NULL;

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

    if(!gUFOTexture.loadFromFile("./models/UFO.png")) {
        success = false;
    }

    if(!gAlienDestroyedTexture.loadFromFile("./models/alienExplosion.png")) {
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
    if(!gLevelSignTexture.loadFromRenderedText("Level ", {255, 255, 255, 200})) {
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
