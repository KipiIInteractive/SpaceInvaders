#include "FPS_Controller.h"

FPS_Controller::FPS_Controller(unsigned fps)
{
    this->fps = fps;
    this->delayCoefficient = 1000 / fps;
    this->startTick = 0;
    this->currentTick = 0;
}

void FPS_Controller::SetTestTick() { this->startTick = SDL_GetTicks(); }

void FPS_Controller::Delay()
{
    this->currentTick = SDL_GetTicks();
    if(this->delayCoefficient > (this->currentTick - this->startTick))
    {
        SDL_Delay( this->delayCoefficient - (this->currentTick - this->startTick) );
    }
}
