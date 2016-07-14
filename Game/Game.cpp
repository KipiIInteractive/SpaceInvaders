#include "Game.h"

bool Game::isRunning = true;
SDL_Texture *Game::background = NULL;
SDL_Texture *Game::borderTexture = NULL;
SDL_Rect Game::Pannel;
SDL_Rect Game::leftBorder;
SDL_Rect Game::rightBorder;
Label Game::ScoreText;
int Game::score = 0;

#define NUMBER_OF_BARRIERS 3
Barrier *Game::barriers[NUMBER_OF_BARRIERS];

const Uint8 *input = SDL_GetKeyboardState(NULL);
bool canShoot = true;
int Game::framesAfterShooting = 0;

FPS_Controller *Game::fps;

void Game::Init()
{
    //Initialize the resolution for the game panel
    Game::Pannel.h = System::Screen::Height;
    Game::Pannel.w = System::Screen::Height + (System::Screen::Height / 4);
    Game::Pannel.y = 0;
    Game::Pannel.x = System::Screen::Width / 2 - Game::Pannel.w / 2;

    //Set borders to the game panel
    Game::leftBorder = {Game::Pannel.x - 5, 0, 5, Game::Pannel.h};
    Game::rightBorder = {Game::Pannel.x + Game::Pannel.w, 0, 5, Game::Pannel.h};

    Game::background = System::CreateTexture("Resources/Textures/game_background.jpg", System::renderer);
    Game::borderTexture = System::CreateTexture("Resources/Textures/border.jpg", System::renderer);

    //Initialize the barriers for the level
    int offset = Game::Pannel.w / 3;
    int firstBarrierX = Game::Pannel.x - offset / 1.5;

    for(int i = 0; i < NUMBER_OF_BARRIERS; i++)
    {
        Barrier *newBarrier = new Barrier("Resources/Textures/barrier.png", firstBarrierX += offset, Game::Pannel.h - Game::Pannel.h / 4);
        Game::barriers[i] = newBarrier;
    }

    //Initialize the score text
    Game::ScoreText.SetText("Score: " + to_string(Game::score));
    Game::ScoreText.SetColor(255, 255, 255);
    Game::ScoreText.SetFont(System::Fonts::Score);
    Game::ScoreText.SetX(System::Screen::Width / 2 - Game::ScoreText.GetWidth() / 2);
    Game::ScoreText.SetY(0);

    //Initialize the FPS regulation controller
    Game::fps = new FPS_Controller(60);
}

void Game::StartGame()
{
    LevelManager::LoadLevel(LevelManager::GetCurrentLevel());

    Player::Init();

    while(Game::isRunning)
    {
        Game::fps->SetTestTick();

        SDL_RenderClear(System::renderer);

        Game::ScoreText.SetText("Score: " + to_string(Game::score));
        Game::ScoreText.SetFont(System::Fonts::Score);
        Game::ScoreText.SetX(System::Screen::Width / 2 - Game::ScoreText.GetWidth() / 2);

        AliensManager::Move();
        BulletsManager::UpdateAll();

        Game::GetPlayerInput();

        if(!canShoot && framesAfterShooting < 20)
        {
            framesAfterShooting++;
        }
        else
        {
            canShoot = true;
            framesAfterShooting = 0;
        }
        Game::RenderEverything();
        SDL_RenderPresent(System::renderer);

        Game::fps->Delay();
    }

}

void Game::RenderEverything()
{
    //Render the game background
    SDL_RenderCopy(System::renderer, Game::background, NULL, NULL);

    //Render the game panel borders
    SDL_RenderCopy(System::renderer, Game::borderTexture, NULL, &Game::leftBorder);
    SDL_RenderCopy(System::renderer, Game::borderTexture, NULL, &Game::rightBorder);

    //Render the aliens, the player and the bullets
    AliensManager::RenderAll();
    BulletsManager::RenderAll();
    Player::Render();

    //Render the barriers
    for(int i = 0; i < NUMBER_OF_BARRIERS; i++)
        Game::barriers[i]->Render();

    //Render the score
    Game::ScoreText.Render();
}

void Game::GetPlayerInput()
{
    SDL_PumpEvents();

    if(input[SDL_SCANCODE_LEFT])
        Player::Move(System::Direction::Left);

    if(input[SDL_SCANCODE_RIGHT])
        Player::Move(System::Direction::Right);

    if(input[SDL_SCANCODE_SPACE])
    {
        if(canShoot)
        {
            Player::Shoot();
            canShoot = false;
        }
    }
}
