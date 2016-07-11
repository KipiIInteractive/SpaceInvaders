#include "GameObjectRenderer.h"

void GameObjectRenderer::renderEnemies() {
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        if((*it)->isAlive()) {
            (*it)->render();
        }
    }
    if(UFO->isAlive()) {
        UFO->render();
    }
}

void GameObjectRenderer::renderPlayer() {
    if(player->getLives()) {
        player->render();
    }
}

void GameObjectRenderer::renderBullets() {
    for(list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
        (*it)->render();
    }
}
