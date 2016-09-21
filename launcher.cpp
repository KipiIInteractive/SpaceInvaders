#include "launcher.h"
int main(int argc, char ** argv)
{
    InitEverything();

    ShowStartWindow();

    FreeEverything();
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
    //Display struct to hold screen resolution properties
    SDL_DisplayMode currentDisplay;
    //Initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Failed to initialize SDL. File: launcher.cpp/Initializations(): \n" << SDL_GetError() << std::endl;
    }
    else {
        if(SDL_GetCurrentDisplayMode(0, &currentDisplay) != 0) {
            std::cout << SDL_GetError() << std::endl;
        }
        else {
            System::Screen::Width = currentDisplay.w;
            System::Screen::Height = currentDisplay.h;
        }
    }
    //Initialize SDL_TTF ( used for the fonts and the texts in the game )
    if(TTF_Init() < 0) {
        std::cout << "Failed to initialize SDL_TTF. File: launcher.cpp/Initializations(): \n" << TTF_GetError() << std::endl;
    }
    //Initialize SDL_IMG ( used for working with all textures in the game )
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !imgFlags) {
        std::cout << "Failed to initialize imgFlags. File: launcher.cpp/Initializations() \n" << IMG_GetError() << std::endl;
    }
    if(!IMG_Init( imgFlags )) {
        std::cout << "Failed to initialize SDL_IMAGE. File: launcher.cpp/Initializations() \n" << IMG_GetError() << std::endl;
    }
    //Initialize SDL_MIXER ( used for playing the music and sound effects in the game )
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) < 0 ) {
        std::cout << "Failed to initialize SDL_MIXER. File: launcher.cpp/Initializations() \n" << Mix_GetError() << std::endl;
    }
    //Create the window
    System::window = SDL_CreateWindow("Space Invaders",
                     SDL_WINDOWPOS_CENTERED,
                     SDL_WINDOWPOS_CENTERED,
                     System::Screen::Height,
                     System::Screen::Width,
                     SDL_WINDOW_FULLSCREEN_DESKTOP);
    if(System::window == NULL) {
        std::cout << "Failed to create the window. File: launcher.cpp/Initizlizations() \n" << SDL_GetError() << std::endl;
    }
    //Create the renderer
    System::renderer = SDL_CreateRenderer(System::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(System::renderer == NULL) {
        std::cout << "Failed to create the renderer. File: launcher.cpp/Initizlizations() \n" << SDL_GetError() << std::endl;
    }
    LoadTheTextures();
    LoadTheFonts();
    SoundManager::Init();
    SoundManager::Play(SoundManager::Sounds::BackgroundMusic);

    //Initialize the game window
    Game::Init();
    UFO::Init();
    Player::Init();

    NameSelectionWindow::Init();
    InitStartWindow();
    WinWindow::Init();
    RankList::Init();
    GameOver::Init();

    //Initialize the keyboard
    System::InitAlphabet();
    Keyboard::Init();
}

/*
void LoadTheTextures()
----------------------
Load all textures used in the game
*/
void LoadTheTextures()
{
    //Aliens sprite sheet
    System::Textures::AliensAlive = System::CreateTexture("Resources/Textures/aliens.png");
    if(System::Textures::AliensAlive == NULL) {
        cout << "Failed to create the Aliens texture: \n" << SDL_GetError() << endl;
    }
    //Aliens explosion
    System::Textures::AliensDead = System::CreateTexture("Resources/Textures/aliens_die.png");
    if(System::Textures::AliensDead == NULL) {
        cout << "Failed to create the Aliens_Dead texture: \n" << SDL_GetError() << endl;
    }
    //UFO
    System::Textures::UFO = System::CreateTexture("Resources/Textures/ufo.png");
    if(System::Textures::UFO == NULL) {
        cout << "Failed to create the Aliens texture: \n" << SDL_GetError() << endl;
    }
    //Bullets
    System::Textures::Bullets = System::CreateTexture("Resources/Textures/bullet.png");
    if(System::Textures::Bullets == NULL) {
        cout << "Failed to create the Bullets texture: \n" << SDL_GetError() << endl;
    }
    //The player
    System::Textures::PlayerAlive = System::CreateTexture("Resources/Textures/player.png");
    if(System::Textures::PlayerAlive == NULL) {
        cout << "Failed to create the Player texture: \n" << SDL_GetError() << endl;
    }
    //Player explosion
    System::Textures::PlayerDead = System::CreateTexture("Resources/Textures/player_die.png");
    if(System::Textures::PlayerDead == NULL) {
        cout << "Failed to create the PlayerDead texture: \n" << SDL_GetError() << endl;
    }
    //The background
    System::Textures::Background = System::CreateTexture("Resources/Textures/bg_black.jpg");
    if(System::Textures::Background == NULL) {
        cout << "Failed to create the Background_Black texture: \n" << SDL_GetError() << endl;
    }
    //Game panel borders
    System::Textures::Border = System::CreateTexture("Resources/Textures/border.jpg");
    if(System::Textures::Border == NULL) {
        cout << "Failed to create the Border texture: \n" << SDL_GetError() << endl;
    }
    //All the barrier's parts
    System::Textures::BarrierBottomLeft = System::CreateTexture("Resources/Textures/bottom-left.png");
    if(System::Textures::BarrierBottomLeft == NULL) {
        cout << "Failed to create the BarrierBottomLeft texture: \n" << SDL_GetError() << endl;
    }
    System::Textures::BarrierBottomMiddle = System::CreateTexture("Resources/Textures/bottom-middle.png");
    if(System::Textures::BarrierBottomMiddle == NULL) {
        cout << "Failed to create the BarrierBottomMiddle texture: \n" << SDL_GetError() << endl;
    }
    System::Textures::BarrierBottomRight = System::CreateTexture("Resources/Textures/bottom-right.png");
    if(System::Textures::BarrierBottomRight == NULL){
        cout << "Failed to create the BarrierBottomRight texture: \n" << SDL_GetError() << endl;
    }
    System::Textures::BarrierCenterLeft = System::CreateTexture("Resources/Textures/whole-block.png");
    if(System::Textures::BarrierCenterLeft == NULL) {
        cout << "Failed to create the BarrierCenterLeft texture: \n" << SDL_GetError() << endl;
    }
    System::Textures::BarrierCenterMiddle = System::CreateTexture("Resources/Textures/whole-block.png");
    if(System::Textures::BarrierCenterMiddle == NULL) {
        cout << "Failed to create the BarrierCenterMiddle texture: \n" << SDL_GetError() << endl;
    }
    System::Textures::BarrierCenterRight = System::CreateTexture("Resources/Textures/whole-block.png");
    if(System::Textures::BarrierCenterRight == NULL) {
        cout << "Failed to create the BarrierCenterRight texture: \n" << SDL_GetError() << endl;
    }
    System::Textures::BarrierTopLeft = System::CreateTexture("Resources/Textures/top-left.png");
    if(System::Textures::BarrierTopLeft == NULL) {
        cout << "Failed to create the BarrierTopLeft texture: \n" << SDL_GetError() << endl;
    }
    System::Textures::BarrierTopMiddle = System::CreateTexture("Resources/Textures/whole-block.png");
    if(System::Textures::BarrierTopMiddle == NULL) {
        cout << "Failed to create the BarrierTopMiddle texture: \n" << SDL_GetError() << endl;
    }
    System::Textures::BarrierTopRight = System::CreateTexture("Resources/Textures/top-right.png");
    if(System::Textures::BarrierTopRight == NULL) {
        cout << "Failed to create the BarrierTopRight texture: \n" << SDL_GetError() << endl;
    }
}

/*
void LoadTheFonts()
-------------------
Load all fonts used in the game
*/
void LoadTheFonts()
{
//Game Over Window fonts
    System::Fonts::GameOverMenuTitle = TTF_OpenFont("Resources/Fonts/invaders.ttf", 90);
    if(System::Fonts::GameOverMenuTitle == NULL) {
        std::cout << "Failed to open the GameOverMenuTitle font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
    System::Fonts::GameOverMenuTopPlayers = TTF_OpenFont("Resources/Fonts/invaders.ttf", 60);
    if(System::Fonts::GameOverMenuTopPlayers == NULL) {
        std::cout << "Failed to open the GameOverMenuTopPlayers font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
    System::Fonts::GameOverMenuNavigationHints = TTF_OpenFont("Resources/Fonts/invaders.ttf", 30);
    if(System::Fonts::GameOverMenuNavigationHints == NULL) {
        std::cout << "Failed to open the GameOverMenuNavigationHints font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
    System::Fonts::GameOverMenuPlayerScore = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
    if(System::Fonts::GameOverMenuPlayerScore == NULL) {
        std::cout << "Failed to open the GameOverMenuPlayerScore font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
//Win Window fonts
    System::Fonts::WinWindowTitle = TTF_OpenFont("Resources/Fonts/invaders.ttf", 90);
    if(System::Fonts::WinWindowTitle == NULL) {
        std::cout << "Failed to open the WinWindowTitle font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
    System::Fonts::WinWindowTopPlayers = TTF_OpenFont("Resources/Fonts/invaders.ttf", 60);
    if(System::Fonts::WinWindowTopPlayers == NULL) {
        std::cout << "Failed to open the WinWindowTopPlayers font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
    System::Fonts::WinWindowNavigationHints = TTF_OpenFont("Resources/Fonts/invaders.ttf", 30);
    if(System::Fonts::WinWindowNavigationHints == NULL) {
        std::cout << "Failed to open the WinWindowNavigationHints font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
    System::Fonts::WinWindowPlayerScore = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
    if(System::Fonts::WinWindowPlayerScore == NULL) {
        std::cout << "Failed to open the WinWindowPlayerScore font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
//Rank list fonts
    System::Fonts::RankListNavigationHints = TTF_OpenFont("Resources/Fonts/invaders.ttf", 30);
    if(System::Fonts::RankListNavigationHints == NULL) {
        std::cout << "Failed to open the RankListNavigationHints font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
    System::Fonts::RankListTitle = TTF_OpenFont("Resources/Fonts/invaders.ttf", 60);
    if(System::Fonts::RankListTitle == NULL) {
        std::cout << "Failed to open the RankListTitle font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
//Game fonts
    System::Fonts::PlayerScore = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
    if(System::Fonts::PlayerScore == NULL) {
        std::cout << "Failed to open the PlayerScore font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }

    System::Fonts::GameLevel = TTF_OpenFont("Resources/Fonts/invaders.ttf", 80);
    if(System::Fonts::GameLevel == NULL) {
        std::cout << "Failed to open the GameLevel font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
    System::Fonts::PlayerLivesLeft = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
    if(System::Fonts::PlayerLivesLeft == NULL) {
        std::cout << "Failed to open the PlayerLivesLeft font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
//Start window fonts
    System::Fonts::StartWindowTitle = TTF_OpenFont("Resources/Fonts/invaders.ttf", 70);
    if(System::Fonts::StartWindowTitle == NULL) {
        std::cout << "Failed to open the StartWindowTitle font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
//Name selection window fonts
    System::Fonts::NameSelectionWindowTitle = TTF_OpenFont("Resources/Fonts/invaders.ttf", 60);
    if(System::Fonts::NameSelectionWindowTitle == NULL) {
        std::cout << "Failed to open the NameSelectionWindowTitle font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
    System::Fonts::NameSelectionWindowInstructions = TTF_OpenFont("Resources/Fonts/invaders.ttf", 30);
    if(System::Fonts::NameSelectionWindowInstructions == NULL) {
        std::cout << "Failed to open the NameSelectionWindowInstructions font. File: launcher.cpp/Initizlizations() \n" << TTF_GetError() << std::endl;
    }
}

/*
void InitStartWindow()
-----------------------
Set-up everything for the Start window once before
showing it many times. Every time when Start window
is showed it does't need to be initialized again.
*/
void InitStartWindow()
{
    //Initialize the title for the Start window
    titleText.SetText("Space invaders");
    titleText.SetColor(200, 200, 0);
    titleText.SetFont(System::Fonts::StartWindowTitle);
    titleText.SetX(System::Screen::Width / 2 - titleText.GetWidth() / 2);
    int titleIndentationFromScreenTop = 10;
    titleText.SetY(System::Screen::Height / titleIndentationFromScreenTop);

    isStartWindowActive = false;

    //Initialize every option for the Start window's menu
    for(unsigned i = 0; i < numOfOptions; i++)
    {
        TTF_Font *tmpFont = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);

        if(i == OPTION_START_CLASSIC_GAME) { //Initialize the classic game option
            menuOptions[i].SetText("Classic");
        }
        else if(i == OPTION_START_SURVIVAL_GAME) { //Initialize the survival game option
            menuOptions[i].SetText("Survival");
        }
        else if(i == OPTION_SEE_RANKLIST) { //Initialize the 'See the rank list' option
            menuOptions[i].SetText("See the rank list");
        }
        else if(i == OPTION_QUIT) { //Initialize the 'Quit' option
            menuOptions[i].SetText("Quit");
        }

        //Initialize the outlook for the menu options
        menuOptions[i].SetColor(255, 255, 255);
        menuOptions[i].SetFont(tmpFont);
        TTF_CloseFont(tmpFont);

        //Initialize the coordinates for the menu options
        int menuOptionIndentationFromTitleDivisor = 10;
        float menuOptionYIndentationFromTitleMultiplier = 1.5;
        //Sets the menu option at the center of the screen on the x coordinate and one below the other on the y
        menuOptions[i].SetX(System::Screen::Width / 2 - menuOptions[i].GetWidth() / 2);
        menuOptions[i].SetY( ( (i) * menuOptions[i].GetHeight() ) + (titleText.GetHeight() + titleText.GetY() + System::Screen::Height / menuOptionIndentationFromTitleDivisor));
        menuOptions[i].SetY(menuOptions[i].GetY() * menuOptionYIndentationFromTitleMultiplier);
    }
}

/*
void ShowStartWindow()
-----------------------
Show the Start window
*/
void ShowStartWindow()
{
    isStartWindowActive = true;

    //Clear the events queue for event's type SDL_KEYDOWN
    SDL_FlushEvent(SDL_KEYDOWN);

    //The default marked option is 'Classic' option
    MarkTheActiveStartWindowOption();

    RenderStartWindow();
    while(isStartWindowActive)
    {
        if(SDL_PollEvent(&System::event))
        {
            if(System::event.type == SDL_KEYDOWN)
            {
                MoveThroughTheStartWindowOptions();
                SelectStartWindowOption();
            }
        }
    }
}

/*
void MarkTheActiveStartWindowOption()
--------------------------------------
Paint the marked menu option red and every
other option white.
*/
void MarkTheActiveStartWindowOption()
{
    for(unsigned i = 0; i < numOfOptions; i++)
    {
        TTF_Font *tmpFont = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
        if(i == activeOption) {
            menuOptions[i].SetColor(255, 0, 0);
        }
        else {
            menuOptions[i].SetColor(255, 255, 255);
        }
        menuOptions[i].SetFont(tmpFont);
        TTF_CloseFont(tmpFont);
    }
}

/*
void MoveThroughTheStartWindowOptions()
----------------------------------------
If down arrow key is pressed go to the next menu option.
If up arrow key is pressed go to the previous menu option.
*/
void MoveThroughTheStartWindowOptions()
{
    if(System::event.key.keysym.sym == SDLK_DOWN)
    {
        if(activeOption < numOfOptions - 1) {
            activeOption++;
        }
        else {
            activeOption = 0;
        }
        MarkTheActiveStartWindowOption();
        RenderStartWindow();
    }
    else if(System::event.key.keysym.sym == SDLK_UP)
    {
        if(activeOption > 0) {
            activeOption--;
        }
        else {
            activeOption = numOfOptions - 1;
        }

        MarkTheActiveStartWindowOption();
        RenderStartWindow();
    }
}

/*
void SelectStartWindowOption()
-------------------------------
When space was pressed go to the
window for the marked option or
quit the game
*/
void SelectStartWindowOption()
{
    if(System::event.key.keysym.sym == SDLK_SPACE)
    {
        SDL_FlushEvent(SDL_KEYDOWN);
        if(activeOption == OPTION_START_CLASSIC_GAME)
        {
            Game::PreClassicGameStartInitializations();
            Game::StartClassicGame();
            InitStartWindow();
            ShowStartWindow();
        }
        else if(activeOption == OPTION_START_SURVIVAL_GAME) {
            Game::PreSurvivalGameStartInitializations();
            Game::StartSurvivalGame();
            InitStartWindow();
            ShowStartWindow();
        }
        else if(activeOption == OPTION_SEE_RANKLIST)
        {
            RankList::Show();
            InitStartWindow();
            ShowStartWindow();
        }
        else if(activeOption == OPTION_QUIT)
        {
            isStartWindowActive = false;
        }
    }
}

/*
void RenderStartWindow()
-------------------------------
Render everything from the Start window:
 - The title
 - The menu options
*/
void RenderStartWindow()
{
    SDL_RenderClear(System::renderer);

    titleText.Render();
    for(unsigned i = 0; i < numOfOptions; i++) {
        menuOptions[i].Render();
    }

    SDL_RenderPresent(System::renderer);
}


void FreeEverything()
{
    SoundManager::Close();
    System::Free();
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
