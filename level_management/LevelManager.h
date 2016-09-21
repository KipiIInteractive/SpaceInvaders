#ifndef LEVELMANAGER_H_INCLUDED
#define LEVELMANAGER_H_INCLUDED

#include <fstream>
#include <iostream>
#include "../Entities/AliensManager.h"
#include "../Entities/AlienType.h"

using namespace std;

class LevelManager
{
    public:
        static void InitCurrentClassicLevel();
        static int GetCurrentClassicLevel();

        static bool LoadClassicLevel(int level);
        static bool LoadSurvivalLevel();

    private:
        static int currentClassicLevel;
        static bool FileIsExisting(string filename);

};

#endif // LEVELMANAGER_H_INCLUDED
