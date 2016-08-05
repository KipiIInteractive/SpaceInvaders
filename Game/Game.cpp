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
int Game::score;
int Game::framesToShowTheLevelNumber = 150;
int framesAfterStart = 0;

#define NUMBER_OF_BARRIERS 3
Barrier *Game::barriers[NUMBER_OF_BARRIERS];

const Uint8 *input = SDL_GetKeyboardState(NULL);
bool canShoot = false;
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

    Game::background = System::Textures::Background_Black;
    Game::borderTexture = System::Textures::Border;

    //Initialize the FPS regulation controller
    Game::fps = new FPS_Controller(60);
}

void Game::PreStartInitializations()
{
    Game::isRunning = true;

    //Initialize the barriers for the level
    int offset = Game::Pannel.w / 3;
    int firstBarrierX = Game::Pannel.x - offset / 1.5;
    for(int i = 0; i < NUMBER_OF_BARRIERS; i++)
    {
        Barrier *newBarrier = new Barrier(firstBarrierX += offset, Game::Pannel.h - Game::Pannel.h / 4);
        Game::barriers[i] = newBarrier;
    }

    LevelManager::LoadLevel(System::Users::Current.GetCurrentLevel());
    Player::Init();

    //Initialize the level text
    Game::LevelText.SetText("Level " + to_string(System::Users::Current.GetCurrentLevel()));
    Game::LevelText.SetColor(255, 255, 255);
    Game::LevelText.SetFont(System::Fonts::Game_Level);
    Game::LevelText.SetX(System::Screen::Width / 2 - Game::LevelText.GetWidth() / 2);
    Game::LevelText.SetY(System::Screen::Height / 2 - Game::LevelText.GetHeight() / 2);

    //Initialize the left lives text
    Game::LivesText.SetText("Lives: " + to_string(Player::lives));
    Game::LivesText.SetColor(255, 255, 255);
    Game::LivesText.SetFont(System::Fonts::Game_LivesLeft);
    Game::LivesText.SetX(Game::Pannel.x + Game::Pannel.w - System::GetSurfaceWidth() - 5);
    Game::LivesText.SetY(5);

    //Initialize the score text
    Game::score = System::Users::Current.GetCurrentScore();
    Game::ScoreText.SetText("Score: " + to_string(Game::score));
    Game::ScoreText.SetColor(255, 255, 255);
    Game::ScoreText.SetFont(System::Fonts::Game_Score);
    Game::ScoreText.SetX(Game::Pannel.x + 5);
    Game::ScoreText.SetY(5);
}

void Game::StartGame()
{
    SDL_FlushEvent(SDL_KEYDOWN);
    SDL_FlushEvent(SDL_KEYUP);

    while(Game::isRunning)
    {
        Game::fps->SetTestTick();
        UFO::Spown();

        SoundManager::Play(SoundManager::Sounds::BackgroundMusic);

        Game::ScoreText.SetText("Score: " + to_string(Game::score));
        Game::ScoreText.SetFont(System::Fonts::Game_Score);

        if(RankList::IsHighScore(Game::score))
        {
            System::Users::Current.SetNewHighScore(Game::score);
            Game::ScoreText.SetColor(0, 255, 0);
        }

        Game::LivesText.SetText("Lives: " + to_string(Player::lives));
        Game::LivesText.SetColor(255, 255, 255);
        Game::LivesText.SetFont(System::Fonts::Game_LivesLeft);

        if(framesAfterStart > framesToShowTheLevelNumber)
        {
            AliensManager::Move();
            BulletsManager::UpdateAll();

            if(!canShoot && framesAfterShooting < 20)
            {
                framesAfterShooting++;
            }
            else
            {
                canShoot = true;
                framesAfterShooting = 0;
            }
        }

        Game::GetPlayerInput();

        //Go to the next level if all the aliens are killed
        if(AliensManager::allAliens.size() == 0)
        {
            framesAfterStart = 0;
            Game::isRunning = false;
            System::Users::Current.SetCurrentScore(Game::score);

            //If this is the last level go to the 'You win window', else go to the next level
            if( !LevelManager::LoadLevel(System::Users::Current.GetCurrentLevel() + 1) )
                WinWindow::Show();
            else
            {
                Game::PreStartInitializations();
                Game::StartGame();
            }
            break;
        }

        //If the player is dead
        if(Player::isDead && Player::lives == 0)
        {
            Game::isRunning = false;
            for(int i = 0; i < NUMBER_OF_BARRIERS; i++)
            {
                delete(&Game::barriers[i]);
                Game::barriers[i] = NULL;
            }
            System::Users::Current.SetCurrentScore(Game::score);
            framesAfterStart = 0;
            GameOver::Show();
            break;
        }

        Game::RenderEverything();
        Game::fps->Delay();
    }
}

void Game::RenderEverything()
{
    SDL_RenderClear(System::renderer);

    //Render the game background
    SDL_RenderCopy(System::renderer, Game::background, NULL, NULL);

    //Render the game panel borders
    SDL_RenderCopy(System::renderer, Game::borderTexture, NULL, &Game::leftBorder);
    SDL_RenderCopy(System::renderer, Game::borderTexture, NULL, &Game::rightBorder);

    //Not render the aliens, the player and the bullets if it's the start of the game
    if(framesAfterStart > framesToShowTheLevelNumber)
    {
        BulletsManager::RenderAll();
        AliensManager::RenderAll();
    }
    Player::Render();

    //Render the barriers
    for(int i = 0; i < NUMBER_OF_BARRIERS; i++)
        Game::barriers[i]->Render();

    //Render the score
    Game::ScoreText.Render();

    //Render the lives left
    Game::LivesText.Render();

    //Render the level number if it's the start of the game
    if(framesAfterStart <= framesToShowTheLevelNumber && framesAfterStart % 1 == 0)
    {
        Game::LevelText.Render();
        framesAfterStart++;
    }

    UFO::Render();

    SDL_RenderPresent(System::renderer);
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
