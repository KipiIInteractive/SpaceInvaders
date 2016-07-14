#include "GameHandler.h"

void GameHandler::startClassicGame() {
    gMenuBackground.render(0, 0);

    if(LevelManager::loadNextLevel) {
        LevelManager::InitCurrentLevel();
        if(LevelManager::LoadLevel(LevelManager::GetCurrentLevel())) {
            LevelManager::renderedLevel = false;
            GameObjectGenerator::enemiesGenerated = false;
            SHOOTING_RNG = 5000;
            ENEMY_ANIMATION_FRAMES = 50;
        }
        LevelManager::loadNextLevel = false;
    }

    if(!LevelManager::renderedLevel) {
        LevelManager::RenderCurrentLevel();
    }
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
    GameObjectHandler::changeEnemiesMovementSpeed();
    GameObjectHandler::changeEnemiesBulletSpeed();

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

    if(GameObjectHandler::getRemainingEnemies() == 0) {
        ofstream file("./levels/current.level");
        if(file.is_open()) {
            file << LevelManager::GetCurrentLevel() + 1;
            file.close();
        }
        LevelManager::loadNextLevel = true;
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
//    ofstream file("./levels/current.level");
//    if(file.is_open()) {
//        file << 1;
//        file.close();
//    }
//    LevelManager::renderedLevel = false;
//    GameObjectGenerator::enemiesGenerated = false;
//    SHOOTING_RNG = 5000;
//    ENEMY_ANIMATION_FRAMES = 50;
//    LevelManager::loadNextLevel = true;
}

void GameHandler::shutdownGame() {
    for(vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
        delete (*it);
    }
    enemies.clear();
    for(vector<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++) {
        delete (*it);
    }
    bullets.clear();
    for(vector<Bullet*>::iterator it = destroyedBullets.begin(); it != destroyedBullets.end(); it++) {
        delete (*it);
    }
    destroyedBullets.clear();
    ofstream file("./levels/current.level");
    if(file.is_open()) {
        file << 1;
        file.close();
    }
}
