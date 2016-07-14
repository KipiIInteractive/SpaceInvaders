#include "GameObjectCollision.h"

vector<Bullet*> destroyedBullets;

void GameObjectCollision::checkEnemyCollision() {
    for(unsigned int i = 0; i < enemies.size(); i++) {
        if(enemies[i]->isAlive()) {
            enemies[i]->checkCollisionWithScreen();
            if(enemies[i]->hasCollidedWithScreen()) {
                handleEnemyCollision();
            }
        }
    }
    if(UFO->isAlive()) {
        UFO->checkCollisionWithScreen();
        if(UFO->hasCollidedWithScreen()) {
            UFO->setIsAlive(false);
            UFO->setHasCollidedWithScreen(false);
        }
    }
}

void GameObjectCollision::handleEnemyCollision() {
    for(unsigned int i = 0; i < enemies.size(); i++) {
        if(enemies[i]->isAlive()) {
            enemies[i]->handleCollisionWithScreen();
        }
    }
}

void GameObjectCollision::checkAndHandlePlayerCollision() {
    if(player->getLives() > 0) {
        player->checkAndHandleCollisionWithScreen();
    }
}

void GameObjectCollision::checkBulletCollision() {
    for(vector<Bullet*>::iterator it = bullets.begin(); it != bullets.end();) {
        (*it)->checkCollision();
        if((*it)->hasCollided()) {
            if((*it)->getMovementDirection() == UP) {
                player->setCanShooT(true);
            }
            Bullet* bullet = (*it);
            destroyedBullets.push_back(bullet);
            it = handleBulletCollision(it);
        }
        else {
            it++;
        }
    }
}

vector<Bullet*>::iterator GameObjectCollision::handleBulletCollision(vector<Bullet*>::iterator it) {
    return bullets.erase(it);
}
