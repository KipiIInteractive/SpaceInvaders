#include "main.h"

int main(int argc, char *argv[])
{
    if(InitSDL::init()) {
        if(LoadMedia::load()) {
            GameLoop::run();
        }
        ShutdownSDL::shutdown();
    }
    return 0;
}
