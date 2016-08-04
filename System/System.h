#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <windows.h>
#include <iostream>

class System
{
    public:
        static SDL_Window *window;
        static SDL_Renderer *renderer;
        static SDL_Event event;

        //Screen properties
        class Screen
        {
            public:
                static int Width;
                static int Height;
        };

        static SDL_Texture *CreateTexture(std::string filePath, SDL_Renderer *textureRenderer);
        static SDL_Texture *CreateTextTexture(std::string text, SDL_Renderer *textureRenderer, TTF_Font *font, SDL_Color color);
        static int GetSurfaceWidth();
        static int GetSurfaceHeight();

        //Fonts
        class Fonts
        {
            public:
                static TTF_Font *Labels;
                static TTF_Font *InputFields;
                static TTF_Font *Buttons;
                static TTF_Font *Buttons_Small;
                static TTF_Font *Errors;
        };

        //Directions
        enum Direction
        {
            Up,
            Down,
            Right,
            Left
        };

        static void Free();

    private:
        static int surfaceWidth;
        static int surfaceHeight;
};

#endif // SYSTEM_H_INCLUDED
