#include "LevelManager.h"

int LevelManager::LEVEL_SIGN_FRAME_COUNTER = 0;

int LevelManager::currentClassicLevel = 0;

bool LevelManager::loadNextClassicLevel = true;
bool LevelManager::loadSurvivalLevel = true;

bool LevelManager::renderedClassicLevel = false;
bool LevelManager::renderedSurvivalLevel = false;

bool LevelManager::FileIsExisting(string filename)
{
    ifstream tmp(filename);
    return (bool)tmp;
}

void LevelManager::InitCurrentClassicLevel()
{
    if(LevelManager::FileIsExisting("./levels/current.level")) {
        ifstream level("./levels/current.level");
        level >> LevelManager::currentClassicLevel;
        level.close();
    }
}

int LevelManager::GetCurrentClassicLevel() { return currentClassicLevel; }

bool LevelManager::LoadSurvivalLevel() {
    string fileToOpen = "./levels/survival.level";
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
                    ENEMY_MOVEMENT_SPEED = ((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*1)/100;

                }
                else if(line_num == 3){
                    level >> ENEMY_SHOOTING_SPEED;
                    ENEMY_SHOOTING_SPEED = ((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*1)/100;
                    cout << ENEMY_SHOOTING_SPEED << endl;
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

bool LevelManager::LoadClassicLevel(int lvl)
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
                    ENEMY_MOVEMENT_SPEED = ((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*1)/100;
                }
                else if(line_num == 3){
                    level >> ENEMY_SHOOTING_SPEED;
                    ENEMY_SHOOTING_SPEED = ((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*1)/100;
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

void LevelManager::RenderSurvivalLevel() {
    if(LevelManager::LEVEL_SIGN_FRAME_COUNTER < 80) {
        gSurvivalLevelSignTexture.render(System::LEFT_X_BORDER + (System::RIGHT_X_BORDER - System::LEFT_X_BORDER - gSurvivalLevelSignTexture.getWidth())/2,
                                (System::SCREEN_HEIGHT - gSurvivalLevelSignTexture.getHeight())/2);
        LevelManager::LEVEL_SIGN_FRAME_COUNTER++;
    }
    else {
        LevelManager::LEVEL_SIGN_FRAME_COUNTER = 0;
        LevelManager::renderedSurvivalLevel = true;
    }
}

void LevelManager::RenderCurrentClassicLevel() {
    if(gClassicLevelDigitTexture.loadFromRenderedText("" + to_string(LevelManager::currentClassicLevel), {255, 255, 255, 200})) {
        if(LevelManager::LEVEL_SIGN_FRAME_COUNTER < 80) {
            gClassicLevelSignTexture.render(System::LEFT_X_BORDER + (System::RIGHT_X_BORDER - System::LEFT_X_BORDER - gClassicLevelSignTexture.getWidth() - gClassicLevelDigitTexture.getWidth())/2,
                                    (System::SCREEN_HEIGHT - gClassicLevelSignTexture.getHeight())/2);
            gClassicLevelDigitTexture.render(System::LEFT_X_BORDER + (System::RIGHT_X_BORDER - System::LEFT_X_BORDER - gClassicLevelSignTexture.getWidth() - gClassicLevelDigitTexture.getWidth())/2 + gClassicLevelSignTexture.getWidth(),
                                    (System::SCREEN_HEIGHT - gClassicLevelDigitTexture.getHeight())/2);
            LevelManager::LEVEL_SIGN_FRAME_COUNTER++;
        }
        else {
            LevelManager::LEVEL_SIGN_FRAME_COUNTER = 0;
            LevelManager::renderedClassicLevel = true;
        }
    }
}

void LevelManager::ResetClassicGameLevel() {
    if(LevelManager::GetCurrentClassicLevel() != 1) {
        ofstream file("./levels/current.level");
        if(file.is_open()) {
            file << 1;
            file.close();
        }
    }
    LevelManager::loadNextClassicLevel = true;
}
