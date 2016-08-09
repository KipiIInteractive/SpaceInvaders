#include "Barrier.h"
#include "../Game/Game.h"

Barrier::Barrier(int xPos, int yPos)
{
    int pannelWidthBarrierWidthRatio = 11/1;
    this->rect.w = Game::Pannel.w / pannelWidthBarrierWidthRatio;
    float barrierWidthBarrierHeightRatio = 1.5;
    this->rect.h = this->rect.w / barrierWidthBarrierHeightRatio;
    this->rect.x = xPos;
    this->rect.y = yPos;

    //Sets the pos of all barrier parts
    this->topLeftPartPos = {xPos, yPos, this->rect.w / 3, this->rect.h / 3};
    this->topMiddlePartPos = {xPos + this->topLeftPartPos.w, yPos, this->rect.w / 3, this->rect.h / 3};
    this->topRightPartPos = {xPos + this->topMiddlePartPos.w * 2, yPos, this->rect.w / 3, this->rect.h / 3};

    this->centerLeftPartPos = {xPos, yPos + this->topLeftPartPos.h, this->rect.w / 3, this->rect.h / 3};
    this->centerMiddlePartPos = {xPos + this->centerLeftPartPos.w, yPos + this->topMiddlePartPos.h, this->rect.w / 3, this->rect.h / 3};
    this->centerRightPartPos = {xPos + this->centerMiddlePartPos.w * 2, yPos + this->topMiddlePartPos.h, this->rect.w / 3, this->rect.h / 3};

    this->bottomLeftPartPos = {xPos, yPos + this->centerLeftPartPos.h * 2, this->rect.w / 3, this->rect.h / 3};
    this->bottomMiddlePartPos = {xPos + this->bottomLeftPartPos.w, yPos + this->centerLeftPartPos.h * 2, this->rect.w / 3, this->rect.h / 3};
    this->bottomRightPartPos = {xPos + this->bottomLeftPartPos.w * 2, yPos + this->centerLeftPartPos.h * 2, this->rect.w / 3, this->rect.h / 3};


    //Initialize the bottom-left corner state
    this->bottomLeftPartTexture = System::Textures::BarrierBottomLeft;
    SDL_QueryTexture(this->bottomLeftPartTexture, NULL, NULL, &this->bottomLeftPartState.w, &this->bottomLeftPartState.h);
    this->bottomLeftPartState.w /= 4;
    this->bottomLeftPartState.x = 0;
    this->bottomLeftPartState.y = 0;
    this->hitsTakenBottomLeftPart = 0;

    //Initialize the bottom-right corner state
    this->bottomRightPartTexture = System::Textures::BarrierBottomRight;
    SDL_QueryTexture(this->bottomRightPartTexture, NULL, NULL, &this->bottomRightPartState.w, &this->bottomRightPartState.h);
    this->bottomRightPartState.w /= 4;
    this->bottomRightPartState.x = 0;
    this->bottomRightPartState.y = 0;
    this->hitsTakenBottomRightPart = 0;

    //Initialize the bottom-middle block state
    this->bottomMiddlePartTexture = System::Textures::BarrierBottomMiddle;
    SDL_QueryTexture(this->bottomMiddlePartTexture, NULL, NULL, &this->bottomMiddlePartState.w, &this->bottomMiddlePartState.h);
    this->bottomMiddlePartState.w /= 4;
    this->bottomMiddlePartState.x = 0;
    this->bottomMiddlePartState.y = 0;
    this->hitsTakenBottomMiddlePart = 0;

    //Initialize the center-left corner state
    this->centerLeftPartTexture = System::Textures::BarrierCenterLeft;
    SDL_QueryTexture(this->centerLeftPartTexture, NULL, NULL, &this->centerLeftPartState.w, &this->centerLeftPartState.h);
    this->centerLeftPartState.w /= 4;
    this->centerLeftPartState.x = 0;
    this->centerLeftPartState.y = 0;
    this->hitsTakenCenterLeftPart = 0;

    //Initialize the center-middle block state
    this->centerMiddlePartTexture = System::Textures::BarrierCenterMiddle;
    SDL_QueryTexture(this->centerMiddlePartTexture, NULL, NULL, &this->centerMiddlePartState.w, &this->centerMiddlePartState.h);
    this->centerMiddlePartState.w /= 4;
    this->centerMiddlePartState.x = 0;
    this->centerMiddlePartState.y = 0;
    this->hitsTakenCenterMiddlePart = 0;

    //Initialize the center-right corner state
    this->centerRightPartTexture = System::Textures::BarrierCenterRight;
    SDL_QueryTexture(this->centerRightPartTexture, NULL, NULL, &this->centerRightPartState.w, &this->centerRightPartState.h);
    this->centerRightPartState.w /= 4;
    this->centerRightPartState.x = 0;
    this->centerRightPartState.y = 0;
    this->hitsTakenCenterRightPart = 0;

    //Initialize the top-left corner state
    this->topLeftPartTexture = System::Textures::BarrierTopLeft;
    SDL_QueryTexture(this->topLeftPartTexture, NULL, NULL, &this->topLeftPartState.w, &this->topLeftPartState.h);
    this->topLeftPartState.w /= 4;
    this->topLeftPartState.x = 0;
    this->topLeftPartState.y = 0;
    this->hitsTakenTopLeftPart = 0;

    //Initialize the top-middle block state
    this->topMiddlePartTexture = System::Textures::BarrierTopMiddle;
    SDL_QueryTexture(this->topMiddlePartTexture, NULL, NULL, &this->topMiddlePartState.w, &this->topMiddlePartState.h);
    this->topMiddlePartState.w /= 4;
    this->topMiddlePartState.x = 0;
    this->topMiddlePartState.y = 0;
    this->hitsTakenTopMiddlePart = 0;

    //Initialize the top-right corner state
    this->topRightPartTexture = System::Textures::BarrierTopRight;
    SDL_QueryTexture(this->topRightPartTexture, NULL, NULL, &this->topRightPartState.w, &this->topRightPartState.h);
    this->topRightPartState.w /= 4;
    this->topRightPartState.x = 0;
    this->topRightPartState.y = 0;
    this->hitsTakenTopRightPart = 0;
}

void Barrier::SetX(int x) { this->rect.x = x; }
int Barrier::GetX() { return this->rect.x; }

void Barrier::SetY(int y) { this->rect.y = y; }
int Barrier::GetY() { return this->rect.y; }

void Barrier::SetWidth(int w) { this->rect.w = w; }
int Barrier::GetWidth() { return this->rect.w; }

void Barrier::SetHeigth(int h) { this->rect.h = h; }
int Barrier::GetHeigth() { return this->rect.h; }

void Barrier::Update()
{
    this->topLeftPartState.x = this->topLeftPartState.w * hitsTakenTopLeftPart;
    if(hitsTakenTopLeftPart >= 4)
    {
        this->topLeftPartPos.x = 0; this->topLeftPartPos.y = 0;
        this->topLeftPartPos.w = 0; this->topLeftPartPos.h = 0;
    }

    this->topMiddlePartState.x = this->topMiddlePartState.w * hitsTakenTopMiddlePart;
    if(hitsTakenTopMiddlePart >= 4)
    {
        this->topMiddlePartPos.x = 0; this->topMiddlePartPos.y = 0;
        this->topMiddlePartPos.w = 0; this->topMiddlePartPos.h = 0;
    }

    this->topRightPartState.x = this->topRightPartState.w * hitsTakenTopRightPart;
    if(hitsTakenTopRightPart >= 4)
    {
        this->topRightPartPos.x = 0; this->topRightPartPos.y = 0;
        this->topRightPartPos.w = 0; this->topRightPartPos.h = 0;
    }

    this->centerLeftPartState.x = this->centerLeftPartState.w * hitsTakenCenterLeftPart;
    if(hitsTakenCenterLeftPart >= 4)
    {
        this->centerLeftPartPos.x = 0; this->centerLeftPartPos.y = 0;
        this->centerLeftPartPos.w = 0; this->centerLeftPartPos.h = 0;
    }

    this->centerMiddlePartState.x = this->centerMiddlePartState.w * hitsTakenCenterMiddlePart;
    if(hitsTakenCenterMiddlePart >= 4)
    {
        this->centerMiddlePartPos.x = 0; this->centerMiddlePartPos.y = 0;
        this->centerMiddlePartPos.w = 0; this->centerMiddlePartPos.h = 0;
    }

    this->centerRightPartState.x = this->centerRightPartState.w * hitsTakenCenterRightPart;
    if(hitsTakenCenterRightPart >= 4)
    {
        this->centerRightPartPos.x = 0; this->centerRightPartPos.y = 0;
        this->centerRightPartPos.w = 0; this->centerRightPartPos.h = 0;
    }

    this->bottomLeftPartState.x = this->bottomLeftPartState.w * hitsTakenBottomLeftPart;
    if(hitsTakenBottomLeftPart >= 4)
    {
        this->bottomLeftPartPos.x = 0; this->bottomLeftPartPos.y = 0;
        this->bottomLeftPartPos.w = 0; this->bottomLeftPartPos.h = 0;
    }

    this->bottomMiddlePartState.x = this->bottomMiddlePartState.w * hitsTakenBottomMiddlePart;
    if(hitsTakenBottomMiddlePart >= 4)
    {
        this->bottomMiddlePartPos.x = 0; this->bottomMiddlePartPos.y = 0;
        this->bottomMiddlePartPos.w = 0; this->bottomMiddlePartPos.h = 0;
    }

    this->bottomRightPartState.x = this->bottomRightPartState.w * hitsTakenBottomRightPart;
    if(hitsTakenBottomRightPart >= 4)
    {
        this->bottomRightPartPos.x = 0; this->bottomRightPartPos.y = 0;
        this->bottomRightPartPos.w = 0; this->bottomRightPartPos.h = 0;
    }
}

void Barrier::Render()
{
    SDL_RenderCopy(System::renderer, this->bottomLeftPartTexture, &this->bottomLeftPartState, &this->bottomLeftPartPos);
    SDL_RenderCopy(System::renderer, this->bottomRightPartTexture, &this->bottomRightPartState, &this->bottomRightPartPos);
    SDL_RenderCopy(System::renderer, this->bottomMiddlePartTexture, &this->bottomMiddlePartState, &this->bottomMiddlePartPos);
    SDL_RenderCopy(System::renderer, this->centerLeftPartTexture, &this->centerLeftPartState, &this->centerLeftPartPos);
    SDL_RenderCopy(System::renderer, this->centerMiddlePartTexture, &this->centerMiddlePartState, &this->centerMiddlePartPos);
    SDL_RenderCopy(System::renderer, this->centerRightPartTexture, &this->centerRightPartState, &this->centerRightPartPos);
    SDL_RenderCopy(System::renderer, this->topLeftPartTexture, &this->topLeftPartState, &this->topLeftPartPos);
    SDL_RenderCopy(System::renderer, this->topMiddlePartTexture, &this->topMiddlePartState, &this->topMiddlePartPos);
    SDL_RenderCopy(System::renderer, this->topRightPartTexture, &this->topRightPartState, &this->topRightPartPos);
}
