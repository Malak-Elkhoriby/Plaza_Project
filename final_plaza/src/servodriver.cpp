#include "servodriver.h"

// ================= OBJECT =================
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// ================= POSITIONS =================
int shoulderPos = 90;
int elbowPos = 90;
int gripperPos = 90;

// ================= HELPERS =================
int angleToPulse(int angle, int minP, int maxP) {
  return map(angle, 0, 180, minP, maxP);
}

// ================= BASE =================
void moveBase(int dir) {
  if (dir == 1) {
    pwm.setPWM(BASE_CH, 0, angleToPulse(base_cw, SERVOMIN, SERVOMAX));
  }
  else if (dir == -1) {
    pwm.setPWM(BASE_CH, 0, angleToPulse(base_ccw, SERVOMIN, SERVOMAX));
  }
  else {
    pwm.setPWM(BASE_CH, 0, angleToPulse(stop_base, SERVOMIN, SERVOMAX));
  }
}

void stopBase() {
  pwm.setPWM(BASE_CH, 0, angleToPulse(stop_base, SERVOMIN, SERVOMAX));
}

// ================= SHOULDER =================
void moveShoulder(int dir) {
  shoulderPos += dir * STEP;

  if (shoulderPos > SHOULDER_MAX) shoulderPos = SHOULDER_MAX;
  if (shoulderPos < SHOULDER_MIN) shoulderPos = SHOULDER_MIN;

  pwm.setPWM(SHOULDER_CH, 0,
             angleToPulse(shoulderPos, SERVOMIN, SERVOMAX));
}

// ================= ELBOW =================
void moveElbow(int dir) {
  elbowPos += dir * STEP;

  if (elbowPos > ELBOW_MAX) elbowPos = ELBOW_MAX;
  if (elbowPos < ELBOW_MIN) elbowPos = ELBOW_MIN;

  pwm.setPWM(ELBOW_CH, 0,
             angleToPulse(elbowPos, SERVOMIN, SERVOMAX));
}

// ================= GRIPPER =================
void moveGripper(int dir) {
  gripperPos += dir * STEP;

  if (gripperPos > GRIPPER_MAX) gripperPos = GRIPPER_MAX;
  if (gripperPos < GRIPPER_MIN) gripperPos = GRIPPER_MIN;

  pwm.setPWM(GRIPPER_CH, 0,
             angleToPulse(gripperPos, SERVOMIN, SERVOMAX));
}