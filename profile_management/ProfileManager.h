#ifndef PROFILEMANAGER_H_INCLUDED
#define PROFILEMANAGER_H_INCLUDED
#include <fstream>
#include <vector>
#include <dirent.h>
#include "User.h"
#include "../System/System.h"
using namespace std;

#define USER_FILES_EXTENSION ".user_data"

class ProfileManager
{
    public:
        static void LoadTheUsersData();
        static bool CreateNewProfile(string username, string password);
        static void DeleteProfile(string username);
        static bool LogIn(string username, string password);
        static vector<User> Users;

    private:
        static bool FileIsExisting(string filename);

};

#endif // PROFILEMANAGER_H_INCLUDED
