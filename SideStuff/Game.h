#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "../level_management/LevelManager.h"
#include "../Entities/AliensManager.h"

class Game
{
    public:
        static void StartGame();

        static void RenderEverything();
};

#endif // GAME_H_INCLUDED
