#ifndef _LANDMARK_H
#define _LANDMARK_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

typedef struct Position{
float x;
float y;
}Position;

class Landmark_map{


public:

Landmark_map(float x,float y,SDL_Color color);
~Landmark_map();
void render(SDL_Renderer * ren);

Position pose;
SDL_Color id;

};

#endif
