/*
 * Start with the constructor
 * then the forward function and then move funtion
 * this is a down up design approach
 * */
#include <iostream>
#include "robot.h"
#define DT 1
using namespace std;

Robot::Robot(int x_start, int y_start, float orientation, int rad, SDL_Color col)
{

    velocity.v=0.0f;
    velocity.phi=0.0f;
    pose.x=x_start;
    pose.y=y_start;
    pose.phi=orientation;
    radius=rad;
    color=col;
}

void Robot::move(uint8_t *state ,Eigen::VectorXf &control){

    control(0);
    control(1);
    if(state[SDL_SCANCODE_RIGHT]){

        printf("rotate right");
        rotateRight(control);
    }
    if(state[SDL_SCANCODE_LEFT]){

        printf("rotate left");
        rotateLeft(control);
    }
    if(state[SDL_SCANCODE_UP]){

        printf("move forward");
        forward(control);
    }
    if(state[SDL_SCANCODE_DOWN]){

        printf("move backward");
        backward(control);
    }

}
void Robot::forward(Eigen::VectorXf &control){

    velocity.v=1*DT;
    control(0)=velocity.v;
    pose.x+=velocity.v*cos(pose.phi);
    pose.y+=velocity.v*sin(pose.phi);
    printf("control %f ,pose.x %f pose.y %f\n",control(0),pose.x,pose.y);

}

void Robot::backward(Eigen::VectorXf &control){

    velocity.v= -1*DT;
    control(0)=velocity.v;
    pose.x+=velocity.v*cos(pose.phi);
    pose.y+=velocity.v*sin(pose.phi);
    printf("backward control %f pose.phi %f ,pose.x %f pose.y %f\n",control(0),pose.phi,pose.x,pose.y);


}
void Robot::rotateLeft(Eigen::VectorXf &control){

      control(1)=0.0f;
      velocity.phi= -DT*2*M_PI/360;
      control(1)=velocity.phi;
      pose.phi+=velocity.phi;
      printf("rotate left control %f pose.phi %f,pose.x %f pose.y %f\n",control(1),pose.phi,pose.x,pose.y);


}

void Robot::rotateRight(Eigen::VectorXf &control){

      velocity.phi=DT*2*M_PI/360;
      control(1)=velocity.phi;
      pose.phi+=velocity.phi;
      printf("rotate left control %f pose.phi %f,pose.x %f pose.y %f\n",control(1),pose.phi,pose.x,pose.y);

}

Robot::~Robot(){

}
