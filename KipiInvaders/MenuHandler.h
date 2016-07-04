#ifndef MENUHANDLER_H_INCLUDED
#define MENUHANDLER_H_INCLUDED

#include <SDL.h>
#include "Resources.h"

class MenuHandler {
public:
    //Renders game menu info(buttons, background)
    static void showMainMenu();
    static void showOptionsMenu();
    static void showControlsMenu();
    static void showGameModesMenu();

    //Event handling functions for different menus
    static void handleMainMenuEvents(SDL_Event *e);
    static void handleGameModesMenuEvents(SDL_Event *e);
    static void handleControlsMenuEvents(SDL_Event *e);
    static void handleOptionsMenuEvents(SDL_Event *e);

    static void returnToPreviousMenu(Button buttonClicked);

};
#endif // MENUHANDLER_H_INCLUDED
