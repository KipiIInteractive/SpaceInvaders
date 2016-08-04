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

        ///Delete the bullet that was hit one of the walls
        if(BulletsManager::isBulletHitWall && CURRENT_BULLET->isHitTheWall())
        {
            BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
            BulletsManager::isBulletHitWall = false;
        }

        ///Check for collision between bullet and alien
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
                                SoundManager::Play(SoundManager::Sounds::KillAlien);
                                Game::score += CURRENT_ALIEN->score;
                            }
                        }
                    }
                }
            }
        }

        ///Check for collision between bullet and barrier
        #define CURRENT_BARRIER Game::barriers[j]
        for(unsigned j = 0; j < 3; j++)
        {
            ///Check for collision with top-left corner
            if(CURRENT_BULLET->rect.x + CURRENT_BULLET->rect.w >= CURRENT_BARRIER->top_left.x)
            {
                if(CURRENT_BULLET->rect.x <= CURRENT_BARRIER->top_left.w + CURRENT_BARRIER->top_left.x)
                {
                    if(CURRENT_BULLET->rect.y >= CURRENT_BARRIER->top_left.y)
                    {
                        if(CURRENT_BULLET->rect.y <= CURRENT_BARRIER->top_left.y + CURRENT_BARRIER->top_left.h)
                        {
                            if(CURRENT_BARRIER->hits_taken_top_left < 4)
                                CURRENT_BARRIER->hits_taken_top_left++;
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            CURRENT_BARRIER->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with center-left block
            if(CURRENT_BULLET->rect.x  + CURRENT_BULLET->rect.w >= CURRENT_BARRIER->center_left.x)
            {
                if(CURRENT_BULLET->rect.x <= CURRENT_BARRIER->center_left.w + CURRENT_BARRIER->center_left.x)
                {
                    if(CURRENT_BULLET->rect.y >= CURRENT_BARRIER->center_left.y)
                    {
                        if(CURRENT_BULLET->rect.y <= CURRENT_BARRIER->center_left.y + CURRENT_BARRIER->center_left.h)
                        {
                            if(CURRENT_BARRIER->hits_taken_center_left < 4)
                                CURRENT_BARRIER->hits_taken_center_left++;
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            CURRENT_BARRIER->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with bottom-left corner
            if(CURRENT_BULLET->rect.x  + CURRENT_BULLET->rect.w >= CURRENT_BARRIER->bottom_left.x)
            {
                if(CURRENT_BULLET->rect.x <= CURRENT_BARRIER->bottom_left.w + CURRENT_BARRIER->bottom_left.x)
                {
                    if(CURRENT_BULLET->rect.y >= CURRENT_BARRIER->bottom_left.y)
                    {
                        if(CURRENT_BULLET->rect.y <= CURRENT_BARRIER->bottom_left.y + CURRENT_BARRIER->bottom_left.h)
                        {
                            if(CURRENT_BARRIER->hits_taken_bottom_left < 4)
                                CURRENT_BARRIER->hits_taken_bottom_left++;
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            CURRENT_BARRIER->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with top-middle block
            if(CURRENT_BULLET->rect.x  + CURRENT_BULLET->rect.w >= CURRENT_BARRIER->top_middle.x)
            {
                if(CURRENT_BULLET->rect.x <= CURRENT_BARRIER->top_middle.w + CURRENT_BARRIER->top_middle.x)
                {
                    if(CURRENT_BULLET->rect.y >= CURRENT_BARRIER->top_middle.y)
                    {
                        if(CURRENT_BULLET->rect.y <= CURRENT_BARRIER->top_middle.y + CURRENT_BARRIER->top_middle.h)
                        {
                            if(CURRENT_BARRIER->hits_taken_top_middle < 4)
                                CURRENT_BARRIER->hits_taken_top_middle++;
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            CURRENT_BARRIER->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with center-middle block
            if(CURRENT_BULLET->rect.x  + CURRENT_BULLET->rect.w >= CURRENT_BARRIER->center_middle.x)
            {
                if(CURRENT_BULLET->rect.x <= CURRENT_BARRIER->center_middle.w + CURRENT_BARRIER->center_middle.x)
                {
                    if(CURRENT_BULLET->rect.y >= CURRENT_BARRIER->center_middle.y)
                    {
                        if(CURRENT_BULLET->rect.y <= CURRENT_BARRIER->center_middle.y + CURRENT_BARRIER->center_middle.h)
                        {
                            if(CURRENT_BARRIER->hits_taken_center_middle < 4)
                                CURRENT_BARRIER->hits_taken_center_middle++;
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            CURRENT_BARRIER->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with bottom-middle block
            if(CURRENT_BULLET->rect.x  + CURRENT_BULLET->rect.w >= CURRENT_BARRIER->bottom_middle.x)
            {
                if(CURRENT_BULLET->rect.x <= CURRENT_BARRIER->bottom_middle.w + CURRENT_BARRIER->bottom_middle.x)
                {
                    if(CURRENT_BULLET->rect.y >= CURRENT_BARRIER->bottom_middle.y)
                    {
                        if(CURRENT_BULLET->rect.y <= CURRENT_BARRIER->bottom_middle.y + CURRENT_BARRIER->bottom_middle.h)
                        {
                            if(CURRENT_BARRIER->hits_taken_bottom_middle < 4)
                                CURRENT_BARRIER->hits_taken_bottom_middle++;
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            CURRENT_BARRIER->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with top-right corner
            if(CURRENT_BULLET->rect.x  + CURRENT_BULLET->rect.w >= CURRENT_BARRIER->top_right.x)
            {
                if(CURRENT_BULLET->rect.x <= CURRENT_BARRIER->top_right.w + CURRENT_BARRIER->top_right.x)
                {
                    if(CURRENT_BULLET->rect.y >= CURRENT_BARRIER->top_right.y)
                    {
                        if(CURRENT_BULLET->rect.y <= CURRENT_BARRIER->top_right.y + CURRENT_BARRIER->top_right.h)
                        {
                            if(CURRENT_BARRIER->hits_taken_top_right < 4)
                                CURRENT_BARRIER->hits_taken_top_right++;
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            CURRENT_BARRIER->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with center-right block
            if(CURRENT_BULLET->rect.x  + CURRENT_BULLET->rect.w >= CURRENT_BARRIER->center_right.x)
            {
                if(CURRENT_BULLET->rect.x <= CURRENT_BARRIER->center_right.w + CURRENT_BARRIER->center_right.x)
                {
                    if(CURRENT_BULLET->rect.y >= CURRENT_BARRIER->center_right.y)
                    {
                        if(CURRENT_BULLET->rect.y <= CURRENT_BARRIER->center_right.y + CURRENT_BARRIER->center_right.h)
                        {
                            if(CURRENT_BARRIER->hits_taken_center_right < 4)
                                CURRENT_BARRIER->hits_taken_center_right++;
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            CURRENT_BARRIER->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with bottom-right corner
            if(CURRENT_BULLET->rect.x  + CURRENT_BULLET->rect.w >= CURRENT_BARRIER->bottom_right.x)
            {
                if(CURRENT_BULLET->rect.x <= CURRENT_BARRIER->bottom_right.w + CURRENT_BARRIER->bottom_right.x)
                {
                    if(CURRENT_BULLET->rect.y >= CURRENT_BARRIER->bottom_right.y)
                    {
                        if(CURRENT_BULLET->rect.y <= CURRENT_BARRIER->bottom_right.y + CURRENT_BARRIER->bottom_right.h)
                        {
                            if(CURRENT_BARRIER->hits_taken_bottom_right < 4)
                                CURRENT_BARRIER->hits_taken_bottom_right++;
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            CURRENT_BARRIER->Update();
                            continue;
                        }
                    }
                }
            }
        }


        ///Check for collision between bullet and the player
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
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);

<<<<<<< HEAD
                            Player::Die();
=======
                            if(!Player::isDead)
                                Player::Die();
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
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
<<<<<<< HEAD
    Bullet *newBullet = new Bullet(speed, pos_x, pos_y, direction);
    BulletsManager::allBullets.push_back(newBullet);
}
=======
    SoundManager::Play(SoundManager::Sounds::Shoot);
    Bullet *newBullet = new Bullet(speed, pos_x, pos_y, direction);
    BulletsManager::allBullets.push_back(newBullet);
}

void BulletsManager::FreeAllBullets()
{
    std::vector<Bullet*> as;
    while(BulletsManager::allBullets.size() > 0)
    {
        for(unsigned i = 0; i < BulletsManager::allBullets.size(); i++)
        {
            BulletsManager::bulletsToDelete.push_back(CURRENT_BULLET);
            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
        }

        for(unsigned i = 0; i < as.size(); i++)
        {
            delete(as[i]);
        }
    }

}
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
