#ifndef UFO_H_INCLUDED
#define UFO_H_INCLUDED

#include "../System/System.h"
#include "../Game/Game.h"

class UFO
{
    public:
        static void Init();
        static bool Spown();
        static void Render();
        static void Update();
        static void Die();

        static SDL_Rect rect;
        static int score;

    private:
        static bool isAlive;
        static int speed;
        static SDL_Texture *texture;
};

#endif // UFO_H_INCLUDED
