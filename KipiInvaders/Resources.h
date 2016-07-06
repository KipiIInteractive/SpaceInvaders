#ifndef RESOURCES_H_INCLUDED
#define RESOURCES_H_INCLUDED

#include <list>
#include <vector>
#include <iterator>
#include "Background.h"
#include "Button.h"
#include "Enemy.h"
#include "Bullet.h"

//GUI
extern Background gMenuBackground;
extern Button gPlayButton;
extern Button gControlsButton;
extern Button gOptionsButton;
extern Button gExitButton;
extern Button gClassicGameModeButton;
extern Button gSurvivalGameModeButton;
extern Button gResumeButton;
extern Button gBackButton;
extern Button gMainMenuButton;
extern Texture gControlsMenuText[3];

extern Texture gBulletTexture;
extern Texture gEnemy1Texture;
extern Texture gEnemy2Texture;

extern const int ENEMY_ROWS;
extern const int MAX_ALIENS_ON_ROW;
extern int CURRENT_LEVEL;
extern const int SHOOTING_RNG;

extern list<Enemy*> enemies;
extern vector<Enemy*> firstRowOfEnemies;
extern vector<Enemy*> secondRowOfEnemies;
extern vector<Enemy*> thirdRowOfEnemies;
extern vector<Enemy*> fourthRowOfEnemies;

extern list<Bullet*> bullets;

#endif // RESOURCES_H_INCLUDED
