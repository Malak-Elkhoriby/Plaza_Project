#include "pins.h"
#include "motor.h"
#include "ultrasonic.h"
#include "servodriver.h"
#include <PS4Controller.h>

// ================= GLOBAL =================
#define auto 1 
#define manual 0
int mode_state  ;
bool autoMode ;
static bool lastOpt = false;
static bool lastSha = false;

// ================= SETUP =================

void setup() {

  Serial.begin(115200);
  delay(2000);

  Serial.println("BOOT");

  PS4.begin("28:56:2F:49:C2:9C");
  Serial.println("WAITING");

  setup_Motor();
  ultrasonic_setup();

  Wire.begin();
  pwm.begin();
  pwm.setPWMFreq(50);

  stop_motors();
  stopBase();
}

// ================= LOOP =================

void loop() {

  bool isConnected = PS4.isConnected();

  if (!isConnected) {
    Serial.println("WAITING...");
    delay(300);
    return;
  }

  Serial.println("CONNECTED");

  bool opt = PS4.Options();
  bool sha = PS4.Share();

  if (opt && !lastOpt) autoMode = false;
  if (sha && !lastSha) autoMode = true;

  lastOpt = opt;
  lastSha = sha;
  bool share = PS4.Share();
static bool lastShare = false;

if (share && !lastShare) {
  autoMode = !autoMode;  // يعكس الحالة
  Serial.print("Mode switched to: ");
  Serial.println(autoMode ? "AUTO" : "MANUAL");
}

lastShare = share;

 if(PS4.Share())
  {
 mode_state = auto ;
  }
  else{
    mode_state = manual ;
  }*/
 /*bool share = PS4.Share();
 static bool lastshare = false ;
 if(share && !lastshare)
 autoMode = !autoMode ;

  // AUTO
  if (autoMode) {

    if (ultrasonic_front() < threshold) {

      if (ultrasonic_right() > threshold) turn_right();
      else if (ultrasonic_left() > threshold) turn_left();
      else stop_motors();

    } else move_forward();
  }

  // MANUAL
  else {

    int lx = PS4.LStickX();
    int ly = PS4.LStickY();

    int speed = map(abs(ly), 0, 127, 0, 255);
    updateSpeed(speed);

    if (ly > 20) move_forward();
    else if (ly < -20) move_backward();
    else if (lx > 20) turn_right();
    else if (lx < -20) turn_left();
    else stop_motors();

    int ry = PS4.RStickY();

    if (ry > 20) moveBase(1);
    else if (ry < -20) moveBase(-1);
    else moveBase(0);

    if (PS4.Triangle())
   { Serial.println("tri is pressed");

    moveShoulder(1);}
    if (PS4.Square()){
    moveShoulder(-1);
    Serial.println("Square is pressed");
    } 
    if (PS4.Cross()) moveElbow(1);
    if (PS4.Circle()) moveElbow(-1);
    if (PS4.R1()) moveGripper(1);
    if (PS4.L1()) moveGripper(-1);
  }

  delay(100);
}

