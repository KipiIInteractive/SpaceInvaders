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
           && (*it)->isAlive()
           && _GODirection == UP) {
            (*it)->setIsAlive(false);
            return true;
        }
    }
    return false;
}

bool Bullet::hasCollidedWithPlayer() {
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
