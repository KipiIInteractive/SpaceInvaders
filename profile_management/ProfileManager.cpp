#include "ProfileManager.h"

vector<User> ProfileManager::Users;

bool ProfileManager::FileIsExisting(string filename)
{
    ifstream tmp(filename);
    return (bool)tmp;
}

bool ProfileManager::CreateNewProfile(string username, string password)
{
    //Check if there is a user with the same user-name
    for (vector<User>::iterator it = ProfileManager::Users.begin(); it != ProfileManager::Users.end(); ++it)
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
    ProfileManager::Users.push_back(newUser);

    ofstream userFile;
    userFile.open("Users/" + newUser.GetUsername() + USER_FILES_EXTENSION);
        //password best_score current_score current_level
        userFile << newUser.GetPassword() << ' '
                << newUser.GetHighScore() << ' '
                << newUser.GetCurrentScore() << ' '
                << newUser.GetCurrentClassicLevel() << '\n';
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
            int highScore, currentClassicLevel, currentScore;

            while (file >> password >> highScore >> currentScore>> currentClassicLevel)
            {
                tmpUser.SetPassword(password);
                tmpUser.SetNewHighScore(highScore);
                tmpUser.SetcurrentClassicLevel(currentClassicLevel);
                tmpUser.SetCurrentScore(currentScore);
                ProfileManager::Users.push_back(tmpUser);
            }

            file.close();
        }
    }
    closedir (dir);
}

bool ProfileManager::LogIn(string username, string password)
{
    for (vector<User>::iterator it = ProfileManager::Users.begin(); it != ProfileManager::Users.end(); ++it)
    {
        User currentUser = *it;

        //Check if there is profile with that user-name
        if(currentUser.GetUsername() == (username + USER_FILES_EXTENSION))
        {
            if(currentUser.GetPassword() == password)
            {
                System::Users::Current.SetcurrentClassicLevel(currentUser.GetCurrentClassicLevel());
                System::Users::Current.SetUsername(currentUser.GetUsername());
                System::Users::Current.SetNewHighScore(currentUser.GetHighScore());
                System::Users::Current.SetPassword(currentUser.GetPassword());
                System::Users::Current.SetCurrentScore(currentUser.GetCurrentScore());
                return true;
            }
        }
    }
    return false;
}
