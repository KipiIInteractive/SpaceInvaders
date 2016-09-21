#include "Player.h"

SDL_Rect Player::rect;
SDL_Texture *Player::aliveTexture;
SDL_Texture *Player::deadTexture;
int Player::movementSpeed;
int Player::lives;
bool Player::isDead;
int Player::respawnTimeInSeconds;
int timeDeadInSeconds;

void Player::Init()
{
    int pannelHeightPlayerHeightRatio = 15/1;
    float playerWidthPlayerHeightRatio = 1.62;
    int additionalYIndentationSubtrahend = 20;
    float pSpeedDivisor = 13.67;
    Player::rect.h = Game::Pannel.h / pannelHeightPlayerHeightRatio;
    Player::rect.w = Player::rect.h * playerWidthPlayerHeightRatio;
    Player::rect.x = (System::Screen::Width  / 2) - (Player::rect.w / 2);
    Player::rect.y = System::Screen::Height - Player::rect.h - additionalYIndentationSubtrahend;
    Player::aliveTexture = System::Textures::PlayerAlive;
    Player::deadTexture = System::Textures::PlayerDead;
    Player::movementSpeed = Player::rect.w / pSpeedDivisor;
    Player::lives = 3;
    Player::respawnTimeInSeconds = 60;
    timeDeadInSeconds = 0;
    Player::isDead = false;
}

void Player::Render()
{
    if(!Player::isDead) {
        SDL_RenderCopy(System::renderer, Player::aliveTexture, NULL, &Player::rect);
    }
    else
    {
        if(timeDeadInSeconds < Player::respawnTimeInSeconds) {
            SDL_RenderCopy(System::renderer, Player::deadTexture, NULL, &Player::rect);
            timeDeadInSeconds++;
        }
        else
        {
            timeDeadInSeconds = 0;
            Player::isDead = false;
        }
    }
}

void Player::Move(int direction)
{
    if(!Player::isDead)
    {
        //Checks and administers collision with game screen
        if(direction == System::Direction::Right)
        {
            Player::rect.x += Player::movementSpeed;
            if(Player::rect.x + Player::rect.w > Game::Pannel.w + Game::Pannel.x) {
                Player::rect.x = Game::Pannel.x + Game::Pannel.w - Player::rect.w;
            }
        }

        else if(direction == System::Direction::Left)
        {
            Player::rect.x -= Player::movementSpeed;
            if(Player::rect.x < Game::Pannel.x) {
                Player::rect.x = Game::Pannel.x;
            }
        }
    }
}

void Player::Shoot()
{
    if(!Player::isDead) {
        int playerBulletSpeedDivisor = 44;
        int bulletAdditionalXIndentationSubtrahend = 3;
        BulletsManager::AddNewBullet(Game::Pannel.h / playerBulletSpeedDivisor, Player::rect.x + (Player::rect.w / 2) - bulletAdditionalXIndentationSubtrahend, Player::rect.y, System::Direction::Up);
    }
}

void Player::DecreaseLives()
{
    SoundManager::Play(SoundManager::Sounds::Explosion);
    if(Player::lives > 0)
    {
        Player::lives--;
        Player::isDead = true;
    }

}
