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
<<<<<<< HEAD

    private:
        string text;
        TTF_Font *font;
=======
        TTF_Font *font;

    private:
        string text;
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
        SDL_Color color;
};

#endif // LABEL_H_INCLUDED
