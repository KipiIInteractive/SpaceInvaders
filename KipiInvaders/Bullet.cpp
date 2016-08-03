#include "Bullet.h"

Bullet::Bullet(Texture& texture, Direction direction, int speed)
{
    _GODirection = direction;
    _GOTexture = texture;
    _GOVelocity = speed;
    collided = false;
}

void Bullet::update() {
    if(_GODirection == UP) {
        _GORect.y -= _GOVelocity;
    }
    else if(_GODirection == DOWN) {
        _GORect.y += _GOVelocity;
    }
}

bool Bullet::hasCollided() { return collided; }
void Bullet::setHasCollided(bool b) { collided = b; }

bool Bullet::hasCollidedWithEnemy() {
    for(unsigned int i = 0; i < enemies.size(); i++) {
        if(_GORect.x + _GORect.w >= enemies[i]->getX()
           && _GORect.x <= enemies[i]->getX() + enemies[i]->getWidth()
           && _GORect.y < enemies[i]->getY() + enemies[i]->getHeight()
           && _GORect.y > enemies[i]->getY() + enemies[i]->getHeight() - 20
           && enemies[i]->isAlive()
           && _GODirection == UP) {
            enemies[i]->setIsAlive(false);
            enemies[i]->setHasBeenHit(true);
            player->addToScore(enemies[i]->getPoints());
            Mix_PlayChannel(-1, gAlienExplosionSound, 0);
            return true;
        }
    }
    if(UFO->isAlive()) {
        if(_GORect.x + _GORect.w >= UFO->getX()
           && _GORect.x <= UFO->getX() + UFO->getWidth()
           && _GORect.y < UFO->getY() + UFO->getHeight()) {
            player->addToScore(UFO->getPoints());
            UFO->setIsAlive(false);
            UFO->setHasBeenHit(true);
            Mix_PlayChannel(-1, gAlienExplosionSound, 0);
            return true;
        }
    }
    return false;
}

bool Bullet::hasCollidedWithPlayer() {
    if(player->getLives() > 0) {
        if(_GORect.x + _GORect.w >= player->getX()
           && _GORect.x <= player->getX() + player->getWidth()
           && _GORect.y > player->getY() && !player->hasBeenHit()) {
            player->decreaseLives();
            player->setHasBeenHit(true);
            Mix_PlayChannel(-1, gPlayerExplosionSound, 0);
            return true;
        }
    }
    return false;
}

bool Bullet::hasCollidedWithBarrier() { return collidedWithBarrier; }
void Bullet::setHasCollidedWithBarrier(bool b) { collidedWithBarrier = b; }

void Bullet::checkCollision() {
    if(_GORect.y < 0 || _GORect.y > System::SCREEN_HEIGHT || hasCollidedWithEnemy() || hasCollidedWithPlayer() || hasCollidedWithBarrier()) {
        collided = true;
    }
}
