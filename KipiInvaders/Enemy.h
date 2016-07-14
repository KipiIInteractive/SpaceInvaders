#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "GameResources.h"
#include "GameObject.h"
#include "EnemyType.h"
#include "LevelManager.h"

using namespace std;

class Enemy : public GameObject {
private:
    EnemyType _EType;
    int _EPoints;
    bool _EAlive;
    bool _EShoot;
    bool _EHasBeenHit;
public:
    Enemy(Texture t, EnemyType type, Direction dir, int points);

    static int _EOffset;

    void setHasCollidedWithScreen(bool b);
    void checkCollisionWithScreen();
    void handleCollisionWithScreen();

    void setIsAlive(bool b);
    bool isAlive();

    void setHasBeenHit(bool b);
    bool hasBeenHit();

    bool isToShooT();

    EnemyType getType();

    int getPoints();
    void setPoints(int points);

    void update();

    void renderWithClipAndTexture(SDL_Rect *clip, Texture t);
};


#endif // ENEMY_H_INCLUDED
