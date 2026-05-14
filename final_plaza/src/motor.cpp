#include "pins.h"
#include "motor.h"

int currentSpeed = default_speed;

void updateSpeed(int newSpeed) {
  if (newSpeed > max_speed) newSpeed = max_speed;
  if (newSpeed < 0) newSpeed = 0;
  currentSpeed = newSpeed;
}

void setSpeed() {
  ledcWrite(CH_L1, currentSpeed);
  ledcWrite(CH_L2, currentSpeed);
  ledcWrite(CH_R1, currentSpeed);
  ledcWrite(CH_R2, currentSpeed);
}

void setDirection(bool l1, bool l2, bool r1, bool r2) {
  digitalWrite(motor_l1_in1, l1);
  digitalWrite(motor_l1_in2, l2);
  digitalWrite(motor_l2_in1, l1);
  digitalWrite(motor_l2_in2, l2);
  digitalWrite(motor_r1_in1, r1);
  digitalWrite(motor_r1_in2, r2);
  digitalWrite(motor_r2_in1, r1);
  digitalWrite(motor_r2_in2, r2);
}

void setup_Motor() {
  ledcSetup(CH_L1, PWM_FREQ, PWM_RES);
  ledcSetup(CH_L2, PWM_FREQ, PWM_RES);
  ledcSetup(CH_R1, PWM_FREQ, PWM_RES);
  ledcSetup(CH_R2, PWM_FREQ, PWM_RES);

  ledcAttachPin(motor_l1_en, CH_L1);
  ledcAttachPin(motor_l2_en, CH_L2);
  ledcAttachPin(motor_r1_en, CH_R1);
  ledcAttachPin(motor_r2_en, CH_R2);

  pinMode(motor_l1_in1, OUTPUT);
  pinMode(motor_l1_in2, OUTPUT);
  pinMode(motor_l2_in1, OUTPUT);
  pinMode(motor_l2_in2, OUTPUT);
  pinMode(motor_r1_in1, OUTPUT);
  pinMode(motor_r1_in2, OUTPUT);
  pinMode(motor_r2_in1, OUTPUT);
  pinMode(motor_r2_in2, OUTPUT);
}

void move_forward() { setDirection(HIGH, LOW, HIGH, LOW); setSpeed(); }
void move_backward(){ setDirection(LOW, HIGH, LOW, HIGH); setSpeed(); }
void turn_left()    { setDirection(LOW, HIGH, HIGH, LOW); setSpeed(); }
void turn_right()   { setDirection(HIGH, LOW, LOW, HIGH); setSpeed(); }

void stop_motors() {
  ledcWrite(CH_L1, 0);
  ledcWrite(CH_L2, 0);
  ledcWrite(CH_R1, 0);
  ledcWrite(CH_R2, 0);
}
