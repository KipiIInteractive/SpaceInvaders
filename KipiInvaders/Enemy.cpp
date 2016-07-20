#include "Enemy.h"

int ENEMY_ANIMATION_FRAMES = 50;
int ENEMY_ANIMATION_FRAMES_COUNTER = 0;
int ENEMY_DESTROYED_FRAMES_COUNTER = 0;

int Enemy::_EOffset = 0;

Enemy::Enemy(Texture& t, EnemyType type, Direction dir, int points) {
    _GOTexture = t;
    _GODirection = dir;
    _EType = type;
    _EPoints = points;
    _GOCollidedWithScreenHorizontally = false;
    _EAlive = true;
    _EShoot = false;
    _EHasBeenHit = false;
}

void Enemy::setHasCollidedWithScreenHorizontally(bool b) { _GOCollidedWithScreenHorizontally = b; }

bool Enemy::hasCollidedWithScreenVertically() { return _GOCollidedWithScreenVertically; }

void Enemy::setIsAlive(bool b) { _EAlive = b; }

bool Enemy::isAlive() { return _EAlive; }

bool Enemy::isToShooT() { return _EShoot; }

int Enemy::getPoints() { return _EPoints; }

void Enemy::setPoints(int points) { _EPoints = points; }

EnemyType Enemy::getType() { return _EType; }

bool Enemy::hasBeenHit() { return _EHasBeenHit; }

void Enemy::setHasBeenHit(bool b) { _EHasBeenHit = b; }

void Enemy::update() {

    if(_EType == MOTHERSHIP) {
        if(_GODirection == RIGHT) {
            _GORect.x += _GOVelocity/3;
        }
        else {
            _GORect.x -= _GOVelocity/3;
        }
    }
    else {
        if((rand() % (SHOOTING_RNG/LevelManager::GetCurrentLevel())) <= 2) {
            _EShoot = true;
        }
        else {
            _EShoot = false;
        }
    }
}

void Enemy::checkCollisionWithScreen() {
    if(_EType != MOTHERSHIP) {
        if(_GORect.x < System::LEFT_X_BORDER) {
            _GOCollidedWithScreenHorizontally = true;
            _EOffset = System::LEFT_X_BORDER - _GORect.x;
        }
        else if(_GORect.x + _GORect.w > System::RIGHT_X_BORDER) {
            _GOCollidedWithScreenHorizontally = true;
            _EOffset = (_GORect.x + _GORect.w) - System::RIGHT_X_BORDER;
        }
        else {
            _GOCollidedWithScreenHorizontally = false;
        }

        if(_GORect.y + _GORect.h >= System::SCREEN_HEIGHT) {
            _GOCollidedWithScreenVertically = true;
        }
    }
    else { // UFO
        if(_GORect.x < -_GORect.w) {
            _GOCollidedWithScreenHorizontally = true;
            _GORect.x = -_GORect.w;
        }
        else if(_GORect.x > System::SCREEN_WIDTH) {
            _GOCollidedWithScreenHorizontally = true;
            _GORect.x = System::SCREEN_WIDTH;
        }
        else {
            _GOCollidedWithScreenHorizontally = false;
        }
    }
}

void Enemy::handleCollisionWithScreenHorizontally() {
    _GORect.y += _GORect.h;
    if(_GODirection == RIGHT) {
        _GORect.x -= 4*_EOffset;
        _GODirection = LEFT;
    }
    else {
        _GORect.x += 2*_EOffset;
        _GODirection = RIGHT;
    }
}

void Enemy::renderWithClipAndTexture(SDL_Rect *clip, Texture& t) {
    _GOTexture.applyTexture(t.getTexture());
    _GOTexture.render(_GORect.x, _GORect.y, clip);
}
