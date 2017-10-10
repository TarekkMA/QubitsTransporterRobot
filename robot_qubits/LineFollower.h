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


  /*
  if       (left && !middle && !right){
    turnRobot(LEFT_R);
    
  }else if (!left && !middle &&  right){
    turnRobot(RIGHT_R);

  }else if ( 
           (!left &&  middle && !right)           
           ){
    moveRobot(FORWARD);
  }else if((!left &&  middle &&  right)){
    turnRobot(RIGHT_R);
  }else if(( left &&  middle && !right) ){
    turnRobot(LEFT_R);
  }
  */


  if(left && right){
    stopAll();
  }else if(left && !right){
    turnRobot(LEFT_R);
    delay(50);
  }else if(!left && right){
    turnRobot(RIGHT_R);
    delay(50);
  }else if(!left && !right){
    moveRobot(FORWARD);
    delay(100);
  }

  
    stopAll();
    delay(100);


  // we need to take it slowly here :D
  
 

}

