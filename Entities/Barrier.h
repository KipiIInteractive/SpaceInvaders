#ifndef BARRIER_H_INCLUDED
#define BARRIER_H_INCLUDED

#include <SDL2/SDL.h>
#include "../System/System.h"

class Barrier
{
    public:
        Barrier(int xPos, int yPos);

        void SetX(int x); int GetX();
        void SetY(int y); int GetY();
        void SetWidth(int w); int GetWidth();
        void SetHeigth(int h); int GetHeigth();

        void Update();
        void Render();

        SDL_Rect topLeftPartPos;
        SDL_Rect topLeftPartState;
        int hitsTakenTopLeftPart;
        SDL_Texture *topLeftPartTexture;

        SDL_Rect topMiddlePartPos;
        SDL_Rect topMiddlePartState;
        int hitsTakenTopMiddlePart;
        SDL_Texture *topMiddlePartTexture;

        SDL_Rect topRightPartPos;
        SDL_Rect topRightPartState;
        int hitsTakenTopRightPart;
        SDL_Texture *topRightPartTexture;

        SDL_Rect centerLeftPartPos;
        SDL_Rect centerLeftPartState;
        int hitsTakenCenterLeftPart;
        SDL_Texture *centerLeftPartTexture;

        SDL_Rect centerMiddlePartPos;
        SDL_Rect centerMiddlePartState;
        int hitsTakenCenterMiddlePart;
        SDL_Texture *centerMiddlePartTexture;

        SDL_Rect centerRightPartPos;
        SDL_Rect centerRightPartState;
        int hitsTakenCenterRightPart;
        SDL_Texture *centerRightPartTexture;

        SDL_Rect bottomLeftPartPos;
        SDL_Rect bottomLeftPartState;
        int hitsTakenBottomLeftPart;
        SDL_Texture *bottomLeftPartTexture;

        SDL_Rect bottomRightPartPos;
        SDL_Rect bottomRightPartState;
        int hitsTakenBottomRightPart;
        SDL_Texture *bottomRightPartTexture;

        SDL_Rect bottomMiddlePartPos;
        SDL_Rect bottomMiddlePartState;
        int hitsTakenBottomMiddlePart;
        SDL_Texture *bottomMiddlePartTexture;

    private:
        SDL_Rect rect;
        SDL_Texture *texture;
};

#endif // BARRIER_H_INCLUDED
