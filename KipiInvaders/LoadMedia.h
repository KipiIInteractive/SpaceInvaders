#ifndef LOADMEDIA_H_INCLUDED
#define LOADMEDIA_H_INCLUDED

#include "main.h"
#include "Background.h"
#include "Button.h"

extern Background gMenuBackground;
extern Button gPlayButton;
extern Button gControlsButton;
extern Button gOptionsButton;
extern Button gExitButton;
extern Button gClassicGameModeButton;
extern Button gSurvivalGameModeButton;
extern Button gBackButton;
extern Texture gControlsMenuText[3];

class LoadMedia {
public:
    static bool load();
};
#endif // LOADMEDIA_H_INCLUDED
