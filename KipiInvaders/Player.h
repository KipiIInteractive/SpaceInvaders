#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "GameObject.h"

class Player : public GameObject {
private:
    int _PLives;
public:
    Player(Texture t, int lives);

    int getLives();

    void handleEvents(SDL_Event *e);

    void update();
};

#endif // PLAYER_H_INCLUDED
