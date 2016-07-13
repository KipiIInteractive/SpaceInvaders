#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include "Texture.h"
#include "Direction.h"

class GameObject {
protected:
    Texture _GOTexture;
    SDL_Rect _GORect;
    int _GOVelocity;
    Direction _GODirection;
    bool _GOCollidedWithScreen;
public:
    GameObject();
    virtual ~GameObject();

    void setPosition(int x, int y);
    int getX();
    int getY();

    void setVelocity(int x);
    int getVelocity();

    void setWidth(int w);
    void setHeight(int h);
    int getWidth();
    int getHeight();

    void setMovementDirection(Direction dir);
    Direction getMovementDirection();

    void checkAndHandleCollisionWithScreen();
    bool hasCollidedWithScreen();

    virtual void update() = 0;

    void render();
};

#endif // GAMEOBJECT_H_INCLUDED
