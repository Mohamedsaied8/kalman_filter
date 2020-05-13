#include <stdio.h>
#include <SDL2/SDL_render.h> //https://wiki.libsdl.org/
#include <eigen3/Eigen/Dense> //https://eigen.tuxfamily.org/dox/group__TutorialMapClass.html
#include <vector>
#include <SDL2/SDL.h>
typedef struct{
float x;
float y;
float phi;
}Pose;

typedef struct{
float v;
float phi;
}Velocity;

class Robot{


public:

//constructor
//inputs x position , y position , orientation, radius of circle robot,color)
Robot(int x_start,int y_start,float orientation,int rad,SDL_Color col);
Velocity velocity;
Pose pose;
int radius;
SDL_Color color;
//destructor
~Robot();

//function prototypes
void move(uint8_t*,Eigen::VectorXf &control);
//forward 
void forward(Eigen::VectorXf &control);
void backward(Eigen::VectorXf &control);
void rotateLeft(Eigen::VectorXf &cotrol);
void rotateRight(Eigen::VectorXf &control);
void setpose(float x,float y,float phi);



private:
//nothing is private



};
