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

        static Label titleText;
        static Label instructionsText;
        static Label initialsText;

        static int initialsTextInsertPos;
        static string name;
};

#endif // NAMESELECTIONWINDOW_H_INCLUDED
