#include "Label.h"

Label::Label()
{
    text = "";
    color = {255, 0, 0};
    font = NULL;
}

Label::~Label()
{
    TTF_CloseFont(font);
    delete(&color);
    text.clear();
}

void Label::SetColor(int r, int g, int b) { this->color = {r, g, b}; }

void Label::SetText(string text) { this->text = text; }

void Label::SetFont(TTF_Font *font)
{
    this->font = font;
    this->texture = System::CreateTextTexture(text, System::renderer, font, color);
    this->rect.w = System::GetSurfaceWidth();
    this->rect.h = System::GetSurfaceHeight();
}
