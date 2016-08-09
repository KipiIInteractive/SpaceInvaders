#include "NameSelectionWindow.h"

bool NameSelectionWindow::isActive;
Label NameSelectionWindow::titleText;
Label NameSelectionWindow::instructionsText;
Label NameSelectionWindow::initialsText;

int NameSelectionWindow::initialsTextInsertPos;
string NameSelectionWindow::name;


void NameSelectionWindow::Init()
{
    NameSelectionWindow::isActive = false;
    NameSelectionWindow::initialsTextInsertPos = 0;
    NameSelectionWindow::name = "";

    //Initialize the title text
    int titleYIndentationFromScreenTopDivisor = 10;
    NameSelectionWindow::titleText.SetText("You reached high score!");
    NameSelectionWindow::titleText.SetColor(0, 255, 0);
    NameSelectionWindow::titleText.SetFont(System::Fonts::NameSelectionWindowTitle);
    NameSelectionWindow::titleText.SetX(System::Screen::Width / 2 - NameSelectionWindow::titleText.GetWidth() / 2);
    NameSelectionWindow::titleText.SetY(System::Screen::Height / titleYIndentationFromScreenTopDivisor);

    //Initialize the instructions text
    int instructionYIndentationFromScreenBottomSubtrahend = 50;
    NameSelectionWindow::instructionsText.SetText("Select your initials for the rank list");
    NameSelectionWindow::instructionsText.SetColor(255, 255, 255);
    NameSelectionWindow::instructionsText.SetFont(System::Fonts::NameSelectionWindowInstructions);
    NameSelectionWindow::instructionsText.SetX(System::Screen::Width / 2 - NameSelectionWindow::instructionsText.GetWidth() / 2);
    NameSelectionWindow::instructionsText.SetY(Keyboard::rect.y - NameSelectionWindow::instructionsText.GetHeight() - instructionYIndentationFromScreenBottomSubtrahend);

    //Initialize the initials text
    NameSelectionWindow::initialsText.SetText("- - -");
    NameSelectionWindow::initialsText.SetColor(255, 255, 255);
    TTF_Font *tmpFont = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
    NameSelectionWindow::initialsText.SetFont(tmpFont);
    NameSelectionWindow::initialsText.SetX(System::Screen::Width / 2 - NameSelectionWindow::initialsText.GetWidth() / 2);
    NameSelectionWindow::initialsText.SetY(System::Screen::Height / 2 - NameSelectionWindow::initialsText.GetHeight() / 2);
}

void NameSelectionWindow::Show()
{
    bool isSpacePressed;

    if(SDL_PollEvent(&System::event))
    {
        if(System::event.type == SDL_KEYDOWN)
        {
            if(System::event.type == SDLK_SPACE) {
                isSpacePressed = true;
            }
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
                if(System::event.type == SDL_KEYDOWN && isSpacePressed == false)
                {
                    isSpacePressed = Keyboard::Navigate();

                    //If space is hit when some letter is selected get that letter
                    if(isSpacePressed)
                    {
                        if(NameSelectionWindow::initialsTextInsertPos < 5) {
                            NameSelectionWindow::name += Keyboard::GetKey();
                        }

                        string newText = NameSelectionWindow::initialsText.GetText();
                        newText[NameSelectionWindow::initialsTextInsertPos] = Keyboard::GetKey();
                        NameSelectionWindow::initialsText.SetText(newText);
                        NameSelectionWindow::initialsText.SetColor(255, 255, 255);
                        TTF_Font *tmpFont = TTF_OpenFont("Resources/Fonts/invaders.ttf", 50);
                        NameSelectionWindow::initialsText.SetFont(tmpFont);
                        NameSelectionWindow::initialsTextInsertPos += 2;

                        if(NameSelectionWindow::initialsTextInsertPos == 6)
                        {
                            //Initialize the instructions text
                            NameSelectionWindow::instructionsText.SetText("Press Fire to continue");
                            NameSelectionWindow::instructionsText.SetColor(0, 255, 0);
                            NameSelectionWindow::instructionsText.SetFont(System::Fonts::NameSelectionWindowInstructions);
                            NameSelectionWindow::instructionsText.SetX(System::Screen::Width / 2 - NameSelectionWindow::instructionsText.GetWidth() / 2);
                        }
                        else if(NameSelectionWindow::initialsTextInsertPos > 6) {
                            NameSelectionWindow::isActive = false;
                        }
                        isSpacePressed = false;
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

    SDL_RenderCopy(System::renderer, System::Textures::Background, NULL, NULL);

    NameSelectionWindow::titleText.Render();
    NameSelectionWindow::instructionsText.Render();
    NameSelectionWindow::initialsText.Render();

    Keyboard::Render();

    SDL_RenderPresent(System::renderer);
}
