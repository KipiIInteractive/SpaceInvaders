#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "GameObject.h"

class Player : public GameObject {
private:
    int _PLives;
    bool _PCanShoot;
    bool _PIsToShoot;
    int _PScore;
public:
    Player(Texture t, int lives);

    int getLives();
    void decreaseLives();

    bool isToShooT();
    void setIsToShooT(bool b);
    void setCanShooT(bool b);

    void addToScore(int points);
    int getScore();

    void handleEvents(SDL_Event *e);

    void update();
};

#endif // PLAYER_H_INCLUDED
