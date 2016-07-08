#include "Bullet.h"

Bullet::Bullet(Texture texture, Direction direction, int speed)
{
    this->texture = texture;

    this->rect.x = 0;
    this->rect.y = 0;
    this->rect.w = 0;
    this->rect.h = 0;

    this->speed = speed;
    this->direction = direction;

    this->collided = false;
}

Bullet::~Bullet() {
    this->texture.free();
    this->rect.x = 0;
    this->rect.y = 0;
    this->rect.w = 0;
    this->rect.h = 0;

    this->speed = 0;
    this->direction = NONE;
}

bool Bullet::loadBulletFromFile(string path) { return texture.loadFromFile(path); }

void Bullet::SetDirection(Direction direction) { this->direction = direction; }

Direction Bullet::GetDirection() { return this->direction; }

int Bullet::GetX() { return rect.x; }
int Bullet::GetY() { return rect.y; }
int Bullet::GetWidth() { return rect.w; }
int Bullet::GetHeight() { return rect.h; }

void Bullet::SetX(int value) { rect.x = value; }
void Bullet::SetY(int value) { rect.y = value; }
void Bullet::SetWidth(int value) { rect.w = value; texture.setWidth(value); }
void Bullet::SetHeight(int value) { rect.h  = value; texture.setHeight(value); }

void Bullet::update() {
    if(direction == UP) {
        rect.y -= speed;
    }
    else if(direction == DOWN) {
        rect.y += speed;
    }
}

void Bullet::render() { texture.render(rect.x, rect.y); }

void Bullet::SetSpeed(int speed) { this->speed = speed; }

bool Bullet::hasCollided() { return collided; }

bool Bullet::hasCollidedWithEnemy() {
    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
        if(rect.x + rect.w >= (*it)->getX()
           && rect.x <= (*it)->getX() + (*it)->getWidth()
           && rect.y < (*it)->getY() + (*it)->getHeight()
           && (*it)->isAlive()
           && direction == UP) {
            (*it)->setIsAlive(false);
            return true;
        }
    }
    return false;
}

bool Bullet::hasCollidedWithPlayer() {
    return false;
}

void Bullet::checkCollision() {
    if(rect.y < 0 || rect.y > System::SCREEN_HEIGHT || hasCollidedWithEnemy() || hasCollidedWithPlayer()) {
        collided = true;
    }
}
