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
<<<<<<< HEAD
            KillAlien
=======
            KillAlien,
            Explode,
            BackgroundMusic
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
        };

        static void Init();
        static void Close();

        static void Play(int sound);

    private:
        static Mix_Chunk *shoot;
        static Mix_Chunk *kill_alien;
<<<<<<< HEAD
=======
        static Mix_Chunk *explode;
        static Mix_Music *background_music;
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
};

#endif // SOUNDMANAGER_H_INCLUDED
