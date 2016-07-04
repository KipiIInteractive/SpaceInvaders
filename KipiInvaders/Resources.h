#ifndef RESOURCES_H_INCLUDED
#define RESOURCES_H_INCLUDED

#include "Background.h"
#include "Button.h"
#include "Enemy.h"
#include <list>

//GUI
extern Background gMenuBackground;
extern Button gPlayButton;
extern Button gControlsButton;
extern Button gOptionsButton;
extern Button gExitButton;
extern Button gClassicGameModeButton;
extern Button gSurvivalGameModeButton;
extern Button gBackButton;
extern Texture gControlsMenuText[3];

extern const int ENEMY_ROWS;
extern const int MAX_ALIENS_ON_ROW;

extern std::list<Enemy> enemies;

#endif // RESOURCES_H_INCLUDED
