#include <Servo.h>

struct ArmMotor{
  Servo motor;
  int val = 20;
  void writeVal(){
    if(val>180){
      val = 180;
    }
    if(val<20){
      val=20;
    }
    motor.write(val);                                                      
  }
};


ArmMotor base;
ArmMotor joints[2];


const int delta = 5 ;
void setupArm(){
  //attach arm motors
  joints[0].motor.attach(P_ARM_JOINT1);
  joints[1].motor.attach(P_ARM_JOINT2);

  //setup gripper
  pinMode(P_ARM_G_GRAB, OUTPUT);
  pinMode(P_ARM_G_RELESE, OUTPUT);

  joints[0].writeVal();
  joints[1].val = 100;
  joints[1].writeVal();
  
}

void armLoop(){
  
}

void moveArmBase(TurnDirection dir){
  
}

void moveArmJoint(byte jointNum,JointCommand cmd){
  if(cmd == EXTEND){
    joints[jointNum].val-=delta;
  }else if(cmd == COLLAPSE){
    joints[jointNum].val+=delta;
  }
  joints[jointNum].writeVal();
}

void moveArmGripper(GripperCommand cmd){
  if(cmd == GRAB){
    digitalWrite(P_ARM_G_GRAB, HIGH);
    digitalWrite(P_ARM_G_RELESE, LOW);
  }else if(cmd == RELEASE){
    digitalWrite(P_ARM_G_GRAB, LOW);
    digitalWrite(P_ARM_G_RELESE, HIGH);
    
  }
}

void stopGripper(){
   digitalWrite(P_ARM_G_GRAB, LOW);
   digitalWrite(P_ARM_G_RELESE, LOW);
}

