#include "Player.h"

int PLAYER_DESTROYED_FRAMES_COUNTER = 0;

Player::Player(Texture t, int lives) {
    _GOTexture = t;
    _PLives = lives;
    _PCanShoot = true;
    _PIsToShoot = false;
    _PScore = 0;
}

int Player::getLives() { return _PLives; }

void Player::decreaseLives() { _PLives--; }

bool Player::isToShooT() { return _PIsToShoot; }

void Player::setIsToShooT(bool b) { _PIsToShoot = b; }

void Player::setCanShooT(bool b) { _PCanShoot = b; }

bool Player::hasBeenHit() { return _PHasBeenHit; }

void Player::setHasBeenHit(bool b) { _PHasBeenHit = b; }

void Player::addToScore(int points) { _PScore += points; }

int Player::getScore() { return _PScore; }

void Player::handleEvents(SDL_Event *e) {}

void Player::update() {
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);
    if(!_PHasBeenHit) {
        if(keyState[SDL_SCANCODE_LEFT]) {
            _GORect.x += -_GOVelocity;
        }
        else if(keyState[SDL_SCANCODE_RIGHT]) {
            _GORect.x += _GOVelocity;
        }

        if(keyState[SDL_SCANCODE_SPACE]) {
            if(_PCanShoot) {
                _PCanShoot = false;
                _PIsToShoot = true;
            }
        }
    }
}

void Player::renderWithTexture(Texture t) { _GOTexture.applyTexture(t.getTexture()); render(); }
