#include "GameObjectRenderer.h"

void GameObjectRenderer::renderEnemies() {
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        (*it)->render();
    }
}

void GameObjectRenderer::renderPlayer() {

}

void GameObjectRenderer::renderBullets() {
    for(list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
        (*it)->render();
    }
}
