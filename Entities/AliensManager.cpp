#include "AliensManager.h"

int AliensManager::number = 0;
int AliensManager::movementSpeed = 0;
int AliensManager::shootingPowerCoefficient = 0;
int AliensManager::direction = System::Direction::Right;

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
    for(unsigned i = 0; i < AliensManager::allAliens.size(); ++i)
    {
        if(AliensManager::isAlienHitTheWall())
        {
            AliensManager::ChangeTheDirection();
            for(unsigned i = 0; i < AliensManager::allAliens.size(); ++i)
                CURRENT_ALIEN->SetY(CURRENT_ALIEN->GetY() + 1);
        }

        if(AliensManager::direction == System::Direction::Right)
            CURRENT_ALIEN->SetX(CURRENT_ALIEN->GetX() + CURRENT_ALIEN->GetMovementSpeed());
        else if(AliensManager::direction == System::Direction::Left)
            CURRENT_ALIEN->SetX(CURRENT_ALIEN->GetX() - CURRENT_ALIEN->GetMovementSpeed());
    }
}

bool AliensManager::isAlienHitTheWall()
{
    for(unsigned i = 0; i < AliensManager::allAliens.size(); ++i)
    {
        if(CURRENT_ALIEN->GetX() + CURRENT_ALIEN->GetWidth() > System::Screen::Width)
            return true;
        else if(CURRENT_ALIEN->GetX() < 0)
            return true;
    }
    return false;
}

void AliensManager::ChangeTheDirection()
{
    if(AliensManager::direction == System::Direction::Right)
        AliensManager::direction = System::Direction::Left;
    else if(AliensManager::direction == System::Direction::Left)
        AliensManager::direction = System::Direction::Right;
}
