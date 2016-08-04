#include "Alien.h"

#define MAX_ALIENS_ON_ROW 20

Alien::Alien(int type, int pos_x, int pos_y)
{
    this->type = type;
    if(type == 1)
        this->texture = System::CreateTexture("Resources/Textures/alien_type_1.jpg", System::renderer);
    else if(type == 2)
        this->texture = System::CreateTexture("Resources/Textures/alien_type_2.jpg", System::renderer);

    this->rect.x = pos_x;
    this->rect.y = pos_y;
    this->rect.w = System::Screen::Width / MAX_ALIENS_ON_ROW;
    this->rect.h = this->rect.w;
}
