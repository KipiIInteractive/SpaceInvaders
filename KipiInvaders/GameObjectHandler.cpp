#include "GameObjectHandler.h"

void GameObjectHandler::updateEnemies() {
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        (*it)->update();
    }
}

void GameObjectHandler::updateBullets() {
    for(list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
        (*it)->update();
    }
}

void GameObjectHandler::destroyBullets() {
    for(list<Bullet*>::iterator it = destroyedBullets.begin(); it != destroyedBullets.end(); it++) {
        //delete (*it);
    }
    destroyedBullets.clear();
}
