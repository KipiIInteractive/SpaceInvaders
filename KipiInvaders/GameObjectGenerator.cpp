#include "GameObjectGenerator.h"

const int ENEMY_ROWS = 4;
const int MAX_ALIENS_ON_ROW = 12;
int CURRENT_LEVEL = 1;
const int SHOOTING_RNG = 2000;

list<Enemy*> enemies;
vector<Enemy*> firstRowOfEnemies;
vector<Enemy*> secondRowOfEnemies;
vector<Enemy*> thirdRowOfEnemies;
vector<Enemy*> fourthRowOfEnemies;

list<Bullet*> bullets;

bool GameObjectGenerator::enemiesGenerated = false;

void GameObjectGenerator::generateEnemies() {
    if(!GameObjectGenerator::enemiesGenerated) {
        int y;
        for(int i = 0; i < ENEMY_ROWS; i++) {
            for(int j = 0; j < MAX_ALIENS_ON_ROW; j++) {
                Enemy* enemy = NULL;
                if(i % 2 != 0) {
                    enemy = new Enemy(/* texture = */ gEnemy1Texture, /* movementDirection = */ RIGHT, /*points= */ 20);
                }
                else {
                    enemy = new Enemy(/* texture = */ gEnemy2Texture, /* movementDirection = */ RIGHT, /*points= */ 50);
                }
                enemy->setWidth(50);
                enemy->setHeight(50);
                y = enemy->getHeight()*i + 20*(i+1);
                enemy->setPosition(enemy->getWidth()*(j+1) + enemy->getWidth()*j, y);
                enemy->setXVelocity(1*CURRENT_LEVEL);
                enemies.push_back(enemy);
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

void GameObjectGenerator::generateBullets() {
    int i = 0;
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
        if((i + MAX_ALIENS_ON_ROW >= enemies.size() && (*it)->isToShooT())
           || ((*it)->isToShooT() && !((*(next(enemies.begin(), MAX_ALIENS_ON_ROW)))->isAlive()))) {
            Bullet* bullet = new Bullet(/* texture = */ gBulletTexture, /* direction = */DOWN, /* velocity = */ 2*CURRENT_LEVEL);
            bullet->SetWidth(20);
            bullet->SetHeight(20);
            bullet->SetX((*it)->getX() + (*it)->getWidth()/2);
            bullet->SetY((*it)->getY() + (*it)->getHeight());
            bullets.push_back(bullet);
        }
        i++;
    }
}
