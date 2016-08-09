#include "SoundManager.h"

Mix_Chunk *SoundManager::shoot = NULL;
Mix_Chunk *SoundManager::alienKilled = NULL;
Mix_Chunk *SoundManager::explosion = NULL;
Mix_Music *SoundManager::backgroundMusic = NULL;

void SoundManager::Init()
{
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) < 0) {
        std::cout << "Failed to open the audio. File: SoundManager.cpp/Init() \n" << Mix_GetError() << std::endl;
    }
    SoundManager::shoot = Mix_LoadWAV("Resources/Sounds/shoot.wav");
    if(SoundManager::shoot == NULL) {
        std::cout << "Failed to initialize shooting sound. File: SoundManager.cpp/Init()\n" << Mix_GetError() << std::endl;
    }
    SoundManager::alienKilled = Mix_LoadWAV("Resources/Sounds/kill_alien.wav");
    if(SoundManager::alienKilled == NULL) {
        std::cout << "Failed to initialize kill alien sound. File: SoundManager.cpp/Init()\n" << Mix_GetError() << std::endl;
    }
    SoundManager::explosion = Mix_LoadWAV("Resources/Sounds/explode.wav");
    if(SoundManager::explosion == NULL) {
        std::cout << "Failed to initialize explosion sound. File: SoundManager.cpp/Init()\n" << Mix_GetError() << std::endl;
    }
    SoundManager::backgroundMusic = Mix_LoadMUS("Resources/Sounds/background_music.wav");
    if(SoundManager::backgroundMusic == NULL) {
        std::cout << "Failed to initialize the music. File: SoundManager.cpp/Init()\n" << Mix_GetError() << std::endl;
    }
    // Sets the volume for the background music and each sound chunk
    int backgroundMusicVolumeDivisor = 20;
    int shootingSoundVolumeDivisor = 111;
    int alienGettingKilledSoundVolumeDivisor = 60;
    int explosionSoundVolumeDivisor = 30;
    Mix_VolumeMusic(MIX_MAX_VOLUME / backgroundMusicVolumeDivisor);
    Mix_VolumeChunk(SoundManager::shoot, MIX_MAX_VOLUME / shootingSoundVolumeDivisor);
    Mix_VolumeChunk(SoundManager::alienKilled, MIX_MAX_VOLUME / alienGettingKilledSoundVolumeDivisor);
    Mix_VolumeChunk(SoundManager::explosion, MIX_MAX_VOLUME / explosionSoundVolumeDivisor);
}

void SoundManager::Play(int sound)
{
    //Shoot
    if(sound == SoundManager::Sounds::Shoot) {
        Mix_PlayChannel(-1, SoundManager::shoot, 0);
    }
    //Kill alien
    if(sound == SoundManager::Sounds::AlienKilled) {
        Mix_PlayChannel(-1, SoundManager::alienKilled, 0);
    }
    //Explosion
    if(sound == SoundManager::Sounds::Explosion) {
        Mix_PlayChannel(-1, SoundManager::explosion, 0);
    }
    //Background music
    else if(sound == SoundManager::Sounds::BackgroundMusic)
    {
        if(!Mix_PlayingMusic()) {
            Mix_PlayMusic(SoundManager::backgroundMusic, -1);
        }
    }
}

void SoundManager::Close()
{
    Mix_FreeChunk(SoundManager::shoot);
    Mix_FreeChunk(SoundManager::explosion);
    Mix_FreeChunk(SoundManager::alienKilled);
    Mix_FreeMusic(SoundManager::backgroundMusic);
}
