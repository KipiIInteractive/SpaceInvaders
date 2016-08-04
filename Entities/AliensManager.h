#ifndef ALIENSMANAGER_H_INCLUDED
#define ALIENSMANAGER_H_INCLUDED

#include "Alien.h"
#include <iostream>
#include <vector>

class AliensManager
{
    public:
        static int number;
        static int movementSpeed;
        static int shootingPowerCoefficient;

        static void RenderAll();
        static void Move();

        static void AddNewAlien(int type, int pos_x, int pos_y);

    private:
        static std::vector<Alien*> allAliens;
        static bool isAlienHitTheWall();
        static void ChangeTheDirection();
        static int direction;
        #define CURRENT_ALIEN AliensManager::allAliens[i]
};

#endif // ALIENSMANAGER_H_INCLUDED
