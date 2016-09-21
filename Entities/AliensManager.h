#ifndef AliensManager_H_INCLUDED
#define AliensManager_H_INCLUDED

#include "Alien.h"
#include <vector>
#include "../Game/GameOverWindow.h"

class AliensManager
{
    public:
        static int numAliens;
        static int aliensOnRow;
        static int movementSpeed;
        static int shootingPowerCoefficient;
        static int movementDelayFrames;

        static void RenderAll();
        static void Move();
        static bool allAliensAreDead();
        static int getRemainingAliens();

        static void AddNewAlien(AlienType type, int xPos, int yPos);
        static std::vector<Alien*> allAliens;
        static void FreeAllAliens();

        static SDL_Rect deadRect;

    private:
        static bool hasAlienHitTheWall;
        static void ChangeMovementDirection();
        static int movementDirection;
        static int currentMovementFrame;
        static int direction;
};

#endif // AliensManager_H_INCLUDED
