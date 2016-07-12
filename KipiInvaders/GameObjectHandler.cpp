#include "GameObjectHandler.h"

void GameObjectHandler::updateEnemies() {
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        if((*it)->isAlive()) {
            (*it)->update();
        }
    }
    if(UFO->isAlive() && firstRowOfEnemies[0]->getY() > UFO->getHeight() + 20) {
        UFO->update();
    }
    else if(!UFO->isAlive() && rand() % 500 == 1) {
        UFO->setIsAlive(true);
        if(rand() % 2 == 0) {
            UFO->setPosition(-UFO->getWidth(), 0);
            UFO->setMovementDirection(RIGHT);
        }
        else {
            UFO->setPosition(System::SCREEN_WIDTH, 0);
            UFO->setMovementDirection(LEFT);
        }
        //New points
        int rNum = rand() % 3;
        UFO->setPoints((rNum == 0) ? 50 : (rNum == 1) ? 100 : 150);
    }
}

void GameObjectHandler::updatePlayer() {
    if(player->getLives() > 0) {
        player->update();
    }
}

void GameObjectHandler::updateBullets() {
    for(list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
        (*it)->update();
    }
}
