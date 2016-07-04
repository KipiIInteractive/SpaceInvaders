#include "GameHandler.h"

void GameHandler::startClassicGame() {
    GameObjectGenerator::generateEnemies();
    gMenuBackground.render(0, 0);
    for(int i = 0; i < ENEMY_ROWS; i++) {
        for(int j = 0; j < MAX_ALIENS_ON_ROW; j++) {
            enemies[i][j].render();
        }
    }
}

void GameHandler::startSurvivalGame() {

}

void GameHandler::handleClassicGameEvents(SDL_Event *e) {

}

void GameHandler::handleSurvivalGameEvents(SDL_Event* e) {

}
