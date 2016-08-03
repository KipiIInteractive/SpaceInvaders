#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "GameObject.h"

class Player : public GameObject {
private:
    int _PLives;
    bool _PCanShoot;
    bool _PIsToShoot;
    bool _PHasBeenHit;
    int _PScore;
public:
    Player(Texture& t, int lives);

    int getLives();
    void decreaseLives();
    void resetLives();

    bool isToShooT();
    void setIsToShooT(bool b);
    void setCanShooT(bool b);
    bool canShoot();

    void setHasBeenHit(bool b);
    bool hasBeenHit();

    void addToScore(int points);
    int getScore();
    void resetScore();

    void handleEvents(SDL_Event *e);

    void update();

    void renderWithTexture(Texture& t);
};

#endif // PLAYER_H_INCLUDED
