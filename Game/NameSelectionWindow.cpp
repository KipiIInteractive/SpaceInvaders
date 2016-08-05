#include "NameSelectionWindow.h"

bool NameSelectionWindow::isActive;
Label NameSelectionWindow::text_title;
Label NameSelectionWindow::text_instructions;
Label NameSelectionWindow::text_initials;

int NameSelectionWindow::initial_num;
string NameSelectionWindow::name;


void NameSelectionWindow::Init()
{
    NameSelectionWindow::isActive = false;
    NameSelectionWindow::initial_num = 0;
    NameSelectionWindow::name = "";

    //Initialize the title text
    NameSelectionWindow::text_title.SetText("You reached high score!");
    NameSelectionWindow::text_title.SetColor(0, 255, 0);
    NameSelectionWindow::text_title.SetFont(System::Fonts::NameSelectionWindow_Title);
    NameSelectionWindow::text_title.SetX(System::Screen::Width / 2 - NameSelectionWindow::text_title.GetWidth() / 2);
    NameSelectionWindow::text_title.SetY(System::Screen::Height / 10);

    //Initialize the instructions text
    NameSelectionWindow::text_instructions.SetText("Select your initials for the rank list");
    NameSelectionWindow::text_instructions.SetColor(255, 255, 255);
    NameSelectionWindow::text_instructions.SetFont(System::Fonts::NameSelectionWindow_Instructions);
    NameSelectionWindow::text_instructions.SetX(System::Screen::Width / 2 - NameSelectionWindow::text_instructions.GetWidth() / 2);
    NameSelectionWindow::text_instructions.SetY(Keyboard::rect.y - NameSelectionWindow::text_instructions.GetHeight() - 50);

    //Initialize the initials text
    NameSelectionWindow::text_initials.SetText("- - -");
    NameSelectionWindow::text_initials.SetColor(255, 255, 255);
    TTF_Font *tmp_font = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
    NameSelectionWindow::text_initials.SetFont(tmp_font);
    NameSelectionWindow::text_initials.SetX(System::Screen::Width / 2 - NameSelectionWindow::text_initials.GetWidth() / 2);
    NameSelectionWindow::text_initials.SetY(System::Screen::Height / 2 - NameSelectionWindow::text_initials.GetHeight() / 2);
}

void NameSelectionWindow::Show()
{
    bool is_space_pressed;

    if(SDL_PollEvent(&System::event))
    {
        if(System::event.type == SDL_KEYDOWN)
        {
            if(System::event.type == SDLK_SPACE)
                is_space_pressed = true;
        }
    }

    SDL_FlushEvent(SDL_KEYDOWN);
    NameSelectionWindow::isActive = true;
    NameSelectionWindow::RenderEverything();
    while(NameSelectionWindow::isActive)
    {
        if(Keyboard::isActive)
        {
            if(SDL_PollEvent(&System::event))
            {
                if(System::event.type == SDL_KEYDOWN && is_space_pressed == false)
                {
                    int nav_status = Keyboard::Navigate();

                    //If enter is hit when some letter is selected get that letter
                    if(nav_status == 0)
                    {
                        if(NameSelectionWindow::initial_num < 5)
                            NameSelectionWindow::name += Keyboard::GetKey();

                        string newText = NameSelectionWindow::text_initials.GetText();
                        newText[NameSelectionWindow::initial_num] = Keyboard::GetKey();
                        NameSelectionWindow::text_initials.SetText(newText);
                        NameSelectionWindow::text_initials.SetColor(255, 255, 255);
                        TTF_Font *tmp_font = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
                        NameSelectionWindow::text_initials.SetFont(tmp_font);
                        NameSelectionWindow::initial_num += 2;

                        if(NameSelectionWindow::initial_num == 6)
                        {
                            //Initialize the instructions text
                            NameSelectionWindow::text_instructions.SetText("Press Fire to continue");
                            NameSelectionWindow::text_instructions.SetColor(0, 255, 0);
                            NameSelectionWindow::text_instructions.SetFont(System::Fonts::NameSelectionWindow_Instructions);
                            NameSelectionWindow::text_instructions.SetX(System::Screen::Width / 2 - NameSelectionWindow::text_instructions.GetWidth() / 2);
                        }
                        else if(NameSelectionWindow::initial_num > 6)
                            NameSelectionWindow::isActive = false;
                    }

                    NameSelectionWindow::RenderEverything();
                }
            }
        }
    }
}

string NameSelectionWindow::GetName() { return NameSelectionWindow::name; }

void NameSelectionWindow::RenderEverything()
{
    SDL_RenderClear(System::renderer);

    SDL_RenderCopy(System::renderer, System::Textures::Background_Black, NULL, NULL);

    NameSelectionWindow::text_title.Render();
    NameSelectionWindow::text_instructions.Render();
    NameSelectionWindow::text_initials.Render();

    Keyboard::Render();

    SDL_RenderPresent(System::renderer);
}
