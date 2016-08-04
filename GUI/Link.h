#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED

#include "GUI.h"
#include <SDL_ttf.h>

class Link : public GUI
{
    public:
        Link();
        void SetText(string text);
        void SetColor(int r, int g, int b);
        void SetFont(TTF_Font *font);

    private:
        TTF_Font *font;
        string text;
        SDL_Color color;
        void Create();
};

#endif // LINK_H_INCLUDED
