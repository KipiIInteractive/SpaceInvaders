#include "Player.h"

Player::Player(Texture t, int lives) {
    _GOTexture = t;
    _PLives = lives;
}

int Player::getLives() {
    return _PLives;
}

void Player::handleEvents(SDL_Event *e) {
    if(e->type == SDL_KEYDOWN) {
        switch(e->key.keysym.sym) {
            case SDLK_LEFT:

                break;

            case SDLK_RIGHT:

                break;

            case SDLK_SPACE:

                break;
        }
    }

}

void Player::update() {
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);
    if(keyState[SDL_SCANCODE_LEFT]) {
        _GORect.x += -_GOVelocity;
    }
    else if(keyState[SDL_SCANCODE_RIGHT]) {
        _GORect.x += _GOVelocity;
    }
}
