#include "Alien.h"
#include "../Game/Game.h"
#include "BulletsManager.h"
#include "AliensManager.h"

#define MAX_ALIENS_ON_ROW 15

Alien::Alien(int type, int pos_x, int pos_y)
{
<<<<<<< HEAD
    this->texture = System::CreateTexture("Resources/Textures/aliens.png", System::renderer);
=======
    this->SetTexture(System::Textures::Aliens);

>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    this->type = type;

    this->rect.x = pos_x;
    this->rect.y = pos_y;
    this->rect.w = (Game::Pannel.w - MAX_ALIENS_ON_ROW * 5) / MAX_ALIENS_ON_ROW;
    this->rect.h = this->rect.w / 1.3;

    SDL_QueryTexture(this->texture, NULL, NULL, &frame.w, &frame.h);
    this->frame.w /= 2;
    this->frame.h /= 3;
    this->frame.x = this->frame.w;

    if(type == 1)
    {
        this->frame.y = 0;
        this->score = 10;
    }
    else if(type == 2)
    {
        this->frame.y = this->frame.h;
        this->score = 20;
    }
    else if(type == 3)
    {
        this->frame.y = this->frame.h * 2;
        this->score = 40;
    }
    srand(time(0));
}

Alien::~Alien()
{
<<<<<<< HEAD

=======
    delete(&this->rect);
    delete(&this->frame);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
}

void Alien::Render()
{
    SDL_RenderCopy(System::renderer, this->texture, &this->frame, &this->rect);
}

void Alien::Shoot()
{
    if(AliensManager::allAliens.size() >= 40)
    {
        if( rand() % 45  == 22 )
<<<<<<< HEAD
        {
            ///SoundManager::Play(SoundManager::Sounds::Shoot);
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
        }
=======
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    }
    else if(AliensManager::allAliens.size() >= 35)
    {
        if( rand() % 40  == 20 )
<<<<<<< HEAD
        {
            ///SoundManager::Play(SoundManager::Sounds::Shoot);
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
        }
=======
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    }
    else if(AliensManager::allAliens.size() >= 30)
    {
        if( rand() % 30  == 15 )
<<<<<<< HEAD
        {
            ///SoundManager::Play(SoundManager::Sounds::Shoot);
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
        }
=======
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    }
    else if(AliensManager::allAliens.size() >= 25)
    {
        if( rand() % 25  == 12 )
<<<<<<< HEAD
        {
            ///SoundManager::Play(SoundManager::Sounds::Shoot);
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
        }
=======
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    }
    else if(AliensManager::allAliens.size() >= 20)
    {
        if( rand() % 20  == 10 )
<<<<<<< HEAD
        {
            ///SoundManager::Play(SoundManager::Sounds::Shoot);
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
        }
=======
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    }
    else if(AliensManager::allAliens.size() >= 15)
    {
        if( rand() % 18  == 9 )
<<<<<<< HEAD
        {
            ///SoundManager::Play(SoundManager::Sounds::Shoot);
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
        }
=======
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    }
    else if(AliensManager::allAliens.size() >= 10)
    {
        if( rand() % 16  ==  8)
<<<<<<< HEAD
        {
            ///SoundManager::Play(SoundManager::Sounds::Shoot);
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
        }
=======
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    }
    else if(AliensManager::allAliens.size() >= 5)
    {
        if( rand() % 14  == 7 )
<<<<<<< HEAD
        {
            ///SoundManager::Play(SoundManager::Sounds::Shoot);
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
        }
=======
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    }
    else
    {
        if( rand() % 12  == 6 )
<<<<<<< HEAD
        {
            ///SoundManager::Play(SoundManager::Sounds::Shoot);
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
        }
=======
            BulletsManager::AddNewBullet(AliensManager::shootingPowerCoefficient, this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h, System::Direction::Down);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    }

}
