#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

#include "../System/System.h"

#define KEYS_NUM 26

class Key
{
    public:
        void Render();

        SDL_Rect rect;
        string symbol;
        SDL_Texture *texture;
};


class Keyboard
{
    public:
        static void Init();
        static void Render();
        static bool Navigate();
        static bool isActive;
        static char GetKey();
        static SDL_Rect rect;

    private:
        static Key keys[KEYS_NUM];
};

#endif // KEYBOARD_H_INCLUDED
