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
        int currentLevel;

    public:
        User();
        ~User();

        string GetUsername();
        string GetPassword();
        int GetHighScore();
        int GetCurrentLevel();

        void SetUsername(string username);
        void SetPassword(string password);
        void SetNewHighScore(int newScore);
        void SetCurrentLevel(int lvl);
};

#endif // USER_H_INCLUDED
