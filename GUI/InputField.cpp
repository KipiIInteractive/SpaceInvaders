#include "InputField.h"

InputField::InputField()
{
    this->isActive = true;
    this->isEnterPressed = false;
    this->isTabPressed = false;
    this->charLimit = 5;
    this->inputTextTexture = NULL;
    this->inputText = "";
    this->textColor = {255, 255, 255};
    this->type = "normal";
}

InputField::~InputField()
{
    TTF_CloseFont(font);
    SDL_DestroyTexture(inputTextTexture);
    delete(&textColor);
    inputText.clear();
}

void InputField::SetTextColor(int r, int g, int b) { this->textColor = {(Uint8)r, (Uint8)g, (Uint8)b}; }

string InputField::GetInputText() { return inputText; }

void InputField::SetCharLimit(int limit) { charLimit = limit; }

void InputField::SetFont(TTF_Font *font) { this->font = font; }

int InputField::GetCharLimit() { return this->charLimit; }

int InputField::GetTextWidth() { return this->textRect.w; }

int InputField::GetTextHeight() { return this->textRect.h; }

void InputField::SetTextX(int x) { this->textRect.x = x; }

void InputField::SetTextY(int y) { this->textRect.y = y; }

void InputField::Input()
{
    if(System::event.type == SDL_KEYDOWN && this->isActive)
    {
        //If Backspace is pressed remove the last character from the string
        if(System::event.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0)
            Delete();

        //If Enter is pressed make the input field inactive
        else if(System::event.key.keysym.sym == SDLK_RETURN || System::event.key.keysym.sym == SDLK_RETURN2)
            this->isEnterPressed = true;

        //if Tab is pressed make the input field inactive
        else if(System::event.key.keysym.sym == SDLK_TAB)
            this->isTabPressed = true;

        else if((System::event.key.keysym.sym >= SDLK_a && System::event.key.keysym.sym <= SDLK_z)
                || (System::event.key.keysym.sym >= SDLK_0 && System::event.key.keysym.sym <= SDLK_9))
        {
            if((int)inputText.length() < charLimit)
            {
                this->inputText += (char)System::event.key.keysym.sym;

                if(type == "normal")
                    inputTextTexture = System::CreateTextTexture(this->inputText, System::renderer, this->font, this->textColor);

                else if(type == "password")
                {
                    string passToShow;
                    for(int i = 0; i < (int)inputText.length(); ++i)
                        passToShow += '*';

                    inputTextTexture = System::CreateTextTexture(passToShow, System::renderer, this->font, this->textColor);
                }
                this->textRect.x = this->rect.x;
                this->textRect.y = this->rect.y;
                this->textRect.w = System::GetSurfaceWidth();
                this->textRect.h = System::GetSurfaceHeight();
            }
        }
    }
}

void InputField::Delete()
{
    inputText.pop_back();
    if(inputText.length() >= 1)
    {
        if(this->type == "password")
        {
            string passToShow;
            for(int i = 0; i < (int)inputText.length(); ++i)
                passToShow += '*';
            inputTextTexture = System::CreateTextTexture(passToShow, System::renderer, this->font, this->textColor);
        }
        else
            inputTextTexture = System::CreateTextTexture(this->inputText, System::renderer, this->font, this->textColor);
    }
    else
    {
        inputTextTexture = System::CreateTextTexture(" ", System::renderer, this->font, this->textColor);
    }
    this->textRect.x = this->rect.x;
    this->textRect.y = this->rect.y;
    this->textRect.w = System::GetSurfaceWidth();
    this->textRect.h = System::GetSurfaceHeight();
}

void InputField::Render()
{
    SDL_RenderCopy(System::renderer, this->texture, NULL, &rect);
    SDL_RenderCopy(System::renderer, inputTextTexture, NULL, &textRect);
}
