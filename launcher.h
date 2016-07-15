#ifndef LAUNCHER_H_INCLUDED
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

void InitEverything();

#endif // LAUNCHER_H_INCLUDED
