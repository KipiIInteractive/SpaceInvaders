#ifndef LABEL_H_INCLUDED
#define LABEL_H_INCLUDED

#include "GUI.h"

class Label : public GUI
{
    public:
        Label();
        ~Label();
        void SetText(string text);
        void SetFont(TTF_Font *font);
        void SetColor(int r, int g, int b);

    private:
        string text;
        TTF_Font *font;
        SDL_Color color;
};

#endif // LABEL_H_INCLUDED
