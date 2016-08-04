#ifndef ALIENSMANAGER_H_INCLUDED
#define ALIENSMANAGER_H_INCLUDED

#include "Alien.h"
#include <vector>
<<<<<<< HEAD
=======
#include "../Game/GameOverWindow.h"
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

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
<<<<<<< HEAD
=======
        static void FreeAllAliens();
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

    private:
        static bool isAlienHitTheWall;
        static void ChangeTheDirection();
        static int direction;
        static int framesForMovement;
        static int currentFrame;
};

#endif // ALIENSMANAGER_H_INCLUDED
