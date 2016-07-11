#ifndef BULLETRESOURCES_H_INCLUDED
#define BULLETRESOURCES_H_INCLUDED

#include <list>
#include <memory>
#include "Bullet.h"

extern Texture gBulletTexture;

extern list<Bullet*> bullets;
extern list<Bullet*> destroyedBullets;

#endif // BULLETRESOURCES_H_INCLUDED
