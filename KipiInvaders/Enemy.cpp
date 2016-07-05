#include "Enemy.h"

Enemy::Enemy() {
    _ERect.x = 0;
    _ERect.y = 0;
    _ERect.w = 0;
    _ERect.h = 0;
    _EVelocity.x = 0;
    _EVelocity.y = 0;
    _ECollidedWithScreen = false;
}

Enemy::~Enemy() {
    _ETexture.free();
    _ERect.x = 0;
    _ERect.y = 0;
    _ERect.w = 0;
    _ERect.h = 0;
    _EVelocity.x = 0;
    _EVelocity.y = 0;
    _ECollidedWithScreen = false;
}

bool Enemy::loadFromFile(string path) { return _ETexture.loadFromFile(path); }

void Enemy::setPosition(int x, int y) { _ERect.x = x;
                                        _ERect.y = y; }

void Enemy::setXVelocity(int x) { _EVelocity.x = x; }
void Enemy::setYVelocity(int y) { _EVelocity.y = y; }

void Enemy::setWidth(int w) { _ERect.w = w; _ETexture.setWidth(w); }
void Enemy::setHeight(int h) { _ERect.h = h; _ETexture.setHeight(h); }

void Enemy::setMovementDirection(Direction dir) { _EDirection = dir; }

void Enemy::setHasCollidedWithScreen(bool b) { _ECollidedWithScreen = b; }

int Enemy::getX() { return _ERect.x; }
int Enemy::getY() { return _ERect.y; }

int Enemy::getWidth() { return _ERect.w; }
int Enemy::getHeight() { return _ERect.h; }

Direction Enemy::getMovementDirection() { return _EDirection; }

bool Enemy::hasCollidedWithScreen() { return _ECollidedWithScreen; }

void Enemy::render() { _ETexture.render(_ERect.x, _ERect.y); }

void Enemy::update() {
    if(_EDirection == RIGHT) {
        _ERect.x += _EVelocity.x;
    }
    else {
        _ERect.x -= _EVelocity.x;
    }
}

void Enemy::checkCollision() {
    if(_ERect.x <= 0) {
        _ERect.x = 0;
        _EDirection = RIGHT;
        _ECollidedWithScreen = true;
    }
    else if(_ERect.x + _ERect.w >= System::SCREEN_WIDTH) {
        _ERect.x = System::SCREEN_WIDTH - _ERect.w;
        _EDirection = LEFT;
        _ECollidedWithScreen = true;
    }
}
