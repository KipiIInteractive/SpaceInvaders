#include "SoundManager.h"

Mix_Chunk *SoundManager::shoot = NULL;
Mix_Chunk *SoundManager::kill_alien = NULL;
<<<<<<< HEAD
=======
Mix_Chunk *SoundManager::explode = NULL;
Mix_Music *SoundManager::background_music = NULL;
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at

void SoundManager::Init()
{
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) < 0)
        std::cout << "Failed to open the audio. File: SoundManager.cpp/Init() \n" << Mix_GetError() << std::endl;

    SoundManager::shoot = Mix_LoadWAV("Resources/Sounds/shoot.wav");
    if(SoundManager::shoot == NULL)
        std::cout << "Failed to initialize shooting sound. File: SoundManager.cpp/Init()\n" << Mix_GetError() << std::endl;

    SoundManager::kill_alien = Mix_LoadWAV("Resources/Sounds/kill_alien.wav");
    if(SoundManager::kill_alien == NULL)
        std::cout << "Failed to initialize kill alien sound. File: SoundManager.cpp/Init()\n" << Mix_GetError() << std::endl;

<<<<<<< HEAD
    Mix_Volume(MIX_DEFAULT_CHANNELS, MIX_MAX_VOLUME / 10);
=======
    SoundManager::explode = Mix_LoadWAV("Resources/Sounds/explode.wav");
    if(SoundManager::explode == NULL)
        std::cout << "Failed to initialize explosion sound. File: SoundManager.cpp/Init()\n" << Mix_GetError() << std::endl;

    SoundManager::background_music = Mix_LoadMUS("Resources/Sounds/background_music.wav");
    if(SoundManager::background_music == NULL)
        std::cout << "Failed to initialize the music. File: SoundManager.cpp/Init()\n" << Mix_GetError() << std::endl;

    Mix_VolumeMusic(MIX_MAX_VOLUME / 20);
    Mix_VolumeChunk(SoundManager::shoot, MIX_MAX_VOLUME / 111);
    Mix_VolumeChunk(SoundManager::kill_alien, MIX_MAX_VOLUME / 60);
    Mix_VolumeChunk(SoundManager::explode, MIX_MAX_VOLUME / 30);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
}

void SoundManager::Play(int sound)
{
<<<<<<< HEAD
    if(sound == SoundManager::Sounds::Shoot)
        Mix_PlayChannel(-1, SoundManager::shoot, 0);
=======
    //Shoot
    if(sound == SoundManager::Sounds::Shoot)
        Mix_PlayChannel(-1, SoundManager::shoot, 0);
    //Kill alien
    if(sound == SoundManager::Sounds::KillAlien)
        Mix_PlayChannel(-1, SoundManager::kill_alien, 0);
    //Explode
    if(sound == SoundManager::Sounds::Explode)
        Mix_PlayChannel(-1, SoundManager::explode, 0);

    //Background music
    else if(sound == SoundManager::Sounds::BackgroundMusic)
    {
        if(!Mix_PlayingMusic())
            Mix_PlayMusic(SoundManager::background_music, -1);
    }
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
}

void SoundManager::Close()
{
    Mix_FreeChunk(SoundManager::shoot);
<<<<<<< HEAD
=======
    Mix_FreeChunk(SoundManager::explode);
    Mix_FreeChunk(SoundManager::kill_alien);
    Mix_FreeMusic(SoundManager::background_music);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
}
