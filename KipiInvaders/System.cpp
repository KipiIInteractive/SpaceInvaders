#include "System.h"

SDL_Window* System::window = NULL;
SDL_Renderer* System::renderer = NULL;

const int System::SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN);
const int System::SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);

const int System::LEFT_X_BORDER = (System::SCREEN_WIDTH - (5*System::SCREEN_HEIGHT)/4)/2;
const int System::RIGHT_X_BORDER = System::SCREEN_WIDTH - System::LEFT_X_BORDER;

const int System::AVG_FPS = 60;
const int System::TIME_PER_FRAME = 1000 / System::AVG_FPS;

TTF_Font* System::font = NULL;
