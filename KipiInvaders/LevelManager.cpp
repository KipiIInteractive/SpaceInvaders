#include "LevelManager.h"

int LevelManager::LEVEL_SIGN_FRAME_COUNTER = 0;

int LevelManager::currentLevel = 0;

bool LevelManager::loadNextLevel = true;

bool LevelManager::renderedLevel = false;

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

void LevelManager::RenderCurrentLevel() {
    if(gLevelDigitTexture.loadFromRenderedText("" + to_string(LevelManager::currentLevel), {255, 255, 255, 200})) {
        if(LevelManager::LEVEL_SIGN_FRAME_COUNTER < 80) {
            gLevelSignTexture.render((System::RIGHT_X_BORDER - System::LEFT_X_BORDER - gLevelSignTexture.getWidth() - gLevelDigitTexture.getWidth())/2,
                                    (System::SCREEN_HEIGHT - gLevelSignTexture.getHeight())/2);
            gLevelDigitTexture.render((System::RIGHT_X_BORDER - System::LEFT_X_BORDER - gLevelSignTexture.getWidth() - gLevelDigitTexture.getWidth())/2 + gLevelSignTexture.getWidth(),
                                    (System::SCREEN_HEIGHT - gLevelDigitTexture.getHeight())/2);
            LevelManager::LEVEL_SIGN_FRAME_COUNTER++;
        }
        else {
            LevelManager::LEVEL_SIGN_FRAME_COUNTER = 0;
            LevelManager::renderedLevel = true;
        }
    }
}
