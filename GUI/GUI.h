#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include <SDL.h>
#include "../System/System.h"
using namespace std;

class GUI
{
    public:
        GUI();
        ~GUI();

        int GetX();
        int GetY();
        int GetWidth();
        int GetHeight();

        int mouseX, mouseY;

        void SetX(int x);
        void SetY(int y);
        void SetWidth(int width);
        void SetHeight(int height);

        void SetTexture(string texturePath);
        void SetHoverTexture(string hoverTexturePath);

        bool isHover();
        bool isClicked();
        bool click;

        SDL_Rect rect;
        SDL_Texture *texture;
        SDL_Texture *hoverTexture;

        void Render();
};


#endif // GUI_H_INCLUDED
