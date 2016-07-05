#include "GameObjectCollision.h"

void GameObjectCollision::checkEnemyCollision() {
    for(list<Enemy*>::iterator it = leftmostEnemyList.begin(); it != leftmostEnemyList.end(); it++) {
        (*it)->checkCollision();
    }

    for(list<Enemy*>::iterator it = rightmostEnemyList.begin(); it != rightmostEnemyList.end(); it++) {
        (*it)->checkCollision();
    }
}

void GameObjectCollision::checkPlayerCollision() {

}
