#include "GameHandler.h"

bool GameHandler::gameOver = false;

bool GameHandler::needToResetClassicGame = false;
bool GameHandler::needToResetSurvivalGame = false;

void GameHandler::startClassicGame() {
    gGameBackground.render(0, 0);

    if(LevelManager::loadNextClassicLevel) {
        LevelManager::InitCurrentClassicLevel();
        if(LevelManager::LoadClassicLevel(LevelManager::GetCurrentClassicLevel())) {
            LevelManager::renderedClassicLevel = false;
            GameObjectGenerator::enemiesGenerated = false;
            SHOOTING_RNG = 5000;
            ENEMY_ANIMATION_FRAMES = 50;
        }
        else {
            GameHandler::gameOver = true;
        }
        LevelManager::loadNextClassicLevel = false;
    }

    if(!LevelManager::renderedClassicLevel) {
        LevelManager::RenderCurrentClassicLevel();
    }

    gLeftBorder.render(System::LEFT_X_BORDER - gLeftBorder.getWidth(), 0);
    gRightBorder.render(System::RIGHT_X_BORDER, 0);

    GameObjectGenerator::generateEnemies();
    GameObjectGenerator::generatePlayer();
    GameObjectGenerator::generateBarriers();

    GameObjectHandler::updateEnemies();
    GameObjectHandler::updatePlayer();
    GameObjectGenerator::generateBullets();
    GameObjectHandler::updateBullets();
    GameObjectHandler::updateBarriers();

    GameObjectCollision::checkEnemyCollisionWithScreen();
    GameObjectCollision::checkAndHandlePlayerCollisionWithScreenHorizontally();
    GameObjectCollision::checkAndHandleBarrierCollisionWithBullets();
    GameObjectCollision::checkBulletCollision();

    GameObjectHandler::changeEnemiesShootingSpeed();
    GameObjectHandler::changeEnemiesMovementSpeed();
    GameObjectHandler::changeEnemiesBulletSpeed();

    GameObjectRenderer::renderBullets();
    GameObjectRenderer::renderEnemies();
    GameObjectRenderer::renderPlayer();
    GameObjectRenderer::renderBarriers();

    if(gScoreDigitsTexture.loadFromRenderedText((to_string(player->getScore())), {255, 255, 255, 255})) {
        gScoreSignTexture.render(System::LEFT_X_BORDER + ((System::RIGHT_X_BORDER-System::LEFT_X_BORDER)/2 - gScoreSignTexture.getWidth())/2,
                                0);
        gScoreDigitsTexture.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*(3 + (player->getScore() < 10 ? 1 : player->getScore() < 100 ? 2 : player->getScore() < 1000 ? 3 : 4)))/100);
        gScoreDigitsTexture.setHeight(gScoreDigitsTexture.getWidth());
        gScoreDigitsTexture.render(System::LEFT_X_BORDER + ((System::RIGHT_X_BORDER-System::LEFT_X_BORDER)/2 - gScoreDigitsTexture.getWidth())/2,
                                   gScoreSignTexture.getHeight());

    }

    if(gLivesDigitsTexture.loadFromRenderedText((to_string(player->getLives())), {255, 255, 255, 255})) {
        gLivesSignTexture.render(System::LEFT_X_BORDER + (System::RIGHT_X_BORDER - System::LEFT_X_BORDER)/2 + ((System::RIGHT_X_BORDER-System::LEFT_X_BORDER)/2 - gLivesSignTexture.getWidth())/2,
                                 0);
        gLivesDigitsTexture.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*4)/100);
        gLivesDigitsTexture.setHeight(gLivesDigitsTexture.getWidth());
        gLivesDigitsTexture.render(System::LEFT_X_BORDER + (System::RIGHT_X_BORDER - System::LEFT_X_BORDER)/2 + ((System::RIGHT_X_BORDER-System::LEFT_X_BORDER)/2 - gLivesDigitsTexture.getWidth())/2,
                                 gLivesSignTexture.getHeight());
    }

    if(GameObjectHandler::getRemainingEnemies() == 0) {
        ofstream file("./levels/current.level");
        if(file.is_open()) {
            file << LevelManager::GetCurrentClassicLevel() + 1;
            file.close();
        }
        LevelManager::loadNextClassicLevel = true;
    }
    else if(player->getLives() == 0 || GameObjectCollision::enemyHasCollidedWithScreenVertically) {
        GameHandler::gameOver = true;
        GameObjectCollision::enemyHasCollidedWithScreenVertically = false;
    }
}

void GameHandler::startSurvivalGame() {
    gGameBackground.render(0, 0);

    if(LevelManager::loadSurvivalLevel) {
        if(LevelManager::LoadSurvivalLevel()) {
            LevelManager::renderedSurvivalLevel = false;
            GameObjectGenerator::enemiesGenerated = false;
            SHOOTING_RNG = 5000;
            ENEMY_ANIMATION_FRAMES = 50;
        }
        LevelManager::loadSurvivalLevel = false;
    }

    if(!LevelManager::renderedSurvivalLevel) {
        LevelManager::RenderSurvivalLevel();
    }

    gLeftBorder.render(System::LEFT_X_BORDER - gLeftBorder.getWidth(), 0);
    gRightBorder.render(System::RIGHT_X_BORDER, 0);

    GameObjectGenerator::generateEnemies();
    GameObjectGenerator::generateAdditionalHordes();
    GameObjectGenerator::generatePlayer();
    GameObjectGenerator::generateBarriers();

    GameObjectHandler::updateEnemies();
    GameObjectHandler::updatePlayer();
    GameObjectGenerator::generateBullets();
    GameObjectHandler::updateBullets();
    GameObjectHandler::updateBarriers();

    GameObjectCollision::checkEnemyCollisionWithScreen();
    GameObjectCollision::checkAndHandlePlayerCollisionWithScreenHorizontally();
    GameObjectCollision::checkAndHandleBarrierCollisionWithBullets();
    GameObjectCollision::checkBulletCollision();

    GameObjectHandler::changeEnemiesShootingSpeed();
    GameObjectHandler::changeEnemiesMovementSpeed();
    GameObjectHandler::changeEnemiesBulletSpeed();

    GameObjectRenderer::renderBullets();
    GameObjectRenderer::renderEnemies();
    GameObjectRenderer::renderPlayer();
    GameObjectRenderer::renderBarriers();

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

    if(player->getLives() == 0 || GameObjectCollision::enemyHasCollidedWithScreenVertically) {
        GameHandler::gameOver = true;
        GameObjectCollision::enemyHasCollidedWithScreenVertically = false;
    }
}

void GameHandler::resetSurvivalGame() {
    LevelManager::loadSurvivalLevel = true;

    GameObjectHandler::resetEnemies();
    GameObjectHandler::resetPlayer();
    GameObjectHandler::resetUFO();
    GameObjectHandler::resetBullets();
    GameObjectHandler::resetBarriers();
}

void GameHandler::resetClassicGame() {
    LevelManager::ResetClassicGameLevel();

    GameObjectHandler::resetEnemies();
    GameObjectHandler::resetPlayer();
    GameObjectHandler::resetUFO();
    GameObjectHandler::resetBullets();
    GameObjectHandler::resetBarriers();
}

void GameHandler::shutdownGame() {
    ofstream file("./levels/current.level");
    if(file.is_open()) {
        file << 1;
        file.close();
    }
    for(unsigned int i = 0; i < enemiesToBeDeleted.size(); i++) {
        delete enemiesToBeDeleted[i];
    }
    enemiesToBeDeleted.clear();
    for(unsigned int i = 0; i < enemies.size(); i++) {
        delete enemies[i];
    }
    enemies.clear();
    for(unsigned int i = 0; i < bullets.size(); i++) {
        delete bullets[i];
    }
    bullets.clear();
    for(unsigned int i = 0; i < destroyedBullets.size(); i++) {
        delete destroyedBullets[i];
    }
    destroyedBullets.clear();
    if(barrier1 != NULL) {
        delete barrier1;
    }
    if(barrier2 != NULL) {
        delete barrier2;
    }
    if(barrier3 != NULL) {
        delete barrier3;
    }
    if(player != NULL) {
        delete player;
    }
    if(UFO != NULL) {
        delete UFO;
    }
    if(gUFOSound != NULL) {
        Mix_FreeChunk(gUFOSound);
    }
    if(gPlayerExplosionSound != NULL) {
        Mix_FreeChunk(gPlayerExplosionSound);
    }
    if(gAlienExplosionSound != NULL) {
        Mix_FreeChunk(gAlienExplosionSound);
    }
    if(gLaserSound != NULL) {
        Mix_FreeChunk(gLaserSound);
    }
}
