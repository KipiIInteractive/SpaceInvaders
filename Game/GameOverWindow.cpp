#include "GameOverWindow.h"

SDL_Texture *GameOver::background_texture;
bool GameOver::isActive;
Link GameOver::NewGameButton;

void GameOver::Init()
{
    GameOver::background_texture = NULL;
    GameOver::background_texture = System::CreateTexture("Resources/Textures/game_background.jpg", System::renderer);
    if(GameOver::background_texture == NULL)
        std::cout << "Failed to create the game over background texture!" << std::endl;

    //Initialize the 'new game' button
    GameOver::NewGameButton.SetFont(System::Fonts::Buttons);
    GameOver::NewGameButton.SetText("New Game");
    GameOver::NewGameButton.SetColor(255, 0, 0);
    GameOver::NewGameButton.SetX(10);
    GameOver::NewGameButton.SetY(10);

    GameOver::isActive = false;
}

void GameOver::Show()
{
    GameOver::isActive = true;
    while(GameOver::isActive)
    {
        SDL_RenderClear(System::renderer);

        GameOver::CreateTheButtonsEffects();
        GameOver::CreateTheButtonsActions();
        if(SDL_PollEvent(&System::event))
            std::cout << "" ;
        SDL_RenderCopy(System::renderer, GameOver::background_texture, NULL, NULL);
        GameOver::NewGameButton.Render();
        SDL_RenderPresent(System::renderer);
    }
}

void GameOver::Free()
{
    SDL_DestroyTexture(GameOver::background_texture);
    delete(&GameOver::NewGameButton);
}

void GameOver::CreateTheButtonsEffects()
{
    //Change the color of the 'new game' button on hover
    if(GameOver::NewGameButton.isHover())
        GameOver::NewGameButton.SetColor(255, 255, 255);
    else
        GameOver::NewGameButton.SetColor(255, 0, 0);
}

void GameOver::CreateTheButtonsActions()
{
    if(GameOver::NewGameButton.isClicked())
    {
        GameOver::isActive = false;
        LevelManager::LoadLevel(1);
        Game::Init();
        Game::StartGame();
    }
}
