#include "User.h"

User::User()
{
    this->username = "";
    this->password = "";
    this->highScore = 0;
<<<<<<< HEAD
=======
    this->currentScore = 0;
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    this->currentLevel = 1;
}

User::~User()
{
    this->username.clear();
    this->password.clear();
}

string User::GetUsername() { return this->username; }

string User::GetPassword() { return this->password; }

int User::GetHighScore() { return this->highScore; }

<<<<<<< HEAD
=======
int User::GetCurrentScore() { return this->currentScore; };

>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
int User::GetCurrentLevel() { return this->currentLevel; }

void User::SetUsername(string username) { this->username = username; }

void User::SetPassword(string password) { this->password = password; }

void User::SetNewHighScore(int newScore) { this->highScore = newScore; }

<<<<<<< HEAD
=======
void User::SetCurrentScore(int score) { this->currentScore = score; }

>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
void User::SetCurrentLevel(int lvl) { this->currentLevel = lvl; }
