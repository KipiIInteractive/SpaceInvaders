#include "Alien.h"
#include "../Game/Game.h"

#define MAX_ALIENS_ON_ROW 15

Alien::Alien(int type, int pos_x, int pos_y)
{
    this->texture = System::CreateTexture("Resources/Textures/aliens.png", System::renderer);
    this->type = type;

    this->rect.x = pos_x;
    this->rect.y = pos_y;
    this->rect.w = (Game::Pannel.w - MAX_ALIENS_ON_ROW * 5) / MAX_ALIENS_ON_ROW;
    this->rect.h = this->rect.w;

    SDL_QueryTexture(this->texture, NULL, NULL, &frame.w, &frame.h);
    this->frame.w /= 2;
    this->frame.h /= 3;
    this->frame.x = this->frame.w;

    if(type == 1)
        this->frame.y = 0;
    else if(type == 2)
        this->frame.y = this->frame.h;
    else if(type == 3)
        this->frame.y = this->frame.h * 2;
}

Alien::~Alien()
{

}

void Alien::Render()
{
    SDL_RenderCopy(System::renderer, this->texture, &this->frame, &this->rect);
}
