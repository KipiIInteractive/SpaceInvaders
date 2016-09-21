#include "RankList.h"

Label RankList::titleText;
Label RankList::topPlayers[TOP_PLAYERS_NUM];

SDL_Texture *RankList::backgroundTexture = NULL;
bool RankList::isActive;

Label RankList::navigationHintText;
int RankList::allScores[TOP_PLAYERS_NUM];

void RankList::Init()
{
    RankList::isActive = false;

    RankList::backgroundTexture = System::Textures::Background;

    //Initialize the title text texture
    int titleYIndentationFromScreenTopDivisor = 6;
    RankList::titleText.SetText("Top Players:");
    RankList::titleText.SetColor(0, 255, 0);
    RankList::titleText.SetFont(System::Fonts::RankListTitle);
    RankList::titleText.SetX(System::Screen::Width / 2 - RankList::titleText.GetWidth() / 2);
    RankList::titleText.SetY(System::Screen::Height / titleYIndentationFromScreenTopDivisor);

    //Initialize the navigation hints text
    int hintYIndentationFromScreenBottomSubtrahend = 50;
    RankList::navigationHintText.SetText("Press Fire to quit the rank list");
    RankList::navigationHintText.SetColor(200, 200, 0);
    RankList::navigationHintText.SetFont(System::Fonts::RankListNavigationHints);
    RankList::navigationHintText.SetX(System::Screen::Width / 2 - RankList::navigationHintText.GetWidth() / 2);
    RankList::navigationHintText.SetY(System::Screen::Height - hintYIndentationFromScreenBottomSubtrahend );

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
                if(System::event.key.keysym.sym == SDLK_SPACE) {
                    RankList::isActive = false;
                }
            }
        }
    }
}

void RankList::RenderEverything()
{
    SDL_RenderClear(System::renderer);

    SDL_RenderCopy(System::renderer, RankList::backgroundTexture, NULL, NULL);
    RankList::titleText.Render();

    for(int i = 0; i < TOP_PLAYERS_NUM; i++) {
        RankList::topPlayers[i].Render();
    }

    RankList::navigationHintText.Render();

    SDL_RenderPresent(System::renderer);
}

void RankList::GetTopPlayers()
{
    string user, ranklistLine[TOP_PLAYERS_NUM];
    int score;
    int records = 0;

    ifstream file(RANKLIST_FILE);
        while(file >> user >> score)
        {
            ranklistLine[records] = user + " " + to_string(score);
            RankList::allScores[records] = score;
            records++;
        }
        for(unsigned i = records; i < TOP_PLAYERS_NUM; i++) {
            RankList::allScores[i] = 0;
        }
    file.close();

    for(unsigned i = 0 ; i < TOP_PLAYERS_NUM; i++)
    {
        if(i < records) {
            RankList::topPlayers[i].SetText(ranklistLine[i]);
        }
        else {
            RankList::topPlayers[i].SetText("-");
        }
        RankList::topPlayers[i].SetColor(255, 255, 255);

        TTF_Font *tmpFont = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
        if(tmpFont != NULL) {
            RankList::topPlayers[i].SetFont(tmpFont);
            TTF_CloseFont(tmpFont);
            int topPlayersTextYIndentationFromTitleAddend = 50;
            RankList::topPlayers[i].SetY((i * RankList::topPlayers[i].GetHeight()) + (RankList::titleText.GetHeight() + RankList::titleText.GetY() + topPlayersTextYIndentationFromTitleAddend));
            RankList::topPlayers[i].SetX(System::Screen::Width / 2 - RankList::topPlayers[i].GetWidth() / 2);
        }
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
        if(score > RankList::allScores[i]) {
            return true;
        }
    }
    return false;
}

int RankList::GetHighScore(int positionInRanklist) { return RankList::allScores[positionInRanklist]; }
