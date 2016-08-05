#ifndef FPS_CONTROLLER_H_INCLUDED
#define FPS_CONTROLLER_H_INCLUDED

#include <SDL.h>

class FPS_Controller
{
    public:
        FPS_Controller(unsigned fps);
        void SetTestTick();
        void Delay();

    private:
        unsigned fps;
        unsigned delayCoefficient;
        unsigned testTick;
        unsigned currentTick;
};

#endif // FPS_CONTROLLER_H_INCLUDED
