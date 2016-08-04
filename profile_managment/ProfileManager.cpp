#include "ProfileManager.h"

list<User> Users;

bool ProfileManager::FileIsExisting(string filename)
{
    ifstream tmp(filename);
    return (bool)tmp;
}

bool ProfileManager::CreateNewProfile(string username, string password)
{
    //Check if there is a user with the same user-name
    for (list<User>::iterator it = Users.begin(); it != Users.end(); ++it)
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
    Users.push_back(newUser);

    ofstream userFile;
    userFile.open("Users/" + newUser.GetUsername() + USER_FILES_EXTENSION);
    userFile << newUser.GetPassword() << ' ' << 0 << '\n';
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
            int highScore;

            while (file >> password >> highScore)
            {
                tmpUser.SetPassword(password);
                tmpUser.SetNewHighScore(highScore);
                Users.push_back(tmpUser);
            }

            file.close();
        }
    }
    closedir (dir);
}

bool ProfileManager::LogIn(string username, string password)
{
    for (list<User>::iterator it = Users.begin(); it != Users.end(); ++it)
    {
        User currentUser = *it;

        //Check if there is profile with that user-name
        if(currentUser.GetUsername() == (username + USER_FILES_EXTENSION))
        {
            if(currentUser.GetPassword() == password)
            {
                return true;
            }
        }
    }
    return false;
}
