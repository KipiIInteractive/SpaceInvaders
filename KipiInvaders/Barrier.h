#ifndef BARRIER_H_INCLUDED
#define BARRIER_H_INCLUDED

#include "Texture.h"
#include "BulletResources.h"

class Barrier {
    Texture _BTopLeftCorner;
    SDL_Point _BTopLeftCornerPos;
    int _BTopLeftCornerHitCounter;

    Texture _BTopRightCorner;
    SDL_Point _BTopRightCornerPos;
    int _BTopRightCornerHitCounter;

    Texture _BBottomLeft;
    SDL_Point _BBottomLeftPos;
    int _BBottomLeftHitCounter;

    Texture _BBottomRight;
    SDL_Point _BBottomRightPos;
    int _BBottomRightHitCounter;

    Texture _BMiddleLeft;
    SDL_Point _BMiddleLeftPos;
    int _BMiddleLeftHitCounter;

    Texture _BMiddleRight;
    SDL_Point _BMiddleRightPos;
    int _BMiddleRightHitCounter;

    Texture _BInnerTopLeft;
    SDL_Point _BInnerTopLeftPos;
    int _BInnerTopLeftHitCounter;

    Texture _BInnerTopRight;
    SDL_Point _BInnerTopRightPos;
    int _BInnerTopRightHitCounter;

    Texture _BInnerBottomLeft;
    SDL_Point _BInnerBottomLeftPos;
    int _BInnerBottomLeftHitCounter;

    Texture _BInnerBottomRight;
    SDL_Point _BInnerBottomRightPos;
    int _BInnerBottomRightHitCounter;

    SDL_Rect _BRect;
    bool destroyed;
public:
    Barrier();

    bool loadInitialTextures();

    void setDimensions();
    int getWidth();
    int getHeight();

    void setPosition(int x, int y);
    int getX();
    int getY();

    void resetHitCounters();

    bool isDestroyed();

    void update();

    void checkAndHandleCollisionWithBullets();

    void render();
};

#endif // BARRIER_H_INCLUDED
