void setupLineFollower(){
  pinMode(P_LF_L,INPUT);
  pinMode(P_LF_M,INPUT);
  pinMode(P_LF_R,INPUT);
}

//vars used in linefollwer
bool left,middle,right;

void autoDrive(){

  // true = black
  // false = white

  /*
  left = analogRead(P_LF_L) > 500;
  middle = analogRead(P_LF_M) > 500;
  right = analogRead(P_LF_R) > 500;
  */
  left = digitalRead(P_LF_L) == HIGH;
  middle = digitalRead(P_LF_M) == HIGH;
  right = digitalRead(P_LF_R) == HIGH;

  
  if       ((left && !middle && !right) || (left && middle && !right)){
    turnRobot(LEFT);
    delay(50);
  }else if ((!left && !middle && right) || (!left && middle && right)){
    turnRobot(RIGHT);
    delay(50);
  }else if ( (!left &&  middle && !right)           ){
    moveRobot(FORWARD);
    delay(50);
  }else if(left && middle && right){
     stopAll();
     playBuzzer();
     delay(500);
  }

  /*
  if(left && right){
    stopAll();
    playBuzzer();
    delay(750);
  }else if(left && !right){
    turnRobot(RIGHT);
    delay(50);
  }else if(!left && right){
    turnRobot(LEFT);
    delay(50);
  }else if(!left && !right){
    moveRobot(FORWARD);
    delay(50);
  }else{
    stopAll();
  }
  */

    if(!left && !middle && !right){
      playBuzzer();
      delay(750);
      playBuzzer();
      delay(1500);
    }else{
     stopAll();
     delay(75);
    }

  // we need to take it slowly here :D
  
 

}

