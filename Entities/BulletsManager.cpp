#include "BulletsManager.h"

std::vector<Bullet*> BulletsManager::allBullets;
std::vector<Bullet*> BulletsManager::bulletsToDelete;
bool BulletsManager::isBulletHitWall = false;

void BulletsManager::RenderAll()
{
    for(unsigned i = 0; i < BulletsManager::allBullets.size(); ++i)
    {
        CURRENT_BULLET->Render();
    }
}

void BulletsManager::UpdateAll()
{
    for(unsigned i = 0; i < BulletsManager::allBullets.size(); ++i)
        CURRENT_BULLET->Update();

    if(BulletsManager::isBulletHitWall)
    {
        for(unsigned i = 0; i < BulletsManager::allBullets.size(); ++i)
        {
            if(CURRENT_BULLET->isHitTheWall())
            {
                BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
                BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
            }
            CURRENT_BULLET->Update();
        }
        for(unsigned i = 0; i < BulletsManager::bulletsToDelete.size(); ++i)
        {
            BulletsManager::bulletsToDelete.erase(BulletsManager::bulletsToDelete.begin() + i);
            delete(BulletsManager::bulletsToDelete[i]);
        }
        BulletsManager::isBulletHitWall = false;
    }
}

void BulletsManager::AddNewBullet(int speed, int pos_x, int pos_y, int direction)
{
    Bullet *newBullet = new Bullet(speed, pos_x, pos_y, direction);
    BulletsManager::allBullets.push_back(newBullet);
}
