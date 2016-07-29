#include "InputField.h"

InputField::InputField() {
    _IFRect.x = 0;
    _IFRect.y = 0;
    _IFRect.w = 0;
    _IFRect.h = 0;
    _IFText = "";
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

}

void InputField::render() { _IFTexture.render(_IFRect.x, _IFRect.y); }
