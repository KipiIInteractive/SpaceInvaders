#include "Keyboard.h"

int current_selected;
bool Keyboard::isActive;
Key Keyboard::keys[26];
SDL_Rect Keyboard::rect;
SDL_Color color_selected = {255, 0, 0};

void Key::Render()
{
    SDL_RenderCopy(System::renderer, this->texture, NULL, &this->rect);
}

void Keyboard::Render()
{
    for(unsigned i = 0; i < KEYS_NUM; i++)
        Keyboard::keys[i].Render();
}

void Keyboard::Init()
{
    Keyboard::isActive = true;
    current_selected = 0;

    Keyboard::rect.h = System::letter_rect[0].h * 3;
    Keyboard::rect.w = System::letter_rect[0].w * 26;
    Keyboard::rect.x = System::Screen::Width / 2  - Keyboard::rect.w / 4;
    Keyboard::rect.y = System::Screen::Height - Keyboard::rect.h - 20;

    for(unsigned i = 0; i < KEYS_NUM; i++)
    {
        Keyboard::keys[i].symbol = System::letters[i];
        Keyboard::keys[i].texture = System::Textures::letters[i];
        Keyboard::keys[i].rect.w = System::letter_rect[i].w;
        Keyboard::keys[i].rect.h = System::letter_rect[i].h;
        if(i < 13)
        {
            Keyboard::keys[i].rect.x = Keyboard::rect.x + i * Keyboard::keys[i].rect.w;
            Keyboard::keys[i].rect.y = Keyboard::rect.y;
        }
        else
        {
            Keyboard::keys[i].rect.x = Keyboard::rect.x + ( ( 13 - i ) * -1 ) * Keyboard::keys[i].rect.w;
            Keyboard::keys[i].rect.y = Keyboard::rect.y + Keyboard::keys[i].rect.h;
        }
    }
    TTF_Font *tmp_font = TTF_OpenFont("Resources/Fonts/invaders.ttf", 60);
    Keyboard::keys[current_selected].texture = System::CreateTextTexture(System::letters[current_selected] + " ", tmp_font, color_selected);
}

int Keyboard::Navigate()
{
    TTF_Font *tmp_font = TTF_OpenFont("Resources/Fonts/invaders.ttf", 60);

    //Un-mark the previous selected key
    Keyboard::keys[current_selected].texture = System::Textures::letters[current_selected];

    if(System::event.key.keysym.sym == SDLK_LEFT && current_selected > 0)
        current_selected--;
    if(System::event.key.keysym.sym == SDLK_RIGHT && current_selected < KEYS_NUM - 1)
        current_selected++;
    if(System::event.key.keysym.sym == SDLK_UP && current_selected > 12)
        current_selected -= 13;
    if(System::event.key.keysym.sym == SDLK_DOWN && current_selected < 13)
        current_selected += 13;

    //Mark the new selected key
    Keyboard::keys[current_selected].texture = System::CreateTextTexture(System::letters[current_selected] + " ", tmp_font, color_selected);

    if(System::event.key.keysym.sym == SDLK_SPACE)
        return 0;
}

char Keyboard::GetKey()
{
    return Keyboard::keys[current_selected].symbol[0];
}
