#ifndef GAMERESOURCES_H_INCLUDED
#define GAMERESOURCES_H_INCLUDED

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <SDL_mixer.h>
#include "Texture.h"

extern int ENEMY_ROWS;
extern int MAX_ALIENS_ON_ROW;
extern int SHOOTING_RNG;
extern int ENEMY_MOVEMENT_SPEED;
extern int ENEMY_SHOOTING_SPEED;
extern int REMAINING_ENEMIES;

extern int ENEMY_ANIMATION_FRAMES;
extern int ENEMY_ANIMATION_FRAMES_COUNTER;

extern int PLAYER_DESTROYED_FRAMES_COUNTER;
extern int ENEMY_DESTROYED_FRAMES_COUNTER;

extern Uint8 startTime;

extern Texture gLeftBorder;
extern Texture gRightBorder;

extern Texture gScoreSignTexture;
extern Texture gScoreDigitsTexture;

extern Texture gLivesSignTexture;
extern Texture gLivesDigitsTexture;

extern Texture gLevelSignTexture;
extern Texture gLevelDigitTexture;

extern Mix_Chunk* gPlayerExplosionSound;
extern Mix_Chunk* gAlienExplosionSound;
extern Mix_Chunk* gLaserSound;
extern Mix_Chunk* gUFOSound;

#endif // GAMERESOURCES_H_INCLUDED
