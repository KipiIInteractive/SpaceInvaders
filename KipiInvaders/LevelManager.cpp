#include "LevelManager.h"

int LevelManager::currentLevel = 0;

bool LevelManager::loadNextLevel = true;

bool LevelManager::FileIsExisting(string filename)
{
    ifstream tmp(filename);
    return (bool)tmp;
}

void LevelManager::InitCurrentLevel()
{
    if(LevelManager::FileIsExisting("./levels/current.level")) {
        ifstream level("./levels/current.level");
        level >> LevelManager::currentLevel;
        level.close();
    }
}

int LevelManager::GetCurrentLevel() { return currentLevel; }

bool LevelManager::LoadLevel(int lvl)
{
    string fileToOpen = "./levels/" + to_string(lvl) + ".level";
    if(LevelManager::FileIsExisting(fileToOpen))
    {
        ifstream level(fileToOpen);
        if(level.is_open())
        {
            string line;
            int line_num = 0;
            while(getline(level, line))
            {
                if(line_num == 0) {
                    level >> ENEMY_ROWS;
                }
                else if(line_num == 1) {
                    level >> MAX_ALIENS_ON_ROW;
                }
                //Add the shooting power coefficient of the alien
                else if(line_num == 2) {
                    level >> ENEMY_MOVEMENT_SPEED;
                }
                else if(line_num == 3){
                    level >> ENEMY_SHOOTING_SPEED;
                }
                line_num++;
            }
            REMAINING_ENEMIES = ENEMY_ROWS*MAX_ALIENS_ON_ROW;
            level.close();
            return true;
        }
        else return false;
    }
    else return false;
}
