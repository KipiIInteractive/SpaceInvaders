#ifndef MENUHANDLER_H_INCLUDED
#define MENUHANDLER_H_INCLUDED

#include <SDL.h>
#include <list>
#include "MenuResources.h"
#include "PlayerResources.h"

class MenuHandler {
public:
    //Renders game menu info(buttons, background)
    static void showMainMenu();
    static void showRankingMenu();
    static void showControlsMenu();
    static void showGameModesMenu();
    static void showPauseMenu();
    static void showGameOverMenu();
    static void showSubmitNameAndScoreMenu();
    static void showRankingMenuWithPlayerScore();

    //Event handling functions for different menus
    static void handleMainMenuEvents(SDL_Event *e);
    static void handleGameModesMenuEvents(SDL_Event *e);
    static void handleControlsMenuEvents(SDL_Event *e);
    static void handleRankingMenuEvents(SDL_Event *e);
    static void handlePauseMenuEvents(SDL_Event *e);
    static void handleGameOverMenuEvents(SDL_Event *e);
    static void handleSubmitNameAndScoreMenuEvents(SDL_Event *e);
    static void handleRankingMenuWithPlayerScoreEvents(SDL_Event *e);

    //does what it says
    static bool updateRankingMenu(list<string>& pNames, list<int>& pScores);
};
#endif // MENUHANDLER_H_INCLUDED
