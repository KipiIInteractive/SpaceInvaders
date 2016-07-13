#include "GameObjectRenderer.h"

void GameObjectRenderer::renderEnemies() {
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        if((*it)->isAlive()) {
            if((*it)->getType() == SQUID) {
                (*it)->renderWithClip(gSquid1Clip);
            }
            else if((*it)->getType() == CRAB) {
                (*it)->renderWithClip(gCrab1Clip);
            }
            else {
                (*it)->renderWithClip(gJellyfish1Clip);
            }
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
