#include "User.h"

User::User()
{
    this->username = "";
    this->password = "";
    this->highScore = 0;
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

int User::GetCurrentLevel() { return this->currentLevel; }

void User::SetUsername(string username) { this->username = username; }

void User::SetPassword(string password) { this->password = password; }

void User::SetNewHighScore(int newScore) { this->highScore = newScore; }

void User::SetCurrentLevel(int lvl) { this->currentLevel = lvl; }
