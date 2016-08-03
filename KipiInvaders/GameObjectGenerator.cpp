#include "GameObjectGenerator.h"

//Game vars
int ENEMY_ROWS = 0;
int MAX_ALIENS_ON_ROW = 0;
int SHOOTING_RNG = 5000;
int ENEMY_MOVEMENT_SPEED = 0;
int ENEMY_SHOOTING_SPEED = 0;
int REMAINING_ENEMIES = 0;

vector<Enemy*> enemies;
vector<Enemy*> enemiesQueue;
Enemy* UFO = NULL;

vector<Bullet*> bullets;

Player* player = NULL;

Barrier* barrier1 = NULL;
Barrier* barrier2 = NULL;
Barrier* barrier3 = NULL;

bool GameObjectGenerator::enemiesGenerated = false;
bool GameObjectGenerator::UFOGenerated = false;
bool GameObjectGenerator::playerGenerated = false;
bool GameObjectGenerator::barriersGenerated = false;

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
                    enemy->setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*6)/100);
                    enemy->setHeight(enemy->getWidth()/1.7);
                }
                else if(i % 2 != 0){
                    enemy = new Enemy(/* texture = */ gAliensTexture,
                                      /* type = */ CRAB,
                                      /* movementDirection = */ RIGHT,
                                      /*points= */ 10);
                    enemy->setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*6)/100);
                    enemy->setHeight(enemy->getWidth()/1.7);
                }

                else {
                    enemy = new Enemy(/* texture = */ gAliensTexture,
                                      /* type = */ JELLYFISH,
                                      /* movementDirection = */ RIGHT,
                                      /*points= */ 20);
                    enemy->setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*6)/100);
                    enemy->setHeight(enemy->getWidth()/1.7);
                }
                y = gLivesSignTexture.getHeight()*2 + i*enemy->getHeight() + (i+1)*15;
                enemy->setPosition(System::LEFT_X_BORDER + (System::RIGHT_X_BORDER - System::LEFT_X_BORDER - MAX_ALIENS_ON_ROW*(enemy->getHeight()*1.7) - 5*(MAX_ALIENS_ON_ROW-1))/2 + (enemy->getHeight()*1.7-3)*(j) + 5*j, y);
                enemy->setVelocity(ENEMY_MOVEMENT_SPEED);
                enemies.push_back(enemy);
            }
        }
        GameObjectGenerator::enemiesGenerated = true;
    }
    if(!GameObjectGenerator::UFOGenerated
       && rand() % 100 == 1
       && enemies[0]->getY() > 2*gScoreSignTexture.getHeight() + gUFOTexture.getHeight()) {
        int rNum = rand() % 3;
        UFO = new Enemy(/* texture = */ gUFOTexture,
                         /* type = */ MOTHERSHIP,
                         /* movementDirection = */ (rand() % 2 == 0) ? RIGHT : LEFT,
                         /*points= */ (rNum == 0) ? 50 : (rNum == 1) ? 100 : 150);
        UFO->setWidth(gUFOTexture.getWidth());
        UFO->setHeight(gUFOTexture.getHeight());
        UFO->getMovementDirection() == RIGHT ? UFO->setPosition(0 - UFO->getWidth(), 2*gScoreSignTexture.getHeight())
                                            : UFO->setPosition(System::SCREEN_WIDTH, 2*gScoreSignTexture.getHeight());
        UFO->setVelocity(ENEMY_MOVEMENT_SPEED+2);
        GameObjectGenerator::UFOGenerated = true;
    }
}

void GameObjectGenerator::generateAdditionalHordes() {
    for(unsigned int j = 0; j < MAX_ALIENS_ON_ROW; j++) {
        if(enemies[j]->getY() >= 2*gLivesSignTexture.getHeight() + enemies[j]->getHeight() + 30
           && enemies[j]->isAlive()
           && ((enemies[j]->getX() == System::LEFT_X_BORDER + (System::RIGHT_X_BORDER - System::LEFT_X_BORDER - MAX_ALIENS_ON_ROW*gJellyfish1Clip.w - 5*(MAX_ALIENS_ON_ROW-1))/2)
                || (System::LEFT_X_BORDER + (System::RIGHT_X_BORDER - System::LEFT_X_BORDER - MAX_ALIENS_ON_ROW*gSquid1Clip.w - 5*(MAX_ALIENS_ON_ROW-1))/2)
                || (System::LEFT_X_BORDER + (System::RIGHT_X_BORDER - System::LEFT_X_BORDER - MAX_ALIENS_ON_ROW*gCrab1Clip.w - 5*(MAX_ALIENS_ON_ROW-1))/2))) {
            int y;
            int randNum = (rand() % 3);
            for(unsigned int i = 0; i < MAX_ALIENS_ON_ROW; i++) {
                Enemy* pEnemy = NULL;
                if(randNum == 0) {
                    pEnemy = new Enemy(/* texture = */ gAliensTexture,
                                      /* type = */ SQUID,
                                      /* movementDirection = */ enemies[j]->getMovementDirection(),
                                      /*points= */ 40);
                    pEnemy->setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*6)/100);
                    pEnemy->setHeight(pEnemy->getWidth()/1.7);
                }
                else if(randNum == 1){
                    pEnemy = new Enemy(/* texture = */ gAliensTexture,
                                      /* type = */ CRAB,
                                      /* movementDirection = */ enemies[j]->getMovementDirection(),
                                      /*points= */ 10);
                    pEnemy->setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*6)/100);
                    pEnemy->setHeight(pEnemy->getWidth()/1.7);
                }

                else {
                    pEnemy = new Enemy(/* texture = */ gAliensTexture,
                                      /* type = */ JELLYFISH,
                                      /* movementDirection = */ enemies[j]->getMovementDirection(),
                                      /*points= */ 20);
                    pEnemy->setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*6)/100);
                    pEnemy->setHeight(pEnemy->getWidth()/1.7);
                }
                y = enemies[j]->getY() - pEnemy->getHeight() - 15;
                pEnemy->setPosition(enemies[j]->getX() + 5*i + (pEnemy->getHeight()*1.7)*i, y);
                pEnemy->setVelocity(ENEMY_MOVEMENT_SPEED);
                enemiesQueue.push_back(pEnemy);
            }
            REMAINING_ENEMIES += MAX_ALIENS_ON_ROW;
            break;
        }
    }
    enemies.insert(enemies.begin(), enemiesQueue.begin(), enemiesQueue.end());
    enemiesQueue.clear();
}

void GameObjectGenerator::generatePlayer() {
    if(!GameObjectGenerator::playerGenerated) {
        player = new Player(/* texture = */ gPlayerTexture,
                            /* lives = */ 3);

        player->setWidth(gPlayerTexture.getWidth());
        player->setHeight(gPlayerTexture.getHeight());
        player->setPosition((System::SCREEN_WIDTH - player->getWidth())/2,
                             System::SCREEN_HEIGHT - player->getHeight() - 20);
        player->setVelocity(4);
        GameObjectGenerator::playerGenerated = true;
    }
}

void GameObjectGenerator::generateBullets() {
    for(unsigned int i = 0; i < enemies.size(); i++) {
        if(enemies[i]->isToShooT()
           && enemies[i]->isAlive()) {
            Bullet* bullet = new Bullet(/* texture = */ gBulletTexture,
                                         /* direction = */DOWN,
                                         /* velocity = */ ENEMY_SHOOTING_SPEED);
            bullet->setWidth(gBulletTexture.getWidth());
            bullet->setHeight(gBulletTexture.getHeight());
            bullet->setPosition(enemies[i]->getX() + enemies[i]->getWidth()/2, enemies[i]->getY() + enemies[i]->getHeight());
            bullets.push_back(bullet);
            Mix_PlayChannel(-1, gLaserSound, 0);
        }
    }
    if(player->isToShooT()) {
        Bullet* bullet = new Bullet(/* texture = */ gBulletTexture,
                                         /* direction = */UP,
                                         /* velocity = */ 13);
        bullet->setWidth(gBulletTexture.getWidth());
        bullet->setHeight(gBulletTexture.getHeight());
        bullet->setPosition(player->getX() + player->getWidth()/2 - 3, player->getY());
        bullets.push_back(bullet);
        player->setIsToShooT(false);
        Mix_PlayChannel(-1, gLaserSound, 0);
    }
}

void GameObjectGenerator::generateBarriers() {
    if(!GameObjectGenerator::barriersGenerated) {
        barrier1 = new Barrier();
        if(barrier1->loadInitialTextures()) {
            barrier1->setDimensions();
            barrier1->setPosition(System::LEFT_X_BORDER + ((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)/3 - barrier1->getWidth())/2,
                              System::SCREEN_HEIGHT - 3*barrier1->getHeight());
        }

        barrier2 = new Barrier();
        if(barrier2->loadInitialTextures()) {
            barrier2->setDimensions();
            barrier2->setPosition(System::LEFT_X_BORDER + (System::RIGHT_X_BORDER - System::LEFT_X_BORDER)/3 + ((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)/3 - barrier2->getWidth())/2,
                              System::SCREEN_HEIGHT - 3*barrier2->getHeight());
        }

        barrier3 = new Barrier();
        if(barrier3->loadInitialTextures()) {
            barrier3->setDimensions();
            barrier3->setPosition(System::LEFT_X_BORDER + 2*(System::RIGHT_X_BORDER - System::LEFT_X_BORDER)/3 + ((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)/3 - barrier3->getWidth())/2,
                            System::SCREEN_HEIGHT - 3*barrier3->getHeight());
        }
        GameObjectGenerator::barriersGenerated = true;
    }
}
