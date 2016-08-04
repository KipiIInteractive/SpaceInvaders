#include "ProfileManager.h"

<<<<<<< HEAD
list<User> Users;
=======
vector<User> ProfileManager::Users;
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

bool ProfileManager::FileIsExisting(string filename)
{
    ifstream tmp(filename);
    return (bool)tmp;
}

bool ProfileManager::CreateNewProfile(string username, string password)
{
    //Check if there is a user with the same user-name
<<<<<<< HEAD
    for (list<User>::iterator it = Users.begin(); it != Users.end(); ++it)
=======
    for (vector<User>::iterator it = ProfileManager::Users.begin(); it != ProfileManager::Users.end(); ++it)
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    {
        User otherUser = *it;
        if(otherUser.GetUsername() == (username + USER_FILES_EXTENSION))
        {
            return false;
        }
    }

    User newUser;
    newUser.SetUsername(username);
    newUser.SetPassword(password);
<<<<<<< HEAD
    Users.push_back(newUser);

    ofstream userFile;
    userFile.open("Users/" + newUser.GetUsername() + USER_FILES_EXTENSION);
    userFile << newUser.GetPassword() << ' ' << 0 << ' ' << 1 << '\n';
=======
    ProfileManager::Users.push_back(newUser);

    ofstream userFile;
    userFile.open("Users/" + newUser.GetUsername() + USER_FILES_EXTENSION);
        //password best_score current_score current_level
        userFile << newUser.GetPassword() << ' '
                << newUser.GetHighScore() << ' '
                << newUser.GetCurrentScore() << ' '
                << newUser.GetCurrentLevel() << '\n';
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    userFile.close();

    return true;
}

void ProfileManager::DeleteProfile(string username)
{
    string userString = "Users/" + username + USER_FILES_EXTENSION;
    const char *userToDelete = userString.c_str();
    remove(userToDelete);
}

void ProfileManager::LoadTheUsersData()
{
    DIR *dir;
    struct dirent *ent;

    dir = opendir ("./Users/");

    while ((ent = readdir (dir)) != NULL)
    {
        if(*ent->d_name != '.' )
        {
            User tmpUser;
            tmpUser.SetUsername(ent->d_name);

            string fileToOpen = "./Users/" + (string)ent->d_name;

            ifstream file(fileToOpen);

            string password;
<<<<<<< HEAD
            int highScore;
            int currentLevel;

            while (file >> password >> highScore >> currentLevel)
=======
            int highScore, currentLevel, currentScore;

            while (file >> password >> highScore >> currentScore>> currentLevel)
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
            {
                tmpUser.SetPassword(password);
                tmpUser.SetNewHighScore(highScore);
                tmpUser.SetCurrentLevel(currentLevel);
<<<<<<< HEAD
                Users.push_back(tmpUser);
=======
                tmpUser.SetCurrentScore(currentScore);
                ProfileManager::Users.push_back(tmpUser);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
            }

            file.close();
        }
    }
    closedir (dir);
}

bool ProfileManager::LogIn(string username, string password)
{
<<<<<<< HEAD
    for (list<User>::iterator it = Users.begin(); it != Users.end(); ++it)
=======
    for (vector<User>::iterator it = ProfileManager::Users.begin(); it != ProfileManager::Users.end(); ++it)
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    {
        User currentUser = *it;

        //Check if there is profile with that user-name
        if(currentUser.GetUsername() == (username + USER_FILES_EXTENSION))
        {
            if(currentUser.GetPassword() == password)
            {
                System::Users::Current.SetCurrentLevel(currentUser.GetCurrentLevel());
                System::Users::Current.SetUsername(currentUser.GetUsername());
                System::Users::Current.SetNewHighScore(currentUser.GetHighScore());
                System::Users::Current.SetPassword(currentUser.GetPassword());
<<<<<<< HEAD
=======
                System::Users::Current.SetCurrentScore(currentUser.GetCurrentScore());
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
                return true;
            }
        }
    }
    return false;
}
