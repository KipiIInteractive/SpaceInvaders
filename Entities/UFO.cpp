#include "UFO.h"

bool UFO::isAlive;
int UFO::speed;
int UFO::score;
SDL_Texture *UFO::texture = NULL;
SDL_Rect UFO::rect;

void UFO::Init()
{
    UFO::isAlive = false;
    UFO::texture = System::Textures::UFO;
    UFO::rect.w = System::Screen::Width / 15;
    UFO::rect.h = UFO::rect.w / 2.32;
    UFO::rect.x = 0;
    UFO::rect.y = UFO::rect.y = Game::Pannel.h / 9.5;
    UFO::speed = UFO::rect.w / 11;
    srand(time(0));
}

bool UFO::Spown()
{
    if(UFO::isAlive == false)
    {
        if(rand() % 1000  == 654)
        {
            UFO::rect.x = Game::Pannel.x - UFO::rect.w;
            UFO::rect.y = Game::Pannel.h / 9.5;
            UFO::isAlive = true;
        }
    }
    else
    {
        UFO::Update();
    }
}

void UFO::Render()
{
    if(UFO::isAlive)
        SDL_RenderCopy(System::renderer, UFO::texture, NULL, &UFO::rect);
}

void UFO::Update()
{
    if(UFO::isAlive)
    {
        if(UFO::rect.x >= Game::Pannel.x + Game::Pannel.w)
            UFO::isAlive = false;

        UFO::rect.x += UFO::speed;
    }
}

void UFO::Die()
{
    SoundManager::Play(SoundManager::Sounds::KillAlien);
    UFO::isAlive = false;
    UFO::rect.x = 0;

    int rand_num = rand() % 10 + 1;
    if(rand_num % 2 == 0)
        UFO::score = 50;
    else
        UFO::score = 150;
}
