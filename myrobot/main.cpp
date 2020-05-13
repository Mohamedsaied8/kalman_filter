#include "robot.h"
#include "cstring"
#include <iostream>
#include "landmark.h"
#include <SDL2/SDL.h>
#define XSTART 100
#define YSTART 100

#define WWIDTH 640
#define WHEIGHT 480
#define DT 1
using namespace std;
vector<Landmark_map> createLandmarks()
{
    vector<Landmark_map> lmks;

    SDL_Color color_red = { 255,  0, 0,  255 };
    SDL_Color color_green = {.r = 0, .g = 255, .b = 0, .a = 255 };
    SDL_Color color_blue = {.r = 0, .g = 0, .b = 255, .a = 255 };
      SDL_Color color_purple = {.r = 255, .g = 0, .b = 255, .a = 255};

   lmks.push_back( Landmark_map(300.0,300.0,color_red));
    Landmark_map lmk1(124.0,478.0,color_blue);
   lmks.push_back(lmk1 );
    lmks.push_back( Landmark_map(214.,312.,color_purple));

    return lmks;
}

int main(){

    if (SDL_Init(SDL_INIT_VIDEO) != 0){
          cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
          return 1;
      }

    SDL_Window *win = SDL_CreateWindow("Robot Program", XSTART, YSTART, WWIDTH, WHEIGHT, SDL_WINDOW_SHOWN);
    if (win == NULL){
        cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL){
        SDL_DestroyWindow(win);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    //First clear the renderer
          SDL_RenderClear(ren);

          //Draw the texture
          SDL_SetRenderDrawColor(ren, 200, 200, 255, 255);

          SDL_RenderClear(ren); // fill the scene with white

          SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);

          // update renderer
          SDL_RenderPresent(ren);

          // move robot
          SDL_PumpEvents();


          SDL_Color c;
          c.r=255;
          c.g=0;
          c.b=255;
          Eigen::VectorXf x(3);

     x<< 200., 200., 0.0;
    Robot automobile(x(0),x(1),0,20,c);

    while (1) {
        Landmark_map map(300.0,300.0,c);
        map.render(ren);
        const Uint8 *key_pressed = SDL_GetKeyboardState(NULL);
          automobile.move((uint8_t*)key_pressed, x);

    }

return 0;
}
