#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>
using namespace std;

class User
{
    private:
        string username;
        string password;
        int highScore;
        int currentClassicLevel;
        int currentScore;

    public:
        User();
        ~User();

        string GetUsername();
        string GetPassword();
        int GetHighScore();
        int GetCurrentClassicLevel();
        int GetCurrentScore();

        void SetUsername(string username);
        void SetPassword(string password);
        void SetNewHighScore(int newScore);
        void SetcurrentClassicLevel(int lvl);
        void SetCurrentScore(int pScore);
};

#endif // USER_H_INCLUDED
