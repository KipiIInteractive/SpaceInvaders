#include "Label.h"

Label::Label()
{
    text = "";
    color = {255, 0, 0};
    font = NULL;
    texture = NULL;
}

Label::~Label()
{
    text.clear();
}

void Label::SetColor(int r, int g, int b) { this->color = { (Uint8)r, (Uint8)g, (Uint8)b}; }

void Label::SetText(string text) { this->text = text; }
string Label::GetText() { return this->text; }
void Label::SetFont(TTF_Font *tmpFont)
{
    if(this->texture != NULL) {
        SDL_DestroyTexture(this->texture);
        this->texture = NULL;
    }
    this->font = tmpFont;
    this->texture = System::CreateTextTexture(text, this->font, color);
    this->rect.w = System::GetSurfaceWidth();
    this->rect.h = System::GetSurfaceHeight();
}
