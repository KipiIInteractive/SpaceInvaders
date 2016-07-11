#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "Direction.h"
#include "GameResources.h"
#include "Texture.h"

using namespace std;

class Enemy {
private:
    Texture _ETexture;
    SDL_Rect _ERect;
    SDL_Point _EVelocity;
    Direction _EDirection;
    int _EPoints;
    bool _ECollidedWithScreen;
    bool _EAlive;
    bool _EShoot;
public:
    Enemy(Texture t, Direction dir, int points);
    ~Enemy();

    void setPosition(int x, int y);

    void setXVelocity(int x);
    void setYVelocity(int y);

    void setWidth(int w);
    void setHeight(int h);

    void setMovementDirection(Direction dir);

    void setHasCollidedWithScreen(bool b);

    void setIsAlive(bool b);

    int getX();
    int getY();

    int getWidth();
    int getHeight();

    Direction getMovementDirection();

    bool isAlive();

    bool isToShooT();

    bool hasCollidedWithScreen();

    void update();

    void checkCollisionWithScreen();

    void handleCollisionWithScreen();

    void render();
};


#endif // ENEMY_H_INCLUDED
