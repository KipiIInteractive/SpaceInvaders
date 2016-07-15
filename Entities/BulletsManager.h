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

        static void AddNewBullet(int speed, int pos_x, int pos_y, int direction);
        static bool isBulletHitWall;

    private:
        static std::vector<Bullet*> allBullets;
        static std::vector<Bullet*> bulletsToDelete;
        static bool isBulletHitTheWall();
        #define CURRENT_BULLET BulletsManager::allBullets[i]
};

#endif // BULLETSMANAGER_H_INCLUDED
