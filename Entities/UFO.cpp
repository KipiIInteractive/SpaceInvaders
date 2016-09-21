#include "UFO.h"

bool UFO::isAlive;
int UFO::speed;
int UFO::pointsWorth;
SDL_Texture *UFO::texture = NULL;
SDL_Rect UFO::rect;

void UFO::Init()
{
    UFO::isAlive = false;
    UFO::texture = System::Textures::UFO;
    int screenWidthUfoWidthRatio = 15/1;
    UFO::rect.w = System::Screen::Width / screenWidthUfoWidthRatio;
    float ufoWidthUfoHeightRatio = 2.32;
    UFO::rect.h = UFO::rect.w / ufoWidthUfoHeightRatio;
    UFO::rect.x = 0;
    float ufoYIndentationFromScreenTopDivisor = 9.5;
    UFO::rect.y = Game::Pannel.h / ufoYIndentationFromScreenTopDivisor;
    int ufoMovementSpeedDivisor = 20;
    UFO::speed = UFO::rect.w / ufoMovementSpeedDivisor;
    srand(time(0));
}

void UFO::Spawn()
{
    if(UFO::isAlive == false)
    {
        // 1% UFO to spawn ( 1 in 100 chance for the UFO to spawn )
        if(rand() % 100  == 1)
        {
            float ufoYIndentationFromScreenTopDivisor = 9.5;
            UFO::rect.x = Game::Pannel.x - UFO::rect.w;
            UFO::rect.y = Game::Pannel.h / ufoYIndentationFromScreenTopDivisor;
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
    if(UFO::isAlive) {
        SDL_RenderCopy(System::renderer, UFO::texture, NULL, &UFO::rect);
    }
}

void UFO::Update()
{
    if(UFO::isAlive)
    {
        if(UFO::rect.x >= Game::Pannel.x + Game::Pannel.w) {
            UFO::isAlive = false;
        }

        UFO::rect.x += UFO::speed;
    }
}

void UFO::Die()
{
    SoundManager::Play(SoundManager::Sounds::AlienKilled);
    UFO::isAlive = false;
    UFO::rect.x = 0;

    int randNum = rand() % 3;
    if(randNum == 0) {
        UFO::pointsWorth = 50;
    }
    else if(randNum == 1) {
        UFO::pointsWorth = 100;
    }
    else {
        UFO::pointsWorth = 150;
    }
}
