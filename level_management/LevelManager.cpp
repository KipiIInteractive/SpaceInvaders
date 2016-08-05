#include "LevelManager.h"
#include "../Game/Game.h"
#include <vector>
int LevelManager::currentLevel;

#define LEVELS_PATH "Resources/Levels/"
#define MAX_ALIENS_ON_ROW 15
#define USER_FILES_EXTENSION ".user_data"

bool LevelManager::FileIsExisting(string filename)
{
    ifstream tmp(filename);
    return (bool)tmp;
}

void LevelManager::InitCurrentLevel()
{
    LevelManager::currentLevel = System::Users::Current.GetCurrentLevel();
}

int LevelManager::GetCurrentLevel() { return LevelManager::currentLevel; }

bool LevelManager::LoadLevel(int lvl)
{
    AliensManager::FreeAllAliens();
    BulletsManager::FreeAllBullets();

    string fileToOpen = (string)LEVELS_PATH + to_string(lvl) + ".level";
    if(LevelManager::FileIsExisting(fileToOpen))
    {
        ifstream level(fileToOpen);
        if(level.is_open())
        {
            string line;
            unsigned line_num = 0;
            for(std::string line; getline(level, line); line_num++)
            {
                //Add the number of the aliens in the AlienManager class
                if(line_num == 0)
                {
                    level >> AliensManager::number;
                }

                //Add movement speed of the aliens in the AlienManager class
                else if(line_num == 1)
                {
                    level >> AliensManager::movementSpeed;
                }

                //Add the shooting power coefficient of the aliens in the AlienManager class
                else if(line_num == 2)
                {
                    level >> AliensManager::shootingPowerCoefficient;
                    Game::Pannel.h / 44;
                }
                //Read the aliens
                else if(line_num > 2)
                {
                    int type = 0;
                    int pos_x = 0;
                    int pos_y = 0;
                    level >> type >> pos_y >> pos_x;
                    pos_x *=  (Game::Pannel.w / MAX_ALIENS_ON_ROW);
                    pos_x += Game::Pannel.x;
                    pos_y *= Game::Pannel.w / MAX_ALIENS_ON_ROW + 5;
                    AliensManager::AddNewAlien(type, pos_x, pos_y);
                }
            }

            level.close();
            System::Users::Current.SetCurrentLevel(lvl);
            LevelManager::InitCurrentLevel();

            ofstream cl;
            cl.open("Users/" + System::Users::Current.GetUsername());
            cl  << System::Users::Current.GetPassword() << ' '
                << System::Users::Current.GetHighScore() << ' '
                << System::Users::Current.GetCurrentScore() << ' '
                << System::Users::Current.GetCurrentLevel() << '\n';
            cl.close();

            return true;
        }
        else return false;
    }
    else return false;
}
