#include "SoundManager.h"

Mix_Chunk *SoundManager::shoot = NULL;
Mix_Chunk *SoundManager::kill_alien = NULL;

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

    Mix_Volume(MIX_DEFAULT_CHANNELS, MIX_MAX_VOLUME / 10);
}

void SoundManager::Play(int sound)
{
    if(sound == SoundManager::Sounds::Shoot)
        Mix_PlayChannel(-1, SoundManager::shoot, 0);
}

void SoundManager::Close()
{
    Mix_FreeChunk(SoundManager::shoot);
}
