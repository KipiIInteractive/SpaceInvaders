#include "Barrier.h"

Barrier::Barrier() {
    _BRect.x = 0;
    _BRect.y = 0;
    _BRect.w = 0;
    _BRect.h = 0;
}

Barrier::~Barrier() {
    delete &(_BRect);
    delete &(_BTopLeftCornerPos);
    delete &(_BTopRightCornerPos);
    delete &(_BBottomLeftPos);
    delete &(_BBottomRightPos);
    delete &(_BMiddleLeftPos);
    delete &(_BMiddleRightPos);
    delete &(_BInnerBottomLeftPos);
    delete &(_BInnerBottomRightPos);
    delete &(_BInnerTopLeftPos);
    delete &(_BInnerTopRightPos);
    _BTopLeftCorner.free();
    _BTopRightCorner.free();
    _BBottomLeft.free();
    _BBottomRight.free();
    _BMiddleLeft.free();
    _BMiddleRight.free();
    _BInnerTopLeft.free();
    _BInnerTopRight.free();
    _BInnerBottomLeft.free();
    _BInnerBottomRight.free();
}

bool Barrier::loadInitialTextures() {
    bool success = true;

    if(!_BTopLeftCorner.loadFromFile("./images/upperLeftCorner.png")) {
        success = false;
    }

    if(!_BTopRightCorner.loadFromFile("./images/upperRightCorner.png")) {
        success = false;
    }

    if(!_BBottomLeft.loadFromFile("./images/fullSquare.png")) {
        success = false;
    }

    if(!_BBottomRight.loadFromFile("./images/fullSquare.png")) {
        success = false;
    }

    if(!_BMiddleLeft.loadFromFile("./images/fullSquare.png")) {
        success = false;
    }

    if(!_BMiddleRight.loadFromFile("./images/fullSquare.png")) {
        success = false;
    }

    if(!_BInnerTopLeft.loadFromFile("./images/fullSquare.png")) {
        success = false;
    }

    if(!_BInnerTopRight.loadFromFile("./images/fullSquare.png")) {
        success = false;
    }

    if(!_BInnerBottomLeft.loadFromFile("./images/innerLeftCorner.png")) {
        success = false;
    }

    if(!_BInnerBottomRight.loadFromFile("./images/innerRightCorner.png")) {
        success = false;
    }

    return success;
}

void Barrier::setDimensions() {
    _BRect.w = _BMiddleLeft.getWidth()
                + _BInnerBottomLeft.getWidth()
                + _BInnerBottomRight.getWidth()
                + _BMiddleRight.getWidth();
    _BRect.h = _BTopLeftCorner.getHeight()
                + _BMiddleLeft.getHeight()
                + _BBottomLeft.getHeight();
}

int Barrier::getWidth() { return _BRect.w; }
int Barrier::getHeight() { return _BRect.h; }

void Barrier::setPosition(int x, int y) {
    _BRect.x = x;
    _BRect.y = y;

    _BTopLeftCornerPos.x = _BRect.x;
    _BTopLeftCornerPos.y =  _BRect.y;

    _BMiddleLeftPos.x = _BRect.x;
    _BMiddleLeftPos.y =  _BRect.y + _BTopLeftCorner.getHeight();

    _BBottomLeftPos.x = _BRect.x;
    _BBottomLeftPos.y = _BRect.y + _BMiddleLeft.getHeight() + _BTopLeftCorner.getHeight();

    _BInnerTopLeftPos.x = _BRect.x + _BTopLeftCorner.getWidth();
    _BInnerTopLeftPos.y = _BRect.y;

    _BInnerBottomLeftPos.x = _BRect.x + _BMiddleLeft.getWidth();
    _BInnerBottomLeftPos.y = _BRect.y + _BInnerTopLeft.getHeight();

    _BInnerTopRightPos.x = _BRect.x + _BInnerTopLeft.getWidth() + _BTopLeftCorner.getWidth();
    _BInnerTopRightPos.y = _BRect.y;

    _BInnerBottomRightPos.x = _BRect.x + _BInnerBottomLeft.getWidth() + _BMiddleLeft.getWidth();
    _BInnerBottomRightPos.y = _BRect.y + _BInnerTopRight.getHeight();

    _BTopRightCornerPos.x = _BRect.x + _BInnerTopRight.getWidth() + _BInnerTopLeft.getWidth() + _BTopLeftCorner.getWidth();
    _BTopRightCornerPos.y = _BRect.y;

    _BMiddleRightPos.x = _BRect.x + _BInnerBottomRight.getWidth() + _BInnerBottomLeft.getWidth() + _BMiddleLeft.getWidth();
    _BMiddleRightPos.y = _BRect.y + _BTopRightCorner.getHeight();

    _BBottomRightPos.x = _BRect.x + _BBottomLeft.getWidth() + _BInnerBottomLeft.getWidth() + _BInnerBottomRight.getWidth();
    _BBottomRightPos.y = _BRect.y + _BMiddleRight.getHeight() + _BTopRightCorner.getHeight();
}

int Barrier::getX() { return _BRect.x; }
int Barrier::getY() { return _BRect.y; }

void Barrier::render() {
    _BTopLeftCorner.render(_BTopLeftCornerPos.x, _BTopLeftCornerPos.y);
    _BMiddleLeft.render(_BMiddleLeftPos.x, _BMiddleLeftPos.y);
    _BBottomLeft.render(_BBottomLeftPos.x, _BBottomLeftPos.y);
    _BInnerTopLeft.render(_BInnerTopLeftPos.x, _BInnerTopLeftPos.y);
    _BInnerBottomLeft.render(_BInnerBottomLeftPos.x, _BInnerBottomLeftPos.y);
    _BInnerTopRight.render(_BInnerTopRightPos.x, _BInnerTopRightPos.y);
    _BInnerBottomRight.render(_BInnerBottomRightPos.x, _BInnerBottomRightPos.y);
    _BTopRightCorner.render(_BTopRightCornerPos.x, _BTopRightCornerPos.y);
    _BMiddleRight.render(_BMiddleRightPos.x, _BMiddleRightPos.y);
    _BBottomRight.render(_BBottomRightPos.x, _BBottomRightPos.y);
}
