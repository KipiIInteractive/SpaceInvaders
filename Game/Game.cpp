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
<<<<<<< HEAD
int Game::score = 0;
int Game::framesToShowTheLevelNumber = 300;
=======
int Game::score;
int Game::framesToShowTheLevelNumber = 150;
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
int framesAfterStart = 0;

#define NUMBER_OF_BARRIERS 3
Barrier *Game::barriers[NUMBER_OF_BARRIERS];

const Uint8 *input = SDL_GetKeyboardState(NULL);
<<<<<<< HEAD
bool canShoot = true;
=======
bool canShoot = false;
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
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

<<<<<<< HEAD
    Game::background = System::CreateTexture("Resources/Textures/game_background.jpg", System::renderer);
    Game::borderTexture = System::CreateTexture("Resources/Textures/border.jpg", System::renderer);
=======
    Game::background = System::Textures::Background_Black;
    Game::borderTexture = System::Textures::Border;

    //Initialize the FPS regulation controller
    Game::fps = new FPS_Controller(60);
}

void Game::PreStartInitializations()
{
    Game::isRunning = true;
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

    //Initialize the barriers for the level
    int offset = Game::Pannel.w / 3;
    int firstBarrierX = Game::Pannel.x - offset / 1.5;
<<<<<<< HEAD

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
=======
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
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

    //Initialize the left lives text
    Game::LivesText.SetText("Lives: " + to_string(Player::lives));
    Game::LivesText.SetColor(255, 255, 255);
<<<<<<< HEAD
    Game::LivesText.SetFont(System::Fonts::Score);
    Game::LivesText.SetX(Game::Pannel.x + Game::Pannel.w - System::GetSurfaceWidth() - 5);
    Game::LivesText.SetY(5);

    Player::Init();
=======
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
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

    while(Game::isRunning)
    {
        Game::fps->SetTestTick();

<<<<<<< HEAD
<<<<<<< HEAD
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
=======
=======
        UFO::Spown();

>>>>>>> ecbd78b... The UFO feature is added. On launch Start Menu is shown with options to
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
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

        //Go to the next level if all the aliens are killed
        if(AliensManager::allAliens.size() == 0)
        {
            framesAfterStart = 0;
            Game::isRunning = false;
<<<<<<< HEAD
            LevelManager::LoadLevel(System::Users::Current.GetCurrentLevel() + 1);
            Game::Init();
        }
=======
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

>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
        //If the player is dead
        if(Player::isDead && Player::lives == 0)
        {
            Game::isRunning = false;
<<<<<<< HEAD
            GameOver::Show();
        }

        Game::fps->Delay();
    }

=======
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
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
}

void Game::RenderEverything()
{
<<<<<<< HEAD
=======
    SDL_RenderClear(System::renderer);

>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    //Render the game background
    SDL_RenderCopy(System::renderer, Game::background, NULL, NULL);

    //Render the game panel borders
    SDL_RenderCopy(System::renderer, Game::borderTexture, NULL, &Game::leftBorder);
    SDL_RenderCopy(System::renderer, Game::borderTexture, NULL, &Game::rightBorder);

<<<<<<< HEAD
    //Render the aliens, the player and the bullets
    BulletsManager::RenderAll();
    AliensManager::RenderAll();
=======
    //Not render the aliens, the player and the bullets if it's the start of the game
    if(framesAfterStart > framesToShowTheLevelNumber)
    {
        BulletsManager::RenderAll();
        AliensManager::RenderAll();
    }
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    Player::Render();

    //Render the barriers
    for(int i = 0; i < NUMBER_OF_BARRIERS; i++)
        Game::barriers[i]->Render();

    //Render the score
    Game::ScoreText.Render();

    //Render the lives left
    Game::LivesText.Render();

<<<<<<< HEAD
    //Render the level number
=======
    //Render the level number if it's the start of the game
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    if(framesAfterStart <= framesToShowTheLevelNumber && framesAfterStart % 1 == 0)
    {
        Game::LevelText.Render();
        framesAfterStart++;
    }
<<<<<<< HEAD
=======

    UFO::Render();

    SDL_RenderPresent(System::renderer);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
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
<<<<<<< HEAD
            //SoundManager::Play(SoundManager::Sounds::Shoot);
=======
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
            Player::Shoot();
            canShoot = false;
        }
    }
}
<<<<<<< HEAD

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
=======
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
