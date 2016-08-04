#include "WinWindow.h"

SDL_Texture *WinWindow::background_texture = NULL;
Label WinWindow::text_navigation_hint;
Label WinWindow::text_title;
Label WinWindow::text_title_top_players;
Label WinWindow::text_score;

bool WinWindow::isActive;

void WinWindow::Init()
{
    WinWindow::isActive = false;
    WinWindow::background_texture = System::Textures::Background_Black;

    //Initialize the title text
    WinWindow::text_title.SetText("You Win!");
    WinWindow::text_title.SetColor(0, 255, 0);
    WinWindow::text_title.SetFont(System::Fonts::WinWindow_Title);
    WinWindow::text_title.SetX(System::Screen::Width / 2 - WinWindow::text_title.GetWidth() / 2);
    WinWindow::text_title.SetY(System::Screen::Height / 10);

    //Initialize the top players title text
    WinWindow::text_title_top_players.SetText("Top Players:");
    WinWindow::text_title_top_players.SetColor(255, 255, 255);
    WinWindow::text_title_top_players.SetFont(System::Fonts::WinWindow_Title_Top_Players);
    WinWindow::text_title_top_players.SetX(System::Screen::Width / 2 - WinWindow::text_title_top_players.GetWidth() / 2);
    WinWindow::text_title_top_players.SetY(WinWindow::text_title.GetY() + WinWindow::text_title.GetHeight() + 40);

    //Initialize the navigation hints text
    WinWindow::text_navigation_hint.SetText("Press Fire to continue");
    WinWindow::text_navigation_hint.SetColor(200, 200, 0);
    WinWindow::text_navigation_hint.SetFont(System::Fonts::WinWindow_NavigationHints);
    WinWindow::text_navigation_hint.SetX(System::Screen::Width / 2 - WinWindow::text_navigation_hint.GetWidth() / 2);
    WinWindow::text_navigation_hint.SetY(System::Screen::Height - 50 );
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
    for(unsigned i = 0 ; i < TOP_PLAYERS_NUM; i++)
        RankList::topPlayers[i].SetY((i * RankList::topPlayers[i].GetHeight()) + (WinWindow::text_title_top_players.GetHeight() + WinWindow::text_title_top_players.GetY() + 50));

    //Initialize the score text
    WinWindow::text_score.SetText("Your Score: " + to_string(System::Users::Current.GetCurrentScore()));
    WinWindow::text_score.SetColor(0, 255, 0);
    WinWindow::text_score.SetFont(System::Fonts::WinWindow_Score);
    WinWindow::text_score.SetX(System::Screen::Width / 2 - WinWindow::text_score.GetWidth() / 2);
    WinWindow::text_score.SetY(RankList::topPlayers[TOP_PLAYERS_NUM - 1].GetY() + RankList::topPlayers[TOP_PLAYERS_NUM - 1].GetHeight() + WinWindow::text_score.GetHeight());

    System::Users::Current.SetCurrentLevel(1);
    Game::PreStartInitializations();

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

    SDL_RenderCopy(System::renderer, WinWindow::background_texture, NULL, NULL);

    WinWindow::text_title.Render();
    WinWindow::text_title_top_players.Render();

    WinWindow::text_score.Render();
    WinWindow::text_navigation_hint.Render();

    for(int i = 0; i < TOP_PLAYERS_NUM; i++)
        RankList::topPlayers[i].Render();

    SDL_RenderPresent(System::renderer);
}
