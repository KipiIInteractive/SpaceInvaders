#ifndef INITSDL_H_INCLUDED
#define INITSDL_H_INCLUDED

#include <iostream>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include "System.h"

using namespace std;

class InitSDL {
public:
    static bool init();
};



#endif // INITSDL_H_INCLUDED
