#include "GameObjectGenerator.h"
#include <vector>

const int ENEMY_ROWS = 4;
const int MAX_ALIENS_ON_ROW = 12;

list<Enemy*> enemies;
list<Enemy*> leftmostEnemyList;
list<Enemy*> rightmostEnemyList;

bool GameObjectGenerator::enemiesGenerated = false;

void GameObjectGenerator::generateEnemies() {
    if(!GameObjectGenerator::enemiesGenerated) {
        int y;
        for(int i = 0; i < ENEMY_ROWS; i++) {
            for(int j = 0; j < MAX_ALIENS_ON_ROW; j++) {
                Enemy* enemy = new Enemy();
                if((enemy->loadFromFile("./models/enemy1.png") && i % 2 != 0)
                   || (enemy->loadFromFile("./models/enemy2.png") && i % 2 == 0)) {
                    enemy->setWidth(50);
                    enemy->setHeight(50);
                    y = enemy->getHeight()*i + 20*(i+1);
                    enemy->setPosition(enemy->getWidth()*(j+1) + enemy->getWidth()*j, y);
                    enemy->setXVelocity(2);
                    if(i % 2 != 0) {
                        enemy->setMovementDirection(RIGHT);
                    }
                    else {
                        enemy->setMovementDirection(LEFT);
                    }
                    if(j == 0) {
                        leftmostEnemyList.push_back(enemy);
                    }
                    else if(j == MAX_ALIENS_ON_ROW - 1) {
                        rightmostEnemyList.push_back(enemy);
                    }
                    enemies.push_back(enemy);
                }
                else {
                    return;
                }
            }
        }
        GameObjectGenerator::enemiesGenerated = true;
    }
}

void GameObjectGenerator::generatePlayer() {

}
