#include "main.h"
#include "InitSDL.h"
#include "LoadMedia.h"
#include "GameLoop.h"

//FPS
const int AVG_FPS = 60;
const int TIME_PER_FRAME = 1000 / AVG_FPS;

int main(int argc, char *argv[])
{
    if(InitSDL::init()) {
        if(LoadMedia::load()) {
            GameLoop::run();
        }
    }
    return 0;
}
