#include "pins.h"
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

extern Adafruit_PWMServoDriver pwm ;

#define BASE_CH 0
#define SHOULDER_CH 1
#define ELBOW_CH 2
#define GRIPPER_CH 3

#define base_cw 135
#define base_ccw 45
#define stop_base 90


#define SHOULDER_MIN 45
#define SHOULDER_MAX 135

#define ELBOW_MIN 30
#define ELBOW_MAX 150

#define GRIPPER_MIN 50
#define GRIPPER_MAX 130


// ================= SERVO MAP =================
#define SERVOMIN 150
#define SERVOMAX 600

#define STEP 2

int angleToPulse(int angle, int minP, int maxP);
void moveBase(int dir);
void moveShoulder(int dir);
void moveElbow(int dir);
void moveGripper(int dir);
void stopBase();