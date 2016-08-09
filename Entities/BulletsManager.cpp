#include "BulletsManager.h"
#include "AliensManager.h"
#include "../Game/Game.h"
#include "Player.h"
#include "UFO.h"

std::vector<Bullet*> BulletsManager::allBullets;
std::vector<Bullet*> BulletsManager::bulletsToDelete;
bool BulletsManager::hasBulletHitWall = false;

void BulletsManager::RenderAll()
{
    for(unsigned i = 0; i < BulletsManager::allBullets.size(); ++i) {
        BulletsManager::allBullets[i]->Render();
    }
}

void BulletsManager::UpdateAll()
{
    for(unsigned i = 0; i < BulletsManager::allBullets.size(); ++i)
    {
        BulletsManager::allBullets[i]->Update();

        ///Delete the bullet that has hit one of the walls
        if(BulletsManager::hasBulletHitWall && BulletsManager::allBullets[i]->hasHitTheWall())
        {
            BulletsManager::bulletsToDelete.push_back(BulletsManager::allBullets[i]);
            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
            BulletsManager::hasBulletHitWall = false;
        }

        ///Check for collision between bullet and the UFO
        if(BulletsManager::allBullets[i]->rect.y <= UFO::rect.y + UFO::rect.h && BulletsManager::allBullets[i]->rect.y + BulletsManager::allBullets[i]->rect.h >= UFO::rect.y)
        {
            if(BulletsManager::allBullets[i]->rect.x <= UFO::rect.x + UFO::rect.w)
            {
                if(BulletsManager::allBullets[i]->rect.x + BulletsManager::allBullets[i]->rect.w >= UFO::rect.x)
                {
                    if(BulletsManager::allBullets[i]->GetDirection() == System::Direction::Up)
                    {
                        //Delete the bullet
                        BulletsManager::bulletsToDelete.push_back(BulletsManager::allBullets[i]);
                        BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);

                        UFO::Die();
                        Game::pScore += UFO::pointsWorth;
                    }
                }
            }
        }

        ///Check for collision between bullet and alien
        for(unsigned j = 0; j < AliensManager::allAliens.size(); j++)
        {
            if(BulletsManager::allBullets[i]->rect.x >= AliensManager::allAliens[j]->GetX() && AliensManager::allAliens[j]->isAlive)
            {
                if(BulletsManager::allBullets[i]->rect.x <= AliensManager::allAliens[j]->GetX() + AliensManager::allAliens[j]->GetWidth())
                {
                    if(BulletsManager::allBullets[i]->rect.y <= AliensManager::allAliens[j]->GetY() + AliensManager::allAliens[j]->GetHeigth())
                    {
                        if(BulletsManager::allBullets[i]->rect.y >= AliensManager::allAliens[j]->GetY())
                        {
                            if(BulletsManager::allBullets[i]->GetDirection() == System::Direction::Up)
                            {
                                // Set alien killed flag
                                AliensManager::allAliens[j]->setHasBeenKilled(true);

                                //Delete the bullet
                                BulletsManager::bulletsToDelete.push_back(BulletsManager::allBullets[i]);
                                BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                                SoundManager::Play(SoundManager::Sounds::AlienKilled);
                                Game::pScore += AliensManager::allAliens[j]->pointsWorth;
                            }
                        }
                    }
                }
            }
        }

        ///Check for collision between bullet and barrier
        for(unsigned j = 0; j < 3; j++)
        {
            ///Check for collision with top-left corner
            if(BulletsManager::allBullets[i]->rect.x + BulletsManager::allBullets[i]->rect.w >= Game::barriers[j]->topLeftPartPos.x)
            {
                if(BulletsManager::allBullets[i]->rect.x <= Game::barriers[j]->topLeftPartPos.w + Game::barriers[j]->topLeftPartPos.x)
                {
                    if(BulletsManager::allBullets[i]->rect.y >= Game::barriers[j]->topLeftPartPos.y)
                    {
                        if(BulletsManager::allBullets[i]->rect.y <= Game::barriers[j]->topLeftPartPos.y + Game::barriers[j]->topLeftPartPos.h)
                        {
                            if(Game::barriers[j]->hitsTakenTopLeftPart < 4) {
                                Game::barriers[j]->hitsTakenTopLeftPart++;
                            }
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(BulletsManager::allBullets[i]);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            Game::barriers[j]->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with center-left block
            if(BulletsManager::allBullets[i]->rect.x  + BulletsManager::allBullets[i]->rect.w >= Game::barriers[j]->centerLeftPartPos.x)
            {
                if(BulletsManager::allBullets[i]->rect.x <= Game::barriers[j]->centerLeftPartPos.w + Game::barriers[j]->centerLeftPartPos.x)
                {
                    if(BulletsManager::allBullets[i]->rect.y >= Game::barriers[j]->centerLeftPartPos.y)
                    {
                        if(BulletsManager::allBullets[i]->rect.y <= Game::barriers[j]->centerLeftPartPos.y + Game::barriers[j]->centerLeftPartPos.h)
                        {
                            if(Game::barriers[j]->hitsTakenCenterLeftPart < 4) {
                                Game::barriers[j]->hitsTakenCenterLeftPart++;
                            }
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(BulletsManager::allBullets[i]);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            Game::barriers[j]->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with bottom-left corner
            if(BulletsManager::allBullets[i]->rect.x  + BulletsManager::allBullets[i]->rect.w >= Game::barriers[j]->bottomLeftPartPos.x)
            {
                if(BulletsManager::allBullets[i]->rect.x <= Game::barriers[j]->bottomLeftPartPos.w + Game::barriers[j]->bottomLeftPartPos.x)
                {
                    if(BulletsManager::allBullets[i]->rect.y >= Game::barriers[j]->bottomLeftPartPos.y)
                    {
                        if(BulletsManager::allBullets[i]->rect.y <= Game::barriers[j]->bottomLeftPartPos.y + Game::barriers[j]->bottomLeftPartPos.h)
                        {
                            if(Game::barriers[j]->hitsTakenBottomLeftPart < 4) {
                                Game::barriers[j]->hitsTakenBottomLeftPart++;
                            }
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(BulletsManager::allBullets[i]);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            Game::barriers[j]->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with top-middle block
            if(BulletsManager::allBullets[i]->rect.x  + BulletsManager::allBullets[i]->rect.w >= Game::barriers[j]->topMiddlePartPos.x)
            {
                if(BulletsManager::allBullets[i]->rect.x <= Game::barriers[j]->topMiddlePartPos.w + Game::barriers[j]->topMiddlePartPos.x)
                {
                    if(BulletsManager::allBullets[i]->rect.y >= Game::barriers[j]->topMiddlePartPos.y)
                    {
                        if(BulletsManager::allBullets[i]->rect.y <= Game::barriers[j]->topMiddlePartPos.y + Game::barriers[j]->topMiddlePartPos.h)
                        {
                            if(Game::barriers[j]->hitsTakenTopMiddlePart < 4) {
                                Game::barriers[j]->hitsTakenTopMiddlePart++;
                            }
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(BulletsManager::allBullets[i]);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            Game::barriers[j]->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with center-middle block
            if(BulletsManager::allBullets[i]->rect.x  + BulletsManager::allBullets[i]->rect.w >= Game::barriers[j]->centerMiddlePartPos.x)
            {
                if(BulletsManager::allBullets[i]->rect.x <= Game::barriers[j]->centerMiddlePartPos.w + Game::barriers[j]->centerMiddlePartPos.x)
                {
                    if(BulletsManager::allBullets[i]->rect.y >= Game::barriers[j]->centerMiddlePartPos.y)
                    {
                        if(BulletsManager::allBullets[i]->rect.y <= Game::barriers[j]->centerMiddlePartPos.y + Game::barriers[j]->centerMiddlePartPos.h)
                        {
                            if(Game::barriers[j]->hitsTakenCenterMiddlePart < 4) {
                                Game::barriers[j]->hitsTakenCenterMiddlePart++;
                            }
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(BulletsManager::allBullets[i]);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            Game::barriers[j]->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with bottom-middle block
            if(BulletsManager::allBullets[i]->rect.x  + BulletsManager::allBullets[i]->rect.w >= Game::barriers[j]->bottomMiddlePartPos.x)
            {
                if(BulletsManager::allBullets[i]->rect.x <= Game::barriers[j]->bottomMiddlePartPos.w + Game::barriers[j]->bottomMiddlePartPos.x)
                {
                    if(BulletsManager::allBullets[i]->rect.y >= Game::barriers[j]->bottomMiddlePartPos.y)
                    {
                        if(BulletsManager::allBullets[i]->rect.y <= Game::barriers[j]->bottomMiddlePartPos.y + Game::barriers[j]->bottomMiddlePartPos.h)
                        {
                            if(Game::barriers[j]->hitsTakenBottomMiddlePart < 4) {
                                Game::barriers[j]->hitsTakenBottomMiddlePart++;
                            }
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(BulletsManager::allBullets[i]);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            Game::barriers[j]->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with top right corner
            if(BulletsManager::allBullets[i]->rect.x  + BulletsManager::allBullets[i]->rect.w >= Game::barriers[j]->topRightPartPos.x)
            {
                if(BulletsManager::allBullets[i]->rect.x <= Game::barriers[j]->topRightPartPos.w + Game::barriers[j]->topRightPartPos.x)
                {
                    if(BulletsManager::allBullets[i]->rect.y >= Game::barriers[j]->topRightPartPos.y)
                    {
                        if(BulletsManager::allBullets[i]->rect.y <= Game::barriers[j]->topRightPartPos.y + Game::barriers[j]->topRightPartPos.h)
                        {
                            if(Game::barriers[j]->hitsTakenTopRightPart < 4) {
                                Game::barriers[j]->hitsTakenTopRightPart++;
                            }
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(BulletsManager::allBullets[i]);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            Game::barriers[j]->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with center right block
            if(BulletsManager::allBullets[i]->rect.x  + BulletsManager::allBullets[i]->rect.w >= Game::barriers[j]->centerRightPartPos.x)
            {
                if(BulletsManager::allBullets[i]->rect.x <= Game::barriers[j]->centerRightPartPos.w + Game::barriers[j]->centerRightPartPos.x)
                {
                    if(BulletsManager::allBullets[i]->rect.y >= Game::barriers[j]->centerRightPartPos.y)
                    {
                        if(BulletsManager::allBullets[i]->rect.y <= Game::barriers[j]->centerRightPartPos.y + Game::barriers[j]->centerRightPartPos.h)
                        {
                            if(Game::barriers[j]->hitsTakenCenterRightPart < 4) {
                                Game::barriers[j]->hitsTakenCenterRightPart++;
                            }
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(BulletsManager::allBullets[i]);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            Game::barriers[j]->Update();
                            continue;
                        }
                    }
                }
            }
            ///Check for collision with bottom right corner
            if(BulletsManager::allBullets[i]->rect.x  + BulletsManager::allBullets[i]->rect.w >= Game::barriers[j]->bottomRightPartPos.x)
            {
                if(BulletsManager::allBullets[i]->rect.x <= Game::barriers[j]->bottomRightPartPos.w + Game::barriers[j]->bottomRightPartPos.x)
                {
                    if(BulletsManager::allBullets[i]->rect.y >= Game::barriers[j]->bottomRightPartPos.y)
                    {
                        if(BulletsManager::allBullets[i]->rect.y <= Game::barriers[j]->bottomRightPartPos.y + Game::barriers[j]->bottomRightPartPos.h)
                        {
                            if(Game::barriers[j]->hitsTakenBottomRightPart < 4) {
                                Game::barriers[j]->hitsTakenBottomRightPart++;
                            }
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(BulletsManager::allBullets[i]);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
                            //Change the texture of the barrier segment
                            Game::barriers[j]->Update();
                            continue;
                        }
                    }
                }
            }
        }


        ///Check for collision between bullet and the player
        if(BulletsManager::allBullets[i]->rect.x >= Player::rect.x)
        {
            if(BulletsManager::allBullets[i]->rect.x <= Player::rect.x + Player::rect.w)
            {
                if(BulletsManager::allBullets[i]->rect.y + BulletsManager::allBullets[i]->rect.h >= Player::rect.y)
                {
                    if(BulletsManager::allBullets[i]->rect.y <= Player::rect.y + Player::rect.h)
                    {
                        if(BulletsManager::allBullets[i]->GetDirection() == System::Direction::Down)
                        {
                            //Delete the bullet
                            BulletsManager::bulletsToDelete.push_back(BulletsManager::allBullets[i]);
                            BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);

                            if(!Player::isDead) {
                                Player::DecreaseLives();
                            }
                        }
                    }
                }
            }
        }
    }

    //Delete the bullets that collided with something
    for(unsigned i = 0; i < BulletsManager::bulletsToDelete.size(); ++i)
    {
        delete(BulletsManager::bulletsToDelete[i]);
        BulletsManager::bulletsToDelete.erase(BulletsManager::bulletsToDelete.begin() + i);
    }
}

void BulletsManager::AddNewBullet(int speed, int xPos, int yPos, int direction)
{
    SoundManager::Play(SoundManager::Sounds::Shoot);
    BulletsManager::allBullets.push_back(new Bullet(speed, xPos, yPos, direction));
}

void BulletsManager::FreeAllBullets()
{
    for(unsigned i = 0; i < BulletsManager::allBullets.size(); i++)
    {
        BulletsManager::bulletsToDelete.push_back(BulletsManager::allBullets[i]);
    }
    BulletsManager::allBullets.clear();
    for(unsigned i = 0; i < BulletsManager::bulletsToDelete.size(); i++)
    {
        delete BulletsManager::bulletsToDelete[i];
    }
    BulletsManager::bulletsToDelete.clear();
}
