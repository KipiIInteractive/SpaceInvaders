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
            KillAlien
        };

        static void Init();
        static void Close();

        static void Play(int sound);

    private:
        static Mix_Chunk *shoot;
        static Mix_Chunk *kill_alien;
};

#endif // SOUNDMANAGER_H_INCLUDED
