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
        static std::vector<Bullet*> allBullets;
<<<<<<< HEAD
=======
        static void FreeAllBullets();
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

    private:
        static std::vector<Bullet*> bulletsToDelete;
        static bool isBulletHitTheWall();
        #define CURRENT_BULLET BulletsManager::allBullets[i]
};

#endif // BULLETSMANAGER_H_INCLUDED
