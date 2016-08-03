#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <string>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include "System.h"

using namespace std;

class Texture {
    SDL_Texture* _Texture;
    SDL_Rect* _TClip;
    int _THeight, _TWidth;
    string _TText;
public:
    Texture();
    ~Texture();

    bool loadFromFile(string path);

    bool loadFromRenderedText(string str, SDL_Color color, TTF_Font* font = NULL);

    void setColor(SDL_Color color);

    string getText();

    void setClip(SDL_Rect* clip = NULL);

    void setWidth(int w);

    void setHeight(int h);

    int getWidth();

    int getHeight();

    SDL_Texture* getTexture();

    void applyTexture(SDL_Texture *pt);

    void render(int x, int y, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE, double angle = 0.0, SDL_Point* center = NULL);

    void free();
};
#endif // TEXTURE_H_INCLUDED
