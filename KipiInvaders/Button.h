#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "Texture.h"

class Button {
protected:
    Texture _BTexture;
    SDL_Rect _BPosition;
    SDL_Color _BColor;
    bool pressed;
    bool active;
    bool activateNextButton;
    bool activatePreviousButton;
    static bool currentOptionHasBeenChanged;
public:
    Button();

    static bool isSpaceReleased;

    //Button Initialization
    bool loadButtonFromFile(string path);
    bool loadButtonFromText(string text, SDL_Color color);
    void setDimensions(int x, int y, int w, int h);

    void handleEvents(SDL_Event* e);

    int getWidth();
    int getHeight();

    int getY();
    int getX();

    bool hasBeenPressed();
    void setHasBeenPressed(bool b);

    void setIsActive(bool b);
    bool isActive();

    bool nextButtonIsToBeActivated();
    bool previousButtonIsToBeActivated();

    void render();

    void free();
};

#endif // BUTTON_H_INCLUDED
