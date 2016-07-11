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
}

void GameObjectCollision::handleEnemyCollision() {
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
        if((*it)->isAlive()) {
            (*it)->handleCollisionWithScreen();
        }
    }
}

void GameObjectCollision::checkPlayerCollision() {

}

void GameObjectCollision::handlePlayerCollision() {

}

void GameObjectCollision::checkBulletCollision() {
    for(list<Bullet*>::iterator it = bullets.begin(); it != bullets.end();) {
        (*it)->checkCollision();
        if((*it)->hasCollided()) {
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
