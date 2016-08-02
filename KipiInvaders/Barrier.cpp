#include "Barrier.h"

Barrier::Barrier() : _BTopLeftCorner(), _BTopRightCorner(), _BBottomLeft(), _BBottomRight(), _BMiddleLeft(),
                    _BMiddleRight(), _BInnerTopLeft(), _BInnerTopRight(), _BInnerBottomLeft(), _BInnerBottomRight(){
    _BRect.x = 0;
    _BRect.y = 0;
    _BRect.w = 0;
    _BRect.h = 0;
    _BTopLeftCornerHitCounter = 0;
    _BTopRightCornerHitCounter = 0;
    _BBottomLeftHitCounter = 0;
    _BBottomRightHitCounter = 0;
    _BMiddleLeftHitCounter = 0;
    _BMiddleRightHitCounter = 0;
    _BInnerTopLeftHitCounter = 0;
    _BInnerTopRightHitCounter = 0;
    _BInnerBottomLeftHitCounter = 0;
    _BInnerBottomRightHitCounter = 0;
    destroyed = false;
}

bool Barrier::loadInitialTextures() {
    bool success = true;

    if(!_BTopLeftCorner.loadFromFile("./images/upperLeftCorner.png")) {
        success = false;
    }
    else {
        _BTopLeftCorner.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
        _BTopLeftCorner.setHeight((_BTopLeftCorner.getWidth()*19)/21);
    }

    if(!_BTopRightCorner.loadFromFile("./images/upperRightCorner.png")) {
        success = false;
    }
    else {
        _BTopRightCorner.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
        _BTopRightCorner.setHeight((_BTopRightCorner.getWidth()*19)/23);
    }

    if(!_BBottomLeft.loadFromFile("./images/fullSquare.png")) {
        success = false;
    }
    else {
        _BBottomLeft.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
        _BBottomLeft.setHeight((_BBottomLeft.getWidth()*19)/22);
    }

    if(!_BBottomRight.loadFromFile("./images/fullSquare.png")) {
        success = false;
    }
    else {
        _BBottomRight.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
        _BBottomRight.setHeight((_BBottomRight.getWidth()*19)/22);
    }

    if(!_BMiddleLeft.loadFromFile("./images/fullSquare.png")) {
        success = false;
    }
    else {
        _BMiddleLeft.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
        _BMiddleLeft.setHeight((_BMiddleLeft.getWidth()*19)/22);
    }

    if(!_BMiddleRight.loadFromFile("./images/fullSquare.png")) {
        success = false;
    }
    else {
        _BMiddleRight.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
        _BMiddleRight.setHeight((_BMiddleRight.getWidth()*19)/22);
    }

    if(!_BInnerTopLeft.loadFromFile("./images/fullSquare.png")) {
        success = false;
    }
    else {
        _BInnerTopLeft.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
        _BInnerTopLeft.setHeight((_BInnerTopLeft.getWidth()*19)/22);
    }

    if(!_BInnerTopRight.loadFromFile("./images/fullSquare.png")) {
        success = false;
    }
    else {
        _BInnerTopRight.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
        _BInnerTopRight.setHeight((_BInnerTopRight.getWidth()*19)/22);
    }

    if(!_BInnerBottomLeft.loadFromFile("./images/innerLeftCorner.png")) {
        success = false;
    }
    else {
        _BInnerBottomLeft.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
        _BInnerBottomLeft.setHeight((_BInnerBottomLeft.getWidth()*19)/22);
    }

    if(!_BInnerBottomRight.loadFromFile("./images/innerRightCorner.png")) {
        success = false;
    }
    else {
        _BInnerBottomRight.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
        _BInnerBottomRight.setHeight((_BInnerBottomRight.getWidth()*19)/22);
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

bool Barrier::isDestroyed() { return destroyed; }

void Barrier::resetHitCounters() {
    _BTopLeftCornerHitCounter = 0;
    _BTopRightCornerHitCounter = 0;
    _BBottomLeftHitCounter = 0;
    _BBottomRightHitCounter = 0;
    _BMiddleLeftHitCounter = 0;
    _BMiddleRightHitCounter = 0;
    _BInnerBottomLeftHitCounter = 0;
    _BInnerBottomRightHitCounter = 0;
    _BInnerTopLeftHitCounter = 0;
    _BInnerTopRightHitCounter = 0;
}

void Barrier::update() {
    if(_BTopLeftCornerHitCounter >= 3 && _BTopRightCornerHitCounter >= 3 && _BBottomLeftHitCounter >= 3
       && _BBottomRightHitCounter >= 3 && _BMiddleLeftHitCounter >= 3 && _BMiddleRightHitCounter >= 3
       && _BInnerBottomLeftHitCounter >= 3 && _BInnerBottomRightHitCounter >= 3 && _BInnerTopLeftHitCounter >= 3
       && _BInnerTopRightHitCounter >= 3) {
        destroyed = true;
    }
}

void Barrier::checkAndHandleCollisionWithBullets() {
    for(unsigned i = 0; i < bullets.size(); i++) {
        if(bullets[i]->getX() + bullets[i]->getWidth() > _BTopLeftCornerPos.x
            && bullets[i]->getX() < _BTopLeftCornerPos.x + _BTopLeftCorner.getWidth()
            && (bullets[i]->getMovementDirection() == DOWN ? bullets[i]->getY() + bullets[i]->getHeight() >= _BTopLeftCornerPos.y
                                                            : bullets[i]->getY() <= _BTopLeftCornerPos.y + _BTopLeftCorner.getHeight())) {
            _BTopLeftCornerHitCounter++;
            if(_BTopLeftCornerHitCounter < 3) {
                _BTopLeftCorner.loadFromFile("./images/upperLeftCorner" + to_string(_BTopLeftCornerHitCounter) + ".png");
                _BTopLeftCorner.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
                _BTopLeftCorner.setHeight((_BTopLeftCorner.getWidth()*19)/21);
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else if(_BTopLeftCornerHitCounter == 3){
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else {
                _BTopLeftCornerHitCounter = 3;
            }
        }
        if(bullets[i]->getX() + bullets[i]->getWidth() > _BTopRightCornerPos.x
            && bullets[i]->getX() < _BTopRightCornerPos.x + _BTopRightCorner.getWidth()
            && (bullets[i]->getMovementDirection() == DOWN ? bullets[i]->getY() + bullets[i]->getHeight() >= _BTopRightCornerPos.y
                                                            : bullets[i]->getY() <= _BTopRightCornerPos.y + _BTopRightCorner.getHeight())) {
            _BTopRightCornerHitCounter++;
            if(_BTopRightCornerHitCounter < 3) {
                _BTopRightCorner.loadFromFile("./images/upperRightCorner" + to_string(_BTopRightCornerHitCounter) + ".png");
                _BTopRightCorner.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
                _BTopRightCorner.setHeight((_BTopRightCorner.getWidth()*19)/23);
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else if(_BTopRightCornerHitCounter == 3){
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else {
                _BTopRightCornerHitCounter = 3;
            }
        }
        if(bullets[i]->getX() + bullets[i]->getWidth() > _BBottomLeftPos.x
            && bullets[i]->getX() < _BBottomLeftPos.x + _BBottomLeft.getWidth()
            && (bullets[i]->getMovementDirection() == DOWN ? bullets[i]->getY() + bullets[i]->getHeight() >= _BBottomLeftPos.y
                                                            : bullets[i]->getY() <= _BBottomLeftPos.y + _BBottomLeft.getHeight())) {
            _BBottomLeftHitCounter++;
            if(_BBottomLeftHitCounter < 3) {
                _BBottomLeft.loadFromFile("./images/fullSquare" + to_string(_BBottomLeftHitCounter) + ".png");
                _BBottomLeft.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
                _BBottomLeft.setHeight((_BBottomLeft.getWidth()*19)/22);
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else if(_BBottomLeftHitCounter == 3){
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else {
                _BBottomLeftHitCounter = 3;
            }
        }
        if(bullets[i]->getX() + bullets[i]->getWidth() > _BBottomRightPos.x
            && bullets[i]->getX() < _BBottomRightPos.x + _BBottomRight.getWidth()
            && (bullets[i]->getMovementDirection() == DOWN ? bullets[i]->getY() + bullets[i]->getHeight() >= _BBottomRightPos.y
                                                            : bullets[i]->getY() <= _BBottomRightPos.y + _BBottomRight.getHeight())) {
            _BBottomRightHitCounter++;
            if(_BBottomRightHitCounter < 3) {
                _BBottomRight.loadFromFile("./images/fullSquare" + to_string(_BBottomRightHitCounter) + ".png");
                _BBottomRight.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
                _BBottomRight.setHeight((_BBottomRight.getWidth()*19)/22);
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else if(_BBottomRightHitCounter == 3){
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else {
                _BBottomRightHitCounter = 3;
            }
        }
        if(bullets[i]->getX() + bullets[i]->getWidth() > _BMiddleLeftPos.x
            && bullets[i]->getX() < _BMiddleLeftPos.x + _BMiddleLeft.getWidth()
            && (bullets[i]->getMovementDirection() == DOWN ? bullets[i]->getY() + bullets[i]->getHeight() >= _BMiddleLeftPos.y
                                                            : bullets[i]->getY() <= _BMiddleLeftPos.y + _BMiddleLeft.getHeight())) {
            _BMiddleLeftHitCounter++;
            if(_BMiddleLeftHitCounter < 3) {
                _BMiddleLeft.loadFromFile("./images/fullSquare" + to_string(_BMiddleLeftHitCounter) + ".png");
                _BMiddleLeft.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
                _BMiddleLeft.setHeight((_BMiddleLeft.getWidth()*19)/22);
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else if(_BMiddleLeftHitCounter == 3){
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else {
                _BMiddleLeftHitCounter = 3;
            }
        }
        if(bullets[i]->getX() + bullets[i]->getWidth() > _BMiddleRightPos.x
            && bullets[i]->getX() < _BMiddleRightPos.x + _BMiddleRight.getWidth()
            && (bullets[i]->getMovementDirection() == DOWN ? bullets[i]->getY() + bullets[i]->getHeight() >= _BMiddleRightPos.y
                                                            : bullets[i]->getY() <= _BMiddleRightPos.y + _BMiddleRight.getHeight())) {
            _BMiddleRightHitCounter++;
            if(_BMiddleRightHitCounter < 3) {
                _BMiddleRight.loadFromFile("./images/fullSquare" + to_string(_BMiddleRightHitCounter) + ".png");
                _BMiddleRight.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
                _BMiddleRight.setHeight((_BMiddleRight.getWidth()*19)/22);
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else if(_BMiddleRightHitCounter == 3){
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else {
                _BMiddleRightHitCounter = 3;
            }
        }
        if(bullets[i]->getX() + bullets[i]->getWidth() > _BInnerBottomLeftPos.x
            && bullets[i]->getX() < _BInnerBottomLeftPos.x + _BInnerBottomLeft.getWidth()
            && (bullets[i]->getMovementDirection() == DOWN ? bullets[i]->getY() + bullets[i]->getHeight() >= _BInnerBottomLeftPos.y
                                                            : bullets[i]->getY() <= _BInnerBottomLeftPos.y + _BInnerBottomLeft.getHeight())) {
            _BInnerBottomLeftHitCounter++;
            if(_BInnerBottomLeftHitCounter < 3) {
                _BInnerBottomLeft.loadFromFile("./images/innerLeftCorner" + to_string(_BInnerBottomLeftHitCounter) + ".png");
                _BInnerBottomLeft.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
                _BInnerBottomLeft.setHeight((_BInnerBottomLeft.getWidth()*19)/22);
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else if(_BInnerBottomLeftHitCounter == 3){
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else {
                _BInnerBottomLeftHitCounter = 3;
            }
        }
        if(bullets[i]->getX() + bullets[i]->getWidth() > _BInnerBottomRightPos.x
            && bullets[i]->getX() < _BInnerBottomRightPos.x + _BInnerBottomRight.getWidth()
            && (bullets[i]->getMovementDirection() == DOWN ? bullets[i]->getY() + bullets[i]->getHeight() >= _BInnerBottomRightPos.y
                                                            : bullets[i]->getY() <= _BInnerBottomRightPos.y + _BInnerBottomRight.getHeight())) {
            _BInnerBottomRightHitCounter++;
            if(_BInnerBottomRightHitCounter < 3) {
                _BInnerBottomRight.loadFromFile("./images/innerRightCorner" + to_string(_BInnerBottomRightHitCounter) + ".png");
                _BInnerBottomRight.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
                _BInnerBottomRight.setHeight((_BInnerBottomRight.getWidth()*19)/22);
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else if(_BInnerBottomRightHitCounter == 3){
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else {
                _BInnerBottomRightHitCounter = 3;
            }
        }
        if(bullets[i]->getX() + bullets[i]->getWidth() > _BInnerTopLeftPos.x
            && bullets[i]->getX() < _BInnerTopLeftPos.x + _BInnerTopLeft.getWidth()
            && (bullets[i]->getMovementDirection() == DOWN ? bullets[i]->getY() + bullets[i]->getHeight() >= _BInnerTopLeftPos.y
                                                            : bullets[i]->getY() <= _BInnerTopLeftPos.y + _BInnerTopLeft.getHeight())) {
            _BInnerTopLeftHitCounter++;
            if(_BInnerTopLeftHitCounter < 3) {
                _BInnerTopLeft.loadFromFile("./images/fullSquare" + to_string(_BInnerTopLeftHitCounter) + ".png");
                _BInnerTopLeft.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
                _BInnerTopLeft.setHeight((_BInnerTopLeft.getWidth()*19)/22);
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else if(_BInnerTopLeftHitCounter == 3){
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else {
                _BInnerTopLeftHitCounter = 3;
            }
        }
        if(bullets[i]->getX() + bullets[i]->getWidth() > _BInnerTopRightPos.x
            && bullets[i]->getX() < _BInnerTopRightPos.x + _BInnerTopRight.getWidth()
            && (bullets[i]->getMovementDirection() == DOWN ? bullets[i]->getY() + bullets[i]->getHeight() >= _BInnerTopRightPos.y
                                                            : bullets[i]->getY() <= _BInnerTopRightPos.y + _BInnerTopRight.getHeight())) {
            _BInnerTopRightHitCounter++;
            if(_BInnerTopRightHitCounter < 3) {
                _BInnerTopRight.loadFromFile("./images/fullSquare" + to_string(_BInnerTopRightHitCounter) + ".png");
                _BInnerTopRight.setWidth(((System::RIGHT_X_BORDER - System::LEFT_X_BORDER)*3)/100);
                _BInnerTopRight.setHeight((_BInnerTopRight.getWidth()*19)/22);
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else if(_BInnerTopRightHitCounter == 3){
                bullets[i]->setHasCollidedWithBarrier(true);
            }
            else {
                _BInnerTopRightHitCounter = 3;
            }
        }
    }
}

void Barrier::render() {
    if(_BTopLeftCornerHitCounter < 3) {
        _BTopLeftCorner.render(_BTopLeftCornerPos.x, _BTopLeftCornerPos.y);
    }
    if(_BMiddleLeftHitCounter < 3) {
        _BMiddleLeft.render(_BMiddleLeftPos.x, _BMiddleLeftPos.y);
    }
    if(_BBottomLeftHitCounter < 3) {
        _BBottomLeft.render(_BBottomLeftPos.x, _BBottomLeftPos.y);
    }
    if(_BInnerTopLeftHitCounter < 3) {
        _BInnerTopLeft.render(_BInnerTopLeftPos.x, _BInnerTopLeftPos.y);
    }
    if(_BInnerBottomLeftHitCounter < 3) {
        _BInnerBottomLeft.render(_BInnerBottomLeftPos.x, _BInnerBottomLeftPos.y);
    }
    if(_BInnerTopRightHitCounter < 3) {
        _BInnerTopRight.render(_BInnerTopRightPos.x, _BInnerTopRightPos.y);
    }
    if(_BInnerBottomRightHitCounter < 3) {
        _BInnerBottomRight.render(_BInnerBottomRightPos.x, _BInnerBottomRightPos.y);
    }
    if(_BTopRightCornerHitCounter < 3) {
        _BTopRightCorner.render(_BTopRightCornerPos.x, _BTopRightCornerPos.y);
    }
    if(_BMiddleRightHitCounter < 3) {
        _BMiddleRight.render(_BMiddleRightPos.x, _BMiddleRightPos.y);
    }
    if(_BBottomRightHitCounter < 3) {
        _BBottomRight.render(_BBottomRightPos.x, _BBottomRightPos.y);
    }
}
