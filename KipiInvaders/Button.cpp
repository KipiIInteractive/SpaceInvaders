#include "Button.h"

Button::Button() {
    _BPosition.x = 0;
    _BPosition.y = 0;
    _BPosition.w = 0;
    _BPosition.h = 0;
    _BColor = {0, 0, 0, 0};
    _BClip = {0, 0, 0, 0};
    clicked = false;
}

Button::~Button() {
    _BTexture.free();
    _BPosition.x = 0;
    _BPosition.y = 0;
    _BPosition.w = 0;
    _BPosition.h = 0;
    _BColor = {0, 0, 0, 0};
    _BClip = {0, 0, 0, 0};
    clicked = false;
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

void Button::setClip(int x, int y, int w, int h) {
    _BClip.x = x;
    _BClip.y = y;
    _BClip.w = w;
    _BClip.h = h;
}

void Button::handleEvents(SDL_Event *e) {
    if(e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONUP) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        bool inside = true;
        if(x < _BPosition.x) {
            inside = false;
        }
        else if(x > _BPosition.x + _BPosition.w) {
            inside = false;
        }
        else if(y < _BPosition.y) {
            inside = false;
        }
        else if(y > _BPosition.y + _BPosition.h) {
            inside = false;
        }
        if(!inside) {
            _BColor = {255, 0, 0, 0};
        }
        else {
            switch(e->type) {
                case SDL_MOUSEBUTTONUP:
                    _BColor = {255, 0, 0, 0};
                    click();
                    break;

                case SDL_MOUSEMOTION:
                    _BColor = {255, 255, 255, 0};
                    break;

                default: _BColor = {255, 0, 0, 0};
            }
        }
    }
}

int Button::getHeight() {
    return _BTexture.getHeight();
}

int Button::getWidth() {
    return _BTexture.getWidth();
}

bool Button::isClicked() {
    return clicked;
}

void Button::click() {
    clicked = true;
}

void Button::unclick() {
    clicked = false;
}

void Button::render() {
    //Checks if the button is text-based and creates it once more in case its color has changed due to being hovered on
    if(_BTexture.getText() != "") {
        if(_BTexture.loadFromRenderedText(_BTexture.getText(), _BColor)) {
            _BTexture.render(_BPosition.x, _BPosition.y);
        }
    }
    else {
        _BTexture.render(_BPosition.x, _BPosition.y, &_BClip);
    }
}

void Button::free() {
    _BTexture.free();
}
