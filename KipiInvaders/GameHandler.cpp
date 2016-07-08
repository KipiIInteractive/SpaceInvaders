#include "GameHandler.h"

void GameHandler::startClassicGame() {
    gMenuBackground.render(0, 0);
    GameObjectGenerator::generateEnemies();
    GameObjectHandler::updateEnemies();
    GameObjectGenerator::generateBullets();
    GameObjectHandler::updateBullets();
    GameObjectCollision::checkEnemyCollision();
    GameObjectCollision::checkBulletCollision();
    //GameObjectHandler::destroyBullets();
    GameObjectRenderer::renderEnemies();
    GameObjectRenderer::renderBullets();
}

void GameHandler::startSurvivalGame() {

}

void GameHandler::handleClassicGameEvents(SDL_Event *e) {

}

void GameHandler::handleSurvivalGameEvents(SDL_Event* e) {

}

void GameHandler::resetGame() {
    GameObjectGenerator::enemiesGenerated = false;
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
        delete (*it);
    }
    enemies.clear();
    firstRowOfEnemies.clear();
    for(list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++) {
        delete (*it);
    }
    bullets.clear();
}
