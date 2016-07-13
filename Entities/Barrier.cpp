#include "Barrier.h"
#include "../Game/Game.h"


Barrier::Barrier(std::string texturePath, int pos_x, int pos_y)
{
    this->rect.w = Game::Pannel.w / 11;
    this->rect.h = this->rect.w / 1.5;
    this->rect.x = pos_x;
    this->rect.y = pos_y;
    this->texture = System::CreateTexture(texturePath, System::renderer);
    this->hitsTaken = 0;
}

Barrier::~Barrier()
{
    delete(&this->rect);
    SDL_DestroyTexture(this->texture);
}

void Barrier::SetX(int x) { this->rect.x = x; }
int Barrier::GetX() { return this->rect.x; }

void Barrier::SetY(int y) { this->rect.y = y; }
int Barrier::GetY() { return this->rect.y; }

void Barrier::SetWidth(int w) { this->rect.w = w; }
int Barrier::GetWidth() { return this->rect.w; }

void Barrier::SetHeigth(int h) { this->rect.h = h; }
int Barrier::GetHeigth() { return this->rect.h; }

void Barrier::SetTexture(SDL_Texture *texture) { this->texture = texture; }

void Barrier::Render() { SDL_RenderCopy(System::renderer, this->texture, NULL, &this->rect); }
