#include "Shared.h"
#include "Movement.h"
#include "Buzzer.h"
#include "Arm.h"
#include "LineFollower.h"
#include "Display.h"

void readBluethooth();
void handleCommand(int val);
void setup() {

  Serial.begin(115200);
  //Setup pins
  setupMotor();
  setupArm();
  setupLineFollower();
  setupDisplay();
  setupBuzzer();
}


void loop() {
  
   readBluethooth();
  
  delay(10);
}


void readBluethooth() {
  if (Serial.available() > 0) {
    int val = Serial.read();
    handleCommand(val);
  }
}

void handleCommand(int val) {
  Serial.println(val);
  switch (val) {
    case FOW:
      moveRobot(FORWARD);
      break;
    case BAK:
      moveRobot(BACKWARD);
      break;
    case RIT:
      turnRobot(RIGHT);
      break;
    case LFT:
      turnRobot(LEFT);
      break;

    case A_B_L:
      moveArmBase(LEFT);
      break;
    case A_B_R:
      moveArmBase(RIGHT);
      break;

    case A_J1_E:
      moveArmJoint(1, EXTEND);
      break;
    case A_J1_C:
      moveArmJoint(1, COLLAPSE);
      break;
    case A_J2_E:
      moveArmJoint(2, EXTEND);
      break;
    case A_J2_C:
      moveArmJoint(2, COLLAPSE);
      break;
    case A_J3_E:
      moveArmJoint(3, EXTEND);
      break;
    case A_J3_C:
      moveArmJoint(3, COLLAPSE);
      break;

    case A_G_G:
      moveArmGripper(GRAB);
      break;
    case A_G_R:
      moveArmGripper(RELEASE);
      break;

    case STOP:
      stopAll();
      break;

    case AUTO:    break;
    case MAN:    break;
    case INC_COUNTER:
    incDisplay();
    break;
    case DEC_COUNTER:
    decDisplay();
    break;
    case BUZZ:
      playBuzzer();
      
      break;
  }
}

