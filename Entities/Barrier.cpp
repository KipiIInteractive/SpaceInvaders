#include "Barrier.h"
#include "../Game/Game.h"

Barrier::Barrier(int pos_x, int pos_y)
{
    this->rect.w = Game::Pannel.w / 11;
    this->rect.h = this->rect.w / 1.5;
    this->rect.x = pos_x;
    this->rect.y = pos_y;

    this->top_left = {pos_x, pos_y, this->rect.w / 3, this->rect.h / 3};
    this->top_middle = {pos_x + this->top_left.w, pos_y, this->rect.w / 3, this->rect.h / 3};
    this->top_right = {pos_x + this->top_middle.w * 2, pos_y, this->rect.w / 3, this->rect.h / 3};

    this->center_left = {pos_x, pos_y + this->top_left.h, this->rect.w / 3, this->rect.h / 3};
    this->center_middle = {pos_x + this->center_left.w, pos_y + this->top_middle.h, this->rect.w / 3, this->rect.h / 3};
    this->center_right = {pos_x + this->center_middle.w * 2, pos_y + this->top_middle.h, this->rect.w / 3, this->rect.h / 3};

    this->bottom_left = {pos_x, pos_y + this->center_left.h * 2, this->rect.w / 3, this->rect.h / 3};
    this->bottom_middle = {pos_x + this->bottom_left.w, pos_y + this->center_left.h * 2, this->rect.w / 3, this->rect.h / 3};
    this->bottom_right = {pos_x + this->bottom_left.w * 2, pos_y + this->center_left.h * 2, this->rect.w / 3, this->rect.h / 3};


    //Initialize the bottom-left corner state
    this->bottom_left_texture = System::Textures::Barrier_Bottom_Left;
    SDL_QueryTexture(this->bottom_left_texture, NULL, NULL, &this->bottom_left_state.w, &this->bottom_left_state.h);
    this->bottom_left_state.w /= 4;
    this->bottom_left_state.x = 0;
    this->bottom_left_state.y = 0;
    this->hits_taken_bottom_left = 0;

    //Initialize the bottom-right corner state
    this->bottom_right_texture = System::Textures::Barrier_Bottom_Right;
    SDL_QueryTexture(this->bottom_right_texture, NULL, NULL, &this->bottom_right_state.w, &this->bottom_right_state.h);
    this->bottom_right_state.w /= 4;
    this->bottom_right_state.x = 0;
    this->bottom_right_state.y = 0;
    this->hits_taken_bottom_right = 0;

    //Initialize the bottom-middle block state
    this->bottom_middle_texture = System::Textures::Barrier_Bottom_Middle;
    SDL_QueryTexture(this->bottom_middle_texture, NULL, NULL, &this->bottom_middle_state.w, &this->bottom_middle_state.h);
    this->bottom_middle_state.w /= 4;
    this->bottom_middle_state.x = 0;
    this->bottom_middle_state.y = 0;
    this->hits_taken_bottom_middle = 0;

    //Initialize the center-left corner state
    this->center_left_texture = System::Textures::Barrier_Center_Left;
    SDL_QueryTexture(this->center_left_texture, NULL, NULL, &this->center_left_state.w, &this->center_left_state.h);
    this->center_left_state.w /= 4;
    this->center_left_state.x = 0;
    this->center_left_state.y = 0;
    this->hits_taken_center_left = 0;

    //Initialize the center-middle block state
    this->center_middle_texture = System::Textures::Barrier_Center_Middle;
    SDL_QueryTexture(this->center_middle_texture, NULL, NULL, &this->center_middle_state.w, &this->center_middle_state.h);
    this->center_middle_state.w /= 4;
    this->center_middle_state.x = 0;
    this->center_middle_state.y = 0;
    this->hits_taken_center_middle = 0;

    //Initialize the center-right corner state
    this->center_right_texture = System::Textures::Barrier_Center_Right;
    SDL_QueryTexture(this->center_right_texture, NULL, NULL, &this->center_right_state.w, &this->center_right_state.h);
    this->center_right_state.w /= 4;
    this->center_right_state.x = 0;
    this->center_right_state.y = 0;
    this->hits_taken_center_right = 0;

    //Initialize the top-left corner state
    this->top_left_texture = System::Textures::Barrier_Top_Left;
    SDL_QueryTexture(this->top_left_texture, NULL, NULL, &this->top_left_state.w, &this->top_left_state.h);
    this->top_left_state.w /= 4;
    this->top_left_state.x = 0;
    this->top_left_state.y = 0;
    this->hits_taken_top_left = 0;

    //Initialize the top-middle block state
    this->top_middle_texture = System::Textures::Barrier_Top_Middle;
    SDL_QueryTexture(this->top_middle_texture, NULL, NULL, &this->top_middle_state.w, &this->top_middle_state.h);
    this->top_middle_state.w /= 4;
    this->top_middle_state.x = 0;
    this->top_middle_state.y = 0;
    this->hits_taken_top_middle = 0;

    //Initialize the top-right corner state
    this->top_right_texture = System::Textures::Barrier_Top_Right;
    SDL_QueryTexture(this->top_right_texture, NULL, NULL, &this->top_right_state.w, &this->top_right_state.h);
    this->top_right_state.w /= 4;
    this->top_right_state.x = 0;
    this->top_right_state.y = 0;
    this->hits_taken_top_right = 0;
}

Barrier::~Barrier()
{
    delete(&this->rect);
    delete(&this->top_left);
    delete(&this->top_middle);
    delete(&this->top_right);
    delete(&this->center_left);
    delete(&this->center_middle);
    delete(&this->center_right);
    delete(&this->bottom_left);
    delete(&this->bottom_middle);
    delete(&this->bottom_right);

    delete(&this->top_left_state);
    delete(&this->top_right_state);
    delete(&this->top_middle_state);
    delete(&this->center_left_state);
    delete(&this->center_right_state);
    delete(&this->center_middle_state);
    delete(&this->bottom_left_state);
    delete(&this->bottom_right_state);
    delete(&this->bottom_middle_state);

    SDL_DestroyTexture(this->texture);
}

void Barrier::SetX(int x) { this->rect.x = x; }
int Barrier::GetX() { return this->rect.x; }

void Barrier::SetY(int y) { this->rect.y = y; }
int Barrier::GetY() { return this->rect.y; }

void Barrier::SetWidth(int w) { this->rect.w = w; }
int Barrier::GetWidth() { return this->rect.w; }

void Barrier::SetHeigth(int h) { this->rect.h = h; }
int Barrier::GetHeigth() { return this->rect.h; }

void Barrier::Update()
{
    this->top_left_state.x = this->top_left_state.w * hits_taken_top_left;
    if(hits_taken_top_left >= 4)
    {
        this->top_left.x = 0; this->top_left.y = 0;
        this->top_left.w = 0; this->top_left.h = 0;
    }

    this->top_middle_state.x = this->top_middle_state.w * hits_taken_top_middle;
    if(hits_taken_top_middle >= 4)
    {
        this->top_middle.x = 0; this->top_middle.y = 0;
        this->top_middle.w = 0; this->top_middle.h = 0;
    }

    this->top_right_state.x = this->top_right_state.w * hits_taken_top_right;
    if(hits_taken_top_right >= 4)
    {
        this->top_right.x = 0; this->top_right.y = 0;
        this->top_right.w = 0; this->top_right.h = 0;
    }

    this->center_left_state.x = this->center_left_state.w * hits_taken_center_left;
    if(hits_taken_center_left >= 4)
    {
        this->center_left.x = 0; this->center_left.y = 0;
        this->center_left.w = 0; this->center_left.h = 0;
    }

    this->center_middle_state.x = this->center_middle_state.w * hits_taken_center_middle;
    if(hits_taken_center_middle >= 4)
    {
        this->center_middle.x = 0; this->center_middle.y = 0;
        this->center_middle.w = 0; this->center_middle.h = 0;
    }

    this->center_right_state.x = this->center_right_state.w * hits_taken_center_right;
    if(hits_taken_center_right >= 4)
    {
        this->center_right.x = 0; this->center_right.y = 0;
        this->center_right.w = 0; this->center_right.h = 0;
    }

    this->bottom_left_state.x = this->bottom_left_state.w * hits_taken_bottom_left;
    if(hits_taken_bottom_left >= 4)
    {
        this->bottom_left.x = 0; this->bottom_left.y = 0;
        this->bottom_left.w = 0; this->bottom_left.h = 0;
    }

    this->bottom_middle_state.x = this->bottom_middle_state.w * hits_taken_bottom_middle;
    if(hits_taken_bottom_middle >= 4)
    {
        this->bottom_middle.x = 0; this->bottom_middle.y = 0;
        this->bottom_middle.w = 0; this->bottom_middle.h = 0;
    }

    this->bottom_right_state.x = this->bottom_right_state.w * hits_taken_bottom_right;
    if(hits_taken_bottom_right >= 4)
    {
        this->bottom_right.x = 0; this->bottom_right.y = 0;
        this->bottom_right.w = 0; this->bottom_right.h = 0;
    }
}

void Barrier::Render()
{
    SDL_RenderCopy(System::renderer, this->bottom_left_texture, &this->bottom_left_state, &this->bottom_left);
    SDL_RenderCopy(System::renderer, this->bottom_right_texture, &this->bottom_right_state, &this->bottom_right);
    SDL_RenderCopy(System::renderer, this->bottom_middle_texture, &this->bottom_middle_state, &this->bottom_middle);
    SDL_RenderCopy(System::renderer, this->center_left_texture, &this->center_left_state, &this->center_left);
    SDL_RenderCopy(System::renderer, this->center_middle_texture, &this->center_middle_state, &this->center_middle);
    SDL_RenderCopy(System::renderer, this->center_right_texture, &this->center_right_state, &this->center_right);
    SDL_RenderCopy(System::renderer, this->top_left_texture, &this->top_left_state, &this->top_left);
    SDL_RenderCopy(System::renderer, this->top_middle_texture, &this->top_middle_state, &this->top_middle);
    SDL_RenderCopy(System::renderer, this->top_right_texture, &this->top_right_state, &this->top_right);
}
