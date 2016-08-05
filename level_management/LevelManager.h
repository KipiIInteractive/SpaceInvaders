#ifndef LEVELMANAGER_H_INCLUDED
#define LEVELMANAGER_H_INCLUDED

#include <fstream>
#include <iostream>
#include "../Entities/AliensManager.h"

using namespace std;

class LevelManager
{
    public:
        static void InitCurrentLevel();
        static int GetCurrentLevel();

        static bool LoadLevel(int level);


    private:
        static int currentLevel;
        static bool FileIsExisting(string filename);

};

#endif // LEVELMANAGER_H_INCLUDED
