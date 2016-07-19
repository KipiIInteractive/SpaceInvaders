#include "GameObjectCollision.h"

vector<Bullet*> destroyedBullets;

void GameObjectCollision::checkEnemyCollisionWithScreen() {
    for(unsigned int i = 0; i < enemies.size(); i++) {
        if(enemies[i]->isAlive()) {
            enemies[i]->checkCollisionWithScreen();
            if(enemies[i]->hasCollidedWithScreenHorizontally()) {
                handleEnemyCollisionWithScreenHorizontally();
            }
        }
    }
    if(UFO->isAlive()) {
        UFO->checkCollisionWithScreen();
        if(UFO->hasCollidedWithScreenHorizontally()) {
            UFO->setIsAlive(false);
            UFO->setHasCollidedWithScreenHorizontally(false);
        }
    }
}

void GameObjectCollision::handleEnemyCollisionWithScreenHorizontally() {
    for(unsigned int i = 0; i < enemies.size(); i++) {
        if(enemies[i]->isAlive()) {
            enemies[i]->handleCollisionWithScreenHorizontally();
        }
    }
}

void GameObjectCollision::checkAndHandlePlayerCollisionWithScreenHorizontally() {
    if(player->getLives() > 0) {
        player->checkAndHandleCollisionWithScreenHorizontally();
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

void GameObjectCollision::checkAndHandleBarrierCollisionWithBullets() {
    if(!barrier1->isDestroyed()) {
        barrier1->checkAndHandleCollisionWithBullets();
    }
    if(!barrier2->isDestroyed()) {
        barrier2->checkAndHandleCollisionWithBullets();
    }
    if(!barrier3->isDestroyed()) {
        barrier3->checkAndHandleCollisionWithBullets();
    }
}
