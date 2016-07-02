#include "LoadMedia.h"

//Background
Background gMenuBackground;

//Music used
Mix_Music* gMusic = NULL;


//Font used
TTF_Font* gFont = NULL;

bool LoadMedia::load() {
    bool success = true;

    if(!gMenuBackground.loadBackgroundFromFile("images/menuBackground.png")) {
        success = false;
    }
    else {
        gMenuBackground.setBackgroundClip(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    }

    return success;
}
