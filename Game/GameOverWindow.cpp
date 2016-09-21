#include "GameOverWindow.h"

SDL_Texture *GameOver::backgroundTexture = NULL;
bool GameOver::isActive;

Label GameOver::titleText;
Label GameOver::topPlayersText;
Label GameOver::scoreText;
Label GameOver::navigationHintText;

void GameOver::Init()
{
    GameOver::isActive = false;
    GameOver::backgroundTexture = System::Textures::Background;

    //Initialize the title text
    int titleYIndentationFromScreenTopDivisor = 10;
    GameOver::titleText.SetText("Game Over!");
    GameOver::titleText.SetColor(255, 0, 0);
    GameOver::titleText.SetFont(System::Fonts::GameOverMenuTitle);
    GameOver::titleText.SetX(System::Screen::Width / 2 - GameOver::titleText.GetWidth() / 2);
    GameOver::titleText.SetY(System::Screen::Height / titleYIndentationFromScreenTopDivisor);

    //Initialize the top players title text
    int topPlayersTextYIndentationFromTitleAddend = 40;
    GameOver::topPlayersText.SetText("Top Players:");
    GameOver::topPlayersText.SetColor(255, 255, 255);
    GameOver::topPlayersText.SetFont(System::Fonts::GameOverMenuTopPlayers);
    GameOver::topPlayersText.SetX(System::Screen::Width / 2 - GameOver::topPlayersText.GetWidth() / 2);
    GameOver::topPlayersText.SetY(GameOver::titleText.GetY() + GameOver::titleText.GetHeight() + topPlayersTextYIndentationFromTitleAddend);


    //Initialize the navigation hints text
    int hintYIndentationFromScreenBottomSubtrahend = 50;
    GameOver::navigationHintText.SetText("Press Fire to continue");
    GameOver::navigationHintText.SetColor(200, 200, 0);
    GameOver::navigationHintText.SetFont(System::Fonts::GameOverMenuNavigationHints);
    GameOver::navigationHintText.SetX(System::Screen::Width / 2 - GameOver::navigationHintText.GetWidth() / 2);
    GameOver::navigationHintText.SetY(System::Screen::Height - hintYIndentationFromScreenBottomSubtrahend );
}

void GameOver::Show()
{
    GameOver::isActive = true;
    SDL_FlushEvent(SDL_KEYDOWN);
    SDL_FlushEvent(SDL_KEYUP);

    //If current score can be in top five scores - put it in the rank list
    bool isTopScore = RankList::IsHighScore(System::Users::Current.GetCurrentScore());
    if(isTopScore)
    {
        NameSelectionWindow::Init();
        NameSelectionWindow::Show();
        RankList::AddToTheRankList(NameSelectionWindow::GetName(), System::Users::Current.GetCurrentScore());
    }

    RankList::GetTopPlayers();
    for(unsigned i = 0 ; i < TOP_PLAYERS_NUM; i++) {
        RankList::topPlayers[i].SetY((i * RankList::topPlayers[i].GetHeight()) + (GameOver::topPlayersText.GetHeight() + GameOver::topPlayersText.GetY() + 50));
    }
    //Initialize the score text texture
    GameOver::scoreText.SetText("Your Score: " + to_string(System::Users::Current.GetCurrentScore()));
    GameOver::scoreText.SetColor(255, 0, 0);
    GameOver::scoreText.SetFont(System::Fonts::GameOverMenuPlayerScore);
    GameOver::scoreText.SetX(System::Screen::Width / 2 - GameOver::scoreText.GetWidth() / 2);
    GameOver::scoreText.SetY(RankList::topPlayers[TOP_PLAYERS_NUM - 1].GetY() + RankList::topPlayers[TOP_PLAYERS_NUM - 1].GetHeight() + GameOver::scoreText.GetHeight());

    System::Users::Current.SetCurrentScore(0);

    System::Users::Current.SetcurrentClassicLevel(1);

    GameOver::RenderEverything();

    while(GameOver::isActive)
    {
        if(SDL_PollEvent(&System::event))
        {
            if(System::event.type == SDL_KEYDOWN)
            {
                if(System::event.key.keysym.sym == SDLK_SPACE)
                {
                    GameOver::isActive = false;
                    break;
                }

            }
            GameOver::RenderEverything();
        }
    }
}

void GameOver::RenderEverything()
{
    SDL_RenderClear(System::renderer);

    SDL_RenderCopy(System::renderer, GameOver::backgroundTexture, NULL, NULL);

    GameOver::titleText.Render();
    GameOver::topPlayersText.Render();

    GameOver::scoreText.Render();
    GameOver::navigationHintText.Render();

    for(int i = 0; i < TOP_PLAYERS_NUM; i++) {
        RankList::topPlayers[i].Render();
    }

    SDL_RenderPresent(System::renderer);
}
