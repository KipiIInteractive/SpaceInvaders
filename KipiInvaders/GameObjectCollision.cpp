#include "GameObjectCollision.h"

list<Bullet*> destroyedBullets;

void GameObjectCollision::checkEnemyCollision() {
    for(int i = 0; i < firstRowOfEnemies.size(); i++) {
        if(firstRowOfEnemies[i]->isAlive()) {
            firstRowOfEnemies[i]->checkCollisionWithScreen();
            if(firstRowOfEnemies[i]->hasCollidedWithScreen()) {
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
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
        if((*it)->isAlive()) {
            (*it)->handleCollisionWithScreen();
        }
    }
}

void GameObjectCollision::checkAndHandlePlayerCollision() {
    if(player->getLives() > 0) {
        player->checkAndHandleCollisionWithScreen();
    }
}

void GameObjectCollision::checkBulletCollision() {
    for(list<Bullet*>::iterator it = bullets.begin(); it != bullets.end();) {
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

list<Bullet*>::iterator GameObjectCollision::handleBulletCollision(list<Bullet*>::iterator it) {
    return bullets.erase(it);
}
