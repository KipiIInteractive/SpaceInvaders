#ifndef SOUNDMANAGER_H_INCLUDED
#define SOUNDMANAGER_H_INCLUDED

#include <SDL_mixer.h>
#include <iostream>

class SoundManager
{
    public:
        enum Sounds
        {
            Shoot,
            KillAlien,
            Explode,
            BackgroundMusic
        };

        static void Init();
        static void Close();

        static void Play(int sound);

    private:
        static Mix_Chunk *shoot;
        static Mix_Chunk *kill_alien;
        static Mix_Chunk *explode;
        static Mix_Music *background_music;
};

#endif // SOUNDMANAGER_H_INCLUDED
