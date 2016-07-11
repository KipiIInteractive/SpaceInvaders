#include "GameHandler.h"

void GameHandler::startClassicGame() {
    gMenuBackground.render(0, 0);
    gLeftBorder.render(System::LEFT_X_BORDER - gLeftBorder.getWidth(), 0);
    gRightBorder.render(System::RIGHT_X_BORDER, 0);
    GameObjectGenerator::generateEnemies();
    GameObjectGenerator::generatePlayer();
    GameObjectHandler::updateEnemies();
    GameObjectHandler::updatePlayer();
    GameObjectGenerator::generateBullets();
    GameObjectHandler::updateBullets();
    GameObjectCollision::checkEnemyCollision();
    GameObjectCollision::checkAndHandlePlayerCollision();
    GameObjectCollision::checkBulletCollision();
    GameObjectRenderer::renderEnemies();
    GameObjectRenderer::renderPlayer();
    GameObjectRenderer::renderBullets();
}

void GameHandler::startSurvivalGame() {

}

void GameHandler::handleClassicGameEvents(SDL_Event *e) {
    player->handleEvents(e);
}

void GameHandler::handleSurvivalGameEvents(SDL_Event* e) {

}

void GameHandler::resetGame() {

}

void GameHandler::shutdownGame() {
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
        delete (*it);
    }
    enemies.clear();
    firstRowOfEnemies.clear();
    for(list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++) {
        delete (*it);
    }
    bullets.clear();
    for(list<Bullet*>::iterator it = destroyedBullets.begin(); it != destroyedBullets.end(); it++) {
        delete (*it);
    }
    destroyedBullets.clear();
}
