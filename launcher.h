#ifndef LAUNCHER_H_INCLUDED
#define LAUNCHER_H_INCLUDE

//Include the 'brains' of the game
#include "System/System.h"
#include "profile_management/ProfileManager.h"
#include "sounds_management/SoundManager.h"
#include "level_management/LevelManager.h"

#include "Entities/Player.h"
#include "Entities/UFO.h"

//Include the scenes for the game
#include "Game/Game.h"
#include "Game/NameSelectionWindow.h"
#include "Game/GameOverWindow.h"
#include "Game/WinWindow.h"
#include "Game/RankList.h"

//Include the GUI parts for the start window
#include "GUI/Keyboard.h"
#include "GUI/Label.h"

void InitEverything();
void LoadTheTextures();
void LoadTheFonts();
void FreeEverything();

//-------------------------Start window stuff
//Macros for the Start window menu options indexes
#define OPTION_START_CLASSIC_GAME 0
#define OPTION_START_SURVIVAL_GAME 1
#define OPTION_SEE_RANKLIST 2
#define OPTION_QUIT 3
const int numOfOptions = 4;
int activeOption = OPTION_START_CLASSIC_GAME; //By default the marked option is 'Classic' option

bool isStartWindowActive;

Label titleText;
Label menuOptions[numOfOptions];

void MoveThroughTheStartWindowOptions();
void MarkTheActiveStartWindowOption();
void SelectStartWindowOption();
void RenderStartWindow();
void InitStartWindow();
void ShowStartWindow();


#endif // LAUNCHER_H_INCLUDED
