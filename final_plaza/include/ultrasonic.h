#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#define sound_speed 0.0343
#define threshold 18

void ultrasonic_setup() ;
float read_ultra(int trig, int echo);
float ultrasonic_front();
float ultrasonic_right();
float ultrasonic_left();


#endif