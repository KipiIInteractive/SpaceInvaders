#ifndef LAUNCHER_H_INCLUDED
<<<<<<< HEAD
#define LAUNCHER_H_INCLUDED

#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "profile_managment/ProfileManager.h"
#include "System/System.h"
#include "profile_managment/Log_in.h"
#include "profile_managment/Registration.h"
#include "level_management/LevelManager.h"
#include "Entities/Player.h"
#include "Game/Game.h"
#include "sounds_management/SoundManager.h"
#include "Game/GameOverWindow.h"

void InitEverything();
=======
#define LAUNCHER_H_INCLUDE

//Include the 'brains' of the game
#include "System/System.h"
#include "profile_managment/ProfileManager.h"
#include "sounds_management/SoundManager.h"
#include "level_management/LevelManager.h"

#include "Entities/Player.h"

//Include the scenes for the game
#include "Game/Game.h"
#include "Game/GameOverWindow.h"
#include "Game/WinWindow.h"
#include "Game/RankList.h"

void InitEverything();
void InitTheTextures();
void InitTheFonts();
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
void FreeEverything();

#endif // LAUNCHER_H_INCLUDED
