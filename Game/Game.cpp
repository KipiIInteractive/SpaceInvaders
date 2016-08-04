#include "Game.h"

bool Game::isRunning = true;
SDL_Texture *Game::background = NULL;

void Game::StartGame()
{
    LevelManager::LoadLevel(LevelManager::GetCurrentLevel());

    Game::background = System::CreateTexture("Resources/Textures/game_background.bmp", System::renderer);

    while(Game::isRunning)
    {
        SDL_RenderClear(System::renderer);
        SDL_RenderCopy(System::renderer, Game::background, NULL, NULL);

        AliensManager::Move();
        Game::RenderEverything();
        SDL_RenderPresent(System::renderer);
    }

}

void Game::RenderEverything()
{
    AliensManager::RenderAll();
}
