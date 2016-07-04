#include "GameObjectGenerator.h"

const int ENEMY_ROWS = 4;
const int MAX_ALIENS_ON_ROW = 8;

bool GameObjectGenerator::enemiesGenerated = false;

void GameObjectGenerator::generateEnemies() {
    if(!enemiesGenerated) {
        int y;
        for(int i = 0; i < ENEMY_ROWS; i++) {
            for(int j = 0; j < MAX_ALIENS_ON_ROW; j++) {
                Enemy enemy;
                if(!enemy.loadFromFile("./images/enemy1.png")) {
                    return;
                }
                else {
                    enemy.setWidth(50);
                    enemy.setHeight(50);
                    enemy.setPosition((enemy.getWidth())*j, y);
                    enemies[i][j] = enemy;
                }
            }
            y += enemies[0][0].getHeight();
        }
        enemiesGenerated = true;
    }
}

void GameObjectGenerator::generatePlayer() {

}
