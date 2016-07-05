#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "Texture.h"
#include "Direction.h"

using namespace std;

class Enemy {
private:
    bool _ECollidedWithScreen;
    Texture _ETexture;
    SDL_Rect _ERect;
    SDL_Point _EVelocity;
    Direction _EDirection;
public:
    Enemy();
    ~Enemy();

    bool loadFromFile(string path);

    void setPosition(int x, int y);

    void setXVelocity(int x);
    void setYVelocity(int y);

    void setWidth(int w);
    void setHeight(int h);

    void setMovementDirection(Direction dir);

    void setHasCollidedWithScreen(bool b);

    int getX();
    int getY();

    int getWidth();
    int getHeight();

    Direction getMovementDirection();

    bool hasCollidedWithScreen();

    void render();

    void update();

    void checkCollision();
};


#endif // ENEMY_H_INCLUDED
