#ifndef LOG_IN_H_INCLUDED
#define LOG_IN_H_INCLUDED

#include <SDL.h>
#include "ProfileManager.h"
#include "../Game/Game.h"
#include "Registration.h"
#include "../System/System.h"
#include "../GUI/Link.h"
#include "../GUI/InputField.h"
#include "../GUI/Label.h"

class LoginWindow
{
    private:
        static SDL_Texture *backgroundTexture;

        static bool isActive;

        static Link LogInButton;
        static Link ExitButtton;
        static Link RegistrationButton;

        static Label Label_Username;
        static InputField InputField_Username;

        static Label Label_Password;
        static InputField InputField_Password;

        static Label Text_Error;

        static void InitializeTheInputFields();
        static void InitializeTheButtons();

        static void MainLoop();
        static void CheckForEvents();

        static void CreateButtonEffects();
        static void CreateButtonActions();

        static void LogIn();

        static void Render();

    public:
        static void Init();
        static void Show();
};

#endif // LOG_IN_H_INCLUDED
