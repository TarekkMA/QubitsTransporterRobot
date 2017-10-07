#include <Servo.h>

struct ArmMotor{
  Servo motor;
  int val = 0;
  void writeVal(){
    /*if(val>180){
      val = 180;
    }
    if(val<0){
      val=0;
    }*/
    motor.write(val);                                                      
  }
};


ArmMotor base;
ArmMotor joints[3];
ArmMotor gripper;


const int delta = 5 ;
void setupArm(){
  //attach arm motors
  base.motor.attach(P_ARM_BASE);
  joints[0].motor.attach(P_ARM_JOINT1);
  joints[1].motor.attach(P_ARM_JOINT2);
  joints[2].motor.attach(P_ARM_JOINT3);
  gripper.motor.attach(P_ARM_GRIPPER);

  // reset to inital val
  base.writeVal();
  joints[0].writeVal();
  joints[1].writeVal();
  joints[2].writeVal();
  gripper.writeVal();
}

void armLoop(){
  
}

void moveArmBase(TurnDirection dir){
  if(dir == LEFT){
    base.val-=delta;
  }else if(dir == RIGHT){
    base.val+=delta;
  }
  base.writeVal(); 
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
    gripper.val+=delta;
  }else if(cmd == RELEASE){
    gripper.val-=delta;
  }
  gripper.writeVal();
}

