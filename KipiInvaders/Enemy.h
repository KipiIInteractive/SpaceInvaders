#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "Texture.h"

using namespace std;

class Enemy {
private:
    Texture _ETexture;
    SDL_Rect _ERect;
    SDL_Point _EVelocity;
public:
    Enemy();
    ~Enemy();

    bool loadFromFile(string path);

    void setPosition(int x, int y);

    void setXVelocity(int x);
    void setYVelocity(int y);

    void setWidth(int w);
    void setHeight(int h);

    int getX();
    int getY();

    int getWidth();
    int getHeight();

    void render();
};


#endif // ENEMY_H_INCLUDED
