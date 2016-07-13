#ifndef GAMERESOURCES_H_INCLUDED
#define GAMERESOURCES_H_INCLUDED

#include <stdlib.h>     /* srand, rand */
#include <time.h>      /* time */
#include "Texture.h"

extern int ENEMY_ROWS;
extern int MAX_ALIENS_ON_ROW;
extern int SHOOTING_RNG;
extern int ENEMY_MOVEMENT_SPEED;
extern int ENEMY_SHOOTING_SPEED;
extern int REMAINING_ENEMIES;

extern Uint8 startTime;

extern Texture gLeftBorder;
extern Texture gRightBorder;

extern Texture gScoreSignTexture;
extern Texture gScoreDigitsTexture;

extern Texture gLivesSignTexture;
extern Texture gLivesDigitsTexture;

#endif // GAMERESOURCES_H_INCLUDED
