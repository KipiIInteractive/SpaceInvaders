#include "GameHandler.h"

void GameHandler::startClassicGame() {
    GameObjectGenerator::generateEnemies();
    gMenuBackground.render(0, 0);
    GameObjectHandler::updateEnemies();
    GameObjectGenerator::generateBullets();
    GameObjectHandler::updateBullets();
    GameObjectCollision::checkEnemyCollision();
    GameObjectCollision::checkBulletCollision();
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
    secondRowOfEnemies.clear();
    thirdRowOfEnemies.clear();
    fourthRowOfEnemies.clear();
}
