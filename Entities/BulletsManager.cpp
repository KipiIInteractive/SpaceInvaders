#include "BulletsManager.h"
#include "AliensManager.h"
#include "../Game/Game.h"
#include "Player.h"

std::vector<Bullet*> BulletsManager::allBullets;
std::vector<Bullet*> BulletsManager::bulletsToDelete;
bool BulletsManager::isBulletHitWall = false;

void BulletsManager::RenderAll()
{
    for(unsigned i = 0; i < BulletsManager::allBullets.size(); ++i)
        CURRENT_BULLET->Render();
}

std::vector<Alien*> aliensToDelete;

void BulletsManager::UpdateAll()
{
    #define CURRENT_ALIEN AliensManager::allAliens[j]
    for(unsigned i = 0; i < BulletsManager::allBullets.size(); ++i)
    {
        CURRENT_BULLET->Update();

        //Delete the bullet that was hit one of the walls
        if(BulletsManager::isBulletHitWall && CURRENT_BULLET->isHitTheWall())
        {
            BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
            BulletsManager::isBulletHitWall = false;
        }

        //Check for collision between bullet and alien
        for(unsigned j = 0; j < AliensManager::allAliens.size(); j++)
        {
            if(CURRENT_BULLET->rect.x >= CURRENT_ALIEN->GetX())
            {
                if(CURRENT_BULLET->rect.x <= CURRENT_ALIEN->GetX() + CURRENT_ALIEN->GetWidth())
                {
                    if(CURRENT_BULLET->rect.y <= CURRENT_ALIEN->GetY() + CURRENT_ALIEN->GetHeigth())
                    {
                        if(CURRENT_BULLET->rect.y >= CURRENT_ALIEN->GetY())
                        {
                            if(CURRENT_BULLET->GetDirection() == System::Direction::Up)
                            {
                                //Delete the bullet
                                BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
                                BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                                //Delete the alien
                                aliensToDelete.push_back(CURRENT_ALIEN);
                                AliensManager::allAliens.erase(AliensManager::allAliens.begin() + j);
                                ///SoundManager::Play(SoundManager::Sounds::KillAlien);
                                Game::score += CURRENT_ALIEN->score;
                            }
                        }
                    }
                }
            }
        }

        //Check for collision between bullet and barrier
        for(unsigned j = 0; j < 3; j++)
        {
            if(CURRENT_BULLET->rect.x >= Game::barriers[j]->GetX())
            {
                if(CURRENT_BULLET->rect.x <= Game::barriers[j]->GetX() + Game::barriers[j]->GetWidth())
                {
                    if(CURRENT_BULLET->rect.y <= Game::barriers[j]->GetY() + Game::barriers[j]->GetHeigth())
                    {
                        if(CURRENT_BULLET->rect.y >= Game::barriers[j]->GetY())
                        {
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                        }
                    }
                }
            }
        }

        //Check for collision between bullet and the player
        if(CURRENT_BULLET->rect.x >= Player::rect.x)
        {
            if(CURRENT_BULLET->rect.x <= Player::rect.x + Player::rect.w)
            {
                if(CURRENT_BULLET->rect.y + CURRENT_BULLET->rect.h >= Player::rect.y)
                {
                    if(CURRENT_BULLET->rect.y <= Player::rect.y + Player::rect.h)
                    {
                        if(CURRENT_BULLET->GetDirection() == System::Direction::Down)
                        {

                        }
                    }
                }
            }
        }
    }

    //Delete the bullets that collided with something
    for(unsigned i = 0; i < BulletsManager::bulletsToDelete.size(); ++i)
    {
        BulletsManager::bulletsToDelete.erase(BulletsManager::bulletsToDelete.begin() + i);
        delete(BulletsManager::bulletsToDelete[i]);
    }

    //Delete the aliens that have been shotted
    for(unsigned i = 0; i < aliensToDelete.size(); ++i)
    {
        aliensToDelete.erase(aliensToDelete.begin() + i);
        delete(aliensToDelete[i]);
    }
}

void BulletsManager::AddNewBullet(int speed, int pos_x, int pos_y, int direction)
{
    Bullet *newBullet = new Bullet(speed, pos_x, pos_y, direction);
    BulletsManager::allBullets.push_back(newBullet);
}
