#include "AliensManager.h"
#include "../Game/Game.h"

#define CURRENT_ALIEN AliensManager::allAliens[i]

int AliensManager::number = 0;
int AliensManager::movementSpeed = 0;
int AliensManager::shootingPowerCoefficient = 0;
int AliensManager::direction = System::Direction::Right;
int AliensManager::currentFrame;
bool AliensManager::isAlienHitTheWall = false;
SDL_Rect AliensManager::dead_rect;

std::vector<Alien*> AliensManager::allAliens;

void AliensManager::AddNewAlien(int type, int pos_x, int pos_y)
{
    Alien *newAlien = new Alien(type, pos_x, pos_y);
    AliensManager::allAliens.push_back(newAlien);
}

void AliensManager::RenderAll()
{
    for(unsigned i = 0; i < AliensManager::allAliens.size(); ++i)
        AliensManager::allAliens[i]->Render();
}

void AliensManager::Move()
{
    if(AliensManager::currentFrame == AliensManager::movementSpeed)
    {
        for(unsigned i = 0; i < AliensManager::allAliens.size(); i++)
        {
<<<<<<< HEAD
            CURRENT_ALIEN->Shoot();
=======
            if(!Player::isDead)
                CURRENT_ALIEN->Shoot();
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

            if(AliensManager::direction == System::Direction::Right)
                CURRENT_ALIEN->SetX( CURRENT_ALIEN->GetX() + CURRENT_ALIEN->GetWidth() / 3 );
            else if(AliensManager::direction == System::Direction::Left)
                CURRENT_ALIEN->SetX( CURRENT_ALIEN->GetX() - CURRENT_ALIEN->GetWidth() / 3 );

<<<<<<< HEAD
            //Check if alien is hit the floor
=======
            //Check if alien is hit the wall
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
            if(!AliensManager::isAlienHitTheWall)
            {
                if(CURRENT_ALIEN->GetX() + CURRENT_ALIEN->GetWidth() >= Game::Pannel.w + Game::Pannel.x)
                    AliensManager::isAlienHitTheWall = true;
                else if(CURRENT_ALIEN->GetX() < Game::Pannel.x)
                    AliensManager::isAlienHitTheWall = true;
<<<<<<< HEAD
=======
                else if(CURRENT_ALIEN->GetY() + CURRENT_ALIEN->GetHeigth() >= System::Screen::Height)
                {
                    GameOver::Show();
                    break;
                }
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
            }

            //Animate the aliens
            if(CURRENT_ALIEN->frame.x == 0)
                CURRENT_ALIEN->frame.x = CURRENT_ALIEN->frame.w;
            else
                CURRENT_ALIEN->frame.x = 0;

        }
        if(AliensManager::isAlienHitTheWall)
        {
            AliensManager::ChangeTheDirection();
            for(unsigned i = 0; i < AliensManager::allAliens.size(); i++)
            {
                CURRENT_ALIEN->SetY( CURRENT_ALIEN->GetY() + CURRENT_ALIEN->GetHeigth() / 2 );

                if(AliensManager::direction == System::Direction::Right)
                    CURRENT_ALIEN->SetX( CURRENT_ALIEN->GetX() + CURRENT_ALIEN->GetWidth() / 3 );
                else if(AliensManager::direction == System::Direction::Left)
                    CURRENT_ALIEN->SetX( CURRENT_ALIEN->GetX() - CURRENT_ALIEN->GetWidth() / 3 );
            }
            AliensManager::isAlienHitTheWall = false;
        }
        AliensManager::currentFrame = 0;
    }
    else AliensManager::currentFrame++;
}

void AliensManager::ChangeTheDirection()
{
    if(AliensManager::direction == System::Direction::Right)
        AliensManager::direction = System::Direction::Left;
    else if(AliensManager::direction == System::Direction::Left)
        AliensManager::direction = System::Direction::Right;
}
<<<<<<< HEAD
=======

void AliensManager::FreeAllAliens()
{
    std::vector<Alien*> as;
    while(AliensManager::allAliens.size() > 0)
    {
        for(unsigned i = 0; i < AliensManager::allAliens.size(); i++)
        {
            as.push_back(AliensManager::allAliens[i]);
            AliensManager::allAliens.erase(AliensManager::allAliens.begin() + i);
        }

        for(unsigned i = 0; i < as.size(); i++)
        {
            delete(as[i]);
        }
    }
}
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
