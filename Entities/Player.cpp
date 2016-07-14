#include "Player.h"

SDL_Rect Player::rect;
SDL_Texture *Player::texture;
int Player::movementSpeed;

void Player::Init()
{
    Player::rect.h = Game::Pannel.h / 13;
    Player::rect.w = Player::rect.h * 1.62;
    Player::rect.x = (System::Screen::Width  / 2) - (Player::rect.w / 2);
    Player::rect.y = System::Screen::Height - Player::rect.h;
    Player::texture = System::CreateTexture("Resources/Textures/p.png", System::renderer);
    Player::movementSpeed = 6;
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
    BulletsManager::AddNewBullet(10, Player::rect.x + (Player::rect.w / 2) - 4, Player::rect.y, System::Direction::Up);
}
