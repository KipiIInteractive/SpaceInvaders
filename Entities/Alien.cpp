#include "Alien.h"
#include "../Game/Game.h"

#define MAX_ALIENS_ON_ROW 15

Alien::Alien(int type, int pos_x, int pos_y)
{
    this->type = type;
    if(type == 1)
        this->texture = System::CreateTexture("Resources/Textures/alien_type_1.png", System::renderer);
    else if(type == 2)
        this->texture = System::CreateTexture("Resources/Textures/alien_type_2.png", System::renderer);

    this->rect.x = pos_x;
    this->rect.y = pos_y;
    this->rect.w = (Game::Pannel.w - MAX_ALIENS_ON_ROW * 5) / MAX_ALIENS_ON_ROW;
    this->rect.h = this->rect.w;
}

Alien::~Alien()
{

}
