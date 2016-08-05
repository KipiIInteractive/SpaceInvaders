#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <windows.h>
#include <iostream>
#include "../profile_managment/User.h"

class System
{
    public:
        static SDL_Window *window;
        static SDL_Renderer *renderer;
        static SDL_Event event;

        class Users
        {
            public:
                static User Current;
        };

        //Screen properties
        class Screen
        {
            public:
                static int Width;
                static int Height;
        };

        static SDL_Texture *CreateTexture(std::string filePath);
        static SDL_Texture *CreateTextTexture(std::string text, TTF_Font *font, SDL_Color color);
        static int GetSurfaceWidth();
        static int GetSurfaceHeight();

        //Fonts
        class Fonts
        {
            public:
                static TTF_Font *Buttons_Small;
                static TTF_Font *InputFields;
                static TTF_Font *Buttons;
                static TTF_Font *Labels;
                static TTF_Font *Errors;

                //Game Over Window fonts
                static TTF_Font *GameOver_NavigationHints;
                static TTF_Font *GameOver_Title;
                static TTF_Font *GameOver_Title_Top_Players;
                static TTF_Font *GameOver_Score;

                //Win Window fonts
                static TTF_Font *WinWindow_NavigationHints;
                static TTF_Font *WinWindow_Title;
                static TTF_Font *WinWindow_Title_Top_Players;
                static TTF_Font *WinWindow_Score;

                //Rank list fonts
                static TTF_Font *RankList_NavigationHints;
                static TTF_Font *RankList_Title;

                //Game fonts
                static TTF_Font *Game_Score;
                static TTF_Font *Game_Level;
                static TTF_Font *Game_LivesLeft;

                //Start window fonts
                static TTF_Font *StartWindow_Title;

                //Name selection window fonts
                static TTF_Font *NameSelectionWindow_Title;
                static TTF_Font *NameSelectionWindow_Instructions;
        };

        //Directions
        enum Direction
        {
            Up,
            Down,
            Right,
            Left
        };

        class Textures
        {
            public:
                static SDL_Texture *Aliens;
                static SDL_Texture *Aliens_Dead;
                static SDL_Texture *UFO;

                static SDL_Texture *Bullets;

                static SDL_Texture *Player;
                static SDL_Texture *Player_Dead;

                static SDL_Texture *Background_Black;

                static SDL_Texture *Border;

                static SDL_Texture *Barrier_Top_Left;
                static SDL_Texture *Barrier_Top_Middle;
                static SDL_Texture *Barrier_Top_Right;
                static SDL_Texture *Barrier_Center_Left;
                static SDL_Texture *Barrier_Center_Middle;
                static SDL_Texture *Barrier_Center_Right;
                static SDL_Texture *Barrier_Bottom_Left;
                static SDL_Texture *Barrier_Bottom_Middle;
                static SDL_Texture *Barrier_Bottom_Right;

                static SDL_Texture *letters[26];
        };

        static string letters[26];
        static SDL_Rect letter_rect[26];
        static void InitAlphabet();

        static void Free();

    private:
        static int surfaceWidth;
        static int surfaceHeight;
};

#endif // SYSTEM_H_INCLUDED
