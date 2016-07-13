#ifndef FPS_CONTROLLER_H_INCLUDED
#define FPS_CONTROLLER_H_INCLUDED

#include <SDL.h>

class FPS_Controller
{
    public:
        FPS_Controller(int fps);
        void SetTestTick();
        void Delay();

    private:
        int fps;
        int delayCoefficient;
        int testTick;
        int currentTick;
};

#endif // FPS_CONTROLLER_H_INCLUDED
