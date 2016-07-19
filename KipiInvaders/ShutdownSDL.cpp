#include <SDL_mixer.h>
#include <SDL_image.h>
#include "ShutdownSDL.h"

void ShutdownSDL::shutdown() {
    TTF_CloseFont(System::font);

    SDL_DestroyRenderer(System::renderer);
    SDL_DestroyWindow(System::window);

    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
