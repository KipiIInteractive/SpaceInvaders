#include "GUI.h"

GUI::GUI()
{
    this->rect.x = 0; this->rect.y = 0;
    this->rect.w = 0; this->rect.h = 0;
    this->texture = NULL;
    this->hoverTexture = NULL;
    SDL_GetMouseState(&mouseX, &mouseY);
    this->click = false;
}

GUI::~GUI()
{
    delete(&rect);
}

bool GUI::isClicked()
{
    click = false;
    if(System::event.type == SDL_MOUSEBUTTONUP)
    {
        if(System::event.button.button == SDL_BUTTON_LEFT)
        {
            if(this->click == false)
            {
                click = true;
                return this->isHover();
            }
        }
    }
    return false;
}

bool GUI::isHover()
{
    SDL_GetMouseState(&mouseX, &mouseY);
    return mouseX >= rect.x && mouseX <= rect.x + rect.w
        && mouseY >= rect.y && mouseY <= rect.y + rect.h ;
}

int GUI::GetX() { return this->rect.x; }
int GUI::GetY() { return this->rect.y; }
int GUI::GetWidth() { return this->rect.w; }
int GUI::GetHeight() { return this->rect.h; }

void GUI::SetHeight(int height) { this->rect.h = height; }
void GUI::SetWidth(int width) { this->rect.w = width; }
void GUI::SetX(int x) { this->rect.x = x; }
void GUI::SetY(int y) { this->rect.y = y; }

void GUI::SetTexture(string texturePath)
{
    this->texture = System::CreateTexture(texturePath);
}

void GUI::Render()
{
    SDL_RenderCopy(System::renderer, this->texture, NULL, &rect);
}
