#ifndef RANKLIST_H_INCLUDED
#define RANKLIST_H_INCLUDED

#include "../profile_management/ProfileManager.h"
#include "../System/System.h"
#include "../GUI/Label.h"

#include <fstream>

#define TOP_PLAYERS_NUM 5
#define RANKLIST_FILE "Resources/Ranklist/top_players.rank_list"

class RankList
{
    public:
        static void Init();
        static void Show();
        static int GetHighScore(int positionInRanklist);
        static void AddToTheRankList(string name, int score);
        static bool IsHighScore(int score);
        static void GetTopPlayers();

        static bool isActive;
        static Label titleText;
        static SDL_Texture *backgroundTexture;

        static void RenderEverything();

        static Label topPlayers[TOP_PLAYERS_NUM];

        static Label navigationHintText;
        static int allScores[TOP_PLAYERS_NUM];
};

#endif // RANKLIST_H_INCLUDED
