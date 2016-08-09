#include "AliensManager.h"
#include "../Game/Game.h"

#define MAX_ALIENS_ON_ROW 15

int AliensManager::numAliens = 0;
int AliensManager::aliensOnRow = 0;
int AliensManager::movementSpeed = 0;
int AliensManager::shootingPowerCoefficient = 0;
int AliensManager::direction = System::Direction::Right;
int AliensManager::currentMovementFrame = 0;
int AliensManager::movementDelayFrames = 0;
bool AliensManager::hasAlienHitTheWall = false;
SDL_Rect AliensManager::deadRect;

std::vector<Alien*> AliensManager::allAliens;

void AliensManager::AddNewAlien(AlienType type, int xPos, int yPos)
{
    AliensManager::allAliens.push_back(new Alien(type, xPos, yPos));
}

void AliensManager::RenderAll()
{
    for(unsigned i = 0; i < AliensManager::allAliens.size(); ++i) {
        AliensManager::allAliens[i]->Render();
    }
}

int AliensManager::getRemainingAliens() {
    int aliveAliensCounter = 0;
    for(unsigned int i = 0; i < AliensManager::allAliens.size(); i++) {
        if(AliensManager::allAliens[i]->isAlive) {
            aliveAliensCounter++;
        }
    }
    return aliveAliensCounter;
}

void AliensManager::Move()
{
    if(AliensManager::currentMovementFrame == AliensManager::movementDelayFrames)
    {
        for(unsigned i = 0; i < AliensManager::allAliens.size(); i++)
        {
            if(!Player::isDead) {
                AliensManager::allAliens[i]->Shoot();
            }

            if(AliensManager::direction == System::Direction::Right) {
                AliensManager::allAliens[i]->SetX( AliensManager::allAliens[i]->GetX() + AliensManager::allAliens[i]->GetWidth() / 3 );
            }
            else if(AliensManager::direction == System::Direction::Left) {
                AliensManager::allAliens[i]->SetX( AliensManager::allAliens[i]->GetX() - AliensManager::allAliens[i]->GetWidth() / 3 );
            }
            //Check if alien is hit the wall
            if(!AliensManager::hasAlienHitTheWall && AliensManager::allAliens[i]->isAlive)
            {
                if(AliensManager::allAliens[i]->GetX() + AliensManager::allAliens[i]->GetWidth() > Game::Pannel.w + Game::Pannel.x) {
                    AliensManager::hasAlienHitTheWall = true;
                }
                else if(AliensManager::allAliens[i]->GetX() < Game::Pannel.x) {
                    AliensManager::hasAlienHitTheWall = true;
                }
                else if(AliensManager::allAliens[i]->GetY() + AliensManager::allAliens[i]->GetHeigth() >= System::Screen::Height)
                {
                    GameOver::Show();
                    break;
                }
            }

            //Animate the Aliens
            if(AliensManager::allAliens[i]->frame.x == 0) {
                AliensManager::allAliens[i]->frame.x = AliensManager::allAliens[i]->frame.w;
            }
            else {
                AliensManager::allAliens[i]->frame.x = 0;
            }
        }
        if(AliensManager::hasAlienHitTheWall)
        {
            AliensManager::ChangeMovementDirection();
            for(unsigned i = 0; i < AliensManager::allAliens.size(); i++)
            {
                AliensManager::allAliens[i]->SetY( AliensManager::allAliens[i]->GetY() + AliensManager::allAliens[i]->GetHeigth() );

                if(AliensManager::direction == System::Direction::Right) {
                    AliensManager::allAliens[i]->SetX( AliensManager::allAliens[i]->GetX() + AliensManager::allAliens[i]->GetWidth() / 3 );
                }
                else if(AliensManager::direction == System::Direction::Left) {
                    AliensManager::allAliens[i]->SetX( AliensManager::allAliens[i]->GetX() - AliensManager::allAliens[i]->GetWidth() / 3 );
                }
            }
            if(AliensManager::allAliens[0]->GetY() >= UFO::rect.y + UFO::rect.h + AliensManager::allAliens[0]->GetHeigth()
               && Game::currentGameMode == "survival") {
                int randNum = rand() % 3;
                vector<Alien*> alienQueue;
                if(AliensManager::direction == System::Direction::Right) {
                    for(int i = 0; i < AliensManager::aliensOnRow; i++) {
                        if(AliensManager::allAliens[i]->isAlive) {
                            for(unsigned int j = 0; j < AliensManager::aliensOnRow; j++) {
                                Alien* pAlien;
                                if(randNum == 0) {
                                    pAlien = new Alien(SQUID, AliensManager::allAliens[i]->GetX() + j*(Game::Pannel.w / MAX_ALIENS_ON_ROW), AliensManager::allAliens[i]->GetY() - Game::Pannel.w / 15 + 5);
                                }
                                else if(randNum == 1) {
                                    pAlien = new Alien(CRAB, AliensManager::allAliens[i]->GetX() + j*(Game::Pannel.w / MAX_ALIENS_ON_ROW), AliensManager::allAliens[i]->GetY() - Game::Pannel.w / 15 + 5);
                                }
                                else {
                                    pAlien = new Alien(JELLYFISH, AliensManager::allAliens[i]->GetX() + j*(Game::Pannel.w / MAX_ALIENS_ON_ROW), AliensManager::allAliens[i]->GetY() - Game::Pannel.w / 15 + 5);
                                }
                                alienQueue.push_back(pAlien);
                            }
                            break;
                        }
                    }
                }
                else if(AliensManager::direction == System::Direction::Left) {
                    for(int i = AliensManager::aliensOnRow - 1; i >= 0; i--) {
                        if(AliensManager::allAliens[i]->isAlive) {
                            for(int j = AliensManager::aliensOnRow - 1; j >= 0; j--) {
                                Alien* pAlien;
                                if(randNum == 0) {
                                    pAlien = new Alien(SQUID, AliensManager::allAliens[i]->GetX() - j*(Game::Pannel.w / MAX_ALIENS_ON_ROW), AliensManager::allAliens[i]->GetY() - Game::Pannel.w / 15 + 5);
                                }
                                else if(randNum == 1) {
                                    pAlien = new Alien(CRAB, AliensManager::allAliens[i]->GetX() - j*(Game::Pannel.w / MAX_ALIENS_ON_ROW), AliensManager::allAliens[i]->GetY() - Game::Pannel.w / 15 + 5);
                                }
                                else {
                                    pAlien = new Alien(JELLYFISH, AliensManager::allAliens[i]->GetX() - j*(Game::Pannel.w / MAX_ALIENS_ON_ROW), AliensManager::allAliens[i]->GetY() - Game::Pannel.w / 15 + 5);
                                }
                                alienQueue.push_back(pAlien);
                            }
                            break;
                        }
                    }
                }
                AliensManager::allAliens.insert(AliensManager::allAliens.begin(), alienQueue.begin(), alienQueue.end());
                alienQueue.clear();
            }
            AliensManager::hasAlienHitTheWall = false;
        }
        AliensManager::currentMovementFrame = 0;
    }
    else {
        AliensManager::currentMovementFrame++;
    }
}

bool AliensManager::allAliensAreDead() {
    for(unsigned i = 0; i < AliensManager::allAliens.size(); i++) {
        if(AliensManager::allAliens[i]->isAlive) {
            return false;
        }
    }
    return true;
}

void AliensManager::ChangeMovementDirection()
{
    if(AliensManager::direction == System::Direction::Right) {
        AliensManager::direction = System::Direction::Left;
    }
    else if(AliensManager::direction == System::Direction::Left) {
        AliensManager::direction = System::Direction::Right;
    }
}

void AliensManager::FreeAllAliens()
{
    for(unsigned i = 0; i < AliensManager::allAliens.size(); i++)
    {
        delete AliensManager::allAliens[i];
    }
    AliensManager::allAliens.clear();
}
