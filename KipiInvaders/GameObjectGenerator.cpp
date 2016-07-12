#include "GameObjectGenerator.h"

const int ENEMY_ROWS = 5;
const int MAX_ALIENS_ON_ROW = 12;
int CURRENT_LEVEL = 1;
const int SHOOTING_RNG = 3000;

list<Enemy*> enemies;
vector<Enemy*> firstRowOfEnemies;
Enemy* UFO = NULL;

list<Bullet*> bullets;

Player* player = NULL;

bool GameObjectGenerator::enemiesGenerated = false;
bool GameObjectGenerator::UFOGenerated = false;
bool GameObjectGenerator::playerGenerated = false;

void GameObjectGenerator::generateEnemies() {
    if(!GameObjectGenerator::enemiesGenerated) {
        int y;
        for(int i = 0; i < ENEMY_ROWS; i++) {
            for(int j = 0; j < MAX_ALIENS_ON_ROW; j++) {
                Enemy* enemy = NULL;
                if(i % 2 != 0) {
                    enemy = new Enemy(/* texture = */ gCrabTexture,
                                      /* type = */ CRAB,
                                      /* movementDirection = */ RIGHT,
                                      /*points= */ 10);
                }
                else {
                    enemy = new Enemy(/* texture = */ gJellyfishTexture,
                                      /* type = */ JELLYFISH,
                                      /* movementDirection = */ RIGHT,
                                      /*points= */ 20);
                }
                enemy->setWidth(40);
                enemy->setHeight(40);
                y = enemy->getHeight()*i + (i == 0 ? enemy->getHeight() : enemy->getHeight() + 20*(i));
                enemy->setPosition(System::LEFT_X_BORDER + enemy->getWidth()*(j+1) + 10*j, y);
                enemy->setVelocity(1*CURRENT_LEVEL);
                enemies.push_back(enemy);
            }
        }
        list<Enemy*>::iterator it = enemies.begin();
        firstRowOfEnemies.insert(firstRowOfEnemies.end(), it, next(it, MAX_ALIENS_ON_ROW));
        GameObjectGenerator::enemiesGenerated = true;
    }
    if(!GameObjectGenerator::UFOGenerated) {
        int rNum = rand() % 3;
        UFO = new Enemy(/* texture = */ gUFOTexture,
                         /* type = */ MOTHERSHIP,
                         /* movementDirection = */ (rand() % 2 == 0) ? RIGHT : LEFT,
                         /*points= */ (rNum == 0) ? 50 : (rNum == 1) ? 100 : 150);
        UFO->setWidth(70);
        UFO->setHeight(50);
        UFO->getMovementDirection() == RIGHT ? UFO->setPosition(0 - UFO->getWidth(), 20)
                                            : UFO->setPosition(System::SCREEN_WIDTH, 20);
        UFO->setVelocity(2*CURRENT_LEVEL);
        GameObjectGenerator::UFOGenerated = true;
    }
}

void GameObjectGenerator::generatePlayer() {
    if(!GameObjectGenerator::playerGenerated) {
        player = new Player(/* texture = */ gPlayerTexture,
                            /* lives = */ 3);
        player->setWidth(60);
        player->setHeight(60);
        player->setPosition((System::SCREEN_WIDTH - player->getWidth())/2,
                             System::SCREEN_HEIGHT - player->getHeight());
        player->setVelocity(3);
        GameObjectGenerator::playerGenerated = true;
    }
}

void GameObjectGenerator::generateBullets() {
    int i = 0;
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
        if((*it)->isToShooT()
           && (*it)->isAlive()) {
            Bullet* bullet = new Bullet(/* texture = */ gBulletTexture,
                                         /* direction = */DOWN,
                                         /* velocity = */ 6*CURRENT_LEVEL);
            bullet->setWidth(20);
            bullet->setHeight(20);
            bullet->setPosition((*it)->getX() + (*it)->getWidth()/2, (*it)->getY() + (*it)->getHeight());
            bullets.push_back(bullet);
        }
        i++;
    }
    if(player->isToShooT()) {
        Bullet* bullet = new Bullet(/* texture = */ gBulletTexture,
                                         /* direction = */UP,
                                         /* velocity = */ 12);
        bullet->setWidth(20);
        bullet->setHeight(20);
        bullet->setPosition(player->getX() + player->getWidth()/2, player->getY());
        bullets.push_back(bullet);
        player->setIsToShooT(false);
    }
}
