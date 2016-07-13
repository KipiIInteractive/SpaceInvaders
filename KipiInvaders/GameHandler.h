#ifndef GAMEHANDLER_H_INCLUDED
#define GAMEHANDLER_H_INCLUDED

#include "GameObjectGenerator.h"
#include "GameObjectRenderer.h"
#include "GameObjectHandler.h"
#include "GameObjectCollision.h"
#include "MenuResources.h"
#include "LevelManager.h"

class GameHandler {
public:
    static void startClassicGame();
    static void startSurvivalGame();

    static void handleClassicGameEvents(SDL_Event* e);
    static void handleSurvivalGameEvents(SDL_Event* e);

    static void resetGame();
    static void shutdownGame();
};
#endif // GAMEHANDLER_H_INCLUDED
