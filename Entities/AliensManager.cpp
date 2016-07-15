#include "AliensManager.h"
#include "../Game/Game.h"

#define CURRENT_ALIEN AliensManager::allAliens[i]

int AliensManager::number = 0;
int AliensManager::movementSpeed = 0;
int AliensManager::shootingPowerCoefficient = 0;
int AliensManager::direction = System::Direction::Right;
int AliensManager::currentFrame;
bool AliensManager::isAlienHitTheWall = false;

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
            CURRENT_ALIEN->Shoot();

            if(AliensManager::direction == System::Direction::Right)
                CURRENT_ALIEN->SetX( CURRENT_ALIEN->GetX() + AliensManager::movementSpeed );
            else if(AliensManager::direction == System::Direction::Left)
                CURRENT_ALIEN->SetX( CURRENT_ALIEN->GetX() - AliensManager::movementSpeed );

            //Check if alien is hit the floor
            if(!AliensManager::isAlienHitTheWall)
            {
                if(CURRENT_ALIEN->GetX() + CURRENT_ALIEN->GetWidth() >= Game::Pannel.w + Game::Pannel.x)
                    AliensManager::isAlienHitTheWall = true;
                else if(CURRENT_ALIEN->GetX() < Game::Pannel.x)
                    AliensManager::isAlienHitTheWall = true;
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
                    CURRENT_ALIEN->SetX( CURRENT_ALIEN->GetX() + AliensManager::movementSpeed );
                else if(AliensManager::direction == System::Direction::Left)
                    CURRENT_ALIEN->SetX( CURRENT_ALIEN->GetX() - AliensManager::movementSpeed );
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
