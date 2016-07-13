#include "GameObject.h"

GameObject::GameObject() {
    _GORect.x = 0;
    _GORect.y = 0;
    _GORect.w = 0;
    _GORect.h = 0;
    _GOVelocity = 0;
    _GODirection = NONE;
    _GOCollidedWithScreen = false;
};

GameObject::~GameObject() {
    _GOTexture.free();
    delete (&_GORect);
}

void GameObject::setPosition(int x, int y) { _GORect.x = x;
                                            _GORect.y = y; }

void GameObject::setVelocity(int x) { _GOVelocity = x; }
int GameObject::getVelocity() { return _GOVelocity; }

void GameObject::setWidth(int w) { _GORect.w = w; _GOTexture.setWidth(w); }
void GameObject::setHeight(int h) { _GORect.h = h; _GOTexture.setHeight(h); }

void GameObject::setMovementDirection(Direction dir) { _GODirection = dir; }

int GameObject::getX() { return _GORect.x; }
int GameObject::getY() { return _GORect.y; }

int GameObject::getWidth() { return _GORect.w; }
int GameObject::getHeight() { return _GORect.h; }

Direction GameObject::getMovementDirection() { return _GODirection; }

void GameObject::render() { _GOTexture.render(_GORect.x, _GORect.y); }

void GameObject::checkAndHandleCollisionWithScreen() {
    if(_GORect.x < System::LEFT_X_BORDER) {
        _GOCollidedWithScreen = true;
        _GORect.x = System::LEFT_X_BORDER;
    }
    else if(_GORect.x + _GORect.w > System::RIGHT_X_BORDER) {
        _GOCollidedWithScreen = true;
        _GORect.x = System::RIGHT_X_BORDER - _GORect.w;
    }
    else {
        _GOCollidedWithScreen = false;
    }
}

bool GameObject::hasCollidedWithScreen() { return _GOCollidedWithScreen; }
