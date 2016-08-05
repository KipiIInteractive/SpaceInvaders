#include "Link.h"

Link::Link()
{
    this->text = " ";
    this->color = {255, 255, 255};
    this->font = NULL;
}

Link::~Link()
{
    SDL_DestroyTexture(this->texture);
    delete(&this->rect);
    delete(&this->color);
    delete(&this->font);
}

void Link::SetText(string text)
{
    this->text = text;
    Link::Create();
}

void Link::SetColor(int r, int g, int b)
{
    this->color = {(Uint8)r, (Uint8)g, (Uint8)b};
    Link::Create();
}

void Link::SetFont(TTF_Font *font)
{
    this->font = font;
    Link::Create();
}

void Link::Create()
{
    SDL_Surface* surface = TTF_RenderText_Solid(this->font, this->text.c_str(), this->color);
    this->texture = SDL_CreateTextureFromSurface(System::renderer, surface);
    this->rect.w = surface->w;
    this->rect.h = surface->h;
    SDL_FreeSurface(surface);
}
