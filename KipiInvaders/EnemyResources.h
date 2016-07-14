#ifndef ENEMYRESOURCES_H_INCLUDED
#define ENEMYRESOURCES_H_INCLUDED

#include <vector>
#include <list>
#include "Enemy.h"

extern Texture gAliensTexture;
extern SDL_Rect gCrab1Clip;
extern SDL_Rect gCrab2Clip;
extern SDL_Rect gJellyfish1Clip;
extern SDL_Rect gJellyfish2Clip;
extern SDL_Rect gSquid1Clip;
extern SDL_Rect gSquid2Clip;
extern Texture gUFOTexture;
extern Texture gAlienDestroyedTexture;

extern vector<Enemy*> enemies;
extern Enemy* UFO;


#endif // ENEMYRESOURCES_H_INCLUDED
