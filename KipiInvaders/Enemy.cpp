#include "Enemy.h"

const int Enemy::MAX_ALIENS_ON_ROW = 8;

Enemy::Enemy() {
    _ERect.x = 0;
    _ERect.y = 0;
    _ERect.w = 0;
    _ERect.h = 0;
    _EVelocity.x = 0;
    _EVelocity.y = 0;
}

Enemy::~Enemy() {
    _ETexture.free();
    _ERect.x = 0;
    _ERect.y = 0;
    _ERect.w = 0;
    _ERect.h = 0;
    _EVelocity.x = 0;
    _EVelocity.y = 0;
}

bool Enemy::loadFromFile(string path) { return _ETexture.loadFromFile(path); }

void Enemy::setPosition() {

}

void Enemy::setXVelocity(int x) { _EVelocity.x = x; }
void Enemy::setYVelocity(int y) { _EVelocity.y = y; }

void Enemy::setWidth(int w) { _ERect.w = w; _ETexture.setWidth(w); }
void Enemy::setHeight(int h) { _ERect.h = h; _ETexture.setHeight(h); }

int Enemy::getX() { return _ERect.x; }
int Enemy::getY() { return _ERect.y; }

int Enemy::getWidth() { return _ERect.w; }
int Enemy::getHeight() { return _ERect.h; }

void Enemy::render() { _ETexture.render(_ERect.x, _ERect.y); }
