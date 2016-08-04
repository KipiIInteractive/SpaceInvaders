#include "RankList.h"

Label RankList::text_title;
Label RankList::topPlayers[TOP_PLAYERS_NUM];

SDL_Texture *RankList::background_texture = NULL;
bool RankList::isActive;

string RankList::top_players[TOP_PLAYERS_NUM];

Label RankList::text_navigation_hint;
int RankList::allScores[TOP_PLAYERS_NUM];

void RankList::Init()
{
    RankList::isActive = false;

    RankList::background_texture = System::Textures::Background_Black;

    //Initialize the title text texture
    RankList::text_title.SetText("Top players:");
    RankList::text_title.SetColor(0, 255, 0);
    RankList::text_title.SetFont(System::Fonts::RankList_Title);
    RankList::text_title.SetX(System::Screen::Width / 2 - RankList::text_title.GetWidth() / 2);
    RankList::text_title.SetY(System::Screen::Height / 6);

    //Initialize the navigation hints text
    RankList::text_navigation_hint.SetText("Press Fire to quit the rank list");
    RankList::text_navigation_hint.SetColor(200, 200, 0);
    RankList::text_navigation_hint.SetFont(System::Fonts::RankList_NavigationHints);
    RankList::text_navigation_hint.SetX(System::Screen::Width / 2 - RankList::text_navigation_hint.GetWidth() / 2);
    RankList::text_navigation_hint.SetY(System::Screen::Height - 50 );

    RankList::GetTopPlayers();
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
                if(System::event.key.keysym.sym == SDLK_SPACE)
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
    string user, ranklist_line[TOP_PLAYERS_NUM];
    int score;
    int records = 0;

    ifstream file(RANKLIST_FILE);
        while(file >> user >> score)
        {
            ranklist_line[records] = user + ' ' + to_string(score);
            RankList::allScores[records] = score;
            records++;
        }
        for(unsigned i = records; i < TOP_PLAYERS_NUM; i++)
            RankList::allScores[i] = 0;
    file.close();

    for(unsigned i = 0 ; i < TOP_PLAYERS_NUM; i++)
    {
        if(i < records)
            RankList::topPlayers[i].SetText(ranklist_line[i]);
        else
            RankList::topPlayers[i].SetText("-");

        RankList::topPlayers[i].SetColor(255, 255, 255);

        TTF_Font *tmp_font = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
        RankList::topPlayers[i].SetFont(tmp_font);

        RankList::topPlayers[i].SetY((i * RankList::topPlayers[i].GetHeight()) + (RankList::text_title.GetHeight() + RankList::text_title.GetY() + 50));
        RankList::topPlayers[i].SetX(System::Screen::Width / 2 - RankList::topPlayers[i].GetWidth() / 2);
    }
}

void RankList::AddToTheRankList(string name, int score)
{
    int place = 0;
    ofstream ranklist;
    ranklist.open(RANKLIST_FILE);
        for(unsigned i = 0; i < TOP_PLAYERS_NUM; i++)
        {
            if(score > RankList::allScores[i])
            {
                ranklist << name << ' ' << score << '\n';
                place = i;
                for(unsigned place = i + 1; place < TOP_PLAYERS_NUM; place++)
                {
                    ranklist << RankList::topPlayers[place].GetText() << '\n';
                }
                break;
            }
            else
            {
                ranklist << RankList::topPlayers[i].GetText() << '\n';
            }
        }
    ranklist.close();
}

bool RankList::IsHighScore(int score)
{
    for(unsigned i = 0; i < TOP_PLAYERS_NUM; i++)
    {
        if(score > RankList::allScores[i])
            return true;
    }
    return false;
}

int RankList::GetHighScore(int position_in_ranklist) { return RankList::allScores[position_in_ranklist]; }
