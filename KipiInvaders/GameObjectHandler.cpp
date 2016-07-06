#include "GameObjectHandler.h"

void GameObjectHandler::updateEnemies() {
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
            (*it)->update();
    }
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        if((rand() % (SHOOTING_RNG/CURRENT_LEVEL)) == 1) {
            (*it)->shoot(CURRENT_LEVEL);
        }
    }
}
