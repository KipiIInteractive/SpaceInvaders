#ifndef BARRIER_H_INCLUDED
#define BARRIER_H_INCLUDED

#include <SDL.h>
#include "../System/System.h"

class Barrier
{
    public:
        Barrier(std::string texturePath, int pos_x, int pos_y);
        ~Barrier();

        void SetX(int x); int GetX();
        void SetY(int y); int GetY();
        void SetWidth(int w); int GetWidth();
        void SetHeigth(int h); int GetHeigth();

        void SetTexture(SDL_Texture *texture);

        int hitsTaken;
        void Render();
    private:
        SDL_Rect rect;
        SDL_Texture *texture;
};

#endif // BARRIER_H_INCLUDED
