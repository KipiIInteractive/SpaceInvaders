#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED

#include "Entity.h"
#include "AlienType.h"
#include <time.h>

class Alien : public Entity
{
        bool hasBeenKilled;
        int timeDeadInSeconds;
    public:
        Alien(AlienType alienType, int xPos, int yPos);

        void Render();
        AlienType type;

        SDL_Rect frame;
        int pointsWorth;

        static int timeToBeRenderedDeadInSeconds;

        bool isAlive;
        void setHasBeenKilled(bool state);

        void Shoot();
};

#endif // ALIEN_H_INCLUDED
