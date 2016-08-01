#include "GameHandler.h"

bool GameHandler::gameOver = false;

void GameHandler::startClassicGame() {
    gGameBackground.render(0, 0);

    if(LevelManager::loadNextLevel) {
        LevelManager::InitCurrentLevel();
        if(LevelManager::LoadLevel(LevelManager::GetCurrentLevel())) {
            LevelManager::renderedLevel = false;
            GameObjectGenerator::enemiesGenerated = false;
            SHOOTING_RNG = 5000;
            ENEMY_ANIMATION_FRAMES = 50;
        }
        else {
            GameHandler::gameOver = true;
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

    if(GameObjectHandler::getRemainingEnemies() == 0) {
        ofstream file("./levels/current.level");
        if(file.is_open()) {
            file << LevelManager::GetCurrentLevel() + 1;
            file.close();
        }
        LevelManager::loadNextLevel = true;
    }
    else if(player->getLives() == 0 || GameObjectCollision::enemyHasCollidedWithScreenVertically) {
        GameHandler::gameOver = true;
        GameObjectCollision::enemyHasCollidedWithScreenVertically = false;
    }
}

void GameHandler::startSurvivalGame() {

}

void GameHandler::resetGame() {
    if(LevelManager::GetCurrentLevel() != 1) {
        ofstream file("./levels/current.level");
        if(file.is_open()) {
            file << 1;
            file.close();
        }
        LevelManager::InitCurrentLevel();
        LevelManager::LoadLevel(LevelManager::GetCurrentLevel());
    }
    LevelManager::renderedLevel = false;
    SHOOTING_RNG = 5000;
    ENEMY_ANIMATION_FRAMES = 50;
    int y;
    for(unsigned int i = ENEMY_ROWS*MAX_ALIENS_ON_ROW; i < enemies.size(); i++) {
        if(enemies[i]->isAlive()) {
            enemies[i]->setIsAlive(false);
        }
    }
    for(int i = 0; i < ENEMY_ROWS; i++) {
        for(int j = 0; j < MAX_ALIENS_ON_ROW; j++) {
            if(!enemies[j+(i*MAX_ALIENS_ON_ROW)]->isAlive()) {
                enemies[j+(i*MAX_ALIENS_ON_ROW)]->setIsAlive(true);
            }
            y = enemies[j+(i*MAX_ALIENS_ON_ROW)]->getHeight()*i + (i == 0 ? 2*enemies[j+(i*MAX_ALIENS_ON_ROW)]->getHeight() + 20 : 2*enemies[j+(i*MAX_ALIENS_ON_ROW)]->getHeight() + 20 + 20*(i));
            enemies[j+(i*MAX_ALIENS_ON_ROW)]->setPosition(System::LEFT_X_BORDER + (System::RIGHT_X_BORDER - System::LEFT_X_BORDER - MAX_ALIENS_ON_ROW*gJellyfish1Clip.w - 5*(MAX_ALIENS_ON_ROW-1))/2 + gJellyfish1Clip.w*(j) + 5*j, y);
            enemies[j+(i*MAX_ALIENS_ON_ROW)]->setMovementDirection(RIGHT);
        }
    }

    UFO->getMovementDirection() == RIGHT ? UFO->setPosition(0 - UFO->getWidth(), 20)
                                            : UFO->setPosition(System::SCREEN_WIDTH, 20);

    player->setPosition((System::SCREEN_WIDTH - player->getWidth())/2,
                             System::SCREEN_HEIGHT - player->getHeight() - 20);
    player->resetScore();
    player->resetLives();

    for(unsigned int i = 0; i < bullets.size(); i++) {
        bullets[i]->setHasCollided(true);
    }

    barrier1->loadInitialTextures();
    barrier1->resetHitCounters();

    barrier2->loadInitialTextures();
    barrier2->resetHitCounters();

    barrier3->loadInitialTextures();
    barrier3->resetHitCounters();
}

void GameHandler::shutdownGame() {
    ofstream file("./levels/current.level");
    if(file.is_open()) {
        file << 1;
        file.close();
    }
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
