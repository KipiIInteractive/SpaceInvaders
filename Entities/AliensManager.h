#ifndef ALIENSMANAGER_H_INCLUDED
#define ALIENSMANAGER_H_INCLUDED

#include "Alien.h"
#include <vector>
#include "../Game/GameOverWindow.h"

class AliensManager
{
    public:
        static int number;
        static int movementSpeed;
        static int shootingPowerCoefficient;

        static void RenderAll();
        static void Move();

        static void AddNewAlien(int type, int pos_x, int pos_y);
        static std::vector<Alien*> allAliens;
        static void FreeAllAliens();

        static SDL_Rect dead_rect;

    private:
        static bool isAlienHitTheWall;
        static void ChangeTheDirection();
        static int direction;
        static int framesForMovement;
        static int currentFrame;
};

#endif // ALIENSMANAGER_H_INCLUDED
