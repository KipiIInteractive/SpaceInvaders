#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED

#include "Entity.h"

class Alien : public Entity
{
    public:
        Alien(int type, int pos_x, int pos_y);
        ~Alien();
        int type;
};

#endif // ALIEN_H_INCLUDED
