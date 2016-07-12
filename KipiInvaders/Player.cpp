#include "Player.h"

const int Player::SHOOTING_DELAY_FRAMES = 50;

Player::Player(Texture t, int lives) {
    _GOTexture = t;
    _PLives = lives;
    _PCanShoot = true;
    _PIsToShoot = false;
    _PShootingDelayCounter = 0;
}

int Player::getLives() { return _PLives; }

void Player::decreaseLives() { _PLives--; }

bool Player::isToShooT() { return _PIsToShoot; }

void Player::setIsToShooT( bool b ) { _PIsToShoot = b; }

void Player::addToScore(int points) { _PScore += points; }

int Player::getScore() { return _PScore; }

void Player::handleEvents(SDL_Event *e) {}

void Player::update() {
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);
    if(keyState[SDL_SCANCODE_LEFT]) {
        _GORect.x += -_GOVelocity;
    }
    else if(keyState[SDL_SCANCODE_RIGHT]) {
        _GORect.x += _GOVelocity;
    }

    if(keyState[SDL_SCANCODE_SPACE]) {
        if(_PCanShoot) {
            _PIsToShoot = true;
            _PCanShoot = false;
        }
    }

    if(_PShootingDelayCounter == Player::SHOOTING_DELAY_FRAMES) {
        _PShootingDelayCounter = 0;
        _PCanShoot = true;
    }
    else if(!_PCanShoot && !_PIsToShoot) {
        _PShootingDelayCounter++;
    }
}
