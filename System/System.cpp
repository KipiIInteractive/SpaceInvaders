#include "System.h"

SDL_Window *System::window = NULL;
SDL_Renderer *System::renderer = NULL;
SDL_Event System::event;

//Screen
int System::Screen::Height = GetSystemMetrics(SM_CYSCREEN);
int System::Screen::Width = GetSystemMetrics(SM_CXSCREEN);

//Textures
int System::surfaceWidth;
int System::surfaceHeight;

//Fonts
TTF_Font *System::Fonts::Buttons = NULL;
TTF_Font *System::Fonts::Buttons_Small = NULL;
TTF_Font *System::Fonts::InputFields = NULL;
TTF_Font *System::Fonts::Labels = NULL;
TTF_Font *System::Fonts::Errors = NULL;
TTF_Font *System::Fonts::Score = NULL;

User System::Users::Current;

SDL_Texture *System::CreateTexture(std::string filePath, SDL_Renderer* textureRenderer)
{
    SDL_Surface *temp_surface = IMG_Load(filePath.c_str());

    SDL_Texture *texture = SDL_CreateTextureFromSurface(textureRenderer, temp_surface);
    SDL_FreeSurface(temp_surface);
    return texture;
}

SDL_Texture *System::CreateTextTexture(std::string text, SDL_Renderer *textureRenderer, TTF_Font *font, SDL_Color color)
{
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), color);

    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(textureRenderer, textSurface);

    surfaceWidth = textSurface->w;
    surfaceHeight = textSurface->h;

    SDL_FreeSurface(textSurface);
    return textTexture;
}

int System::GetSurfaceWidth() { return surfaceWidth; }
int System::GetSurfaceHeight() { return surfaceHeight; }

void System::Free()
{
    SDL_DestroyRenderer(System::renderer);
    SDL_DestroyWindow(System::window);

    delete(&System::event);

    TTF_CloseFont(System::Fonts::Buttons);
    TTF_CloseFont(System::Fonts::InputFields);
    TTF_CloseFont(System::Fonts::Labels);
}
