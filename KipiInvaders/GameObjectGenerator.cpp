#include "GameObjectGenerator.h"

//Game vars
int ENEMY_ROWS = 0;
int MAX_ALIENS_ON_ROW = 0;
int SHOOTING_RNG = 5000;
int ENEMY_MOVEMENT_SPEED = 0;
int ENEMY_SHOOTING_SPEED = 0;
int REMAINING_ENEMIES = 0;

vector<Enemy*> enemies;
Enemy* UFO = NULL;

vector<Bullet*> bullets;

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
                    enemy->setWidth(gSquid1Clip.w-14);
                    enemy->setHeight(gSquid1Clip.h);
                }
                else if(i % 2 != 0){
                    enemy = new Enemy(/* texture = */ gAliensTexture,
                                      /* type = */ CRAB,
                                      /* movementDirection = */ RIGHT,
                                      /*points= */ 10);
                    enemy->setWidth(gCrab1Clip.w-8);
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
                y = enemy->getHeight()*i + (i == 0 ? 2*enemy->getHeight() + 20 : 2*enemy->getHeight() + 20 + 20*(i));
                enemy->setPosition(System::LEFT_X_BORDER + (System::RIGHT_X_BORDER - System::LEFT_X_BORDER - MAX_ALIENS_ON_ROW*gJellyfish1Clip.w - 5*(MAX_ALIENS_ON_ROW-1))/2 + gJellyfish1Clip.w*(j) + 5*j, y);
                enemy->setVelocity(ENEMY_MOVEMENT_SPEED);
                enemies.push_back(enemy);
            }
        }
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
                             System::SCREEN_HEIGHT - player->getHeight() - 20);
        player->setVelocity(4);
        GameObjectGenerator::playerGenerated = true;
    }
}

void GameObjectGenerator::generateBullets() {
    int i = 0;
    for(unsigned int i = 0; i < enemies.size(); i++) {
        if(enemies[i]->isToShooT()
           && enemies[i]->isAlive()) {
            Bullet* bullet = new Bullet(/* texture = */ gBulletTexture,
                                         /* direction = */DOWN,
                                         /* velocity = */ ENEMY_SHOOTING_SPEED);
            bullet->setWidth(3);
            bullet->setHeight(20);
            bullet->setPosition(enemies[i]->getX() + enemies[i]->getWidth()/2, enemies[i]->getY() + enemies[i]->getHeight());
            bullets.push_back(bullet);
            Mix_PlayChannel(-1, gLaserSound, 0);
        }
        i++;
    }
    if(player->isToShooT()) {
        Bullet* bullet = new Bullet(/* texture = */ gBulletTexture,
                                         /* direction = */UP,
                                         /* velocity = */ 12);
        bullet->setWidth(3);
        bullet->setHeight(20);
        bullet->setPosition(player->getX() + player->getWidth()/2 - 3, player->getY());
        bullets.push_back(bullet);
        player->setIsToShooT(false);
        Mix_PlayChannel(-1, gLaserSound, 0);
    }
}
