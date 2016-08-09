#include "Game.h"

string Game::currentGameMode = "";
bool Game::isRunning;
SDL_Texture *Game::background = NULL;
SDL_Texture *Game::borderTexture = NULL;
SDL_Rect Game::Pannel;
SDL_Rect Game::leftBorder;
SDL_Rect Game::rightBorder;
Label Game::ScoreText;
Label Game::LevelText;
Label Game::LivesText;
int Game::pScore = 0;
int Game::LevelRenderTimeInSeconds = 150;
int timeInSecondsAfterGameStart = 0;

Barrier *Game::barriers[NUMBER_OF_BARRIERS];

const Uint8 *input = SDL_GetKeyboardState(NULL);
bool playerCanShoot = false;
int Game::timeInSecondsAfterPlayerShooting = 0;

FPS_Controller *Game::fps;

void Game::Init()
{
    //Initialize the resolution for the game panel
    float gameScreenAspectRatio = (float)5/4;
    Game::Pannel.h = System::Screen::Height;
    Game::Pannel.w = System::Screen::Height * gameScreenAspectRatio;
    Game::Pannel.y = 0;
    Game::Pannel.x = System::Screen::Width / 2 - Game::Pannel.w / 2;

    //Set borders to the game panel
    int borderWidth = 5;
    Game::leftBorder = {Game::Pannel.x - borderWidth, 0, borderWidth, Game::Pannel.h};
    Game::rightBorder = {Game::Pannel.x + Game::Pannel.w, 0, borderWidth, Game::Pannel.h};

    Game::background = System::Textures::Background;
    Game::borderTexture = System::Textures::Border;

    //Initialize the FPS regulation controller
    Game::fps = new FPS_Controller(60);
}

void Game::PreClassicGameStartInitializations()
{
    Game::isRunning = true;

    //Initialize the barriers and their pos for the level
    int distanceBetweenBarriers = Game::Pannel.w / 3;
    float barrierYIndentationFromScreenBottomMultiplier = (float)3/4;
    for(int i = 0; i < NUMBER_OF_BARRIERS; i++)
    {
        Barrier *newBarrier = new Barrier(Game::Pannel.x - distanceBetweenBarriers / 1.5 + (i+1)*distanceBetweenBarriers, Game::Pannel.h * barrierYIndentationFromScreenBottomMultiplier);
        Game::barriers[i] = newBarrier;
    }

    LevelManager::LoadClassicLevel(System::Users::Current.GetCurrentClassicLevel());

    //Initialize the level text
    Game::LevelText.SetText("Level " + to_string(System::Users::Current.GetCurrentClassicLevel()));
    Game::LevelText.SetColor(255, 255, 255);
    Game::LevelText.SetFont(System::Fonts::GameLevel);
    Game::LevelText.SetX(System::Screen::Width / 2 - Game::LevelText.GetWidth() / 2);
    Game::LevelText.SetY(System::Screen::Height / 2 - Game::LevelText.GetHeight() / 2);

    //Initialize the player lives text
    int livesTextAdditionalXIndentationSubtrahend = 5;
    Game::LivesText.SetText("Lives: " + to_string(Player::lives));
    Game::LivesText.SetColor(255, 255, 255);
    Game::LivesText.SetFont(System::Fonts::PlayerLivesLeft);
    Game::LivesText.SetX(Game::Pannel.x + Game::Pannel.w - System::GetSurfaceWidth() - livesTextAdditionalXIndentationSubtrahend);
    Game::LivesText.SetY(5);

    //Initialize the pScore text
    int scoreTextAdditionalXIndentationAddend = 5;
    Game::pScore = 0;
    Game::ScoreText.SetText("Score: " + to_string(Game::pScore));
    Game::ScoreText.SetColor(255, 255, 255);
    Game::ScoreText.SetFont(System::Fonts::PlayerScore);
    Game::ScoreText.SetX(Game::Pannel.x + scoreTextAdditionalXIndentationAddend);
    Game::ScoreText.SetY(5);
}

void Game::PreSurvivalGameStartInitializations()
{
    Game::isRunning = true;

    //Initialize the barriers for the level
    int distanceBetweenBarriers = Game::Pannel.w / 3;
    float barrierYIndentationFromScreenBottomMultiplier = (float)3/4;
    for(int i = 0; i < NUMBER_OF_BARRIERS; i++)
    {
        Barrier *newBarrier = new Barrier(Game::Pannel.x - distanceBetweenBarriers / 1.5 + (i+1)*distanceBetweenBarriers, Game::Pannel.h * barrierYIndentationFromScreenBottomMultiplier);
        Game::barriers[i] = newBarrier;
    }

    LevelManager::LoadSurvivalLevel();

    //Initialize the level text
    Game::LevelText.SetText("Survival Level");
    Game::LevelText.SetColor(255, 255, 255);
    Game::LevelText.SetFont(System::Fonts::GameLevel);
    Game::LevelText.SetX(System::Screen::Width / 2 - Game::LevelText.GetWidth() / 2);
    Game::LevelText.SetY(System::Screen::Height / 2 - Game::LevelText.GetHeight() / 2);

    //Initialize the left lives text
    int livesTextAdditionalXIndentationSubtrahend = 5;
    Game::LivesText.SetText("Lives: " + to_string(Player::lives));
    Game::LivesText.SetColor(255, 255, 255);
    Game::LivesText.SetFont(System::Fonts::PlayerLivesLeft);
    Game::LivesText.SetX(Game::Pannel.x + Game::Pannel.w - System::GetSurfaceWidth() - livesTextAdditionalXIndentationSubtrahend);
    Game::LivesText.SetY(5);

    //Initialize the player score text
    int scoreTextAdditionalXIndentationAddend = 5;
    Game::pScore = 0;
    Game::ScoreText.SetText("Score: " + to_string(Game::pScore));
    Game::ScoreText.SetColor(255, 255, 255);
    Game::ScoreText.SetFont(System::Fonts::PlayerScore);
    Game::ScoreText.SetX(Game::Pannel.x + scoreTextAdditionalXIndentationAddend);
    Game::ScoreText.SetY(5);
}

void Game::StartClassicGame()
{
    SDL_FlushEvent(SDL_KEYDOWN);
    SDL_FlushEvent(SDL_KEYUP);

    Game::currentGameMode = "classic";

    while(Game::isRunning)
    {
        Game::fps->SetTestTick();
        UFO::Spawn();

        SoundManager::Play(SoundManager::Sounds::BackgroundMusic);

        Game::ScoreText.SetText("Score: " + to_string(Game::pScore));
        Game::ScoreText.SetFont(System::Fonts::PlayerScore);

        if(RankList::IsHighScore(Game::pScore))
        {
            System::Users::Current.SetNewHighScore(Game::pScore);
            Game::ScoreText.SetColor(0, 255, 0);
        }

        Game::LivesText.SetText("Lives: " + to_string(Player::lives));
        Game::LivesText.SetColor(255, 255, 255);
        Game::LivesText.SetFont(System::Fonts::PlayerLivesLeft);

        if(timeInSecondsAfterGameStart > LevelRenderTimeInSeconds)
        {
            AliensManager::Move();
            BulletsManager::UpdateAll();

            if(!playerCanShoot && timeInSecondsAfterPlayerShooting < 20)
            {
                timeInSecondsAfterPlayerShooting++;
            }
            else
            {
                playerCanShoot = true;
                timeInSecondsAfterPlayerShooting = 0;
            }
        }

        Game::GetPlayerInput();

        //Go to the next level if all the Aliens are killed
        if(AliensManager::allAliensAreDead())
        {
            timeInSecondsAfterGameStart = 0;
            Player::isDead = false;
            Game::isRunning = false;
            //If this is the last level go to the 'You win window', else go to the next level
            if( !LevelManager::LoadClassicLevel(System::Users::Current.GetCurrentClassicLevel() + 1) ) {
                System::Users::Current.SetCurrentScore(Game::pScore);
                WinWindow::Show();
                System::Users::Current.SetcurrentClassicLevel(1);
                AliensManager::FreeAllAliens();
                BulletsManager::FreeAllBullets();
            }
            else
            {
                Game::isRunning = true;
                Game::LevelText.SetText("Level " + to_string(LevelManager::GetCurrentClassicLevel()));
                Game::LevelText.SetFont(System::Fonts::GameLevel);
                Game::StartClassicGame();
            }
            break;
        }

        //If the Player has no lives left
        if(Player::lives == 0)
        {
            timeInSecondsAfterGameStart = 0;
            Game::isRunning = false;
            for(int i = 0; i < NUMBER_OF_BARRIERS; i++)
            {
                delete(Game::barriers[i]);
                Game::barriers[i] = NULL;
            }
            System::Users::Current.SetCurrentScore(Game::pScore);
            GameOver::Show();
            Player::isDead = false;
            Player::lives = 3;
            AliensManager::FreeAllAliens();
            BulletsManager::FreeAllBullets();
            break;
        }

        Game::RenderEverything();
        Game::fps->Delay();
    }
}

void Game::StartSurvivalGame()
{
    SDL_FlushEvent(SDL_KEYDOWN);
    SDL_FlushEvent(SDL_KEYUP);

    Game::currentGameMode = "survival";

    while(Game::isRunning)
    {
        Game::fps->SetTestTick();
        UFO::Spawn();

        SoundManager::Play(SoundManager::Sounds::BackgroundMusic);

        Game::ScoreText.SetText("Score: " + to_string(Game::pScore));
        Game::ScoreText.SetFont(System::Fonts::PlayerScore);

        if(RankList::IsHighScore(Game::pScore))
        {
            System::Users::Current.SetNewHighScore(Game::pScore);
            Game::ScoreText.SetColor(0, 255, 0);
        }

        Game::LivesText.SetText("Lives: " + to_string(Player::lives));
        Game::LivesText.SetColor(255, 255, 255);
        Game::LivesText.SetFont(System::Fonts::PlayerLivesLeft);

        if(timeInSecondsAfterGameStart > LevelRenderTimeInSeconds)
        {
            AliensManager::Move();
            BulletsManager::UpdateAll();

            if(!playerCanShoot && timeInSecondsAfterPlayerShooting < 20)
            {
                timeInSecondsAfterPlayerShooting++;
            }
            else
            {
                playerCanShoot = true;
                timeInSecondsAfterPlayerShooting = 0;
            }
        }

        Game::GetPlayerInput();

        //show the win window if all the Aliens are killed
        if(AliensManager::allAliensAreDead())
        {
            Player::isDead = false;
            Game::isRunning = false;
            System::Users::Current.SetCurrentScore(Game::pScore);
            WinWindow::Show();
            timeInSecondsAfterGameStart = 0;
            AliensManager::FreeAllAliens();
            BulletsManager::FreeAllBullets();
            break;
        }

        //If the player is dead
        if(Player::lives == 0)
        {
            Game::isRunning = false;
            for(int i = 0; i < NUMBER_OF_BARRIERS; i++)
            {
                delete(Game::barriers[i]);
                Game::barriers[i] = NULL;
            }
            System::Users::Current.SetCurrentScore(Game::pScore);
            GameOver::Show();
            Player::isDead = false;
            Player::lives = 3;
            timeInSecondsAfterGameStart = 0;
            AliensManager::FreeAllAliens();
            BulletsManager::FreeAllBullets();
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
    if(timeInSecondsAfterGameStart > LevelRenderTimeInSeconds)
    {
        BulletsManager::RenderAll();
        AliensManager::RenderAll();
    }
    Player::Render();

    //Render the barriers
    for(int i = 0; i < NUMBER_OF_BARRIERS; i++) {
        Game::barriers[i]->Render();
    }

    //Render score
    Game::ScoreText.Render();

    //Render the lives left
    Game::LivesText.Render();

    //Render the level number if it's the start of the game
    if(timeInSecondsAfterGameStart <= LevelRenderTimeInSeconds)
    {
        Game::LevelText.Render();
        timeInSecondsAfterGameStart++;
    }

    UFO::Render();

    SDL_RenderPresent(System::renderer);
}

void Game::GetPlayerInput()
{
    SDL_PumpEvents();

    if(input[SDL_SCANCODE_LEFT]) {
        Player::Move(System::Direction::Left);
    }

    if(input[SDL_SCANCODE_RIGHT]) {
        Player::Move(System::Direction::Right);
    }

    if(input[SDL_SCANCODE_SPACE])
    {
        if(playerCanShoot)
        {
            Player::Shoot();
            playerCanShoot = false;
        }
    }
}
