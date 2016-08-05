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

void Label::SetColor(int r, int g, int b) { this->color = { (Uint8)r, (Uint8)g, (Uint8)b}; }

void Label::SetText(string text) { this->text = text; }
string Label::GetText() { return this->text; }
void Label::SetFont(TTF_Font *font)
{
    this->font = font;
    this->texture = System::CreateTextTexture(text, font, color);
    this->rect.w = System::GetSurfaceWidth();
    this->rect.h = System::GetSurfaceHeight();
}
