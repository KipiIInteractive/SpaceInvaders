#include "User.h"

User::User()
{
    this->username = "";
    this->password = "";
    this->highScore = 0;
    this->currentScore = 0;
    this->currentClassicLevel = 1;
}

User::~User()
{
    this->username.clear();
    this->password.clear();
}

string User::GetUsername() { return this->username; }

string User::GetPassword() { return this->password; }

int User::GetHighScore() { return this->highScore; }

int User::GetCurrentScore() { return this->currentScore; };

int User::GetCurrentClassicLevel() { return this->currentClassicLevel; }

void User::SetUsername(string username) { this->username = username; }

void User::SetPassword(string password) { this->password = password; }

void User::SetNewHighScore(int newScore) { this->highScore = newScore; }

void User::SetCurrentScore(int pScore) { this->currentScore = pScore; }

void User::SetcurrentClassicLevel(int lvl) { this->currentClassicLevel = lvl; }
