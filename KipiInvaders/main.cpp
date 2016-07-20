#include "main.h"

int main(int argc, char *argv[])
{
    if(InitSDL::init()) {
        if(LoadMedia::load() && RankingSystem::init()) {
            GameLoop::run();
        }
        ShutdownSDL::shutdown();
    }
    return 0;
}
