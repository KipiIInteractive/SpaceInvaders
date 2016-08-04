#include "launcher.h"

int main(int argc, char ** argv)
{
    //Initialize SDL, create the window and the renderer
    InitEverything();

    //Load all users and put them into list
    ProfileManager::LoadTheUsersData();

    //Go to Log-in window
    LoginWindow::Show();

    System::Free();

    TTF_Quit();
    SDL_Quit();

    return 0;
}

void InitEverything()
{
    //Initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cout << "Failed to initialize SDL. File: launcher.cpp/Initizlizations(): \n" << SDL_GetError() << std::endl;

    //Initialize SDL_TTF
    if(TTF_Init() < 0)
        std::cout << "Failed to initialize SDL_TTF. File: launcher.cpp/Initizlizations(): \n" << TTF_GetError() << std::endl;

    //Create the window
    System::window = SDL_CreateWindow("Space Invaders",
                     SDL_WINDOWPOS_UNDEFINED,
                     SDL_WINDOWPOS_UNDEFINED,
                     System::Screen::Height,
                     System::Screen::Width,
                     SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
    if(System::window == NULL)
        std::cout << "Failed to create the window. File: launcher.cpp/Initizlizations() \n" << SDL_GetError() << std::endl;


    //Create the renderer
    System::renderer = SDL_CreateRenderer(System::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(System::renderer == NULL)
        std::cout << "Failed to create the renderer. File: launcher.cpp/Initizlizations()" << SDL_GetError() << std::endl;


    //Initialize the used fonts
    System::Fonts::InputFields = TTF_OpenFont("Resources/Fonts/spaceage.ttf", 40);
    if(System::Fonts::InputFields == NULL)
        std::cout << "Failed to open the Space age font. File: launcher.cpp/Initizlizations()" << TTF_GetError() << std::endl;

    System::Fonts::Buttons = TTF_OpenFont("Resources/Fonts/spaceage.ttf", 50);
    if(System::Fonts::Buttons == NULL)
        std::cout << "Failed to open the Space age font. File: launcher.cpp/Initizlizations()" << TTF_GetError() << std::endl;

    System::Fonts::Labels = TTF_OpenFont("Resources/Fonts/earthorbiter.ttf", 45);
    if(System::Fonts::Labels == NULL)
        std::cout << "Failed to open the Space age font. File: launcher.cpp/Initizlizations()" << TTF_GetError() << std::endl;

    System::Fonts::Buttons_Small = TTF_OpenFont("Resources/Fonts/spaceage.ttf", 25);
    if(System::Fonts::Buttons_Small == NULL)
        std::cout << "Failed to open the Space age font. File: launcher.cpp/Initizlizations()" << TTF_GetError() << std::endl;

    System::Fonts::Errors = TTF_OpenFont("Resources/Fonts/halo.ttf", 55);
    if(System::Fonts::Errors == NULL)
        std::cout << "Failed to open the halo font. File: launcher.cpp/Initizlizations()" << TTF_GetError() << std::endl;

    //Initialize the log-in window
    LoginWindow::Init();

    //Initialize the registration window
    RegistrationWindow::Init();

    //Read which is the current level number
    LevelManager::InitCurrentLevel();
}
