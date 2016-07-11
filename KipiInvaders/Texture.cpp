#include "Texture.h"

Texture::Texture() {
    _Texture = NULL;
    _THeight = 0;
    _TWidth = 0;
    _TText = "";
}

bool Texture::loadFromFile(string path) {
    SDL_Texture* finalTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL) {
        cout << IMG_GetError() << endl;
    }
    else {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0, 0));

        finalTexture = SDL_CreateTextureFromSurface(System::renderer, loadedSurface);
        if(finalTexture == NULL) {
            cout << SDL_GetError() << endl;
        }
        else {
            _THeight = loadedSurface->h;
            _TWidth = loadedSurface->w;
        }
        SDL_FreeSurface(loadedSurface);
    }
    _Texture = finalTexture;
    return (_Texture != NULL);
}

bool Texture::loadFromRenderedText(string textureText, SDL_Color textColor, TTF_Font* font) {
    //Dispose of previously loaded textures
    free();

    _TText = textureText;
    //Render passed string
    SDL_Surface* textSurface = NULL;
    if(font != NULL) {
        textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
    }
    else {
        textSurface = TTF_RenderText_Solid(System::font, textureText.c_str(), textColor);
    }
    if(textSurface == NULL) {
        cout << TTF_GetError() << endl;
    }
    else {
        _Texture = SDL_CreateTextureFromSurface(System::renderer, textSurface);
        if(_Texture == NULL) {
            cout << SDL_GetError() << endl;
        }
        else {
            //Get texture dimensions
            _TWidth = textSurface->w;
            _THeight = textSurface->h;
        }
        //Free old surface
        SDL_FreeSurface(textSurface);
    }
    return _Texture != NULL;
}

void Texture::setColor(SDL_Color color) {
    SDL_SetTextureColorMod(_Texture, color.r, color.g, color.b);
}

void Texture::setWidth(int w) {
    _TWidth = w;
}

void Texture::setHeight(int h) {
    _THeight = h;
}

int Texture::getHeight() {
    return _THeight;
}

int Texture::getWidth() {
    return _TWidth;
}

string Texture::getText() {
    return _TText;
}

void Texture::render(int x, int y, SDL_Rect* clip, SDL_RendererFlip flip, double angle, SDL_Point* center) {
    SDL_Rect renderQuad;
    renderQuad = {x, y, _TWidth, _THeight};
    if(clip != NULL && clip->w != 0 && clip->h != 0) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopyEx(System::renderer, _Texture, clip, &renderQuad, angle, center, flip);
}

void Texture::free() {
    SDL_DestroyTexture(_Texture);
}
