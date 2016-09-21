#include "Entity.h"

Entity::Entity()
{
    this->rect.h = 0; this->rect.w = 0;
    this->rect.x = 0; this->rect.y = 0;
    this->texture = NULL;
    this->movementSpeed = 0;
    this->isAlive = true;
}

Entity::~Entity() {}

void Entity::SetMovementSpeed(int speed) { this->movementSpeed = speed; }
int Entity::GetMovementSpeed() { return this->movementSpeed; }

void Entity::SetTexture(SDL_Texture *texture) { this->texture = texture; }

void Entity::Render()
{
    SDL_RenderCopy(System::renderer, this->texture, NULL, &this->rect);
}

void Entity::SetX(int x) { this->rect.x = x; }
int Entity::GetX() { return this->rect.x; }

void Entity::SetY(int y) { this->rect.y = y; }
int Entity::GetY() { return this->rect.y; }

void Entity::SetWidth(int w) { this->rect.w = w; }
int Entity::GetWidth() { return this->rect.w; }

void Entity::SetHeigth(int h) { this->rect.h = h; }
int Entity::GetHeigth() { return this->rect.h; }
