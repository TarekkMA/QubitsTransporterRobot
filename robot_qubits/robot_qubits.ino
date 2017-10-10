#include "Shared.h"
#include "Movement.h"
#include "Buzzer.h"
#include "Arm.h"
#include "LineFollower.h"
#include "Display.h"

void readBluethooth();
void handleCommand(int val);


//
bool autoPilotState  = false;

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

  if(autoPilotState){
    autoDrive();
  }

  readBluethooth();
  
  delay(10);
}


void readBluethooth() {
  
  if (Serial.available() > 0) {
    int val = Serial.read();

    if(autoPilotState && val == MAN){
      autoPilotState = false;
    }else{
      handleCommand(val);
    }
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
    case A_J1_E:
      moveArmJoint1(EXTEND);
      break;
    case A_J1_C:
      moveArmJoint1(COLLAPSE);
      break;
    case A_J2_E:
      moveArmJoint2(EXTEND);
      break;
    case A_J2_C:
      moveArmJoint2(COLLAPSE);
      break;

    case A_G_G:
      moveArmGripper(GRAB);
      break;
    case A_G_R:
      moveArmGripper(RELEASE);
      break;

    case STOP:
      stopAll();
      stopGripper();
      break;

    case AUTO:
      autoPilotState = true;
      break;
    case MAN:
      autoPilotState = false;
      break;
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




