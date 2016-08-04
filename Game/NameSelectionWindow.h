#ifndef NAMESELECTIONWINDOW_H_INCLUDED
#define NAMESELECTIONWINDOW_H_INCLUDED

#include "../System/System.h"
#include "../GUI/Keyboard.h"
#include "../GUI/Label.h"

class NameSelectionWindow
{
    public:
        static void Init();
        static void Show();
        static string GetName();

    private:
        static void RenderEverything();
        static bool isActive;

        static Label text_title;
        static Label text_instructions;
        static Label text_initials;

        static int initial_num;
        static string name;
};

#endif // NAMESELECTIONWINDOW_H_INCLUDED
