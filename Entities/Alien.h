#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED

#include "Entity.h"
#include <time.h>

class Alien : public Entity
{
    public:
        Alien(int type, int pos_x, int pos_y);
        ~Alien();
        void Render();
        int type;

        SDL_Rect frame;
        int score;

        void Shoot();
};

#endif // ALIEN_H_INCLUDED
