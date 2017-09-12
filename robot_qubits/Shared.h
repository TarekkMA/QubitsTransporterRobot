/** Commands **/
enum BTCommands {
  FOW = 'a',
  BAK = 'b',
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
  MAN  = 'q'
};
enum Direction      { FORWARD , BACKWARD };
enum TurnDirection  { RIGHT , LEFT };
enum JointCommand   { EXTEND , COLLAPSE };
enum GripperCommand { GRAB , RELEASE };

/** Pins **/

//Motor
const byte P_MOTOR_R_F = 2,      // Right motor forward
           P_MOTOR_R_B = 3,      //             backward
           P_MOTOR_L_F = 4,      // Left motor forward
           P_MOTOR_L_B = 5;      //             backward

//Arm Servos
const byte P_ARM_BASE    = A0,
           P_ARM_JOINT1  = A1,
           P_ARM_JOINT2  = A2,
           P_ARM_JOINT3  = A3,
           P_ARM_GRIPPER = A4;

//Bluetooth Serial
const byte P_BLUETOOTH_RX = 10,
           P_BLUETOOTH_TX = 11;

//Automatic Sitch
const byte P_LF_SWITCH = 5;

//Line Follower
const byte P_LF_L = A0,        //Left sensor
           P_LF_M = A1,        //Middle sensor
           P_LF_R = A2;        //Right sensor


