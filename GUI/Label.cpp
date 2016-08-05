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

<<<<<<< HEAD
void Label::SetColor(int r, int g, int b) { this->color = {r, g, b}; }
=======
void Label::SetColor(int r, int g, int b) { this->color = { (Uint8)r, (Uint8)g, (Uint8)b}; }
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

void Label::SetText(string text) { this->text = text; }
string Label::GetText() { return this->text; }
void Label::SetFont(TTF_Font *font)
{
    this->font = font;
    this->texture = System::CreateTextTexture(text, font, color);
    this->rect.w = System::GetSurfaceWidth();
    this->rect.h = System::GetSurfaceHeight();
}
