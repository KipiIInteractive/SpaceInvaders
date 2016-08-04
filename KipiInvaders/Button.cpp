#include "Button.h"

bool Button::currentOptionHasBeenChanged = false;
bool Button::isSpaceReleased = true;

Button::Button() {
    _BPosition.x = 0;
    _BPosition.y = 0;
    _BPosition.w = 0;
    _BPosition.h = 0;
    _BColor = {0, 0, 0, 0};
    active = false;
    pressed = false;
    activateNextButton = false;
    activatePreviousButton = false;
}

bool Button::loadButtonFromFile(string path) {
    return _BTexture.loadFromFile(path);
}

bool Button::loadButtonFromText(string text, SDL_Color color) {
    return _BTexture.loadFromRenderedText(text, color);
}

void Button::setDimensions(int x, int y, int w, int h) {
    _BPosition.x = x;
    _BPosition.y = y;
    _BPosition.w = w;
    _BPosition.h = h;
}

void Button::setIsActive(bool b) { active = b; }

bool Button::isActive() { return active; }

bool Button::nextButtonIsToBeActivated() { return activateNextButton; }

bool Button::previousButtonIsToBeActivated() { return activatePreviousButton; }

void Button::handleEvents(SDL_Event *e) {
    if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_UP && !Button::currentOptionHasBeenChanged && active) {
        active = false;
        activatePreviousButton = true;
        Button::currentOptionHasBeenChanged = true;
    }
    else if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_DOWN && !Button::currentOptionHasBeenChanged && active) {
        active = false;
        activateNextButton = true;
        Button::currentOptionHasBeenChanged = true;
    }
    else if(e->type == SDL_KEYUP && (e->key.keysym.sym == SDLK_UP || e->key.keysym.sym == SDLK_DOWN)) {
        activateNextButton = false;
        activatePreviousButton = false;
        Button::currentOptionHasBeenChanged = false;
    }

    if(active) {
        _BColor = {255, 255, 255, 255};
        if(e->type == SDL_KEYDOWN && (e->key.keysym.sym == SDLK_SPACE) && Button::isSpaceReleased) {
            pressed = true;
            Button::isSpaceReleased = false;
        }
        else if(e->type == SDL_KEYUP && (e->key.keysym.sym == SDLK_SPACE) && !Button::isSpaceReleased){
            Button::isSpaceReleased = true;
        }
    }
    else {
        _BColor = {255, 0, 0, 255};
    }
}

int Button::getHeight() { return _BTexture.getHeight(); }

int Button::getWidth() { return _BTexture.getWidth(); }

int Button::getX() { return _BPosition.x; }

int Button::getY() { return _BPosition.y; }

bool Button::hasBeenPressed() { return pressed; }

void Button::setHasBeenPressed(bool b) { pressed = b; }

void Button::render() {
    //Checks if the button is text-based and creates it once more in case its color has changed due to being hovered on
    if(_BTexture.getText() != "") {
        if(_BTexture.loadFromRenderedText(_BTexture.getText(), _BColor)) {
            _BTexture.render(_BPosition.x, _BPosition.y);
        }
    }
}
