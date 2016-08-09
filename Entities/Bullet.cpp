#include "Bullet.h"
#include "BulletsManager.h"
#include "../Game/Game.h"

Bullet::Bullet(int speed, int xPos, int yPos, int direction)
{
    int pannelHeightBulletHeightRatio = 40/1;
    this->rect.h = Game::Pannel.h / pannelHeightBulletHeightRatio;
    int bulletHeightBulletWidthRatio = 4/1;
    this->rect.w = this->rect.h / bulletHeightBulletWidthRatio;
    this->rect.x = xPos;
    this->rect.y = yPos;
    this->texture = System::Textures::Bullets;
    this->movementSpeed = speed;
    this->direction = direction;
}

void Bullet::Render()
{
    SDL_RenderCopy(System::renderer, this->texture, NULL, &this->rect);
}

void Bullet::Update()
{
    if(this->direction == System::Direction::Up) {
        this->rect.y -= movementSpeed;
    }
    else if(this->direction == System::Direction::Down) {
        this->rect.y += movementSpeed;
    }
}

void Bullet::SetDirection(int direction) { this->direction = direction; }
int Bullet::GetDirection() { return this->direction; }

bool Bullet::hasHitTheWall()
{
    if(this->direction == System::Direction::Up)
    {
        if(this->rect.y < 0)
        {
            BulletsManager::hasBulletHitWall = true;
            return true;
        }
        return false;
    }
    else if(this->direction == System::Direction::Down)
    {
        if(this->rect.y + this->rect.h > System::Screen::Height)
        {
            BulletsManager::hasBulletHitWall = true;
            return true;
        }
        return false;
    }

    return false;
}
