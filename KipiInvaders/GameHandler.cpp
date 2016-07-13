#include "GameHandler.h"

void GameHandler::startClassicGame() {
    if(LevelManager::loadNextLevel) {
        LevelManager::InitCurrentLevel();
        LevelManager::LoadLevel(LevelManager::GetCurrentLevel());
        LevelManager::loadNextLevel = false;
    }

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

    GameObjectHandler::changeEnemiesShootingSpeed();

    GameObjectRenderer::renderBullets();
    GameObjectRenderer::renderEnemies();
    GameObjectRenderer::renderPlayer();

    if(gScoreDigitsTexture.loadFromRenderedText(("" + to_string(player->getScore())), {255, 255, 255, 255})) {
        gScoreSignTexture.render(System::LEFT_X_BORDER + ((System::RIGHT_X_BORDER-System::LEFT_X_BORDER)/2 - gScoreSignTexture.getWidth())/2,
                                0);
        gScoreDigitsTexture.render(System::LEFT_X_BORDER + ((System::RIGHT_X_BORDER-System::LEFT_X_BORDER)/2 - gScoreDigitsTexture.getWidth())/2,
                                   gScoreSignTexture.getHeight());

    }

    if(gLivesDigitsTexture.loadFromRenderedText(("" + to_string(player->getLives())), {255, 255, 255, 255})) {
        gLivesSignTexture.render(System::LEFT_X_BORDER + (System::RIGHT_X_BORDER - System::LEFT_X_BORDER)/2 + ((System::RIGHT_X_BORDER-System::LEFT_X_BORDER)/2 - gLivesSignTexture.getWidth())/2,
                                 0);
        gLivesDigitsTexture.render(System::LEFT_X_BORDER + (System::RIGHT_X_BORDER - System::LEFT_X_BORDER)/2 + ((System::RIGHT_X_BORDER-System::LEFT_X_BORDER)/2 - gLivesDigitsTexture.getWidth())/2,
                                 gLivesSignTexture.getHeight());
    }
}

void GameHandler::startSurvivalGame() {

}

void GameHandler::handleClassicGameEvents(SDL_Event *e) {
    //player->handleEvents(e);
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
