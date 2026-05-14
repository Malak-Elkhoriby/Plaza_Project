#include "pins.h"
#include "ultrasonic.h"

void ultrasonic_setup() {
  pinMode(us_f_trig, OUTPUT);
  pinMode(us_r_trig, OUTPUT);
  pinMode(us_l_trig, OUTPUT);

  pinMode(us_f_echo, INPUT);
  pinMode(us_r_echo, INPUT);
  pinMode(us_l_echo, INPUT);
}

float read_ultra(int trig, int echo) {
  digitalWrite(trig, LOW); delayMicroseconds(2);
  digitalWrite(trig, HIGH); delayMicroseconds(10);
  digitalWrite(trig, LOW);
  return (pulseIn(echo, HIGH) * sound_speed) / 2;
}

float ultrasonic_front() { return read_ultra(us_f_trig, us_f_echo); }
float ultrasonic_right() { return read_ultra(us_r_trig, us_r_echo); }
float ultrasonic_left()  { return read_ultra(us_l_trig, us_l_echo); }
