#include "Enemy.h"

Enemy::Enemy(Texture t, Direction dir, int points) {
    _ETexture = t;
    _EDirection = dir;
    _ERect.x = 0;
    _ERect.y = 0;
    _ERect.w = 0;
    _ERect.h = 0;
    _EVelocity.x = 0;
    _EVelocity.y = 0;
    _EPoints = points;
    _ECollidedWithScreen = false;
    _EAlive = true;
    _EShoot = false;
}

Enemy::~Enemy() {
    _ETexture.free();
    _ERect.x = 0;
    _ERect.y = 0;
    _ERect.w = 0;
    _ERect.h = 0;
    _EVelocity.x = 0;
    _EVelocity.y = 0;
    _EPoints = 0;
    _ECollidedWithScreen = false;
    _EAlive = false;
    _EShoot = false;
}

void Enemy::setPosition(int x, int y) { _ERect.x = x;
                                        _ERect.y = y; }

void Enemy::setXVelocity(int x) { _EVelocity.x = x; }
void Enemy::setYVelocity(int y) { _EVelocity.y = y; }

void Enemy::setWidth(int w) { _ERect.w = w; _ETexture.setWidth(w); }
void Enemy::setHeight(int h) { _ERect.h = h; _ETexture.setHeight(h); }

void Enemy::setMovementDirection(Direction dir) { _EDirection = dir; }

void Enemy::setHasCollidedWithScreen(bool b) { _ECollidedWithScreen = b; }

void Enemy::setIsAlive(bool b) { _EAlive = b; }

int Enemy::getX() { return _ERect.x; }
int Enemy::getY() { return _ERect.y; }

int Enemy::getWidth() { return _ERect.w; }
int Enemy::getHeight() { return _ERect.h; }

Direction Enemy::getMovementDirection() { return _EDirection; }

bool Enemy::hasCollidedWithScreen() { return _ECollidedWithScreen; }

bool Enemy::isAlive() { return _EAlive; }

bool Enemy::isToShooT() { return _EShoot; }

void Enemy::update() {
    if(_EDirection == RIGHT) {
        _ERect.x += _EVelocity.x;
    }
    else {
        _ERect.x -= _EVelocity.x;
    }

    if((rand() % (SHOOTING_RNG/CURRENT_LEVEL)) == 1) {
        _EShoot = true;
    }
    else {
        _EShoot = false;
    }
}

void Enemy::checkCollisionWithScreen() {
    if(_ERect.x < 0) {
        _ECollidedWithScreen = true;
        _ERect.x = 0;
    }
    else if(_ERect.x + _ERect.w > System::SCREEN_WIDTH) {
        _ECollidedWithScreen = true;
        _ERect.x = System::SCREEN_WIDTH - _ERect.w;
    }
    else {
        _ECollidedWithScreen = false;
    }
}

void Enemy::handleCollisionWithScreen() {
    if(_EDirection == RIGHT) {
        _EDirection = LEFT;
    }
    else {
        _EDirection = RIGHT;
    }
    _ERect.y += _ERect.h/4;
}

void Enemy::render() { _ETexture.render(_ERect.x, _ERect.y); }
