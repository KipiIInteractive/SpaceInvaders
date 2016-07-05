#include "GameHandler.h"

void GameHandler::startClassicGame() {
    GameObjectGenerator::generateEnemies();
    gMenuBackground.render(0, 0);
    GameObjectHandler::updateEnemies();
    GameObjectCollision::checkEnemyCollision();
    GameObjectRenderer::renderEnemies();
}

void GameHandler::startSurvivalGame() {

}

void GameHandler::handleClassicGameEvents(SDL_Event *e) {

}

void GameHandler::handleSurvivalGameEvents(SDL_Event* e) {

}

void GameHandler::resetGame() {
    GameObjectGenerator::enemiesGenerated = false;
    enemies.clear();
    leftmostEnemyList.clear();
    rightmostEnemyList.clear();
}
