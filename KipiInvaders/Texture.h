#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include "main.h"

class Texture {
    SDL_Texture* _Texture;
    int _THeight, _TWidth;
    string _TText;
public:
    Texture();

    ~Texture();

    bool loadFromFile(string path);

    bool loadFromRenderedText(string str, SDL_Color color, TTF_Font* font = NULL);

    void setColor(SDL_Color color);

    string getText();

    int getHeight();

    int getWidth();

    void render(int x, int y, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE, double angle = 0.0, SDL_Point* center = NULL);

    void free();
};
#endif // TEXTURE_H_INCLUDED
