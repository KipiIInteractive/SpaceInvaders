#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "Texture.h"

class Button {
protected:
    Texture _BTexture;
    SDL_Rect _BClip;
    SDL_Rect _BPosition;
    SDL_Color _BColor;
    bool clicked;
public:
    Button();

    //Button Initialization
    bool loadButtonFromFile(string path);
    bool loadButtonFromText(string text, SDL_Color color);
    void setDimensions(int x, int y, int w, int h);
    void setClip(int x, int y, int w, int h);

    void handleEvents(SDL_Event* e);

    int getWidth();
    int getHeight();

    //func related to clicking
    bool isClicked();
    void click();
    void unclick();

    void render();

    void free();
};

#endif // BUTTON_H_INCLUDED
