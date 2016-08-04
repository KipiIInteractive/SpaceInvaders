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
<<<<<<< HEAD
=======
        int currentScore;
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

    public:
        User();
        ~User();

        string GetUsername();
        string GetPassword();
        int GetHighScore();
        int GetCurrentLevel();
<<<<<<< HEAD
=======
        int GetCurrentScore();
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

        void SetUsername(string username);
        void SetPassword(string password);
        void SetNewHighScore(int newScore);
        void SetCurrentLevel(int lvl);
<<<<<<< HEAD
=======
        void SetCurrentScore(int score);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
};

#endif // USER_H_INCLUDED
