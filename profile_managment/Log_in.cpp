#include "Log_in.h"

SDL_Texture *LoginWindow::backgroundTexture = NULL;
Link LoginWindow::LogInButton;
Link LoginWindow::ExitButtton;
Link LoginWindow::RegistrationButton;

Label LoginWindow::Label_Username;
InputField LoginWindow::InputField_Username;

Label LoginWindow::Label_Password;
InputField LoginWindow::InputField_Password;

Label LoginWindow::Text_Error;

bool LoginWindow::isActive;

void LoginWindow::Init()
{
    //Load the data for the users
    ProfileManager::LoadTheUsersData();

    //Create the backgroud texture for the log-in window
    LoginWindow::backgroundTexture = System::CreateTexture("Resources/Textures/menuBackground.png", System::renderer);
    if(LoginWindow::backgroundTexture == NULL)
        std::cout << "Failed to create the log-in background texture. File: profile_managment/Log_in.cpp/Init(): \n" << IMG_GetError() << std::endl;

    //Initialize the log-in error text
    LoginWindow::Text_Error.SetText(" ");
    LoginWindow::Text_Error.SetColor(255, 10, 30);
    LoginWindow::Text_Error.SetFont(System::Fonts::Errors);
    LoginWindow::Text_Error.SetX(System::Screen::Width / 2 - LoginWindow::Text_Error.GetWidth() / 2);
    LoginWindow::Text_Error.SetY(System::Screen::Height - LoginWindow::Text_Error.GetHeight() - 70);

    LoginWindow::InitializeTheInputFields();
    LoginWindow::InitializeTheButtons();
}

void LoginWindow::InitializeTheInputFields()
{
    //Initialize the label for the username input field
    LoginWindow::Label_Username.SetText("Username:");
    LoginWindow::Label_Username.SetColor(255, 10, 30);
    LoginWindow::Label_Username.SetFont(System::Fonts::Labels);
    LoginWindow::Label_Username.SetX(System::Screen::Width / 2 - LoginWindow::Label_Username.GetWidth() / 2);
    LoginWindow::Label_Username.SetY(System::Screen::Height / 7);

    //Initialize the username input field
    LoginWindow::InputField_Username.SetFont(System::Fonts::InputFields);
    LoginWindow::InputField_Username.SetTextColor(255, 255, 255);
    LoginWindow::InputField_Username.isActive = true;
    LoginWindow::InputField_Username.SetCharLimit(20);
    LoginWindow::InputField_Username.SetWidth(System::Screen::Width /1.5);
    LoginWindow::InputField_Username.SetHeight(35);
    LoginWindow::InputField_Username.SetX(System::Screen::Width / 2 - LoginWindow::InputField_Username.GetWidth() / 2);
    LoginWindow::InputField_Username.SetY(LoginWindow::Label_Username.GetY() + LoginWindow::Label_Username.GetHeight() + 20);
    LoginWindow::InputField_Username.SetTexture("Resources/Textures/inputField.bmp");


     //Initialize the label for the password input field
    LoginWindow::Label_Password.SetText("Password:");
    LoginWindow::Label_Password.SetColor(255, 10, 30);
    LoginWindow::Label_Password.SetFont(System::Fonts::Labels);
    LoginWindow::Label_Password.SetX(System::Screen::Width / 2 - LoginWindow::Label_Password.GetWidth() / 2);
    LoginWindow::Label_Password.SetY(LoginWindow::InputField_Username.GetY() + LoginWindow::InputField_Username.GetHeight() + 60);

    //Initialize the password input field
    LoginWindow::InputField_Password.type = "password";
    LoginWindow::InputField_Password.SetFont(System::Fonts::InputFields);
    LoginWindow::InputField_Password.SetTextColor(255, 255, 255);
    LoginWindow::InputField_Password.isActive = false;
    LoginWindow::InputField_Password.SetCharLimit(20);
    LoginWindow::InputField_Password.SetWidth(System::Screen::Width /1.5);
    LoginWindow::InputField_Password.SetHeight(35);
    LoginWindow::InputField_Password.SetX(System::Screen::Width / 2 - LoginWindow::InputField_Password.GetWidth() / 2);
    LoginWindow::InputField_Password.SetY(LoginWindow::Label_Password.GetY() + LoginWindow::Label_Password.GetHeight() + 20);
    LoginWindow::InputField_Password.SetTexture("Resources/Textures/inputField.bmp");
}

void LoginWindow::InitializeTheButtons()
{
    //Initialize the Log-in button
    LoginWindow::LogInButton.SetFont(System::Fonts::Buttons);
    LoginWindow::LogInButton.SetText("Log In");
    LoginWindow::LogInButton.SetColor(255, 0, 0);
    LoginWindow::LogInButton.SetX(System::Screen::Width / 2 - LoginWindow::LogInButton.GetWidth() / 2);
    LoginWindow::LogInButton.SetY(LoginWindow::InputField_Password.GetY() + LoginWindow::InputField_Password.GetHeight() + 80);

    //Initialize the Exit button
    LoginWindow::ExitButtton.SetFont(System::Fonts::Buttons);
    LoginWindow::ExitButtton.SetText("Exit");
    LoginWindow::ExitButtton.SetColor(255, 0, 0);
    LoginWindow::ExitButtton.SetX(System::Screen::Width - LoginWindow::ExitButtton.GetWidth() - 5);
    LoginWindow::ExitButtton.SetY(5);

     //Initialize the Registration button
    LoginWindow::RegistrationButton.SetFont(System::Fonts::Buttons_Small);
    LoginWindow::RegistrationButton.SetText("Don't have an account?");
    LoginWindow::RegistrationButton.SetColor(255, 255, 255);
    LoginWindow::RegistrationButton.SetX(System::Screen::Width - LoginWindow::RegistrationButton.GetWidth() - 5);
    LoginWindow::RegistrationButton.SetY(System::Screen::Height - LoginWindow::RegistrationButton.GetHeight() - 5);
}

void LoginWindow::Show()
{
    //Set the log-in window to be active
    LoginWindow::isActive = true;

    LoginWindow::MainLoop();
}

void LoginWindow::MainLoop()
{
    while(LoginWindow::isActive)
    {
        CheckForEvents();
    }
}

void LoginWindow::CheckForEvents()
{

    if(SDL_PollEvent(&System::event))
    {
        LoginWindow::InputField_Username.Input();
        LoginWindow::InputField_Password.Input();

        LoginWindow::InputField_Username.SetTextX(System::Screen::Width / 2 - LoginWindow::InputField_Username.GetTextWidth() / 2);
        LoginWindow::InputField_Password.SetTextX(System::Screen::Width / 2 - LoginWindow::InputField_Password.GetTextWidth() / 2);


        LoginWindow::CreateButtonEffects();
        LoginWindow::CreateButtonActions();


        //Switch the active input field when TAB is pressed
        if(LoginWindow::InputField_Username.isActive && LoginWindow::InputField_Username.isTabPressed)
        {
            LoginWindow::InputField_Username.isActive = false;
            LoginWindow::InputField_Password.isActive = true;
            LoginWindow::InputField_Username.isTabPressed = false;
        }
        else if(LoginWindow::InputField_Password.isActive && LoginWindow::InputField_Password.isTabPressed)
        {
            LoginWindow::InputField_Password.isActive = false;
            LoginWindow::InputField_Username.isActive = true;
            LoginWindow::InputField_Password.isTabPressed = false;
        }

        //Switch the active input field when input field is clicked
        if(LoginWindow::InputField_Username.isClicked())
        {
            LoginWindow::InputField_Password.isActive = false;
            LoginWindow::InputField_Username.isActive = true;
        }
        else if(LoginWindow::InputField_Password.isClicked())
        {
            LoginWindow::InputField_Password.isActive = true;
            LoginWindow::InputField_Username.isActive = false;
        }

        //When the Enter button is pressed try to log in with the given user input
        if(LoginWindow::InputField_Username.isEnterPressed)
        {
            LoginWindow::InputField_Username.isEnterPressed = false;
            LoginWindow::LogIn();
        }
        else if(LoginWindow::InputField_Password.isEnterPressed)
        {
            LoginWindow::InputField_Password.isEnterPressed = false;
            LoginWindow::LogIn();
        }

        //Render the new frame on the window
        LoginWindow::Render();
    }
}

void LoginWindow::CreateButtonEffects()
{
    //Change the color of the log-in button when it is hover
    if(LoginWindow::LogInButton.isHover())
        LoginWindow::LogInButton.SetColor(255, 255, 255);
    else
        LoginWindow::LogInButton.SetColor(255, 0, 0);

    //Change the color of the exit button when it is hover
    if(LoginWindow::ExitButtton.isHover())
        LoginWindow::ExitButtton.SetColor(255, 255, 255);
    else
        LoginWindow::ExitButtton.SetColor(255, 0, 0);

    //Change the color of the registration button when it is hover
    if(LoginWindow::RegistrationButton.isHover())
        LoginWindow::RegistrationButton.SetColor(255, 0, 0);
    else
        LoginWindow::RegistrationButton.SetColor(255, 255, 255);
}

void LoginWindow::CreateButtonActions()
{
    //When the log-in button is pressed try to log in with the given user input
    if(LoginWindow::LogInButton.isClicked())
    {
        LoginWindow::LogIn();
    }

    //When the exit button is pressed exit the game
    if(LoginWindow::ExitButtton.isClicked())
        LoginWindow::isActive = false;

    //When the registration button is pressed go to the registration window
    if(LoginWindow::RegistrationButton.isClicked())
    {
        LoginWindow::isActive = false;
        RegistrationWindow::Show();
    }

}

void LoginWindow::LogIn()
{
    //Not successful login
    if( !ProfileManager::LogIn(LoginWindow::InputField_Username.GetInputText(), LoginWindow::InputField_Password.GetInputText()))
    {
        LoginWindow::Text_Error.SetText("Log in denied!");
        LoginWindow::Text_Error.SetColor(255, 10, 30);
        LoginWindow::Text_Error.SetFont(System::Fonts::Errors);
        LoginWindow::Text_Error.SetX(System::Screen::Width / 2 - LoginWindow::Text_Error.GetWidth() / 2);
    }
    //Successful login
    else
    {
        LoginWindow::Text_Error.SetText("Log in successful!");
        LoginWindow::Text_Error.SetColor(0, 255, 0);
        LoginWindow::Text_Error.SetFont(System::Fonts::Errors);
        LoginWindow::Text_Error.SetX(System::Screen::Width / 2 - LoginWindow::Text_Error.GetWidth() / 2);

        Game::StartGame();
    }
}

void LoginWindow::Render()
{
    //Clear the previous frame
    SDL_RenderClear(System::renderer);

    //Add the textures to the renderer
    SDL_RenderCopy(System::renderer, LoginWindow::backgroundTexture, NULL, NULL);

    LoginWindow::InputField_Username.Render();
    LoginWindow::Label_Username.Render();

    LoginWindow::InputField_Password.Render();
    LoginWindow::Label_Password.Render();

    LoginWindow::LogInButton.Render();
    LoginWindow::ExitButtton.Render();
    LoginWindow::RegistrationButton.Render();

    LoginWindow::Text_Error.Render();

    //Render the new frame
    SDL_RenderPresent(System::renderer);
}
