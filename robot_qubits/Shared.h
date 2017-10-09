/** Commands **/
enum BTCommands {
  FOW = 'b',
  BAK = 'a',
  RIT = 'c',
  LFT = 'd',

  A_B_L = 'e',
  A_B_R = 'f',

  A_J1_E = 'g',
  A_J1_C = 'h',
  A_J2_E = 'i',
  A_J2_C = 'j',
  A_J3_E = 'k',
  A_J3_C = 'l',
  
  A_G_G = 'm',
  A_G_R = 'n',

  STOP = 'o',

  AUTO = 'p',
  MAN  = 'q',

  BUZZ = 'r',

  INC_COUNTER  = 's',
  DEC_COUNTER  = 't',

};
enum Direction      { FORWARD , BACKWARD };
enum TurnDirection  { RIGHT , LEFT };
enum JointCommand   { EXTEND , COLLAPSE };
enum GripperCommand { GRAB , RELEASE };

/** Pins **/

//Motor
const byte P_MOTOR_R_F = A0,      // Right motor forward
           P_MOTOR_R_B = A1,      //             backward
           P_MOTOR_L_F = A2,      // Left motor forward
           P_MOTOR_L_B = A3;      //             backward

//Arm Servos
const byte P_ARM_JOINT1  = 3,
           P_ARM_JOINT2  = 5,
           P_ARM_G_GRAB  = 6,
           P_ARM_G_RELESE= 9;
           




//Line Follower
const byte P_LF_L = A4,        //Left sensor
           P_LF_M = A5,        //Middle sensor
           P_LF_R = 8;        //Right sensor



//7 segment
const byte one = 11,        //one
           two = 12,        //two
           four = 13;        //four

const byte P_BUZZER = 7;
