#ifndef RANKLIST_H_INCLUDED
#define RANKLIST_H_INCLUDED

#include "../profile_managment/ProfileManager.h"
#include "../System/System.h"
#include "../GUI/Label.h"

#define TOP_PLAYERS_NUM 5

class RankList
{
    public:
        static void Init();
        static void Show();

    private:
        static bool isActive;
        static string top_players[];
        static Label text_title;
        static SDL_Texture *background_texture;

        static void RenderEverything();

        static Label topPlayers[TOP_PLAYERS_NUM];
        static void GetTopPlayers();

        static Label text_navigation_hint;
};

#endif // RANKLIST_H_INCLUDED
