#include "FPS_Controller.h"

FPS_Controller::FPS_Controller(int fps)
{
    this->fps = fps;
    this->delayCoefficient = 1000 / fps;
    this->testTick = 0;
    this->currentTick = 0;
}

void FPS_Controller::SetTestTick() { this->testTick = SDL_GetTicks(); }

void FPS_Controller::Delay()
{
    this->currentTick = SDL_GetTicks();
    if(this->delayCoefficient > (this->currentTick - this->testTick))
    {
        SDL_Delay( this->delayCoefficient - (this->currentTick - this->testTick) );
    }
}
