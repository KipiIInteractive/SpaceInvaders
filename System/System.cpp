#include "System.h"

SDL_Window *System::window = NULL;
SDL_Renderer *System::renderer = NULL;
SDL_Event System::event;

//Screen
int System::Screen::Height = 0;
int System::Screen::Width = 0;

//Textures
int System::surfaceWidth;
int System::surfaceHeight;

//Game Over Window fonts
TTF_Font *System::Fonts::GameOverMenuNavigationHints = NULL;
TTF_Font *System::Fonts::GameOverMenuTitle = NULL;
TTF_Font *System::Fonts::GameOverMenuTopPlayers = NULL;
TTF_Font *System::Fonts::GameOverMenuPlayerScore = NULL;

//Win Window fonts
TTF_Font *System::Fonts::WinWindowNavigationHints = NULL;
TTF_Font *System::Fonts::WinWindowTitle = NULL;
TTF_Font *System::Fonts::WinWindowTopPlayers = NULL;
TTF_Font *System::Fonts::WinWindowPlayerScore = NULL;

//Rank list fonts
TTF_Font *System::Fonts::RankListNavigationHints = NULL;
TTF_Font *System::Fonts::RankListTitle = NULL;

//Game fonts
TTF_Font *System::Fonts::PlayerScore = NULL;
TTF_Font *System::Fonts::GameLevel = NULL;
TTF_Font *System::Fonts::PlayerLivesLeft = NULL;

//Start window fonts
TTF_Font *System::Fonts::StartWindowTitle = NULL;

//Name selection window fonts
TTF_Font *System::Fonts::NameSelectionWindowTitle = NULL;
TTF_Font *System::Fonts::NameSelectionWindowInstructions = NULL;

SDL_Texture *System::Textures::AliensAlive = NULL;
SDL_Texture *System::Textures::AliensDead = NULL;
SDL_Texture *System::Textures::UFO = NULL;

SDL_Texture *System::Textures::Bullets = NULL;

SDL_Texture *System::Textures::PlayerAlive = NULL;
SDL_Texture *System::Textures::PlayerDead = NULL;

SDL_Texture *System::Textures::Background = NULL;

SDL_Texture *System::Textures::Border = NULL;

SDL_Texture *System::Textures::BarrierTopLeft = NULL;
SDL_Texture *System::Textures::BarrierTopMiddle = NULL;
SDL_Texture *System::Textures::BarrierTopRight = NULL;
SDL_Texture *System::Textures::BarrierCenterLeft = NULL;
SDL_Texture *System::Textures::BarrierCenterMiddle = NULL;
SDL_Texture *System::Textures::BarrierCenterRight = NULL;
SDL_Texture *System::Textures::BarrierBottomLeft = NULL;
SDL_Texture *System::Textures::BarrierBottomMiddle = NULL;
SDL_Texture *System::Textures::BarrierBottomRight = NULL;

SDL_Texture *System::Textures::letters[ALPHABET_SIZE];

string System::letters[ALPHABET_SIZE];
SDL_Rect System::letterRect[ALPHABET_SIZE];

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
    for(unsigned i = 0; i < ALPHABET_SIZE; i++)
    {
        TTF_Font *tmpFont = TTF_OpenFont("Resources/Fonts/invaders.ttf", 60);
        System::Textures::letters[i] = System::CreateTextTexture(System::letters[i] + " ", tmpFont, color);
        System::letterRect[i].w = System::GetSurfaceWidth();
        System::letterRect[i].h = System::GetSurfaceHeight();
        System::letterRect[i].x = 0;
        System::letterRect[i].y = 0;
        TTF_CloseFont(tmpFont);
    }
}
User System::Users::Current;

SDL_Texture *System::CreateTexture(std::string filePath)
{
    SDL_Surface *tempSurface = IMG_Load(filePath.c_str());

    SDL_Texture *texture = SDL_CreateTextureFromSurface(System::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
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
    //Destroy the used fonts
    TTF_CloseFont(System::Fonts::GameOverMenuNavigationHints);
    TTF_CloseFont(System::Fonts::GameOverMenuTitle);
    TTF_CloseFont(System::Fonts::GameOverMenuTopPlayers);
    TTF_CloseFont(System::Fonts::GameOverMenuPlayerScore);
    TTF_CloseFont(System::Fonts::WinWindowNavigationHints);
    TTF_CloseFont(System::Fonts::WinWindowTitle);
    TTF_CloseFont(System::Fonts::WinWindowTopPlayers);
    TTF_CloseFont(System::Fonts::WinWindowPlayerScore);
    TTF_CloseFont(System::Fonts::RankListNavigationHints);
    TTF_CloseFont(System::Fonts::RankListTitle);
    TTF_CloseFont(System::Fonts::PlayerScore);
    TTF_CloseFont(System::Fonts::GameLevel);
    TTF_CloseFont(System::Fonts::PlayerLivesLeft);
    TTF_CloseFont(System::Fonts::StartWindowTitle);
    TTF_CloseFont(System::Fonts::NameSelectionWindowTitle);
    TTF_CloseFont(System::Fonts::NameSelectionWindowInstructions);

    //Destroy the used textures
    SDL_DestroyTexture(System::Textures::AliensAlive);
    SDL_DestroyTexture(System::Textures::AliensDead);
    SDL_DestroyTexture(System::Textures::UFO);
    SDL_DestroyTexture(System::Textures::Bullets);
    SDL_DestroyTexture(System::Textures::PlayerAlive);
    SDL_DestroyTexture(System::Textures::PlayerDead);
    SDL_DestroyTexture(System::Textures::Background);
    SDL_DestroyTexture(System::Textures::Border);
    SDL_DestroyTexture(System::Textures::BarrierTopLeft);
    SDL_DestroyTexture(System::Textures::BarrierTopMiddle);
    SDL_DestroyTexture(System::Textures::BarrierTopRight);
    SDL_DestroyTexture(System::Textures::BarrierCenterLeft);
    SDL_DestroyTexture(System::Textures::BarrierCenterMiddle);
    SDL_DestroyTexture(System::Textures::BarrierCenterRight);
    SDL_DestroyTexture(System::Textures::BarrierBottomLeft);
    SDL_DestroyTexture(System::Textures::BarrierBottomMiddle);
    SDL_DestroyTexture(System::Textures::BarrierBottomRight);
    for(unsigned i = 0; i < ALPHABET_SIZE; i++)
    {
        SDL_DestroyTexture(System::Textures::letters[i]);
    }

    SDL_DestroyRenderer(System::renderer);
    SDL_DestroyWindow(System::window);
}
