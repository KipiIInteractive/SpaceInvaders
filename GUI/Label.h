#ifndef LABEL_H_INCLUDED
#define LABEL_H_INCLUDED

#include "GUI.h"

class Label : public GUI
{
    public:
        Label();
        ~Label();
        void SetText(string text);
        string GetText();
        void SetFont(TTF_Font *font);
        void SetColor(int r, int g, int b);
        TTF_Font *font;

    private:
        string text;
        SDL_Color color;
};

#endif // LABEL_H_INCLUDED
