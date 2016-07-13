#include "GameObjectGenerator.h"

//Game vars
int ENEMY_ROWS = 0;
int MAX_ALIENS_ON_ROW = 0;
int SHOOTING_RNG = 5000;
int ENEMY_MOVEMENT_SPEED = 0;
int ENEMY_SHOOTING_SPEED = 0;
int REMAINING_ENEMIES = 0;

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
                if(i == 0) {
                    enemy = new Enemy(/* texture = */ gAliensTexture,
                                      /* type = */ SQUID,
                                      /* movementDirection = */ RIGHT,
                                      /*points= */ 40);
                    enemy->setWidth(gSquid1Clip.w);
                    enemy->setHeight(gSquid1Clip.h);
                }
                else if(i % 2 != 0){
                    enemy = new Enemy(/* texture = */ gAliensTexture,
                                      /* type = */ CRAB,
                                      /* movementDirection = */ RIGHT,
                                      /*points= */ 10);
                    enemy->setWidth(gCrab1Clip.w);
                    enemy->setHeight(gCrab1Clip.h);
                }

                else {
                    enemy = new Enemy(/* texture = */ gAliensTexture,
                                      /* type = */ JELLYFISH,
                                      /* movementDirection = */ RIGHT,
                                      /*points= */ 20);
                    enemy->setWidth(gJellyfish1Clip.w);
                    enemy->setHeight(gJellyfish1Clip.h);
                }
                y = enemy->getHeight()*i + (i == 0 ? enemy->getHeight() : enemy->getHeight() + 20*(i));
                enemy->setPosition(System::LEFT_X_BORDER + enemy->getWidth()*(j+1) + 10*j, y);
                enemy->setVelocity(ENEMY_MOVEMENT_SPEED);
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
        UFO->setWidth(90);
        UFO->setHeight(40);
        UFO->getMovementDirection() == RIGHT ? UFO->setPosition(0 - UFO->getWidth(), 20)
                                            : UFO->setPosition(System::SCREEN_WIDTH, 20);
        UFO->setVelocity(ENEMY_MOVEMENT_SPEED+2);
        GameObjectGenerator::UFOGenerated = true;
    }
}

void GameObjectGenerator::generatePlayer() {
    if(!GameObjectGenerator::playerGenerated) {
        player = new Player(/* texture = */ gPlayerTexture,
                            /* lives = */ 3);
        player->setWidth(70);
        player->setHeight(40);
        player->setPosition((System::SCREEN_WIDTH - player->getWidth())/2,
                             System::SCREEN_HEIGHT - player->getHeight());
        player->setVelocity(4);
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
                                         /* velocity = */ ENEMY_SHOOTING_SPEED);
            bullet->setWidth(5);
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
        bullet->setWidth(5);
        bullet->setHeight(20);
        bullet->setPosition(player->getX() + player->getWidth()/2 - 3, player->getY());
        bullets.push_back(bullet);
        player->setIsToShooT(false);
    }
}
