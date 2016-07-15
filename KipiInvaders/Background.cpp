#include "Background.h"

Background::Background() {
    _BClip.x = 0;
    _BClip.y = 0;
    _BClip.w = 0;
    _BClip.h = 0;
}

Background::~Background() {
    _BTexture.free();
    delete &(_BClip);
}

bool Background::loadBackgroundFromFile(string path) {
    return _BTexture.loadFromFile(path);
}

void Background::setBackgroundClip(int x, int y, int w, int h) {
    _BClip.x = x;
    _BClip.y = y;
    _BClip.w = w;
    _BClip.h = h;
}

void Background::render(int x, int y) {
    _BTexture.render(x, y, &_BClip);
}
