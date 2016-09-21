#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <SDL2/SDL.h>
#include "../System/System.h"

class Entity
{
    public:
        Entity();
        ~Entity();

        void SetX(int x); int GetX();
        void SetY(int y); int GetY();
        void SetWidth(int w); int GetWidth();
        void SetHeigth(int h); int GetHeigth();

        void SetMovementSpeed(int mSpeed);
        int GetMovementSpeed();

        void SetTexture(SDL_Texture *texture);

        bool isAlive;

        void Render();
        SDL_Rect rect;

    protected:
        SDL_Texture *texture;
        int movementSpeed;
};

#endif // ENTITY_H_INCLUDED
