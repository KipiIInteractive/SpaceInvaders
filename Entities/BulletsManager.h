#ifndef BULLETSMANAGER_H_INCLUDED
#define BULLETSMANAGER_H_INCLUDED

#include "Bullet.h"
#include <vector>
#include <time.h>
#include "../sounds_management/SoundManager.h"

class BulletsManager
{
    public:
        static void RenderAll();
        static void UpdateAll();

        static void AddNewBullet(int speed, int xPos, int yPos, int direction);
        static bool hasBulletHitWall;
        static std::vector<Bullet*> allBullets;
        static void FreeAllBullets();

    private:
        static std::vector<Bullet*> bulletsToDelete;
};

#endif // BULLETSMANAGER_H_INCLUDED
