#include "Game.h"

void Game::StartGame()
{
    LevelManager::LoadLevel(LevelManager::GetCurrentLevel());

    while(true)
    {
        SDL_RenderClear(System::renderer);

        Game::RenderEverything();

        SDL_RenderPresent(System::renderer);
    }

}

void Game::RenderEverything()
{
    AliensManager::RenderAll();
}
