#ifndef INPUTFIELD_H_INCLUDED
#define INPUTFIELD_H_INCLUDED

#include <string>
#include "GUI.h"
#include "../System/System.h"

class InputField : public GUI
{
    public:
        InputField();
        ~InputField();

        string type;

        string GetInputText();
        bool isActive;

        void SetCharLimit(int limit);
        int GetCharLimit();
        void SetTextColor(int r, int g, int b);
        void SetFont(TTF_Font *font);
        void Input();

        bool isTabPressed;
        bool isEnterPressed;

        void Render();

        int GetTextWidth();
        int GetTextHeight();
        void SetTextX(int x);
        void SetTextY(int y);

    private:
        int charLimit;
        SDL_Texture *inputTextTexture;
        TTF_Font *font;
        SDL_Color textColor;
        SDL_Rect textRect;

        string inputText;

        void Delete();
};

#endif // INPUTFIELD_H_INCLUDED
