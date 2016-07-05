#include "GameObjectHandler.h"

void GameObjectHandler::updateEnemies() {
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
            (*it)->update();
    }
}
