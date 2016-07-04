#include "Player.h"

SDL_Rect Player::rect;
SDL_Texture *Player::texture;
int Player::movementSpeed;

void Player::Init()
{
    Player::rect.w = Game::Pannel.w / 7.89;
    Player::rect.h = Game::Pannel.h / 10;
    Player::rect.x = (System::Screen::Width  / 2) - (Player::rect.w / 2);
    Player::rect.y = System::Screen::Height - 150;
    Player::texture = System::CreateTexture("Resources/Textures/player.png", System::renderer);
    Player::movementSpeed = 4;
}

void Player::Render()
{
    SDL_RenderCopy(System::renderer, Player::texture, NULL, &Player::rect);
}

void Player::Move(int direction)
{
    if(direction == System::Direction::Right)
    {
        Player::rect.x += Player::movementSpeed;
        if(Player::rect.x + Player::rect.w > Game::Pannel.w + Game::Pannel.x)
            Player::rect.x = Game::Pannel.x + Game::Pannel.w - Player::rect.w;
    }

    else if(direction == System::Direction::Left)
    {
        Player::rect.x -= Player::movementSpeed;
        if(Player::rect.x < Game::Pannel.x)
            Player::rect.x = Game::Pannel.x;
    }
}

void Player::Shoot()
{
    BulletsManager::AddNewBullet(10, Player::rect.x + (Player::rect.w / 2) - 10, Player::rect.y, System::Direction::Up);
}
