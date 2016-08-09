#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "../profile_management/User.h"

#define ALPHABET_SIZE 26

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
                //Game Over Window fonts
                static TTF_Font *GameOverMenuNavigationHints;
                static TTF_Font *GameOverMenuTitle;
                static TTF_Font *GameOverMenuTopPlayers;
                static TTF_Font *GameOverMenuPlayerScore;

                //Win Window fonts
                static TTF_Font *WinWindowNavigationHints;
                static TTF_Font *WinWindowTitle;
                static TTF_Font *WinWindowTopPlayers;
                static TTF_Font *WinWindowPlayerScore;

                //Rank list fonts
                static TTF_Font *RankListNavigationHints;
                static TTF_Font *RankListTitle;

                //Game fonts
                static TTF_Font *PlayerScore;
                static TTF_Font *GameLevel;
                static TTF_Font *PlayerLivesLeft;

                //Start window fonts
                static TTF_Font *StartWindowTitle;

                //Name selection window fonts
                static TTF_Font *NameSelectionWindowTitle;
                static TTF_Font *NameSelectionWindowInstructions;
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
                static SDL_Texture *AliensAlive;
                static SDL_Texture *AliensDead;
                static SDL_Texture *UFO;

                static SDL_Texture *Bullets;

                static SDL_Texture *PlayerAlive;
                static SDL_Texture *PlayerDead;

                static SDL_Texture *Background;

                static SDL_Texture *Border;

                static SDL_Texture *BarrierTopLeft;
                static SDL_Texture *BarrierTopMiddle;
                static SDL_Texture *BarrierTopRight;
                static SDL_Texture *BarrierCenterLeft;
                static SDL_Texture *BarrierCenterMiddle;
                static SDL_Texture *BarrierCenterRight;
                static SDL_Texture *BarrierBottomLeft;
                static SDL_Texture *BarrierBottomMiddle;
                static SDL_Texture *BarrierBottomRight;

                static SDL_Texture *letters[ALPHABET_SIZE];
        };

        static string letters[ALPHABET_SIZE];
        static SDL_Rect letterRect[ALPHABET_SIZE];
        static void InitAlphabet();

        static void Free();

    private:
        static int surfaceWidth;
        static int surfaceHeight;
};

#endif // SYSTEM_H_INCLUDED
