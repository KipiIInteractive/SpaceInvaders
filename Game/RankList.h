#ifndef RANKLIST_H_INCLUDED
#define RANKLIST_H_INCLUDED

#include "../profile_managment/ProfileManager.h"
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
        static int GetHighScore(int position_in_ranklist);
        static void AddToTheRankList(string name, int score);
        static bool IsHighScore(int score);
        static void GetTopPlayers();

        static bool isActive;
        static string top_players[];
        static Label text_title;
        static SDL_Texture *background_texture;

        static void RenderEverything();

        static Label topPlayers[TOP_PLAYERS_NUM];

        static Label text_navigation_hint;
        static int allScores[TOP_PLAYERS_NUM];
};

#endif // RANKLIST_H_INCLUDED
