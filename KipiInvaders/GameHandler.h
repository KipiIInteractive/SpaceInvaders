#ifndef GAMEHANDLER_H_INCLUDED
#define GAMEHANDLER_H_INCLUDED

#include <SDL.h>
#include "Resources.h"
#include "GameObjectGenerator.h"
#include "GameObjectRenderer.h"

class GameHandler {
public:
    static void startClassicGame();
    static void startSurvivalGame();

    static void handleClassicGameEvents(SDL_Event* e);
    static void handleSurvivalGameEvents(SDL_Event* e);
};
#endif // GAMEHANDLER_H_INCLUDED
