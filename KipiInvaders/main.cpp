#include "main.h"

int main(int argc, char *argv[])
{
    if(InitSDL::init()) {
        if(RankingSystem::init() && LoadMedia::load()) {
            GameLoop::run();
        }
        ShutdownSDL::shutdown();
    }
    return 0;
}
