#ifndef GAMERESOURCES_H_INCLUDED
#define GAMERESOURCES_H_INCLUDED

#include <stdlib.h>     /* srand, rand */
#include <time.h>      /* time */
#include "Texture.h"

extern const int ENEMY_ROWS;
extern const int MAX_ALIENS_ON_ROW;
extern int CURRENT_LEVEL;
extern const int SHOOTING_RNG;

extern Texture gLeftBorder;
extern Texture gRightBorder;

#endif // GAMERESOURCES_H_INCLUDED
