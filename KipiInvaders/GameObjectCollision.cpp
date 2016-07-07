#include "GameObjectCollision.h"

void GameObjectCollision::checkEnemyCollision() {
    int enemyCounter = 0;
    //Tries to find an alive leftmost alien on the current row
    while(!(firstRowOfEnemies[enemyCounter]->isAlive()) && enemyCounter < firstRowOfEnemies.size()) {
        enemyCounter++;
    }
    // If the found alien is the only one alive on the row
    if(enemyCounter == firstRowOfEnemies.size()-1) {
        firstRowOfEnemies.at(enemyCounter)->checkCollision();
        if(firstRowOfEnemies.at(enemyCounter)->hasCollidedWithScreen()) {
            for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
                if((*it)->isAlive()) {
                    if((*it)->getMovementDirection() == LEFT) {
                        (*it)->setMovementDirection(RIGHT);
                    }
                    else {
                        (*it)->setMovementDirection(LEFT);
                    }
                    (*it)->setPosition((*it)->getX(),
                                        (*it)->getY() + (*it)->getHeight()/4);
                }
            }
            firstRowOfEnemies.at(enemyCounter)->setHasCollidedWithScreen(false);
        }
    }
    else if(enemyCounter < firstRowOfEnemies.size()-1) {
        firstRowOfEnemies.at(enemyCounter)->checkCollision();
        if(firstRowOfEnemies.at(enemyCounter)->hasCollidedWithScreen()) {
            for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
                if((*it)->isAlive()) {
                    if((*it)->getMovementDirection() == LEFT) {
                        (*it)->setMovementDirection(RIGHT);
                    }
                    else {
                        (*it)->setMovementDirection(LEFT);
                    }
                    (*it)->setPosition((*it)->getX(),
                                        (*it)->getY() + (*it)->getHeight()/4);
                }
            }
            firstRowOfEnemies.at(enemyCounter)->setHasCollidedWithScreen(false);
        }
        else {
            int enemyCounter2 = firstRowOfEnemies.size()-1;
            //Tries to find an alive rightmost alien
            while(!(firstRowOfEnemies[enemyCounter2]->isAlive()) && enemyCounter2 > enemyCounter) {
                enemyCounter2--;
            }
            //It found another alien, which is the rightmost
            if(enemyCounter2 > enemyCounter) {
                firstRowOfEnemies.at(enemyCounter2)->checkCollision();
                if(firstRowOfEnemies.at(enemyCounter2)->hasCollidedWithScreen()) {
                    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
                        if((*it)->isAlive()) {
                            (*it)->setMovementDirection(LEFT);
                            (*it)->setPosition((*it)->getX(),
                                                (*it)->getY() + (*it)->getHeight()/4);
                        }
                    }
                    firstRowOfEnemies.at(enemyCounter2)->setHasCollidedWithScreen(false);
                }
            }
        }
    }
//    enemyCounter = 0;
//    //Tries to find an alive leftmost alien on the current row
//    while(!(secondRowOfEnemies[enemyCounter]->isAlive()) && enemyCounter < secondRowOfEnemies.size()) {
//        enemyCounter++;
//    }
//    // If the found alien is the only one alive on the row
//    if(enemyCounter == secondRowOfEnemies.size()-1) {
//        secondRowOfEnemies.at(enemyCounter)->checkCollision();
//        if(secondRowOfEnemies.at(enemyCounter)->hasCollidedWithScreen()) {
//            for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
//                if((*it)->isAlive()) {
//                    if((*it)->getMovementDirection() == LEFT) {
//                        (*it)->setMovementDirection(RIGHT);
//                    }
//                    else {
//                        (*it)->setMovementDirection(LEFT);
//                    }
//                    (*it)->setPosition((*it)->getX(),
//                                        (*it)->getY() + (*it)->getHeight()/4);
//                }
//            }
//            secondRowOfEnemies.at(enemyCounter)->setHasCollidedWithScreen(false);
//        }
//    }
//    else if(enemyCounter < secondRowOfEnemies.size()-1) {
//        secondRowOfEnemies.at(enemyCounter)->checkCollision();
//        if(secondRowOfEnemies.at(enemyCounter)->hasCollidedWithScreen()) {
//            for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
//                if((*it)->isAlive()) {
//                    if((*it)->getMovementDirection() == LEFT) {
//                        (*it)->setMovementDirection(RIGHT);
//                    }
//                    else {
//                        (*it)->setMovementDirection(LEFT);
//                    }
//                    (*it)->setPosition((*it)->getX(),
//                                            (*it)->getY() + (*it)->getHeight()/4);
//                }
//            }
//            secondRowOfEnemies.at(enemyCounter)->setHasCollidedWithScreen(false);
//        }
//        else {
//            int enemyCounter2 = secondRowOfEnemies.size()-1;
//            //Tries to find an alive rightmost alien
//            while(!(secondRowOfEnemies[enemyCounter2]->isAlive()) && enemyCounter2 > enemyCounter) {
//                enemyCounter2--;
//            }
//            //It found another alien, which is the rightmost
//            if(enemyCounter2 > enemyCounter) {
//                secondRowOfEnemies.at(enemyCounter2)->checkCollision();
//                if(secondRowOfEnemies.at(enemyCounter2)->hasCollidedWithScreen()) {
//                    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
//                        if((*it)->isAlive()) {
//                            (*it)->setMovementDirection(LEFT);
//                            (*it)->setPosition((*it)->getX(),
//                                                (*it)->getY() + (*it)->getHeight()/4);
//                        }
//                    }
//                    secondRowOfEnemies.at(enemyCounter2)->setHasCollidedWithScreen(false);
//                }
//            }
//        }
//    }
//
//    enemyCounter = 0;
//    //Tries to find an alive leftmost alien on the current row
//    while(!(thirdRowOfEnemies[enemyCounter]->isAlive()) && enemyCounter < thirdRowOfEnemies.size()) {
//        enemyCounter++;
//    }
//    // If the found alien is the only one alive on the row
//    if(enemyCounter == thirdRowOfEnemies.size()-1) {
//        thirdRowOfEnemies.at(enemyCounter)->checkCollision();
//        if(thirdRowOfEnemies.at(enemyCounter)->hasCollidedWithScreen()) {
//            for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
//                if((*it)->isAlive()) {
//                    if((*it)->getMovementDirection() == LEFT) {
//                        (*it)->setMovementDirection(RIGHT);
//                    }
//                    else {
//                        (*it)->setMovementDirection(LEFT);
//                    }
//                    (*it)->setPosition((*it)->getX(),
//                                        (*it)->getY() + (*it)->getHeight()/4);
//                }
//            }
//            thirdRowOfEnemies.at(enemyCounter)->setHasCollidedWithScreen(false);
//        }
//    }
//    else if(enemyCounter < thirdRowOfEnemies.size()-1) {
//        thirdRowOfEnemies.at(enemyCounter)->checkCollision();
//        if(thirdRowOfEnemies.at(enemyCounter)->hasCollidedWithScreen()) {
//            for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
//                if((*it)->isAlive()) {
//                    if((*it)->getMovementDirection() == LEFT) {
//                        (*it)->setMovementDirection(RIGHT);
//                    }
//                    else {
//                        (*it)->setMovementDirection(LEFT);
//                    }
//                    (*it)->setPosition((*it)->getX(),
//                                            (*it)->getY() + (*it)->getHeight()/4);
//                }
//            }
//            thirdRowOfEnemies.at(enemyCounter)->setHasCollidedWithScreen(false);
//        }
//        else {
//            int enemyCounter2 = thirdRowOfEnemies.size()-1;
//            //Tries to find an alive rightmost alien
//            while(!(thirdRowOfEnemies[enemyCounter2]->isAlive()) && enemyCounter2 > enemyCounter) {
//                enemyCounter2--;
//            }
//            //It found another alien, which is the rightmost
//            if(enemyCounter2 > enemyCounter) {
//                thirdRowOfEnemies.at(enemyCounter2)->checkCollision();
//                if(thirdRowOfEnemies.at(enemyCounter2)->hasCollidedWithScreen()) {
//                    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
//                        if((*it)->isAlive()) {
//                            (*it)->setMovementDirection(LEFT);
//                            (*it)->setPosition((*it)->getX(),
//                                                (*it)->getY() + (*it)->getHeight()/4);
//                        }
//                    }
//                    thirdRowOfEnemies.at(enemyCounter2)->setHasCollidedWithScreen(false);
//                }
//            }
//        }
//    }
//
//    enemyCounter = 0;
//    //Tries to find an alive leftmost alien on the current row
//    while(!(fourthRowOfEnemies[enemyCounter]->isAlive()) && enemyCounter < fourthRowOfEnemies.size()) {
//        enemyCounter++;
//    }
//    // If the found alien is the only one alive on the row
//    if(enemyCounter == fourthRowOfEnemies.size()-1) {
//        fourthRowOfEnemies.at(enemyCounter)->checkCollision();
//        if(fourthRowOfEnemies.at(enemyCounter)->hasCollidedWithScreen()) {
//            for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
//                if((*it)->isAlive()) {
//                    if((*it)->getMovementDirection() == LEFT) {
//                        (*it)->setMovementDirection(RIGHT);
//                    }
//                    else {
//                        (*it)->setMovementDirection(LEFT);
//                    }
//                    (*it)->setPosition((*it)->getX(),
//                                        (*it)->getY() + (*it)->getHeight()/4);
//                }
//            }
//            fourthRowOfEnemies.at(enemyCounter)->setHasCollidedWithScreen(false);
//        }
//    }
//    else if(enemyCounter < fourthRowOfEnemies.size()-1) {
//        fourthRowOfEnemies.at(enemyCounter)->checkCollision();
//        if(fourthRowOfEnemies.at(enemyCounter)->hasCollidedWithScreen()) {
//            for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
//                if((*it)->isAlive()) {
//                    if((*it)->getMovementDirection() == LEFT) {
//                        (*it)->setMovementDirection(RIGHT);
//                    }
//                    else {
//                        (*it)->setMovementDirection(LEFT);
//                    }
//                    (*it)->setPosition((*it)->getX(),
//                                            (*it)->getY() + (*it)->getHeight()/4);
//                }
//            }
//            fourthRowOfEnemies.at(enemyCounter)->setHasCollidedWithScreen(false);
//        }
//        else {
//            int enemyCounter2 = fourthRowOfEnemies.size()-1;
//            //Tries to find an alive rightmost alien
//            while(!(fourthRowOfEnemies[enemyCounter2]->isAlive()) && enemyCounter2 > enemyCounter) {
//                enemyCounter2--;
//            }
//            //It found another alien, which is the rightmost
//            if(enemyCounter2 > enemyCounter) {
//                fourthRowOfEnemies.at(enemyCounter2)->checkCollision();
//                if(fourthRowOfEnemies.at(enemyCounter2)->hasCollidedWithScreen()) {
//                    for(list<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
//                        if((*it)->isAlive()) {
//                            (*it)->setMovementDirection(LEFT);
//                            (*it)->setPosition((*it)->getX(),
//                                                (*it)->getY() + (*it)->getHeight()/4);
//                        }
//                    }
//                    fourthRowOfEnemies.at(enemyCounter2)->setHasCollidedWithScreen(false);
//                }
//            }
//        }
//    }
}

void GameObjectCollision::checkPlayerCollision() {

}

void GameObjectCollision::checkBulletCollision() {
    for(list<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++) {
        (*it)->checkCollision();
        if((*it)->hasCollided()) {
            delete (*it);
            it = bullets.erase(it);
        }
    }
}
