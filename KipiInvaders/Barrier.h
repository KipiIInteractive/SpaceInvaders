#ifndef BARRIER_H_INCLUDED
#define BARRIER_H_INCLUDED

#include "Texture.h"

class Barrier {
    Texture _BTopLeftCorner;
    SDL_Point _BTopLeftCornerPos;

    Texture _BTopRightCorner;
    SDL_Point _BTopRightCornerPos;

    Texture _BBottomLeft;
    SDL_Point _BBottomLeftPos;

    Texture _BBottomRight;
    SDL_Point _BBottomRightPos;

    Texture _BMiddleLeft;
    SDL_Point _BMiddleLeftPos;

    Texture _BMiddleRight;
    SDL_Point _BMiddleRightPos;

    Texture _BInnerTopLeft;
    SDL_Point _BInnerTopLeftPos;

    Texture _BInnerTopRight;
    SDL_Point _BInnerTopRightPos;

    Texture _BInnerBottomLeft;
    SDL_Point _BInnerBottomLeftPos;

    Texture _BInnerBottomRight;
    SDL_Point _BInnerBottomRightPos;

    SDL_Rect _BRect;
public:
    Barrier();
    ~Barrier();

    bool loadInitialTextures();

    void setDimensions();
    int getWidth();
    int getHeight();

    void setPosition(int x, int y);
    int getX();
    int getY();

    void render();
};

#endif // BARRIER_H_INCLUDED
