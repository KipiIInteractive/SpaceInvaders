#ifndef LEVELMANAGER_H_INCLUDED
#define LEVELMANAGER_H_INCLUDED

#include <fstream>
#include <iostream>
#include "GameResources.h"

using namespace std;

class LevelManager
{
    public:
        static void InitCurrentClassicLevel();
        static int GetCurrentClassicLevel();

        static bool LoadClassicLevel(int level);
        static bool LoadSurvivalLevel();
        static bool loadNextClassicLevel;
        static bool loadSurvivalLevel;

        static void RenderCurrentClassicLevel();
        static void RenderSurvivalLevel();
        static bool renderedClassicLevel;
        static bool renderedSurvivalLevel;

        static void ResetClassicGameLevel();

        static int LEVEL_SIGN_FRAME_COUNTER;

    private:
        static int currentClassicLevel;
        static bool FileIsExisting(string filename);

};

#endif // LEVELMANAGER_H_INCLUDED
