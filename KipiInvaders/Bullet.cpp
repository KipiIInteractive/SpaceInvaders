#include "Bullet.h"

Bullet::Bullet(Texture texture, Direction direction, int speed)
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

bool Bullet::hasCollidedWithEnemy() {
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
        if(_GORect.x + _GORect.w >= (*it)->getX()
           && _GORect.x <= (*it)->getX() + (*it)->getWidth()
           && _GORect.y < (*it)->getY() + (*it)->getHeight()
           && _GORect.y > (*it)->getY() + (*it)->getHeight() - 20
           && (*it)->isAlive()
           && _GODirection == UP) {
            (*it)->setIsAlive(false);
            player->addToScore((*it)->getPoints());
            return true;
        }
    }
    if(UFO->isAlive()) {
        if(_GORect.x + _GORect.w >= UFO->getX()
           && _GORect.x <= UFO->getX() + UFO->getWidth()
           && _GORect.y < UFO->getY() + UFO->getHeight()) {
            player->addToScore(UFO->getPoints());
            UFO->setIsAlive(false);
            return true;
        }
    }
    return false;
}

bool Bullet::hasCollidedWithPlayer() {
    if(player->getLives() > 0) {
        if(_GORect.x + _GORect.w >= player->getX()
           && _GORect.x <= player->getX() + player->getWidth()
           && _GORect.y > player->getY()) {
            player->decreaseLives();
            return true;
        }
    }
    return false;
}

void Bullet::checkCollision() {
    if(_GORect.y < 0 || _GORect.y > System::SCREEN_HEIGHT || hasCollidedWithEnemy() || hasCollidedWithPlayer()) {
        collided = true;
    }
    else {
        collided = false;
    }
}
