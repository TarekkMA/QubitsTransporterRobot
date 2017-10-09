void setupLineFollower(){
  pinMode(P_LF_L,OUTPUT);
  pinMode(P_LF_M,OUTPUT);
  pinMode(P_LF_R,OUTPUT);
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

  
  if       (left && !middle && !right){
    Serial.println("RIGHT");
    turnRobot(RIGHT);
  }else if (!left && !middle &&  right){
    Serial.println("LEFT");
    turnRobot(LEFT);
  }else if ( 
           ( left && !middle &&  right) ||
           (!left &&  middle &&  right) ||
           ( left &&  middle && !right) 
           ){
    Serial.println("FORWARD");
    moveRobot(FORWARD);
  }


  // we need to take it slowly here :D
  delay(100);
  stopAll();
  delay(200);
 

}

