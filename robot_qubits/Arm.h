#include <Servo.h>

struct ArmMotor{
  Servo motor;
  int val = 20;
  void writeVal(){
    if(val>180){
      val = 180;
    }
    if(val<15){
      val=15;
    }
    
    motor.write(val);                                                   
  }
};


ArmMotor joint1;
ArmMotor joint1_extra;
ArmMotor joint2;


const int delta = 5 ;
void setupArm(){
  //attach arm motors
  joint1.motor.attach(P_ARM_JOINT1);
  joint1_extra.motor.attach(P_ARM_JOINT1_2);
  joint2.motor.attach(P_ARM_JOINT2);

  //setup gripper
  pinMode(P_ARM_G_GRAB, OUTPUT);
  pinMode(P_ARM_G_RELESE, OUTPUT);

  joint1.writeVal();
  joint1_extra.writeVal();
  joint2.val = 150;
  joint2.writeVal();
  
}

void armLoop(){
  
}

void moveArmBase(TurnDirection dir){
  
}

void moveArmJoint1(JointCommand cmd){
  if(cmd == EXTEND){
    joint1.val+=delta;
  }else if(cmd == COLLAPSE){
    joint1.val-=delta;
  }
  joint1.writeVal();
}

void moveArmJoint2(JointCommand cmd){
   if(cmd == EXTEND){
    joint2.val+=delta;
  }else if(cmd == COLLAPSE){
    joint2.val-=delta;
  }
  joint2.writeVal();
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

