#ifndef LAUNCHER_H_INCLUDED
#define LAUNCHER_H_INCLUDE

//Include the 'brains' of the game
#include "System/System.h"
#include "profile_managment/ProfileManager.h"
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
#define OPTION_START_GAME 0
#define OPTION_SEE_RANKLIST 1
#define OPTION_QUIT 2
const int num_of_options = 3;
int active_option = 0; //By default the marked option is 'Start new game'

bool start_window_is_active;

Label text_title;
Label text_options[num_of_options];

void StartWindow_MoveThroughTheOptions();
void StartWindow_MarkTheActiveOption();
void StartWindow_SelectOption();
void StartWindow_RenderWindow();
void StartWindow_Init();
void StartWindow_Show();


#endif // LAUNCHER_H_INCLUDED
