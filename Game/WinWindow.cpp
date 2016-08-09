#include "WinWindow.h"

SDL_Texture *WinWindow::backgroundTexture = NULL;
Label WinWindow::navigationHintText;
Label WinWindow::titleText;
Label WinWindow::topPlayersText;
Label WinWindow::scoreText;

bool WinWindow::isActive;

void WinWindow::Init()
{
    WinWindow::isActive = false;
    WinWindow::backgroundTexture = System::Textures::Background;

    //Initialize the title text
    int titleYIndentationFromScreenTopDivisor = 10;
    WinWindow::titleText.SetText("You Win!");
    WinWindow::titleText.SetColor(0, 255, 0);
    WinWindow::titleText.SetFont(System::Fonts::WinWindowTitle);
    WinWindow::titleText.SetX(System::Screen::Width / 2 - WinWindow::titleText.GetWidth() / 2);
    WinWindow::titleText.SetY(System::Screen::Height / titleYIndentationFromScreenTopDivisor);

    //Initialize the top players title text
    int topPlayersTextYIndentationFromTitleAddend = 40;
    WinWindow::topPlayersText.SetText("Top Players:");
    WinWindow::topPlayersText.SetColor(255, 255, 255);
    WinWindow::topPlayersText.SetFont(System::Fonts::WinWindowTopPlayers);
    WinWindow::topPlayersText.SetX(System::Screen::Width / 2 - WinWindow::topPlayersText.GetWidth() / 2);
    WinWindow::topPlayersText.SetY(WinWindow::titleText.GetY() + WinWindow::titleText.GetHeight() + topPlayersTextYIndentationFromTitleAddend);

    //Initialize the navigation hints text
    int hintYIndentationFromScreenBottomSubtrahend = 50;
    WinWindow::navigationHintText.SetText("Press Fire to continue");
    WinWindow::navigationHintText.SetColor(200, 200, 0);
    WinWindow::navigationHintText.SetFont(System::Fonts::WinWindowNavigationHints);
    WinWindow::navigationHintText.SetX(System::Screen::Width / 2 - WinWindow::navigationHintText.GetWidth() / 2);
    WinWindow::navigationHintText.SetY(System::Screen::Height - hintYIndentationFromScreenBottomSubtrahend );
}

void WinWindow::Show()
{
    WinWindow::isActive = true;

    //If current score can be in top five scores - put it in the rank list
    bool isTopScore = RankList::IsHighScore(System::Users::Current.GetCurrentScore());
    if(isTopScore)
    {
        NameSelectionWindow::Init();
        NameSelectionWindow::Show();
        RankList::AddToTheRankList(NameSelectionWindow::GetName(), System::Users::Current.GetCurrentScore());
    }

    RankList::GetTopPlayers();
    int topPlayersYIndentationFromOneAnotherAddend = 50;
    for(unsigned i = 0 ; i < TOP_PLAYERS_NUM; i++) {
        RankList::topPlayers[i].SetY((i * RankList::topPlayers[i].GetHeight()) + (WinWindow::topPlayersText.GetHeight() + WinWindow::topPlayersText.GetY() + topPlayersYIndentationFromOneAnotherAddend));
    }
    //Initialize the score text
    WinWindow::scoreText.SetText("Your Score: " + to_string(System::Users::Current.GetCurrentScore()));
    WinWindow::scoreText.SetColor(0, 255, 0);
    WinWindow::scoreText.SetFont(System::Fonts::WinWindowPlayerScore);
    WinWindow::scoreText.SetX(System::Screen::Width / 2 - WinWindow::scoreText.GetWidth() / 2);
    WinWindow::scoreText.SetY(RankList::topPlayers[TOP_PLAYERS_NUM - 1].GetY() + RankList::topPlayers[TOP_PLAYERS_NUM - 1].GetHeight() + WinWindow::scoreText.GetHeight());

    SDL_FlushEvent(SDL_KEYDOWN);
    SDL_FlushEvent(SDL_KEYUP);

    WinWindow::RenderEverything();

    while(WinWindow::isActive)
    {
        if(SDL_PollEvent(&System::event))
        {
            if(System::event.type == SDL_KEYDOWN)
            {
                if(System::event.key.keysym.sym == SDLK_SPACE)
                {
                    WinWindow::isActive = false;
                    break;
                }
            }
        }
    }
}

void WinWindow::RenderEverything()
{
    SDL_RenderClear(System::renderer);

    SDL_RenderCopy(System::renderer, WinWindow::backgroundTexture, NULL, NULL);

    WinWindow::titleText.Render();
    WinWindow::topPlayersText.Render();

    WinWindow::scoreText.Render();
    WinWindow::navigationHintText.Render();

    for(int i = 0; i < TOP_PLAYERS_NUM; i++) {
        RankList::topPlayers[i].Render();
    }

    SDL_RenderPresent(System::renderer);
}
