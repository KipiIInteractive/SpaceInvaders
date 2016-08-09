#include "Keyboard.h"

int currentSelectedKey;
bool Keyboard::isActive;
Key Keyboard::keys[KEYS_NUM];
SDL_Rect Keyboard::rect;
SDL_Color colorSelected = {255, 0, 0};

void Key::Render()
{
    SDL_RenderCopy(System::renderer, this->texture, NULL, &this->rect);
}

void Keyboard::Render()
{
    for(unsigned i = 0; i < KEYS_NUM; i++) {
        Keyboard::keys[i].Render();
    }
}

void Keyboard::Init()
{
    Keyboard::isActive = true;
    currentSelectedKey = 0;

    int alphabetLettersCount = 26;

    Keyboard::rect.h = System::letterRect[0].h * 3;
    Keyboard::rect.w = System::letterRect[0].w * alphabetLettersCount;
    Keyboard::rect.x = System::Screen::Width / 2  - Keyboard::rect.w / 4;
    Keyboard::rect.y = System::Screen::Height - Keyboard::rect.h - 20;

    for(unsigned i = 0; i < KEYS_NUM; i++)
    {
        Keyboard::keys[i].symbol = System::letters[i];
        Keyboard::keys[i].texture = System::Textures::letters[i];
        Keyboard::keys[i].rect.w = System::letterRect[i].w;
        Keyboard::keys[i].rect.h = System::letterRect[i].h;
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
    TTF_Font *tmpFont = TTF_OpenFont("Resources/Fonts/invaders.ttf", 60);
    Keyboard::keys[currentSelectedKey].texture = System::CreateTextTexture(System::letters[currentSelectedKey] + " ", tmpFont, colorSelected);
    TTF_CloseFont(tmpFont);
    tmpFont = NULL;
}

bool Keyboard::Navigate()
{
    TTF_Font *tmpFont = TTF_OpenFont("Resources/Fonts/invaders.ttf", 60);
    int numLettersOnRow  = 13;
    //Unmark the previous selected key
    SDL_DestroyTexture(Keyboard::keys[currentSelectedKey].texture);
    Keyboard::keys[currentSelectedKey].texture = NULL;
    Keyboard::keys[currentSelectedKey].texture = System::Textures::letters[currentSelectedKey];

    if(System::event.key.keysym.sym == SDLK_LEFT && currentSelectedKey > 0) {
        currentSelectedKey--;
    }
    if(System::event.key.keysym.sym == SDLK_RIGHT && currentSelectedKey < KEYS_NUM - 1) {
        currentSelectedKey++;
    }
    if(System::event.key.keysym.sym == SDLK_UP && currentSelectedKey > numLettersOnRow - 1) {
        currentSelectedKey -= numLettersOnRow;
    }
    if(System::event.key.keysym.sym == SDLK_DOWN && currentSelectedKey < numLettersOnRow) {
        currentSelectedKey += numLettersOnRow;
    }

    //Mark the new selected key
    Keyboard::keys[currentSelectedKey].texture = System::CreateTextTexture(System::letters[currentSelectedKey] + " ", tmpFont, colorSelected);
    TTF_CloseFont(tmpFont);
    tmpFont = NULL;
    if(System::event.key.keysym.sym == SDLK_SPACE) {
        return true;
    }
    else {
        return false;
    }
}

char Keyboard::GetKey()
{
    return Keyboard::keys[currentSelectedKey].symbol[0];
}
