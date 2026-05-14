#ifndef MOTOR_H
#define MOTOR_H

#include "pins.h"


    #define max_speed 255
    #define default_speed 150
    #define PWM_FREQ 2000
    #define PWM_RES 8

    #define CH_L1 0
    #define CH_L2 1
    #define CH_R1 2
    #define CH_R2 3

void updateSpeed(int newSpeed);
void setSpeed();
void setDirection();
void setup_Motor() ;
void move_forward();
void move_backward();
void turn_left();
void turn_right();
void stop_motors();
#endif