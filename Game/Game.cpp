#include "Game.h"

bool Game::isRunning;
SDL_Texture *Game::background = NULL;
SDL_Texture *Game::borderTexture = NULL;
SDL_Rect Game::Pannel;
SDL_Rect Game::leftBorder;
SDL_Rect Game::rightBorder;
Label Game::ScoreText;
Label Game::LevelText;
Label Game::LivesText;
int Game::score = 0;
int Game::framesToShowTheLevelNumber = 300;
int framesAfterStart = 0;

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
    Game::ScoreText.SetX(Game::Pannel.x + 5);
    Game::ScoreText.SetY(5);

    //Initialize the FPS regulation controller
    Game::fps = new FPS_Controller(60);

    Game::isRunning = true;
}

void Game::StartGame()
{
    LevelManager::LoadLevel(System::Users::Current.GetCurrentLevel());

    //Initialize the level text
    Game::LevelText.SetText("Level " + to_string(System::Users::Current.GetCurrentLevel()));
    Game::LevelText.SetColor(255, 20, 20);
    Game::LevelText.SetFont(System::Fonts::Score);
    Game::LevelText.SetX(System::Screen::Width / 2 - Game::LevelText.GetWidth() / 2);
    Game::LevelText.SetY(System::Screen::Height / 10);

    //Initialize the left lives text
    Game::LivesText.SetText("Lives: " + to_string(Player::lives));
    Game::LivesText.SetColor(255, 255, 255);
    Game::LivesText.SetFont(System::Fonts::Score);
    Game::LivesText.SetX(Game::Pannel.x + Game::Pannel.w - System::GetSurfaceWidth() - 5);
    Game::LivesText.SetY(5);

    Player::Init();

    while(Game::isRunning)
    {
        Game::fps->SetTestTick();

        SDL_RenderClear(System::renderer);

        Game::ScoreText.SetText("Score: " + to_string(Game::score));
        Game::ScoreText.SetFont(System::Fonts::Score);

        Game::LivesText.SetText("Lives: " + to_string(Player::lives));
        Game::LivesText.SetColor(255, 255, 255);
        Game::LivesText.SetFont(System::Fonts::Score);

        Game::LevelText.SetText("Level " + to_string(System::Users::Current.GetCurrentLevel()));
        Game::LevelText.SetFont(System::Fonts::Score);

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

        //Go to the next level if all the aliens are killed
        if(AliensManager::allAliens.size() == 0)
        {
            framesAfterStart = 0;
            Game::isRunning = false;
            LevelManager::LoadLevel(System::Users::Current.GetCurrentLevel() + 1);
            Game::Init();
        }
        //If the player is dead
        if(Player::isDead && Player::lives == 0)
        {
            Game::isRunning = false;
            GameOver::Show();
        }

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
    BulletsManager::RenderAll();
    AliensManager::RenderAll();
    Player::Render();

    //Render the barriers
    for(int i = 0; i < NUMBER_OF_BARRIERS; i++)
        Game::barriers[i]->Render();

    //Render the score
    Game::ScoreText.Render();

    //Render the lives left
    Game::LivesText.Render();

    //Render the level number
    if(framesAfterStart <= framesToShowTheLevelNumber && framesAfterStart % 1 == 0)
    {
        Game::LevelText.Render();
        framesAfterStart++;
    }
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
            //SoundManager::Play(SoundManager::Sounds::Shoot);
            Player::Shoot();
            canShoot = false;
        }
    }
}

void Game::FreeCurrentLevel()
{
    delete(&Game::ScoreText);
    delete(&Game::LevelText);
    delete(&Game::LivesText);

    for(int i = 0; i < AliensManager::allAliens.size(); i++)
    {
        AliensManager::allAliens.erase(AliensManager::allAliens.begin() + i);
        delete(AliensManager::allAliens[i]);
    }

    for(int i = 0; i < BulletsManager::allBullets.size(); i++)
    {
        BulletsManager::allBullets.erase(BulletsManager::allBullets.begin() + i);
        delete(BulletsManager::allBullets[i]);
    }
}
