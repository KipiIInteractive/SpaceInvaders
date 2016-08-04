#include "launcher.h"

int main(int argc, char ** argv)
{
<<<<<<< HEAD
    //Initialize SDL, create the window and the renderer
    InitEverything();

    //Load all users and put them into list
    ProfileManager::LoadTheUsersData();

    //Go to Log-in window
    LoginWindow::Show();

    FreeEverything();

    Mix_Quit();
    TTF_Quit();
    SDL_Quit();

=======
    InitEverything();

    ProfileManager::LoadTheUsersData();

    //Start new game
    Game::StartGame();

    FreeEverything();
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    return 0;
}

void InitEverything()
{
    //Initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cout << "Failed to initialize SDL. File: launcher.cpp/Initializations(): \n" << SDL_GetError() << std::endl;

<<<<<<< HEAD
    //Initialize SDL_TTF
    if(TTF_Init() < 0)
        std::cout << "Failed to initialize SDL_TTF. File: launcher.cpp/Initializations(): \n" << TTF_GetError() << std::endl;

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !imgFlags)
        std::cout << "Failed to initialize imgFlags. File: launcher.cpp/Initializations() \n" << IMG_GetError() << std::endl;

    if(!IMG_Init( imgFlags ))
        std::cout << "Failed to initialize SDL_IMAGE. File: launcher.cpp/Initializations() \n" << IMG_GetError() << std::endl;

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) < 0 )
        std::cout << "Failed to initialize SDL_MIXER. File: launcher.cpp/Initializations() \n" << Mix_GetError() << std::endl;
=======
    //Initialize SDL_TTF ( used for the fonts and the texts in the game )
    if(TTF_Init() < 0)
        std::cout << "Failed to initialize SDL_TTF. File: launcher.cpp/Initializations(): \n" << TTF_GetError() << std::endl;

    //Initialize SDL_IMG ( used for working with all textures in the game )
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !imgFlags)
        std::cout << "Failed to initialize imgFlags. File: launcher.cpp/Initializations() \n" << IMG_GetError() << std::endl;
    if(!IMG_Init( imgFlags ))
        std::cout << "Failed to initialize SDL_IMAGE. File: launcher.cpp/Initializations() \n" << IMG_GetError() << std::endl;

    //Initialize SDL_MIXER ( used for playing the music and sound effects in the game )
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) < 0 )
        std::cout << "Failed to initialize SDL_MIXER. File: launcher.cpp/Initializations() \n" << Mix_GetError() << std::endl;

>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    //Create the window
    System::window = SDL_CreateWindow("Space Invaders",
                     SDL_WINDOWPOS_UNDEFINED,
                     SDL_WINDOWPOS_UNDEFINED,
                     System::Screen::Height,
                     System::Screen::Width,
                     SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
    if(System::window == NULL)
        std::cout << "Failed to create the window. File: launcher.cpp/Initizlizations() \n" << SDL_GetError() << std::endl;

<<<<<<< HEAD

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

    System::Fonts::Score = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
    if(System::Fonts::Score == NULL)
        std::cout << "Failed to open the invaders font. File: launcher.cpp/Initizlizations()" << TTF_GetError() << std::endl;

    //Initialize the log-in window
    LoginWindow::Init();

    //Initialize the registration window
    RegistrationWindow::Init();
=======
    //Create the renderer
    System::renderer = SDL_CreateRenderer(System::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(System::renderer == NULL)
        std::cout << "Failed to create the renderer. File: launcher.cpp/Initizlizations() \n" << SDL_GetError() << std::endl;

    //Initialize the used textures
    InitTheTextures();

    //Initialize the used fonts
    InitTheFonts();
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

    //Read which is the current level number
    LevelManager::InitCurrentLevel();

    //Initialize the player
    Player::Init();

    //Initialize the game window
    Game::Init();
<<<<<<< HEAD

    //Initialize the sounds manager
    SoundManager::Init();
=======
    Game::PreStartInitializations();

    //Initialize the sounds manager and start the background music
    SoundManager::Init();
    SoundManager::Play(SoundManager::Sounds::BackgroundMusic);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

    //Initialize the Game over window
    GameOver::Init();

<<<<<<< HEAD
=======
    //Initialize the Win window
    WinWindow::Init();

    //Initialize the Rank list window
    RankList::Init();
}


void InitTheTextures()
{
    System::Textures::Aliens = System::CreateTexture("Resources/Textures/aliens.png");
    if(System::Textures::Aliens == NULL)
        cout << "Failed to create the Aliens texture: \n" << SDL_GetError() << endl;

    System::Textures::Bullets = System::CreateTexture("Resources/Textures/bullet.png");
    if(System::Textures::Bullets == NULL)
        cout << "Failed to create the Bullets texture: \n" << SDL_GetError() << endl;

    System::Textures::Player = System::CreateTexture("Resources/Textures/player.png");
    if(System::Textures::Player == NULL)
        cout << "Failed to create the Player texture: \n" << SDL_GetError() << endl;

    System::Textures::Player_Dead = System::CreateTexture("Resources/Textures/player_die.png");
    if(System::Textures::Player_Dead == NULL)
        cout << "Failed to create the Player_Dead texture: \n" << SDL_GetError() << endl;

    System::Textures::Background_Black = System::CreateTexture("Resources/Textures/bg_black.jpg");
    if(System::Textures::Background_Black == NULL)
        cout << "Failed to create the Background_Black texture: \n" << SDL_GetError() << endl;

    System::Textures::Background_Stars = System::CreateTexture("Resources/Textures/bg_stars.jpg");
    if(System::Textures::Background_Stars == NULL)
        cout << "Failed to create the Background_Stars texture: \n" << SDL_GetError() << endl;

    System::Textures::Border = System::CreateTexture("Resources/Textures/border.jpg");
    if(System::Textures::Border == NULL)
        cout << "Failed to create the Border texture: \n" << SDL_GetError() << endl;

    System::Textures::Barrier_Bottom_Left = System::CreateTexture("Resources/Textures/bottom-left.png");
    if(System::Textures::Barrier_Bottom_Left == NULL)
        cout << "Failed to create the Barrier_Bottom_Left texture: \n" << SDL_GetError() << endl;

    System::Textures::Barrier_Bottom_Middle = System::CreateTexture("Resources/Textures/bottom-middle.png");
    if(System::Textures::Barrier_Bottom_Middle == NULL)
        cout << "Failed to create the Barrier_Bottom_Middle texture: \n" << SDL_GetError() << endl;

    System::Textures::Barrier_Bottom_Right = System::CreateTexture("Resources/Textures/bottom-right.png");
    if(System::Textures::Barrier_Bottom_Right == NULL)
        cout << "Failed to create the Barrier_Bottom_Right texture: \n" << SDL_GetError() << endl;

    System::Textures::Barrier_Center_Left = System::CreateTexture("Resources/Textures/whole-block.png");
    if(System::Textures::Barrier_Center_Left == NULL)
        cout << "Failed to create the Barrier_Center_Left texture: \n" << SDL_GetError() << endl;

    System::Textures::Barrier_Center_Middle = System::CreateTexture("Resources/Textures/whole-block.png");
    if(System::Textures::Barrier_Center_Middle == NULL)
        cout << "Failed to create the Barrier_Center_Middle texture: \n" << SDL_GetError() << endl;

    System::Textures::Barrier_Center_Right = System::CreateTexture("Resources/Textures/whole-block.png");
    if(System::Textures::Barrier_Center_Right == NULL)
        cout << "Failed to create the Barrier_Center_Right texture: \n" << SDL_GetError() << endl;

    System::Textures::Barrier_Top_Left = System::CreateTexture("Resources/Textures/top-left.png");
    if(System::Textures::Barrier_Top_Left == NULL)
        cout << "Failed to create the Barrier_Top_Left texture: \n" << SDL_GetError() << endl;

    System::Textures::Barrier_Top_Middle = System::CreateTexture("Resources/Textures/whole-block.png");
    if(System::Textures::Barrier_Top_Middle == NULL)
        cout << "Failed to create the Barrier_Top_Middle texture: \n" << SDL_GetError() << endl;

    System::Textures::Barrier_Top_Right = System::CreateTexture("Resources/Textures/top-right.png");
    if(System::Textures::Barrier_Top_Right == NULL)
        cout << "Failed to create the Barrier_Top_Right texture: \n" << SDL_GetError() << endl;

}

void InitTheFonts()
{
//Game Over Window fonts
    System::Fonts::GameOver_Title = TTF_OpenFont("Resources/Fonts/invaders.ttf", 80);
    if(System::Fonts::GameOver_Title == NULL)
        std::cout << "Failed to open the GameOver_Title font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

    System::Fonts::GameOver_NavigationHints = TTF_OpenFont("Resources/Fonts/invaders.ttf", 30);
    if(System::Fonts::GameOver_NavigationHints == NULL)
        std::cout << "Failed to open the GameOver_NavigationHints font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

    System::Fonts::GameOver_Score = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
    if(System::Fonts::GameOver_Score == NULL)
        std::cout << "Failed to open the GameOver_Score font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

//Win Window fonts
    System::Fonts::WinWindow_Title = TTF_OpenFont("Resources/Fonts/invaders.ttf", 90);
    if(System::Fonts::WinWindow_Title == NULL)
        std::cout << "Failed to open the WinWindow_Title font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

    System::Fonts::WinWindow_NavigationHints = TTF_OpenFont("Resources/Fonts/invaders.ttf", 30);
    if(System::Fonts::WinWindow_NavigationHints == NULL)
        std::cout << "Failed to open the WinWindow_NavigationHints font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

    System::Fonts::WinWindow_Score = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
    if(System::Fonts::WinWindow_Score == NULL)
        std::cout << "Failed to open the WinWindow_Score font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

//Rank list fonts
    System::Fonts::RankList_NavigationHints = TTF_OpenFont("Resources/Fonts/invaders.ttf", 30);
    if(System::Fonts::RankList_NavigationHints == NULL)
        std::cout << "Failed to open the RankList_NavigationHints font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

    System::Fonts::RankList_Title = TTF_OpenFont("Resources/Fonts/invaders.ttf", 60);
    if(System::Fonts::RankList_Title == NULL)
        std::cout << "Failed to open the RankList_Title font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

//Game fonts
    System::Fonts::Game_Score = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
    if(System::Fonts::Game_Score == NULL)
        std::cout << "Failed to open the Game_Score font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;


    System::Fonts::Game_Level = TTF_OpenFont("Resources/Fonts/invaders.ttf", 80);
    if(System::Fonts::Game_Level == NULL)
        std::cout << "Failed to open the Game_Level font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

    System::Fonts::Game_LivesLeft = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
    if(System::Fonts::Game_LivesLeft == NULL)
        std::cout << "Failed to open the Game_LivesLeft font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;


///TO DELETE
    System::Fonts::InputFields = TTF_OpenFont("Resources/Fonts/invaders.ttf", 40);
    if(System::Fonts::InputFields == NULL)
        std::cout << "Failed to open the Space age font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

    System::Fonts::Buttons = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
    if(System::Fonts::Buttons == NULL)
        std::cout << "Failed to open the Space age font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

    System::Fonts::Labels = TTF_OpenFont("Resources/Fonts/invaders.ttf", 45);
    if(System::Fonts::Labels == NULL)
        std::cout << "Failed to open the Space age font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

    System::Fonts::Buttons_Small = TTF_OpenFont("Resources/Fonts/invaders.ttf", 25);
    if(System::Fonts::Buttons_Small == NULL)
        std::cout << "Failed to open the Space age font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

    System::Fonts::Errors = TTF_OpenFont("Resources/Fonts/invaders.ttf", 55);
    if(System::Fonts::Errors == NULL)
        std::cout << "Failed to open the halo font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

    System::Fonts::Hints = TTF_OpenFont("Resources/Fonts/invaders.ttf", 30);
    if(System::Fonts::Hints == NULL)
        std::cout << "Failed to open the space age font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
}

void FreeEverything()
{
    SoundManager::Close();
<<<<<<< HEAD
    GameOver::Free();
    Player::Free();
    System::Free();
=======
    Player::Free();
    System::Free();
    Mix_Quit();
    SDL_Quit();
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
}
