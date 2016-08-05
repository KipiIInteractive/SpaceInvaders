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

//Game Over Window fonts
TTF_Font *System::Fonts::GameOver_NavigationHints = NULL;
TTF_Font *System::Fonts::GameOver_Title = NULL;
TTF_Font *System::Fonts::GameOver_Title_Top_Players = NULL;
TTF_Font *System::Fonts::GameOver_Score = NULL;

//Win Window fonts
TTF_Font *System::Fonts::WinWindow_NavigationHints = NULL;
TTF_Font *System::Fonts::WinWindow_Title = NULL;
TTF_Font *System::Fonts::WinWindow_Title_Top_Players = NULL;
TTF_Font *System::Fonts::WinWindow_Score = NULL;

//Rank list fonts
TTF_Font *System::Fonts::RankList_NavigationHints = NULL;
TTF_Font *System::Fonts::RankList_Title = NULL;

//Game fonts
TTF_Font *System::Fonts::Game_Score = NULL;
TTF_Font *System::Fonts::Game_Level = NULL;
TTF_Font *System::Fonts::Game_LivesLeft = NULL;

//Start window fonts
TTF_Font *System::Fonts::StartWindow_Title = NULL;

//Name selection window fonts
TTF_Font *System::Fonts::NameSelectionWindow_Title = NULL;
TTF_Font *System::Fonts::NameSelectionWindow_Instructions = NULL;

TTF_Font *System::Fonts::Buttons_Small = NULL;
TTF_Font *System::Fonts::InputFields = NULL;
TTF_Font *System::Fonts::Buttons = NULL;
TTF_Font *System::Fonts::Labels = NULL;
TTF_Font *System::Fonts::Errors = NULL;


SDL_Texture *System::Textures::Aliens = NULL;
SDL_Texture *System::Textures::Aliens_Dead = NULL;
SDL_Texture *System::Textures::UFO = NULL;

SDL_Texture *System::Textures::Bullets = NULL;

SDL_Texture *System::Textures::Player = NULL;
SDL_Texture *System::Textures::Player_Dead = NULL;

SDL_Texture *System::Textures::Background_Black = NULL;

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

SDL_Texture *System::Textures::letters[26];

string System::letters[26];
SDL_Rect System::letter_rect[26];

void System::InitAlphabet()
{
    System::letters[0] = 'a';    System::letters[10] = 'k';   System::letters[20] = 'u';
    System::letters[1] = 'b';    System::letters[11] = 'l';   System::letters[21] = 'v';
    System::letters[2] = 'c';    System::letters[12] = 'm';   System::letters[22] = 'w';
    System::letters[3] = 'd';    System::letters[13] = 'n';   System::letters[23] = 'x';
    System::letters[4] = 'e';    System::letters[14] = 'o';   System::letters[24] = 'y';
    System::letters[5] = 'f';    System::letters[15] = 'p';   System::letters[25] = 'z';
    System::letters[6] = 'g';    System::letters[16] = 'q';
    System::letters[7] = 'h';    System::letters[17] = 'r';
    System::letters[8] = 'i';    System::letters[18] = 's';
    System::letters[9] = 'j';    System::letters[19] = 't';

    SDL_Color color = {255, 255, 255};
    for(unsigned i = 0; i < 26; i++)
    {
        TTF_Font *tmp_font = TTF_OpenFont("Resources/Fonts/invaders.ttf", 60);
        System::Textures::letters[i] = System::CreateTextTexture(System::letters[i] + " ", tmp_font, color);
        System::letter_rect[i].w = System::GetSurfaceWidth();
        System::letter_rect[i].h = System::GetSurfaceHeight();
        System::letter_rect[i].x = 0;
        System::letter_rect[i].y = 0;
    }
}
User System::Users::Current;

SDL_Texture *System::CreateTexture(std::string filePath)
{
    SDL_Surface *temp_surface = IMG_Load(filePath.c_str());

    SDL_Texture *texture = SDL_CreateTextureFromSurface(System::renderer, temp_surface);
    SDL_FreeSurface(temp_surface);
    return texture;
}

SDL_Texture *System::CreateTextTexture(std::string text, TTF_Font *font, SDL_Color color)
{
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), color);

    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(System::renderer, textSurface);

    surfaceWidth = textSurface->w;
    surfaceHeight = textSurface->h;

    SDL_FreeSurface(textSurface);
    return textTexture;
}

int System::GetSurfaceWidth() { return surfaceWidth; }
int System::GetSurfaceHeight() { return surfaceHeight; }

void System::Free()
{
    //Destroy the used textures
    SDL_DestroyTexture(System::Textures::Aliens);
    SDL_DestroyTexture(System::Textures::UFO);
    SDL_DestroyTexture(System::Textures::Bullets);
    SDL_DestroyTexture(System::Textures::Player);
    SDL_DestroyTexture(System::Textures::Player_Dead);
    SDL_DestroyTexture(System::Textures::Background_Black);
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

    SDL_DestroyRenderer(System::renderer);
    SDL_DestroyWindow(System::window);

    delete(&System::event);
}
