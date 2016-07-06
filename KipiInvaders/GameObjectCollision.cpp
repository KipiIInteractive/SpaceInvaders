#include "GameObjectCollision.h"

void GameObjectCollision::checkEnemyCollision() {
    firstRowOfEnemies.at(0)->checkCollision();
    if(firstRowOfEnemies.at(0)->hasCollidedWithScreen()) {
        for(int i = 1; i < firstRowOfEnemies.size(); i++) {
            if(firstRowOfEnemies[i]->getMovementDirection() == RIGHT) {
                firstRowOfEnemies[i]->setMovementDirection(LEFT);
            }
            else {
                firstRowOfEnemies[i]->setMovementDirection(RIGHT);
            }
            firstRowOfEnemies[i]->setPosition(firstRowOfEnemies[i]->getX(),
                                              firstRowOfEnemies[i]->getY() + firstRowOfEnemies[i]->getHeight()/4);
        }
        firstRowOfEnemies.at(0)->setHasCollidedWithScreen(false);
    }
    firstRowOfEnemies.at(firstRowOfEnemies.size()-1)->checkCollision();
    if(firstRowOfEnemies.at(firstRowOfEnemies.size()-1)->hasCollidedWithScreen()) {
        for(int i = 0; i < firstRowOfEnemies.size()-1; i++) {
            if(firstRowOfEnemies[i]->getMovementDirection() == RIGHT) {
                firstRowOfEnemies[i]->setMovementDirection(LEFT);
            }
            else {
                firstRowOfEnemies[i]->setMovementDirection(RIGHT);
            }
            firstRowOfEnemies[i]->setPosition(firstRowOfEnemies[i]->getX(),
                                              firstRowOfEnemies[i]->getY() + firstRowOfEnemies[i]->getHeight()/4);
        }
        firstRowOfEnemies.at(firstRowOfEnemies.size()-1)->setHasCollidedWithScreen(false);
    }
    secondRowOfEnemies.at(0)->checkCollision();
    if(secondRowOfEnemies.at(0)->hasCollidedWithScreen()) {
        for(int i = 1; i < secondRowOfEnemies.size(); i++) {
            if(secondRowOfEnemies[i]->getMovementDirection() == RIGHT) {
                secondRowOfEnemies[i]->setMovementDirection(LEFT);
            }
            else {
                secondRowOfEnemies[i]->setMovementDirection(RIGHT);
            }
            secondRowOfEnemies[i]->setPosition(secondRowOfEnemies[i]->getX(),
                                              secondRowOfEnemies[i]->getY() + secondRowOfEnemies[i]->getHeight()/4);
        }
        secondRowOfEnemies.at(0)->setHasCollidedWithScreen(false);
    }
    secondRowOfEnemies.at(secondRowOfEnemies.size()-1)->checkCollision();
    if(secondRowOfEnemies.at(secondRowOfEnemies.size()-1)->hasCollidedWithScreen()) {
        for(int i = 0; i < secondRowOfEnemies.size()-1; i++) {
            if(secondRowOfEnemies[i]->getMovementDirection() == RIGHT) {
                secondRowOfEnemies[i]->setMovementDirection(LEFT);
            }
            else {
                secondRowOfEnemies[i]->setMovementDirection(RIGHT);
            }
            secondRowOfEnemies[i]->setPosition(secondRowOfEnemies[i]->getX(),
                                              secondRowOfEnemies[i]->getY() + secondRowOfEnemies[i]->getHeight()/4);
        }
        secondRowOfEnemies.at(secondRowOfEnemies.size()-1)->setHasCollidedWithScreen(false);
    }
    thirdRowOfEnemies.at(0)->checkCollision();
    if(thirdRowOfEnemies.at(0)->hasCollidedWithScreen()) {
        for(int i = 1; i < thirdRowOfEnemies.size(); i++) {
            if(thirdRowOfEnemies[i]->getMovementDirection() == RIGHT) {
                thirdRowOfEnemies[i]->setMovementDirection(LEFT);
            }
            else {
                thirdRowOfEnemies[i]->setMovementDirection(RIGHT);
            }
            thirdRowOfEnemies[i]->setPosition(thirdRowOfEnemies[i]->getX(),
                                              thirdRowOfEnemies[i]->getY() + thirdRowOfEnemies[i]->getHeight()/4);
        }
        thirdRowOfEnemies.at(0)->setHasCollidedWithScreen(false);
    }
    thirdRowOfEnemies.at(thirdRowOfEnemies.size()-1)->checkCollision();
    if(thirdRowOfEnemies.at(thirdRowOfEnemies.size()-1)->hasCollidedWithScreen()) {
        for(int i = 0; i < thirdRowOfEnemies.size()-1; i++) {
            if(thirdRowOfEnemies[i]->getMovementDirection() == RIGHT) {
                thirdRowOfEnemies[i]->setMovementDirection(LEFT);
            }
            else {
                thirdRowOfEnemies[i]->setMovementDirection(RIGHT);
            }
            thirdRowOfEnemies[i]->setPosition(thirdRowOfEnemies[i]->getX(),
                                              thirdRowOfEnemies[i]->getY() + thirdRowOfEnemies[i]->getHeight()/4);
        }
        thirdRowOfEnemies.at(thirdRowOfEnemies.size()-1)->setHasCollidedWithScreen(false);
    }
    fourthRowOfEnemies.at(0)->checkCollision();
    if(fourthRowOfEnemies.at(0)->hasCollidedWithScreen()) {
        for(int i = 1; i < fourthRowOfEnemies.size(); i++) {
            if(fourthRowOfEnemies[i]->getMovementDirection() == RIGHT) {
                fourthRowOfEnemies[i]->setMovementDirection(LEFT);
            }
            else {
                fourthRowOfEnemies[i]->setMovementDirection(RIGHT);
            }
            fourthRowOfEnemies[i]->setPosition(fourthRowOfEnemies[i]->getX(),
                                              fourthRowOfEnemies[i]->getY() + fourthRowOfEnemies[i]->getHeight()/4);
        }
        fourthRowOfEnemies.at(0)->setHasCollidedWithScreen(false);
    }
    fourthRowOfEnemies.at(fourthRowOfEnemies.size()-1)->checkCollision();
    if(fourthRowOfEnemies.at(fourthRowOfEnemies.size()-1)->hasCollidedWithScreen()) {
        for(int i = 0; i < fourthRowOfEnemies.size()-1; i++) {
            if(fourthRowOfEnemies[i]->getMovementDirection() == RIGHT) {
                fourthRowOfEnemies[i]->setMovementDirection(LEFT);
            }
            else {
                fourthRowOfEnemies[i]->setMovementDirection(RIGHT);
            }
            fourthRowOfEnemies[i]->setPosition(fourthRowOfEnemies[i]->getX(),
                                              fourthRowOfEnemies[i]->getY() + fourthRowOfEnemies[i]->getHeight()/4);
        }
        fourthRowOfEnemies.at(fourthRowOfEnemies.size()-1)->setHasCollidedWithScreen(false);
    }
}

void GameObjectCollision::checkPlayerCollision() {

}
