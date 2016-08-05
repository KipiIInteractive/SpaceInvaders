#include "GameOverWindow.h"

SDL_Texture *GameOver::background_texture = NULL;
bool GameOver::isActive;

Label GameOver::text_title;
Label GameOver::text_title_top_players;
Label GameOver::text_score;
Label GameOver::text_navigation_hint;

void GameOver::Init()
{
    GameOver::isActive = false;
    GameOver::background_texture = System::Textures::Background_Black;

    //Initialize the title text
    GameOver::text_title.SetText("Game Over!");
    GameOver::text_title.SetColor(255, 0, 0);
    GameOver::text_title.SetFont(System::Fonts::GameOver_Title);
    GameOver::text_title.SetX(System::Screen::Width / 2 - GameOver::text_title.GetWidth() / 2);
    GameOver::text_title.SetY(System::Screen::Height / 10);

    //Initialize the top players title text
    GameOver::text_title_top_players.SetText("Top players:");
    GameOver::text_title_top_players.SetColor(255, 255, 255);
    GameOver::text_title_top_players.SetFont(System::Fonts::GameOver_Title_Top_Players);
    GameOver::text_title_top_players.SetX(System::Screen::Width / 2 - GameOver::text_title_top_players.GetWidth() / 2);
    GameOver::text_title_top_players.SetY(GameOver::text_title.GetY() + GameOver::text_title.GetHeight() + 40);


    //Initialize the navigation hints text
    GameOver::text_navigation_hint.SetText("Press Fire to continue");
    GameOver::text_navigation_hint.SetColor(200, 200, 0);
    GameOver::text_navigation_hint.SetFont(System::Fonts::GameOver_NavigationHints);
    GameOver::text_navigation_hint.SetX(System::Screen::Width / 2 - GameOver::text_navigation_hint.GetWidth() / 2);
    GameOver::text_navigation_hint.SetY(System::Screen::Height - 50 );
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
    for(unsigned i = 0 ; i < TOP_PLAYERS_NUM; i++)
        RankList::topPlayers[i].SetY((i * RankList::topPlayers[i].GetHeight()) + (GameOver::text_title_top_players.GetHeight() + GameOver::text_title_top_players.GetY() + 50));

    //Initialize the score text texture
    GameOver::text_score.SetText("Your Score: " + to_string(System::Users::Current.GetCurrentScore()));
    GameOver::text_score.SetColor(255, 0, 0);
    GameOver::text_score.SetFont(System::Fonts::GameOver_Score);
    GameOver::text_score.SetX(System::Screen::Width / 2 - GameOver::text_score.GetWidth() / 2);
    GameOver::text_score.SetY(RankList::topPlayers[TOP_PLAYERS_NUM - 1].GetY() + RankList::topPlayers[TOP_PLAYERS_NUM - 1].GetHeight() + GameOver::text_score.GetHeight());

    System::Users::Current.SetCurrentScore(0);

    System::Users::Current.SetCurrentLevel(1);

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

    SDL_RenderCopy(System::renderer, GameOver::background_texture, NULL, NULL);

    GameOver::text_title.Render();
    GameOver::text_title_top_players.Render();

    GameOver::text_score.Render();
    GameOver::text_navigation_hint.Render();

    for(int i = 0; i < TOP_PLAYERS_NUM; i++)
        RankList::topPlayers[i].Render();

    SDL_RenderPresent(System::renderer);
}
