#include "Alien.h"
#include "../Game/Game.h"
#include "BulletsManager.h"
#include "AliensManager.h"

#define MAX_ALIENS_ON_ROW 15

int Alien::timeToBeRenderedDeadInSeconds = 20;

Alien::Alien(AlienType type, int xPos, int yPos)
{
    this->SetTexture(System::Textures::AliensAlive);

    this->type = type;

    float alienWidthAlienHeightRatio = 1.3;
    this->rect.x = xPos;
    this->rect.y = yPos;
    this->rect.w = (Game::Pannel.w - MAX_ALIENS_ON_ROW * 5) / MAX_ALIENS_ON_ROW;
    this->rect.h = this->rect.w / alienWidthAlienHeightRatio;

    SDL_QueryTexture(this->texture, NULL, NULL, &frame.w, &frame.h);
    this->frame.w /= 2;
    this->frame.h /= 3;
    this->frame.x = this->frame.w;

    this->isAlive = true;
    this->hasBeenKilled = false;
    this->timeDeadInSeconds = 0;

    if(type == SQUID)
    {
        this->frame.y = 0;
        this->pointsWorth = 40;
    }
    else if(type == CRAB)
    {
        this->frame.y = this->frame.h;
        this->pointsWorth = 20;
    }
    else if(type == JELLYFISH)
    {
        this->frame.y = this->frame.h * 2;
        this->pointsWorth = 10;
    }
    srand(time(0));
}

void Alien::setHasBeenKilled(bool state) {
    this->hasBeenKilled = state;
    this->isAlive = false;
}

void Alien::Render()
{
    if(this->isAlive) {
        SDL_RenderCopy(System::renderer, this->texture, &this->frame, &this->rect);
    }
    else if(this->hasBeenKilled && this->timeDeadInSeconds < this->timeToBeRenderedDeadInSeconds) {
        SDL_RenderCopy(System::renderer, System::Textures::AliensDead, NULL, &this->rect);
        this->timeDeadInSeconds++;
    }
    else {
        this->hasBeenKilled = false;
        this->timeDeadInSeconds = 0;
    }
}

void Alien::Shoot()
{
    if(this->isAlive) {
        if(AliensManager::getRemainingAliens() >= 40)
        {
            // 1% chance for the alien to shoot (1 in 100)
            if( rand() % 100 < 1 ) {
                BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
            }
        }
        else if(AliensManager::getRemainingAliens() >= 35)
        {
            // 1.25% chance for the alien to shoot (1 in 100)
            if( rand() % 100 < 1.25f ) {
                BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
            }
        }
        else if(AliensManager::getRemainingAliens() >= 30)
        {
            // 1.67% chance for the alien to shoot (1 in 100)
            if( rand() % 100 < 1.67f ) {
                BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
            }
        }
        else if(AliensManager::getRemainingAliens() >= 25)
        {
            // 2.5% chance for the alien to shoot (1 in 100)
            if( rand() % 100 < 2.5f ) {
                BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
            }
        }
        else if(AliensManager::getRemainingAliens() >= 20)
        {
            // 3.3% chance for the alien to shoot (1 in 100)
            if( rand() % 100 < 3.3f) {
                BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
            }
        }
        else if(AliensManager::getRemainingAliens() >= 15)
        {
            // 5% chance for the alien to shoot (1 in 100)
            if( rand() % 100 < 5 ) {
                BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
            }
        }
        else if(AliensManager::getRemainingAliens() >= 10)
        {
            // 10% chance for the alien to shoot (1 in 100)
            if( rand() % 100 < 10) {
                BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
            }
        }
        else if(AliensManager::getRemainingAliens() >= 5)
        {
            // 20% chance for the alien to shoot (1 in 100)
            if( rand() % 100 < 20 ) {
                BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
            }
        }
        else
        {
            // 100% chance for the alien to shoot (1 in 100)
            if( rand() % 100 < 100 ) {
                BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
            }
        }
    }
}
