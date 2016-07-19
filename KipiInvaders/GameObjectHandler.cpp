#include "GameObjectHandler.h"

bool GameObjectHandler::playedUFOSound = false;

void GameObjectHandler::updateEnemies() {
    for(unsigned int i = 0; i < enemies.size(); i++) {
        if(enemies[i]->isAlive()) {
            enemies[i]->update();
        }
        else if(enemies[i]->hasBeenHit()) {
            ENEMY_DESTROYED_FRAMES_COUNTER++;
        }
    }
    if(UFO->isAlive() && enemies[0]->getY() > UFO->getY() + UFO->getHeight()) {
        UFO->update();
        if(!GameObjectHandler::playedUFOSound) {
            Mix_PlayChannel(-1, gUFOSound, 0);
            GameObjectHandler::playedUFOSound = true;
        }
    }
    else if(!UFO->isAlive() && rand() % 700 == 1) {
        UFO->setIsAlive(true);
        if(rand() % 2 == 0) {
            UFO->setPosition(-UFO->getWidth(), 20);
            UFO->setMovementDirection(RIGHT);
        }
        else {
            UFO->setPosition(System::SCREEN_WIDTH, 20);
            UFO->setMovementDirection(LEFT);
        }
        //New points
        int rNum = rand() % 3;
        UFO->setPoints((rNum == 0) ? 50 : (rNum == 1) ? 100 : 150);
        GameObjectHandler::playedUFOSound = false;
    }
    ENEMY_ANIMATION_FRAMES_COUNTER++;
}

void GameObjectHandler::updatePlayer() {
    if(player->getLives() > 0) {
        player->update();
        if(player->hasBeenHit()) {
            PLAYER_DESTROYED_FRAMES_COUNTER++;
        }
    }
}

void GameObjectHandler::updateBullets() {
    for(unsigned int i = 0; i < bullets.size(); i++) {
        bullets[i]->update();
    }
}

void GameObjectHandler::updateBarriers() {
    if(!barrier1->isDestroyed()) {
        barrier1->update();
    }
    if(!barrier2->isDestroyed()) {
        barrier2->update();
    }
    if(!barrier3->isDestroyed()) {
        barrier3->update();
    }
}

void GameObjectHandler::changeEnemiesShootingSpeed() {
    if(REMAINING_ENEMIES - GameObjectHandler::getRemainingEnemies() >= 6) {
        if(SHOOTING_RNG - 1000 > 0) {
            SHOOTING_RNG -= 1000;
        }
        else if(SHOOTING_RNG - 200 > 0) {
            SHOOTING_RNG -= 200;
        }
    }
}

void GameObjectHandler::changeEnemiesMovementSpeed() {
    if(REMAINING_ENEMIES - GameObjectHandler::getRemainingEnemies() >= 6) {
        if(ENEMY_ANIMATION_FRAMES - 10 > 0) {
           ENEMY_ANIMATION_FRAMES -= 10;
           ENEMY_ANIMATION_FRAMES_COUNTER = 0;
        }
    }
}

void GameObjectHandler::changeEnemiesBulletSpeed() {
    if(REMAINING_ENEMIES - GameObjectHandler::getRemainingEnemies() >= 6) {
        REMAINING_ENEMIES = GameObjectHandler::getRemainingEnemies();
        ENEMY_SHOOTING_SPEED += 1;
    }
}

int GameObjectHandler::getRemainingEnemies() {
    int aliveEnemies = 0;
    for(unsigned int i = 0; i < enemies.size(); i++) {
        if(enemies[i]->isAlive()) {
            aliveEnemies++;
        }
    }
    return aliveEnemies;
}
