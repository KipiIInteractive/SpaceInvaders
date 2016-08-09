#ifndef SOUNDMANAGER_H_INCLUDED
#define SOUNDMANAGER_H_INCLUDED

#include <SDL2/SDL_mixer.h>
#include <iostream>

class SoundManager
{
    public:
        enum Sounds
        {
            Shoot,
            AlienKilled,
            Explosion,
            BackgroundMusic
        };

        static void Init();
        static void Close();

        static void Play(int sound);

    private:
        static Mix_Chunk *shoot;
        static Mix_Chunk *alienKilled;
        static Mix_Chunk *explosion;
        static Mix_Music *backgroundMusic;
};

#endif // SOUNDMANAGER_H_INCLUDED
