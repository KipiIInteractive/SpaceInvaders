#include "InputField.h"

InputField::InputField() {
    _IFRect.x = 0;
    _IFRect.y = 0;
    _IFRect.w = 0;
    _IFRect.h = 0;
    _IFText = "";
    isSpacePressed = false;
    isActive = true;
}

bool InputField::loadFromFile(string path) {
    bool res = _IFTexture.loadFromFile(path);
    if(res) {
        _IFRect.w =_IFTexture.getWidth();
        _IFRect.h = _IFTexture.getHeight();
    }
    return res;
}

void InputField::setWidth(int w) { _IFRect.w = w;
                                   _IFTexture.setWidth(w); }

void InputField::setHeight(int h) { _IFRect.h = h;
                                    _IFTexture.setHeight(h); }

int InputField::getWidth() { return _IFRect.w; }

int InputField::getHeight() { return _IFRect.h; }

void InputField::setPosition(int x, int y) { _IFRect.x = x;
                                             _IFRect.y = y; }

int InputField::getX() { return _IFRect.x; }

int InputField::getY() { return _IFRect.y; }

void InputField::handleEvents(SDL_Event *e) {
    if(e->type == SDL_KEYDOWN && isActive) {
        if((e->key.keysym.sym >= SDLK_0 && e->key.keysym.sym <= SDLK_9)
           || (e->key.keysym.sym >= SDLK_a && e->key.keysym.sym <= SDLK_z) && _IFTextTexture.getWidth() < _IFRect.w - 45) {
            _IFText += (char)e->key.keysym.sym;
            _IFTextTexture.loadFromRenderedText(_IFText, {255, 255, 255, 255});
        }
        else if(e->key.keysym.sym == SDLK_SPACE && _IFText.length() > 0) {
            isSpacePressed = true;
        }
        else if(e->key.keysym.sym == SDLK_BACKSPACE && _IFText.length() > 0) {
            _IFText.pop_back();
            _IFTextTexture.loadFromRenderedText(_IFText, {255, 255, 255, 255});
        }
    }
}

string InputField::getInput() { return _IFText; }

bool InputField::spaceHasBeenPressed() { return isSpacePressed; }

void InputField::render() { _IFTexture.render(_IFRect.x, _IFRect.y);
                            _IFTextTexture.render(_IFRect.x + (_IFRect.w - _IFTextTexture.getWidth())/2,
                                                  _IFRect.y); }
