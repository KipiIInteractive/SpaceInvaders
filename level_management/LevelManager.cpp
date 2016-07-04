#include "LevelManager.h"
#include "../Game/Game.h"

int LevelManager::currentLevel;

#define LEVELS_PATH "Resources/Levels/"
#define MAX_ALIENS_ON_ROW 15

bool LevelManager::FileIsExisting(string filename)
{
    ifstream tmp(filename);
    return (bool)tmp;
}

void LevelManager::InitCurrentLevel()
{
    ifstream level((string)LEVELS_PATH + "current.level");
    level >> LevelManager::currentLevel;
    level.close();
}

int LevelManager::GetCurrentLevel() { return currentLevel; }

bool LevelManager::LoadLevel(int lvl)
{
    string fileToOpen = (string)LEVELS_PATH + to_string(lvl) + ".level";
    if(LevelManager::FileIsExisting(fileToOpen))
    {
        ifstream level(fileToOpen);
        if(level.is_open())
        {
            string line;
            int line_num = 0;
            for(std::string line; getline(level, line); )
            {
                //Add the number of the aliens in the AlienManager class
                if(line_num == 0)
                    level >> AliensManager::number;

                //Add movement speed of the aliens in the AlienManager class
                else if(line_num == 1)
                    level >> AliensManager::movementSpeed;

                //Add the shooting power coefficient of the aliens in the AlienManager class
                else if(line_num == 2)
                    level >> AliensManager::shootingPowerCoefficient;
                //Read the aliens
                else
                {
                    int type, pos_x, pos_y;
                    level >> type >> pos_y >> pos_x;
                    pos_x *=  (Game::Pannel.w / MAX_ALIENS_ON_ROW);
                    pos_x += Game::Pannel.x;
                    pos_y *= Game::Pannel.w / MAX_ALIENS_ON_ROW + 5;
                    AliensManager::AddNewAlien(type, pos_x, pos_y);
                }

                line_num++;
            }

            level.close();
            return true;
        }
        else return false;
    }
    else return false;
}
