#include "Registration.h"

SDL_Texture *RegistrationWindow::backgroundTexture = NULL;
Link RegistrationWindow::LogInButton;
Link RegistrationWindow::RegistrationButton;

Label RegistrationWindow::Label_Username;
InputField RegistrationWindow::InputField_Username;

Label RegistrationWindow::Label_Password;
InputField RegistrationWindow::InputField_Password;

Label RegistrationWindow::Label_Password_Repeat;
InputField RegistrationWindow::InputField_Password_Repeat;

Label RegistrationWindow::Text_Error;

bool RegistrationWindow::isActive;

void RegistrationWindow::Init()
{
<<<<<<< HEAD
    //Create the backgroud texture for the log-in window
    RegistrationWindow::backgroundTexture = System::CreateTexture("Resources/Textures/menuBackground.jpg", System::renderer);
    if(RegistrationWindow::backgroundTexture == NULL)
        std::cout << "Failed to create the registration background texture. File: profile_managment/Log_in.cpp/Init(): \n" << IMG_GetError() << std::endl;
=======
    //Create the background texture for the registration window
<<<<<<< HEAD
    RegistrationWindow::backgroundTexture = System::Textures::Background_Stars;
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
=======
    RegistrationWindow::backgroundTexture = System::Textures::Background_Black;
>>>>>>> ecbd78b... The UFO feature is added. On launch Start Menu is shown with options to

    //Initialize the registration error text
    RegistrationWindow::Text_Error.SetText(" ");
    RegistrationWindow::Text_Error.SetColor(255, 10, 30);
    RegistrationWindow::Text_Error.SetFont(System::Fonts::Errors);
    RegistrationWindow::Text_Error.SetX(System::Screen::Width / 2 - RegistrationWindow::Text_Error.GetWidth() / 2);
    RegistrationWindow::Text_Error.SetY(System::Screen::Height - RegistrationWindow::Text_Error.GetHeight() - 70);

    RegistrationWindow::InitializeTheInputFields();
    RegistrationWindow::InitializeTheButtons();
}

void RegistrationWindow::InitializeTheInputFields()
{
    //Initialize the label for the username input field
    RegistrationWindow::Label_Username.SetText("Username:");
    RegistrationWindow::Label_Username.SetColor(255, 10, 30);
    RegistrationWindow::Label_Username.SetFont(System::Fonts::Labels);
    RegistrationWindow::Label_Username.SetX(System::Screen::Width / 2 - RegistrationWindow::Label_Username.GetWidth() / 2);
    RegistrationWindow::Label_Username.SetY(System::Screen::Height / 7);

    //Initialize the username input field
    RegistrationWindow::InputField_Username.SetFont(System::Fonts::InputFields);
    RegistrationWindow::InputField_Username.SetTextColor(255, 255, 255);
    RegistrationWindow::InputField_Username.isActive = true;
    RegistrationWindow::InputField_Username.SetCharLimit(20);
    RegistrationWindow::InputField_Username.SetWidth(System::Screen::Width /1.5);
    RegistrationWindow::InputField_Username.SetHeight(35);
    RegistrationWindow::InputField_Username.SetX(System::Screen::Width / 2 - RegistrationWindow::InputField_Username.GetWidth() / 2);
    RegistrationWindow::InputField_Username.SetY(RegistrationWindow::Label_Username.GetY() + RegistrationWindow::Label_Username.GetHeight() + 20);
    RegistrationWindow::InputField_Username.SetTexture("Resources/Textures/inputField.bmp");


     //Initialize the label for the password input field
    RegistrationWindow::Label_Password.SetText("Password:");
    RegistrationWindow::Label_Password.SetColor(255, 10, 30);
    RegistrationWindow::Label_Password.SetFont(System::Fonts::Labels);
    RegistrationWindow::Label_Password.SetX(System::Screen::Width / 2 - RegistrationWindow::Label_Password.GetWidth() / 2);
    RegistrationWindow::Label_Password.SetY(RegistrationWindow::InputField_Username.GetY() + RegistrationWindow::InputField_Username.GetHeight() + 60);

    //Initialize the password input field
    RegistrationWindow::InputField_Password.type = "password";
    RegistrationWindow::InputField_Password.SetFont(System::Fonts::InputFields);
    RegistrationWindow::InputField_Password.SetTextColor(255, 255, 255);
    RegistrationWindow::InputField_Password.isActive = false;
    RegistrationWindow::InputField_Password.SetCharLimit(20);
    RegistrationWindow::InputField_Password.SetWidth(System::Screen::Width /1.5);
    RegistrationWindow::InputField_Password.SetHeight(35);
    RegistrationWindow::InputField_Password.SetX(System::Screen::Width / 2 - RegistrationWindow::InputField_Password.GetWidth() / 2);
    RegistrationWindow::InputField_Password.SetY(RegistrationWindow::Label_Password.GetY() + RegistrationWindow::Label_Password.GetHeight() + 20);
    RegistrationWindow::InputField_Password.SetTexture("Resources/Textures/inputField.bmp");


    //Initialize the label for the password repeat input field
    RegistrationWindow::Label_Password_Repeat.SetText("Repeat password:");
    RegistrationWindow::Label_Password_Repeat.SetColor(255, 10, 30);
    RegistrationWindow::Label_Password_Repeat.SetFont(System::Fonts::Labels);
    RegistrationWindow::Label_Password_Repeat.SetX(System::Screen::Width / 2 - RegistrationWindow::Label_Password_Repeat.GetWidth() / 2);
    RegistrationWindow::Label_Password_Repeat.SetY(RegistrationWindow::InputField_Password.GetY() + RegistrationWindow::InputField_Password.GetHeight() + 60);

    //Initialize the password repeat input field
    RegistrationWindow::InputField_Password_Repeat.type = "password";
    RegistrationWindow::InputField_Password_Repeat.SetFont(System::Fonts::InputFields);
    RegistrationWindow::InputField_Password_Repeat.SetTextColor(255, 255, 255);
    RegistrationWindow::InputField_Password_Repeat.isActive = false;
    RegistrationWindow::InputField_Password_Repeat.SetCharLimit(20);
    RegistrationWindow::InputField_Password_Repeat.SetWidth(System::Screen::Width /1.5);
    RegistrationWindow::InputField_Password_Repeat.SetHeight(35);
    RegistrationWindow::InputField_Password_Repeat.SetX(System::Screen::Width / 2 - RegistrationWindow::InputField_Password_Repeat.GetWidth() / 2);
    RegistrationWindow::InputField_Password_Repeat.SetY(RegistrationWindow::Label_Password_Repeat.GetY() + RegistrationWindow::Label_Password_Repeat.GetHeight() + 20);
    RegistrationWindow::InputField_Password_Repeat.SetTexture("Resources/Textures/inputField.bmp");
}

void RegistrationWindow::InitializeTheButtons()
{
    //Initialize the Registration button
    RegistrationWindow::RegistrationButton.SetFont(System::Fonts::Buttons);
    RegistrationWindow::RegistrationButton.SetText("Register");
    RegistrationWindow::RegistrationButton.SetColor(255, 0, 0);
    RegistrationWindow::RegistrationButton.SetX(System::Screen::Width / 2 - RegistrationWindow::RegistrationButton.GetWidth() / 2);
    RegistrationWindow::RegistrationButton.SetY(RegistrationWindow::InputField_Password_Repeat.GetY() + RegistrationWindow::InputField_Password_Repeat.GetHeight() + 80);

     //Initialize the Registration button
    RegistrationWindow::LogInButton.SetFont(System::Fonts::Buttons_Small);
    RegistrationWindow::LogInButton.SetText("Already have an account?");
    RegistrationWindow::LogInButton.SetColor(255, 255, 255);
    RegistrationWindow::LogInButton.SetX(System::Screen::Width - RegistrationWindow::LogInButton.GetWidth() - 5);
    RegistrationWindow::LogInButton.SetY(System::Screen::Height - RegistrationWindow::LogInButton.GetHeight() - 5);
}


void RegistrationWindow::Show()
{
    //Set the log-in window to be active
    RegistrationWindow::isActive = true;

    RegistrationWindow::MainLoop();
}

void RegistrationWindow::MainLoop()
{
    while(RegistrationWindow::isActive)
    {
        CheckForEvents();
    }
}

void RegistrationWindow::CheckForEvents()
{

    if(SDL_PollEvent(&System::event))
    {
        RegistrationWindow::InputField_Username.Input();
        RegistrationWindow::InputField_Password.Input();
        RegistrationWindow::InputField_Password_Repeat.Input();

        RegistrationWindow::InputField_Username.SetTextX(System::Screen::Width / 2 - RegistrationWindow::InputField_Username.GetTextWidth() / 2);
        RegistrationWindow::InputField_Password.SetTextX(System::Screen::Width / 2 - RegistrationWindow::InputField_Password.GetTextWidth() / 2);
        RegistrationWindow::InputField_Password_Repeat.SetTextX(System::Screen::Width / 2 - RegistrationWindow::InputField_Password_Repeat.GetTextWidth() / 2);

        RegistrationWindow::CreateButtonEffects();
        RegistrationWindow::CreateButtonActions();


        //Switch the active input field when TAB is pressed
        if(RegistrationWindow::InputField_Username.isActive && RegistrationWindow::InputField_Username.isTabPressed)
        {
            RegistrationWindow::InputField_Username.isActive = false;
            RegistrationWindow::InputField_Password.isActive = true;
            RegistrationWindow::InputField_Password_Repeat.isActive = false;
            RegistrationWindow::InputField_Username.isTabPressed = false;
        }
        else if(RegistrationWindow::InputField_Password.isActive && RegistrationWindow::InputField_Password.isTabPressed)
        {
            RegistrationWindow::InputField_Password.isActive = false;
            RegistrationWindow::InputField_Username.isActive = false;
            RegistrationWindow::InputField_Password_Repeat.isActive = true;
            RegistrationWindow::InputField_Password.isTabPressed = false;
        }
        else if(RegistrationWindow::InputField_Password_Repeat.isActive && RegistrationWindow::InputField_Password_Repeat.isTabPressed)
        {
            RegistrationWindow::InputField_Password.isActive = false;
            RegistrationWindow::InputField_Username.isActive = true;
            RegistrationWindow::InputField_Password_Repeat.isActive = false;
            RegistrationWindow::InputField_Password_Repeat.isTabPressed = false;
        }

        //Switch the active input field when input field is clicked
        if(RegistrationWindow::InputField_Username.isClicked())
        {
            RegistrationWindow::InputField_Password.isActive = false;
            RegistrationWindow::InputField_Password_Repeat.isActive = false;
            RegistrationWindow::InputField_Username.isActive = true;
        }
        else if(RegistrationWindow::InputField_Password.isClicked())
        {
            RegistrationWindow::InputField_Password.isActive = true;
            RegistrationWindow::InputField_Username.isActive = false;
            RegistrationWindow::InputField_Password_Repeat.isActive = false;
        }
        else if(RegistrationWindow::InputField_Password_Repeat.isClicked())
        {
            RegistrationWindow::InputField_Password.isActive = false;
            RegistrationWindow::InputField_Username.isActive = false;
            RegistrationWindow::InputField_Password_Repeat.isActive = true;
        }

        //When the Enter button is pressed try to register new profile with the given user input
        if(RegistrationWindow::InputField_Username.isEnterPressed)
        {
            RegistrationWindow::InputField_Username.isEnterPressed = false;
            RegistrationWindow::Register();
        }
        else if(RegistrationWindow::InputField_Password.isEnterPressed)
        {
            RegistrationWindow::InputField_Password.isEnterPressed = false;
            RegistrationWindow::Register();
        }
        else if(RegistrationWindow::InputField_Password_Repeat.isEnterPressed)
        {
            RegistrationWindow::InputField_Password_Repeat.isEnterPressed = false;
            RegistrationWindow::Register();
        }

        //Render the new frame on the window
        RegistrationWindow::Render();
    }
}

void RegistrationWindow::CreateButtonEffects()
{
    //Change the color of the registration button when it is hover
    if(RegistrationWindow::RegistrationButton.isHover())
        RegistrationWindow::RegistrationButton.SetColor(255, 255, 255);
    else
        RegistrationWindow::RegistrationButton.SetColor(255, 0, 0);

    //Change the color of the log in button when it is hover
    if(RegistrationWindow::LogInButton.isHover())
        RegistrationWindow::LogInButton.SetColor(255, 0, 0);
    else
        RegistrationWindow::LogInButton.SetColor(255, 255, 255);
}

void RegistrationWindow::CreateButtonActions()
{
    if(RegistrationWindow::RegistrationButton.isClicked())
    {
        RegistrationWindow::Register();
    }

    if(RegistrationWindow::LogInButton.isClicked())
    {
        RegistrationWindow::isActive = false;
        LoginWindow::Show();
    }

}

void RegistrationWindow::Register()
{
    if(RegistrationWindow::InputField_Username.GetInputText() != "")
    {
        if(RegistrationWindow::InputField_Password.GetInputText() != "")
        {
            if(RegistrationWindow::InputField_Password_Repeat.GetInputText() != "")
            {
                if(RegistrationWindow::InputField_Password.GetInputText() ==
                    RegistrationWindow::InputField_Password_Repeat.GetInputText())
                {
                    if(ProfileManager::CreateNewProfile(RegistrationWindow::InputField_Username.GetInputText(),
                                                        RegistrationWindow::InputField_Password.GetInputText()))
                    {
                        RegistrationWindow::Text_Error.SetText("Successful registration!");
                        RegistrationWindow::Text_Error.SetColor(0, 255, 0);
<<<<<<< HEAD
=======
                        System::Users::Current.SetCurrentLevel(1);
                        System::Users::Current.SetUsername(RegistrationWindow::InputField_Username.GetInputText());
                        System::Users::Current.SetNewHighScore(0);
                        System::Users::Current.SetPassword(RegistrationWindow::InputField_Password.GetInputText());
                        System::Users::Current.SetCurrentScore(0);
                        RegistrationWindow::isActive = false;

                        Game::PreStartInitializations();
                        Game::StartGame();
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
                    }
                    else
                    {
                        RegistrationWindow::Text_Error.SetText("This user-name is taken!");
                        RegistrationWindow::Text_Error.SetColor(255, 10, 30);
                    }
                }
                else
                {
                    RegistrationWindow::Text_Error.SetText("Repeat the pass correctly!");
                    RegistrationWindow::Text_Error.SetColor(255, 10, 30);
                }
            }
            else
            {
                RegistrationWindow::Text_Error.SetText("Repeat the pass!");
                RegistrationWindow::Text_Error.SetColor(255, 10, 30);
            }
        }
        else
        {
            RegistrationWindow::Text_Error.SetText("Type password!");
            RegistrationWindow::Text_Error.SetColor(255, 10, 30);
        }
    }
    else
    {
        RegistrationWindow::Text_Error.SetText("Type user-name!");
        RegistrationWindow::Text_Error.SetColor(255, 10, 30);
    }

    RegistrationWindow::Text_Error.SetFont(System::Fonts::Errors);
    RegistrationWindow::Text_Error.SetX(System::Screen::Width / 2 - RegistrationWindow::Text_Error.GetWidth() / 2);
}

void RegistrationWindow::Render()
{
    //Clear the previous frame
    SDL_RenderClear(System::renderer);

    //Add the textures to the renderer
    SDL_RenderCopy(System::renderer, RegistrationWindow::backgroundTexture, NULL, NULL);

    RegistrationWindow::InputField_Username.Render();
    RegistrationWindow::Label_Username.Render();

    RegistrationWindow::InputField_Password.Render();
    RegistrationWindow::Label_Password.Render();

    RegistrationWindow::InputField_Password_Repeat.Render();
    RegistrationWindow::Label_Password_Repeat.Render();

    RegistrationWindow::LogInButton.Render();
    RegistrationWindow::RegistrationButton.Render();

    RegistrationWindow::Text_Error.Render();

    //Render the new frame
    SDL_RenderPresent(System::renderer);
}
