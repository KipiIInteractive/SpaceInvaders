#ifndef INPUTFIELD_H_INCLUDED
#define INPUTFIELD_H_INCLUDED

#include "Texture.h"

class InputField {
    Texture _IFTexture;
    SDL_Rect _IFRect;
    string _IFText;
    Texture _IFTextTexture;
    bool isSpacePressed;
    bool isActive;
public:
    InputField();

    bool loadFromFile(string path);

    void setWidth(int w);
    void setHeight(int h);
    int getWidth();
    int getHeight();

    void setPosition(int x, int y);
    int getX();
    int getY();

    string getInput();

    void resetInput();

    bool spaceHasBeenPressed();

    void handleEvents(SDL_Event *e);

    void render();
};

#endif // INPUTFIELD_H_INCLUDED
