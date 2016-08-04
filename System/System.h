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

<<<<<<< HEAD
        static SDL_Texture *CreateTexture(std::string filePath, SDL_Renderer *textureRenderer);
=======
        static SDL_Texture *CreateTexture(std::string filePath);
<<<<<<< HEAD
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
        static SDL_Texture *CreateTextTexture(std::string text, SDL_Renderer *textureRenderer, TTF_Font *font, SDL_Color color);
=======
        static SDL_Texture *CreateTextTexture(std::string text, TTF_Font *font, SDL_Color color);
>>>>>>> 57ab2ef... Created new scene - NameSelectionWindow. When the score from the game is
        static int GetSurfaceWidth();
        static int GetSurfaceHeight();

        //Fonts
        class Fonts
        {
            public:
<<<<<<< HEAD
                static TTF_Font *Labels;
                static TTF_Font *InputFields;
                static TTF_Font *Buttons;
                static TTF_Font *Buttons_Small;
                static TTF_Font *Errors;
                static TTF_Font *Score;
=======
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
<<<<<<< HEAD
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
=======

                //Start window fonts
                static TTF_Font *StartWindow_Title;
<<<<<<< HEAD
>>>>>>> ecbd78b... The UFO feature is added. On launch Start Menu is shown with options to
=======

                //Name selection window fonts
                static TTF_Font *NameSelectionWindow_Title;
                static TTF_Font *NameSelectionWindow_Instructions;
>>>>>>> 57ab2ef... Created new scene - NameSelectionWindow. When the score from the game is
        };

        //Directions
        enum Direction
        {
            Up,
            Down,
            Right,
            Left
        };

<<<<<<< HEAD
=======
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

<<<<<<< HEAD
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
=======
        static string letters[26];
        static SDL_Rect letter_rect[26];
        static void InitAlphabet();

>>>>>>> 57ab2ef... Created new scene - NameSelectionWindow. When the score from the game is
        static void Free();

    private:
        static int surfaceWidth;
        static int surfaceHeight;
};

#endif // SYSTEM_H_INCLUDED
