#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include "main.h"
#include "Texture.h"

class Background {
private:
    Texture _BTexture;
    SDL_Rect _BClip;
public:
    Background();
    ~Background();

    //Background initialization
    bool loadBackgroundFromFile(string path);
    void setBackgroundClip(int x, int y, int w, int h);

    //Shows background
    void render(int x, int y);
};


#endif // BACKGROUND_H_INCLUDED
