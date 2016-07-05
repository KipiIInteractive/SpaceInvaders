#include "GameObjectGenerator.h"

const int ENEMY_ROWS = 4;
const int MAX_ALIENS_ON_ROW = 12;

list<Enemy*> enemies;
vector<Enemy*> firstRowOfEnemies;
vector<Enemy*> secondRowOfEnemies;
vector<Enemy*> thirdRowOfEnemies;
vector<Enemy*> fourthRowOfEnemies;

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

                    enemies.push_back(enemy);
                }
                else {
                    return;
                }
            }
        }
        list<Enemy*>::iterator it = enemies.begin();
        firstRowOfEnemies.insert(firstRowOfEnemies.end(), it, next(it, MAX_ALIENS_ON_ROW));
        secondRowOfEnemies.insert(secondRowOfEnemies.end(), next(it, MAX_ALIENS_ON_ROW), next(it, 2*MAX_ALIENS_ON_ROW));
        thirdRowOfEnemies.insert(thirdRowOfEnemies.end(), next(it, 2*MAX_ALIENS_ON_ROW), next(it, 3*MAX_ALIENS_ON_ROW));
        fourthRowOfEnemies.insert(fourthRowOfEnemies.end(), next(it, 3*MAX_ALIENS_ON_ROW), next(it, 4*MAX_ALIENS_ON_ROW));
        GameObjectGenerator::enemiesGenerated = true;
    }
}

void GameObjectGenerator::generatePlayer() {

}
