#include "Bullet.h"
#include "BulletsManager.h"

Bullet::Bullet(int speed, int pos_x, int pos_y, int direction)
{
    this->rect.h = 20; this->rect.w = 20;
    this->rect.x = pos_x; this->rect.y = pos_y;
    this->texture = System::CreateTexture("Resources/Textures/bullet.png", System::renderer);
    this->movementSpeed = speed;
    this->direction = direction;
}

Bullet::~Bullet()
{
    delete(&this->rect);
    SDL_DestroyTexture(texture);
}

void Bullet::Render()
{
    SDL_RenderCopy(System::renderer, this->texture, NULL, &this->rect);
}

void Bullet::Update()
{
    if(this->direction == System::Direction::Up)
        this->rect.y -= movementSpeed;

    else if(this->direction == System::Direction::Down)
        this->rect.y += movementSpeed;

    else if(this->direction == System::Direction::Right)
        this->rect.x += movementSpeed;

    else if(this->direction == System::Direction::Left)
        this->rect.x -= movementSpeed;
}

void Bullet::SetDirection(int directoin) { this->direction = direction; }
int Bullet::GetDirection() { return this->direction; }

bool Bullet::isHitTheWall()
{
    if(this->direction == System::Direction::Up)
    {
        if(this->rect.y < 0)
        {
            return true;
            BulletsManager::isBulletHitWall = true;
        }
        return false;
    }
    else if(this->direction == System::Direction::Down)
    {
        if(this->rect.y + this->rect.h > System::Screen::Height)
        {
            return true;
            BulletsManager::isBulletHitWall = true;
        }
        return false;
    }
}
