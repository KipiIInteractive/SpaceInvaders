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

    StartWindow_Show();

    FreeEverything();
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    return 0;
}

/*
void InitEverything()
---------------------
Initialize everything needed to run the program:
 - SDL, SDL_IMAGE, SDL_TTF, SDL_MIXER

Create the base stuff needed to made the game
 - Window, Renderer, Event listener

Load the media used for the game
 - Textures, Fonts, Sounds, Scenes/Windows
*/
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

<<<<<<< HEAD
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
=======

>>>>>>> d724ac1... Added README containing the game download link
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


<<<<<<< HEAD
    //Initialize the used fonts
    InitTheFonts();
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
=======
    LoadTheTextures();
    LoadTheFonts();
    SoundManager::Init();
    SoundManager::Play(SoundManager::Sounds::BackgroundMusic);
>>>>>>> d724ac1... Added README containing the game download link

    LevelManager::InitCurrentLevel();

    //Initialize the game window
    Game::Init();
<<<<<<< HEAD

    //Initialize the sounds manager
    SoundManager::Init();
=======
    Game::PreStartInitializations();

<<<<<<< HEAD
    //Initialize the UFO
    UFO::Init();

    //Initialize the sounds manager and start the background music
    SoundManager::Init();
    SoundManager::Play(SoundManager::Sounds::BackgroundMusic);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
=======
>>>>>>> d724ac1... Added README containing the game download link

    UFO::Init();
    Player::Init();

<<<<<<< HEAD
<<<<<<< HEAD
=======
    //Initialize the Win window
=======
    NameSelectionWindow::Init();
    StartWindow_Init();
>>>>>>> d724ac1... Added README containing the game download link
    WinWindow::Init();
    RankList::Init();
    GameOver::Init();

    //Initialize the keyboard
    System::InitAlphabet();
    Keyboard::Init();

    ProfileManager::LoadTheUsersData();
}

/*
void LoadTheTextures()
----------------------
Load all textures used in the game
*/
void LoadTheTextures()
{
    //Aliens sprite sheet
    System::Textures::Aliens = System::CreateTexture("Resources/Textures/aliens.png");
    if(System::Textures::Aliens == NULL)
        cout << "Failed to create the Aliens texture: \n" << SDL_GetError() << endl;

    //Aliens explosion
    System::Textures::Aliens_Dead = System::CreateTexture("Resources/Textures/aliens_die.png");
    if(System::Textures::Aliens_Dead == NULL)
        cout << "Failed to create the Aliens_Dead texture: \n" << SDL_GetError() << endl;

    //UFO
    System::Textures::UFO = System::CreateTexture("Resources/Textures/ufo.png");
    if(System::Textures::UFO == NULL)
        cout << "Failed to create the Aliens texture: \n" << SDL_GetError() << endl;

    //Bullets
    System::Textures::Bullets = System::CreateTexture("Resources/Textures/bullet.png");
    if(System::Textures::Bullets == NULL)
        cout << "Failed to create the Bullets texture: \n" << SDL_GetError() << endl;

    //The player
    System::Textures::Player = System::CreateTexture("Resources/Textures/player.png");
    if(System::Textures::Player == NULL)
        cout << "Failed to create the Player texture: \n" << SDL_GetError() << endl;

    //Player explosion
    System::Textures::Player_Dead = System::CreateTexture("Resources/Textures/player_die.png");
    if(System::Textures::Player_Dead == NULL)
        cout << "Failed to create the Player_Dead texture: \n" << SDL_GetError() << endl;

    //The background
    System::Textures::Background_Black = System::CreateTexture("Resources/Textures/bg_black.jpg");
    if(System::Textures::Background_Black == NULL)
        cout << "Failed to create the Background_Black texture: \n" << SDL_GetError() << endl;

    //Game panel borders
    System::Textures::Border = System::CreateTexture("Resources/Textures/border.jpg");
    if(System::Textures::Border == NULL)
        cout << "Failed to create the Border texture: \n" << SDL_GetError() << endl;

//All the barrier's parts
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

/*
void LoadTheFonts()
-------------------
Load all fonts used in the game
*/
void LoadTheFonts()
{
//Game Over Window fonts
    System::Fonts::GameOver_Title = TTF_OpenFont("Resources/Fonts/invaders.ttf", 90);
    if(System::Fonts::GameOver_Title == NULL)
        std::cout << "Failed to open the GameOver_Title font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

    System::Fonts::GameOver_Title_Top_Players = TTF_OpenFont("Resources/Fonts/invaders.ttf", 60);
    if(System::Fonts::GameOver_Title_Top_Players == NULL)
        std::cout << "Failed to open the GameOver_Title_Top_Players font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

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

    System::Fonts::WinWindow_Title_Top_Players = TTF_OpenFont("Resources/Fonts/invaders.ttf", 60);
    if(System::Fonts::WinWindow_Title_Top_Players == NULL)
        std::cout << "Failed to open the WinWindow_Title_Top_Players font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

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

//Start window fonts
    System::Fonts::StartWindow_Title = TTF_OpenFont("Resources/Fonts/invaders.ttf", 70);
    if(System::Fonts::StartWindow_Title == NULL)
        std::cout << "Failed to open the StartWindow_Title font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

//Name selection window fonts
    System::Fonts::NameSelectionWindow_Title = TTF_OpenFont("Resources/Fonts/invaders.ttf", 60);
    if(System::Fonts::NameSelectionWindow_Title == NULL)
        std::cout << "Failed to open the NameSelectionWindow_Title font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

    System::Fonts::NameSelectionWindow_Instructions = TTF_OpenFont("Resources/Fonts/invaders.ttf", 30);
    if(System::Fonts::NameSelectionWindow_Instructions == NULL)
        std::cout << "Failed to open the NameSelectionWindow_Instructions font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;

//Other fonts
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
}

/*
void StartWindow_Init()
-----------------------
Set-up everything for the Start window once before
showing it many times. Every time when Start window
is showed it does't need to be initialized again.
*/
void StartWindow_Init()
{
    //Initialize the title for the Start window
    text_title.SetText("Space invaders");
    text_title.SetColor(200, 200, 0);
    text_title.SetFont(System::Fonts::StartWindow_Title);
    text_title.SetX(System::Screen::Width / 2 - text_title.GetWidth() / 2);
    text_title.SetY(System::Screen::Height / 10);

    start_window_is_active = false;

    //Initialize every option for the Start window's menu
    for(unsigned i = 0; i < num_of_options; i++)
    {
        TTF_Font *tmp_font = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);

        if(i == OPTION_START_GAME) //Initialize the 'Start new game' option
            text_options[i].SetText("Start new game");
        else if(i == OPTION_SEE_RANKLIST) //Initialize the 'See the rank list' option
            text_options[i].SetText("See the rank list");
        else if(i == OPTION_QUIT) //Initialize the 'Quit' option
            text_options[i].SetText("Quit");

        //Initialize the outlook for the menu options
        text_options[i].SetColor(255, 255, 255);
        text_options[i].SetFont(tmp_font);

        //Initialize the coordinates for the menu options
        text_options[i].SetX(System::Screen::Width / 2 - text_options[i].GetWidth() / 2);
        text_options[i].SetY( ( (i) * text_options[i].GetHeight() ) + (text_title.GetHeight() + text_title.GetY() + System::Screen::Height / 10));
        text_options[i].SetY(text_options[i].GetY() * 1.5);
    }
}

/*
void StartWindow_Show()
-----------------------
Show the Start window
*/
void StartWindow_Show()
{
    start_window_is_active = true;

    //Clear the events queue for event's type SDL_KEYDOWN
    SDL_FlushEvent(SDL_KEYDOWN);

    //The default marked option is 'Start new game' option
    StartWindow_MarkTheActiveOption();

    StartWindow_RenderWindow();
    while(start_window_is_active)
    {
        if(SDL_PollEvent(&System::event))
        {
            if(System::event.type == SDL_KEYDOWN)
            {
                StartWindow_MoveThroughTheOptions();
                StartWindow_SelectOption();
            }
        }
    }
}

/*
void StartWindow_MarkTheActiveOption()
--------------------------------------
Paint the marked menu option red and every
other option white.
*/
void StartWindow_MarkTheActiveOption()
{
    for(unsigned i = 0; i < num_of_options; i++)
    {
        TTF_Font *tmp_font = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
        if(i == active_option)
            text_options[i].SetColor(255, 0, 0);
        else
            text_options[i].SetColor(255, 255, 255);

        text_options[i].SetFont(tmp_font);
    }
}

/*
void StartWindow_MoveThroughTheOptions()
----------------------------------------
If down arrow key is pressed go to the next menu option.
If up arrow key is pressed go to the previous menu option.
*/
void StartWindow_MoveThroughTheOptions()
{
    if(System::event.key.keysym.sym == SDLK_DOWN)
    {
        if(active_option < num_of_options - 1)
            active_option++;
        else
            active_option = 0;

        StartWindow_MarkTheActiveOption();
        StartWindow_RenderWindow();
    }
    else if(System::event.key.keysym.sym == SDLK_UP)
    {
        if(active_option > 0)
            active_option--;
        else
            active_option = num_of_options - 1;

        StartWindow_MarkTheActiveOption();
        StartWindow_RenderWindow();
    }
}

/*
void StartWindow_SelectOption()
-------------------------------
When space was pressed go to the
window for the marked option or
quit the game
*/
void StartWindow_SelectOption()
{
    if(System::event.key.keysym.sym == SDLK_SPACE)
    {
        SDL_FlushEvent(SDL_KEYDOWN);
        if(active_option == OPTION_START_GAME)
        {
            Game::PreStartInitializations();
            Game::StartGame();
            StartWindow_Init();
            StartWindow_Show();
        }
        else if(active_option == OPTION_SEE_RANKLIST)
        {
            RankList::Show();
            StartWindow_Init();
            StartWindow_Show();
        }
        else if(active_option == OPTION_QUIT)
        {
            start_window_is_active = false;
        }
    }
}

<<<<<<< HEAD
<<<<<<< HEAD
    System::Fonts::Hints = TTF_OpenFont("Resources/Fonts/invaders.ttf", 30);
    if(System::Fonts::Hints == NULL)
        std::cout << "Failed to open the space age font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
=======
void StartWIndow_RenderWindow()
=======
/*
void StartWindow_RenderWindow()
-------------------------------
Render everything from the Start window:
 - The title
 - The menu options
*/
void StartWindow_RenderWindow()
>>>>>>> d724ac1... Added README containing the game download link
{
    SDL_RenderClear(System::renderer);

    text_title.Render();
    for(unsigned i = 0; i < num_of_options; i++)
        text_options[i].Render();

    SDL_RenderPresent(System::renderer);
>>>>>>> ecbd78b... The UFO feature is added. On launch Start Menu is shown with options to
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
