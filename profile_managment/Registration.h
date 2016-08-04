#ifndef REGISTRATION_H_INCLUDED
#define REGISTRATION_H_INCLUDED

#include <SDL.h>
#include "ProfileManager.h"
#include "Log_in.h"
#include "../System/System.h"
#include "../GUI/Link.h"
#include "../GUI/InputField.h"
#include "../GUI/Label.h"
<<<<<<< HEAD
=======
#include "../Game/Game.h"
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

class RegistrationWindow
{
    private:
        static SDL_Texture *backgroundTexture;

        static bool isActive;

        static Link RegistrationButton;
        static Link LogInButton;

        static Label Label_Username;
        static InputField InputField_Username;

        static Label Label_Password;
        static InputField InputField_Password;

        static Label Label_Password_Repeat;
        static InputField InputField_Password_Repeat;

        static Label Text_Error;

        static void InitializeTheInputFields();
        static void InitializeTheButtons();

        static void MainLoop();
        static void CheckForEvents();

        static void CreateButtonEffects();
        static void CreateButtonActions();

        static void Register();

        static void Render();

    public:
        static void Init();
        static void Show();
};

#endif // REGISTRATION_H_INCLUDED
