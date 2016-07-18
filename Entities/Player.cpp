#include "Player.h"

SDL_Rect Player::rect;
SDL_Texture *Player::texture;
SDL_Texture *Player::texture_dead;
int Player::movementSpeed;
int Player::lives;
bool Player::isDead;
int Player::framesToBeDead;
int frames_dead;

void Player::Init()
{
    Player::rect.h = Game::Pannel.h / 13;
    Player::rect.w = Player::rect.h * 1.62;
    Player::rect.x = (System::Screen::Width  / 2) - (Player::rect.w / 2);
    Player::rect.y = System::Screen::Height - Player::rect.h;
    Player::texture = System::CreateTexture("Resources/Textures/player.png", System::renderer);
    Player::texture_dead = System::CreateTexture("Resources/Textures/player_die.png", System::renderer);
    Player::movementSpeed = 7;
    Player::lives = 3;
    Player::framesToBeDead = 60;
    frames_dead = 0;
}

void Player::Render()
{
    if(!Player::isDead)
        SDL_RenderCopy(System::renderer, Player::texture, NULL, &Player::rect);
    else
    {
        if(frames_dead < Player::framesToBeDead)
            frames_dead++;
        else
        {
            frames_dead = 0;
            Player::isDead = false;
        }
        SDL_RenderCopy(System::renderer, Player::texture_dead, NULL, &Player::rect);
    }
}

void Player::Move(int direction)
{
    if(!Player::isDead)
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
}

void Player::Shoot()
{
    if(!Player::isDead)
        BulletsManager::AddNewBullet(20, Player::rect.x + (Player::rect.w / 2) - 4, Player::rect.y, System::Direction::Up);
}

void Player::Die()
{
    if(Player::lives > 0)
    {
        Player::lives--;
        Player::isDead = true;
        Player::rect.x = (System::Screen::Width  / 2) - (Player::rect.w / 2);
        Player::rect.y = System::Screen::Height - Player::rect.h;
    }

}

void Player::Free()
{
    SDL_DestroyTexture(Player::texture);
    SDL_DestroyTexture(Player::texture_dead);
}
