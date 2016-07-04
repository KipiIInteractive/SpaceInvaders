#include "Game.h"

bool Game::isRunning = true;
SDL_Texture *Game::background = NULL;
SDL_Texture *Game::borderTexture = NULL;
SDL_Rect Game::Pannel;
SDL_Rect Game::leftBorder;
SDL_Rect Game::rightBorder;

const Uint8 *input = SDL_GetKeyboardState(NULL);
bool canShoot = true;
int Game::framesAfterShooting = 0;

void Game::Init()
{
    Game::Pannel.h = System::Screen::Height;
    Game::Pannel.w = System::Screen::Height + (System::Screen::Height / 4);
    Game::Pannel.y = 0;
    Game::Pannel.x = System::Screen::Width / 2 - Game::Pannel.w / 2;

    Game::leftBorder = {Game::Pannel.x - 5, 0, 5, Game::Pannel.h};
    Game::rightBorder = {Game::Pannel.x + Game::Pannel.w + 5, 0, 5, Game::Pannel.h};

    Game::background = System::CreateTexture("Resources/Textures/game_background.jpg", System::renderer);
    Game::borderTexture = System::CreateTexture("Resources/Textures/border.jpg", System::renderer);
}

void Game::StartGame()
{
    LevelManager::LoadLevel(LevelManager::GetCurrentLevel());

    Player::Init();

    while(Game::isRunning)
    {
        SDL_RenderClear(System::renderer);

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
    }

}

void Game::RenderEverything()
{
    SDL_RenderCopy(System::renderer, Game::background, NULL, NULL);
    SDL_RenderCopy(System::renderer, Game::borderTexture, NULL, &Game::leftBorder);
    SDL_RenderCopy(System::renderer, Game::borderTexture, NULL, &Game::rightBorder);
    AliensManager::RenderAll();
    BulletsManager::RenderAll();
    Player::Render();
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
