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

<<<<<<< HEAD
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
=======
//Game Over Window fonts
TTF_Font *System::Fonts::GameOver_NavigationHints = NULL;
TTF_Font *System::Fonts::GameOver_Title = NULL;
TTF_Font *System::Fonts::GameOver_Score = NULL;

//Win Window fonts
TTF_Font *System::Fonts::WinWindow_NavigationHints = NULL;
TTF_Font *System::Fonts::WinWindow_Title = NULL;
TTF_Font *System::Fonts::WinWindow_Score = NULL;

//Rank list fonts
TTF_Font *System::Fonts::RankList_NavigationHints = NULL;
TTF_Font *System::Fonts::RankList_Title = NULL;

//Game fonts
TTF_Font *System::Fonts::Game_Score = NULL;
TTF_Font *System::Fonts::Game_Level = NULL;
TTF_Font *System::Fonts::Game_LivesLeft = NULL;

                                            ///TO DELETE
                            TTF_Font *System::Fonts::Buttons_Small = NULL;
                            TTF_Font *System::Fonts::InputFields = NULL;
                            TTF_Font *System::Fonts::Buttons = NULL;
                            TTF_Font *System::Fonts::Labels = NULL;
                            TTF_Font *System::Fonts::Errors = NULL;
                            TTF_Font *System::Fonts::Hints = NULL;


SDL_Texture *System::Textures::Aliens = NULL;
SDL_Texture *System::Textures::Bullets = NULL;
SDL_Texture *System::Textures::Player = NULL;
SDL_Texture *System::Textures::Player_Dead = NULL;
SDL_Texture *System::Textures::Background_Black = NULL;
SDL_Texture *System::Textures::Background_Stars = NULL;
SDL_Texture *System::Textures::Border = NULL;
SDL_Texture *System::Textures::Barrier_Top_Left = NULL;
SDL_Texture *System::Textures::Barrier_Top_Middle = NULL;
SDL_Texture *System::Textures::Barrier_Top_Right = NULL;
SDL_Texture *System::Textures::Barrier_Center_Left = NULL;
SDL_Texture *System::Textures::Barrier_Center_Middle = NULL;
SDL_Texture *System::Textures::Barrier_Center_Right = NULL;
SDL_Texture *System::Textures::Barrier_Bottom_Left = NULL;
SDL_Texture *System::Textures::Barrier_Bottom_Middle = NULL;
SDL_Texture *System::Textures::Barrier_Bottom_Right = NULL;

User System::Users::Current;

SDL_Texture *System::CreateTexture(std::string filePath)
{
    SDL_Surface *temp_surface = IMG_Load(filePath.c_str());

    SDL_Texture *texture = SDL_CreateTextureFromSurface(System::renderer, temp_surface);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
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
<<<<<<< HEAD
=======
    //Destroy the used textures
    SDL_DestroyTexture(System::Textures::Aliens);
    SDL_DestroyTexture(System::Textures::Bullets);
    SDL_DestroyTexture(System::Textures::Player);
    SDL_DestroyTexture(System::Textures::Player_Dead);
    SDL_DestroyTexture(System::Textures::Background_Black);
    SDL_DestroyTexture(System::Textures::Background_Stars);
    SDL_DestroyTexture(System::Textures::Border);
    SDL_DestroyTexture(System::Textures::Barrier_Top_Left);
    SDL_DestroyTexture(System::Textures::Barrier_Top_Middle);
    SDL_DestroyTexture(System::Textures::Barrier_Top_Right);
    SDL_DestroyTexture(System::Textures::Barrier_Center_Left);
    SDL_DestroyTexture(System::Textures::Barrier_Center_Middle);
    SDL_DestroyTexture(System::Textures::Barrier_Center_Right);
    SDL_DestroyTexture(System::Textures::Barrier_Bottom_Left);
    SDL_DestroyTexture(System::Textures::Barrier_Bottom_Middle);
    SDL_DestroyTexture(System::Textures::Barrier_Bottom_Right);

>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
    SDL_DestroyRenderer(System::renderer);
    SDL_DestroyWindow(System::window);

    delete(&System::event);
<<<<<<< HEAD

    TTF_CloseFont(System::Fonts::Buttons);
    TTF_CloseFont(System::Fonts::InputFields);
    TTF_CloseFont(System::Fonts::Labels);
=======
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
}
