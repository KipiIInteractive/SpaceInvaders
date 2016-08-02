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
    static bool gameOver;

    static bool needToResetClassicGame;
    static bool needToResetSurvivalGame;

    static string currentGameMode;

    static void startClassicGame();
    static void startSurvivalGame();

    static void resetClassicGame();
    static void resetSurvivalGame();
    static void shutdownGame();
};
#endif // GAMEHANDLER_H_INCLUDED
