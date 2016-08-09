#include "LevelManager.h"
#include "../Game/Game.h"
#include <vector>
int LevelManager::currentClassicLevel;

#define LEVELS_PATH "Resources/Levels/"
#define MAX_ALIENS_ON_ROW 15
#define USER_FILES_EXTENSION ".user_data"

bool LevelManager::FileIsExisting(string filename)
{
    ifstream tmp(filename);
    return (bool)tmp;
}

void LevelManager::InitCurrentClassicLevel()
{
    LevelManager::currentClassicLevel = System::Users::Current.GetCurrentClassicLevel();
}

int LevelManager::GetCurrentClassicLevel() { return LevelManager::currentClassicLevel; }

bool LevelManager::LoadClassicLevel(int lvl)
{
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
                //Add the number of the AliensAlive in the AlienManager class
                if(line_num == 0)
                {
                    level >> AliensManager::numAliens;
                }

                //Add movement speed of the AliensAlive in the AlienManager class
                else if(line_num == 1)
                {
                    level >> AliensManager::movementSpeed;
                    AliensManager::movementDelayFrames = AliensManager::movementSpeed;
                }

                //Add the shooting power coefficient of the AliensAlive in the AlienManager class
                else if(line_num == 2)
                {
                    level >> AliensManager::shootingPowerCoefficient;
                }
                //Read the AliensAlive
                else if(line_num > 2)
                {
                    AlienType alienType;
                    int xPos = 0;
                    int yPos = 0;
                    string type;
                    if(level >> type >> yPos >> xPos) {
                        xPos *=  (Game::Pannel.w / MAX_ALIENS_ON_ROW);
                        xPos += Game::Pannel.x;
                        yPos *= Game::Pannel.w / MAX_ALIENS_ON_ROW + 5;
                        if(type == "SQUID") {
                            alienType = SQUID;
                        }
                        else if(type == "CRAB") {
                            alienType = CRAB;
                        }
                        else {
                            alienType = JELLYFISH;
                        }
                        AliensManager::AddNewAlien(alienType, xPos, yPos);
                    }
                }
            }

            level.close();
            System::Users::Current.SetcurrentClassicLevel(lvl);
            LevelManager::InitCurrentClassicLevel();

            ofstream cl;
            cl.open("Users/" + System::Users::Current.GetUsername());
            cl  << System::Users::Current.GetPassword() << ' '
                << System::Users::Current.GetHighScore() << ' '
                << System::Users::Current.GetCurrentScore() << ' '
                << System::Users::Current.GetCurrentClassicLevel() << '\n';
            cl.close();

            return true;
        }
        else return false;
    }
    else return false;
}

bool LevelManager::LoadSurvivalLevel() {
    string fileToOpen = "./Resources/Levels/survival.level";
    if(LevelManager::FileIsExisting(fileToOpen))
    {
        ifstream level(fileToOpen);
        if(level.is_open())
        {
            string line;
            unsigned line_num = 0;
            for(std::string line; getline(level, line); line_num++)
            {
                //Add the number of the AliensAlive in the AlienManager class
                if(line_num == 0)
                {
                    level >> AliensManager::numAliens;
                }

                else if(line_num == 1) {
                    level >> AliensManager::aliensOnRow;
                }

                //Add movement speed of the Aliens in the AlienManager class
                else if(line_num == 2)
                {
                    level >> AliensManager::movementSpeed;
                    AliensManager::movementDelayFrames = AliensManager::movementSpeed;
                }

                //Add the shooting power coefficient of the Aliens in the AlienManager class
                else if(line_num == 3)
                {
                    level >> AliensManager::shootingPowerCoefficient;
                }
                //Add Aliens while setting their initial pos
                else if(line_num > 3)
                {
                    AlienType alienType;
                    int xPos = 0;
                    int yPos = 0;
                    string type;
                    if(level >> type >> yPos >> xPos) {
                        xPos *=  (Game::Pannel.w / MAX_ALIENS_ON_ROW);
                        xPos += Game::Pannel.x;
                        yPos *= Game::Pannel.w / MAX_ALIENS_ON_ROW + 5;
                        if(type == "SQUID") {
                            alienType = SQUID;
                        }
                        else if(type == "CRAB") {
                            alienType = CRAB;
                        }
                        else {
                            alienType = JELLYFISH;
                        }
                        AliensManager::AddNewAlien(alienType, xPos, yPos);
                    }
                }
            }

            level.close();
            return true;
        }
        else return false;
    }
    else return false;
}
