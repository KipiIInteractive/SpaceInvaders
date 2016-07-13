#include "GameObjectRenderer.h"

void GameObjectRenderer::renderEnemies() {
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        if((*it)->isAlive()) {
            if(ENEMY_ANIMATION_FRAMES_COUNTER == 1 || ENEMY_ANIMATION_FRAMES_COUNTER == ENEMY_ANIMATION_FRAMES) {
                if((*it)->getMovementDirection() == RIGHT) {
                    (*it)->setPosition((*it)->getX() + (*it)->getVelocity(),(*it)->getY());
                }
                else {
                    (*it)->setPosition((*it)->getX() - (*it)->getVelocity(),(*it)->getY());
                }
            }
            if((*it)->getType() == SQUID) {
                if(ENEMY_ANIMATION_FRAMES_COUNTER < ENEMY_ANIMATION_FRAMES) {
                    (*it)->renderWithClip(gSquid1Clip);
                }
                else if(ENEMY_ANIMATION_FRAMES_COUNTER < 2*ENEMY_ANIMATION_FRAMES) {
                    (*it)->renderWithClip(gSquid2Clip);
                }
            }
            else if((*it)->getType() == CRAB) {
                if(ENEMY_ANIMATION_FRAMES_COUNTER < ENEMY_ANIMATION_FRAMES) {
                    (*it)->renderWithClip(gCrab1Clip);
                }
                else if(ENEMY_ANIMATION_FRAMES_COUNTER < 2*ENEMY_ANIMATION_FRAMES) {
                    (*it)->renderWithClip(gCrab2Clip);
                }
            }
            else {
                if(ENEMY_ANIMATION_FRAMES_COUNTER < ENEMY_ANIMATION_FRAMES) {
                    (*it)->renderWithClip(gJellyfish1Clip);
                }
                else if(ENEMY_ANIMATION_FRAMES_COUNTER < 2*ENEMY_ANIMATION_FRAMES) {
                    (*it)->renderWithClip(gJellyfish2Clip);
                }
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
    if(player->getLives()) {
        player->render();
    }
}

void GameObjectRenderer::renderBullets() {
    for(list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
        (*it)->render();
    }
}
