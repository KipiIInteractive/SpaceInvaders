#include "GameObjectRenderer.h"

void GameObjectRenderer::renderEnemies() {
    for(unsigned int i = 0; i < enemies.size(); i++) {
        if(enemies[i]->isAlive()) {
            if(ENEMY_ANIMATION_FRAMES_COUNTER == 1 || ENEMY_ANIMATION_FRAMES_COUNTER == ENEMY_ANIMATION_FRAMES) {
                if(enemies[i]->getMovementDirection() == RIGHT) {
                    enemies[i]->setPosition(enemies[i]->getX() + enemies[i]->getVelocity(),enemies[i]->getY());
                }
                else {
                    enemies[i]->setPosition(enemies[i]->getX() - enemies[i]->getVelocity(),enemies[i]->getY());
                }
            }
            if(enemies[i]->getType() == SQUID) {
                if(ENEMY_ANIMATION_FRAMES_COUNTER < ENEMY_ANIMATION_FRAMES) {
                    enemies[i]->renderWithClipAndTexture(&gSquid1Clip, gAliensTexture);
                }
                else if(ENEMY_ANIMATION_FRAMES_COUNTER < 2*ENEMY_ANIMATION_FRAMES) {
                    enemies[i]->renderWithClipAndTexture(&gSquid2Clip, gAliensTexture);
                }
            }
            else if(enemies[i]->getType() == CRAB) {
                if(ENEMY_ANIMATION_FRAMES_COUNTER < ENEMY_ANIMATION_FRAMES) {
                    enemies[i]->renderWithClipAndTexture(&gCrab1Clip, gAliensTexture);
                }
                else if(ENEMY_ANIMATION_FRAMES_COUNTER < 2*ENEMY_ANIMATION_FRAMES) {
                    enemies[i]->renderWithClipAndTexture(&gCrab2Clip, gAliensTexture);
                }
            }
            else {
                if(ENEMY_ANIMATION_FRAMES_COUNTER < ENEMY_ANIMATION_FRAMES) {
                    enemies[i]->renderWithClipAndTexture(&gJellyfish1Clip, gAliensTexture);
                }
                else if(ENEMY_ANIMATION_FRAMES_COUNTER < 2*ENEMY_ANIMATION_FRAMES) {
                    enemies[i]->renderWithClipAndTexture(&gJellyfish2Clip, gAliensTexture);
                }
            }
        }
        else if(enemies[i]->hasBeenHit()) {
            if(ENEMY_DESTROYED_FRAMES_COUNTER < 40) {
                enemies[i]->renderWithClipAndTexture(NULL, gAlienDestroyedTexture);
            }
            else {
                enemies[i]->setHasBeenHit(false);
                ENEMY_DESTROYED_FRAMES_COUNTER = 0;
            }
        }
    }
    if(UFO->isAlive()) {
        UFO->render();
    }
    if(ENEMY_ANIMATION_FRAMES_COUNTER+1 == 2*ENEMY_ANIMATION_FRAMES) {
        ENEMY_ANIMATION_FRAMES_COUNTER = 0;
    }
}

void GameObjectRenderer::renderPlayer() {
    if(player->getLives() > 0) {
        if(PLAYER_DESTROYED_FRAMES_COUNTER < 40 && player->hasBeenHit()) {
            player->renderWithTexture(gPlayerDestroyedTexture);
        }
        else if(!player->hasBeenHit()) {
            player->renderWithTexture(gPlayerTexture);
        }
        else {
            player->setHasBeenHit(false);
            player->setPosition((System::RIGHT_X_BORDER - System::LEFT_X_BORDER - player->getWidth())/2, System::SCREEN_HEIGHT - player->getHeight() - 20);
            PLAYER_DESTROYED_FRAMES_COUNTER = 0;
        }
    }
}

void GameObjectRenderer::renderBullets() {
    for(unsigned int i = 0; i < bullets.size(); i++) {
        bullets[i]->render();
    }
}
