#include "GameObjectHandler.h"

void GameObjectHandler::updateEnemies() {
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        (*it)->update();
    }
    for(list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
        (*it)->update();
    }
}
