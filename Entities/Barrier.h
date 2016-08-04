#ifndef BARRIER_H_INCLUDED
#define BARRIER_H_INCLUDED

#include <SDL.h>
#include "../System/System.h"

class Barrier
{
    public:
<<<<<<< HEAD
        Barrier(std::string texturePath, int pos_x, int pos_y);
=======
        Barrier(int pos_x, int pos_y);
>>>>>>> 33f3dd5... Made the game to be reachable without account. Load all the textures at
        ~Barrier();

        void SetX(int x); int GetX();
        void SetY(int y); int GetY();
        void SetWidth(int w); int GetWidth();
        void SetHeigth(int h); int GetHeigth();

        void Update();
        void Render();

        SDL_Rect top_left;
        SDL_Rect top_left_state;
        int hits_taken_top_left;
        SDL_Texture *top_left_texture;

        SDL_Rect top_middle;
        SDL_Rect top_middle_state;
        int hits_taken_top_middle;
        SDL_Texture *top_middle_texture;

        SDL_Rect top_right;
        SDL_Rect top_right_state;
        int hits_taken_top_right;
        SDL_Texture *top_right_texture;

        SDL_Rect center_left_state;
        SDL_Rect center_left;
        int hits_taken_center_left;
        SDL_Texture *center_left_texture;

        SDL_Rect center_middle;
        SDL_Rect center_middle_state;
        int hits_taken_center_middle;
        SDL_Texture *center_middle_texture;

        SDL_Rect center_right;
        SDL_Rect center_right_state;
        int hits_taken_center_right;
        SDL_Texture *center_right_texture;

        SDL_Rect bottom_left;
        SDL_Rect bottom_left_state;
        int hits_taken_bottom_left;
        SDL_Texture *bottom_left_texture;

        SDL_Rect bottom_right;
        SDL_Rect bottom_right_state;
        int hits_taken_bottom_right;
        SDL_Texture *bottom_right_texture;

        SDL_Rect bottom_middle;
        SDL_Rect bottom_middle_state;
        int hits_taken_bottom_middle;
        SDL_Texture *bottom_middle_texture;

    private:
        SDL_Rect rect;
        SDL_Texture *texture;
};

#endif // BARRIER_H_INCLUDED
