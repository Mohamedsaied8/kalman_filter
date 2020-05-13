#include "landmark.h"


Landmark_map::Landmark_map(float x,float y,SDL_Color color){

pose.x=x;
pose.y=y;
id=color;

}
Landmark_map::~Landmark_map(){

}
void Landmark_map::render(SDL_Renderer * ren)
{
    int32_t radius = 5;
    int32_t x = radius - 1;
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t err = tx - (radius << 1); // shifting bits left by 1 effectively
    // doubles the value. == tx - diameter

    int32_t int_pose_x = int(pose.x);
    int32_t int_pose_y = int(pose.y);




    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(ren, int_pose_x + x, int_pose_y - y);
        SDL_RenderDrawPoint(ren, int_pose_x + x, int_pose_y + y);
        SDL_RenderDrawPoint(ren, int_pose_x - x, int_pose_y - y);
        SDL_RenderDrawPoint(ren, int_pose_x - x, int_pose_y + y);
        SDL_RenderDrawPoint(ren, int_pose_x + y, int_pose_y - x);
        SDL_RenderDrawPoint(ren, int_pose_x + y, int_pose_y + x);
        SDL_RenderDrawPoint(ren, int_pose_x - y, int_pose_y - x);
        SDL_RenderDrawPoint(ren, int_pose_x - y, int_pose_y + x);

        if (err <= 0)
        {
            y++;
            err += ty;
            ty += 2;
        }
        if (err > 0)
        {
            x--;
            tx += 2;
            err += tx - (radius << 1);
        }
    }//while
}//render



