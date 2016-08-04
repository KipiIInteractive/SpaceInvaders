#include "RankList.h"

Label RankList::text_title;
Label RankList::topPlayers[TOP_PLAYERS_NUM];

SDL_Texture *RankList::background_texture = NULL;
bool RankList::isActive;

string RankList::top_players[TOP_PLAYERS_NUM];

Label RankList::text_navigation_hint;

void RankList::Init()
{
    RankList::isActive = false;

    RankList::background_texture = System::Textures::Background_Black;

    for(int i = 0; i < TOP_PLAYERS_NUM; i++)
        RankList::top_players[i] = "---";

    //Initialize the title text texture
    RankList::text_title.SetText("Top players:");
    RankList::text_title.SetColor(0, 255, 0);
    RankList::text_title.SetFont(System::Fonts::RankList_Title);
    RankList::text_title.SetX(System::Screen::Width / 2 - RankList::text_title.GetWidth() / 2);
    RankList::text_title.SetY(System::Screen::Height / 6);

    //Initialize the navigation hints text
    RankList::text_navigation_hint.SetText("[ Escape = Quit ]");
    RankList::text_navigation_hint.SetColor(200, 200, 0);
    RankList::text_navigation_hint.SetFont(System::Fonts::RankList_NavigationHints);
    RankList::text_navigation_hint.SetX(System::Screen::Width / 2 - RankList::text_navigation_hint.GetWidth() / 2);
    RankList::text_navigation_hint.SetY(System::Screen::Height - 50 );
}

void RankList::Show()
{
    RankList::isActive = true;
    RankList::GetTopPlayers();
    SDL_FlushEvent(SDL_KEYDOWN);
    SDL_FlushEvent(SDL_KEYUP);
    RankList::RenderEverything();

    while(RankList::isActive)
    {
        if(SDL_PollEvent(&System::event))
        {
            if(System::event.type == SDL_KEYDOWN)
            {
                if(System::event.key.keysym.sym == SDLK_ESCAPE)
                    RankList::isActive = false;
            }
        }
    }
}

void RankList::RenderEverything()
{
    SDL_RenderClear(System::renderer);

    SDL_RenderCopy(System::renderer, RankList::background_texture, NULL, NULL);
    RankList::text_title.Render();

    for(int i = 0; i < TOP_PLAYERS_NUM; i++)
        RankList::topPlayers[i].Render();

    RankList::text_navigation_hint.Render();

    SDL_RenderPresent(System::renderer);
}

void RankList::GetTopPlayers()
{
    int last_best = 0;
    string last_usr = "";

    for(unsigned i = 0; i < TOP_PLAYERS_NUM; i++)
    {
        int best = 0;
        for(unsigned j = 0; j < ProfileManager::Users.size(); j++)
        {
            if(ProfileManager::Users[j].GetHighScore() >= best)
            {
                string file = ProfileManager::Users[j].GetUsername();

                if(i > 0)
                {
                    if(ProfileManager::Users[j].GetHighScore() < last_best)
                    {
                        best = ProfileManager::Users[j].GetHighScore();
                        string curr_usr = "";
                        //Get only the user name for the user
                        for(unsigned ch = 0; file[ch] != '.'; ch++)
                        {
                            curr_usr += file[ch];
                        }

                        if(curr_usr.compare(last_usr) != 0)
                        {
                            string data = curr_usr + " " + to_string(ProfileManager::Users[j].GetHighScore());
                            RankList::top_players[i] = data;
                            last_usr = curr_usr;
                        }
                    }
                }
                else
                {
                     string curr_usr = "";
                    //Get only the user name for the user
                    for(unsigned ch = 0; file[ch] != '.'; ch++)
                    {
                        curr_usr += file[ch];
                    }
                    string data = curr_usr + " " + to_string(ProfileManager::Users[j].GetHighScore());
                    RankList::top_players[i] = data;

                    last_usr = curr_usr;
                    best = ProfileManager::Users[j].GetHighScore();
                }
            }
        }
        last_best = best;
    }

    for(unsigned i = 0 ; i < TOP_PLAYERS_NUM; i++)
    {
        RankList::topPlayers[i].SetText(RankList::top_players[i]);
        RankList::topPlayers[i].SetColor(255, 255, 255);

        TTF_Font *tmp_font = NULL ;
        tmp_font = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
        RankList::topPlayers[i].SetFont(tmp_font);

        RankList::topPlayers[i].SetX(System::Screen::Width / 2 - RankList::topPlayers[i].GetWidth() / 2);
        RankList::topPlayers[i].SetY((i * RankList::topPlayers[i].GetHeight()) + (RankList::text_title.GetHeight() + RankList::text_title.GetY() + 50));
    }
}
