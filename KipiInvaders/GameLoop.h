#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED

#include "main.h"

class GameLoop {
public:
    //Starts main game loop
    static void run();

    //Renders game menu info(buttons, background)
    static void showMainMenu();
    static void showOptionsMenu();
    static void showControlsMenu();
    static void showGameModesMenu();

    //Event handling functions for different menus
    static void handleGameModesMenuEvents(SDL_Event *e);
    static void handleControlsMenuEvents(SDL_Event *e);
    static void handleOptionsMenuEvents(SDL_Event *e);

    //Game modes
    static void startClassicGame();
    static void startSurvivalGame();

};


#endif // GAMELOOP_H_INCLUDED
