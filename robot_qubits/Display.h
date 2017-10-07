int displayVal = 0;

void setupDisplay(){
  pinMode(one,OUTPUT);
  pinMode(two,OUTPUT);
  pinMode(four,OUTPUT);
  digitalWrite(one, LOW);
  digitalWrite(two, LOW);
  digitalWrite(four, LOW);
}


void writeDisplay(){

   bool oneVal = displayVal == 1 || displayVal == 3;
   bool twoVal = displayVal == 2 || displayVal == 3;
   bool fourVal = displayVal == 4;
   
   digitalWrite(one, oneVal);
   digitalWrite(two, twoVal);
   digitalWrite(four, fourVal);
}


void incDisplay(){
  displayVal++;
  if(displayVal>4)displayVal=4;
  writeDisplay();
}


void decDisplay(){
  displayVal--;
  if(displayVal<0)displayVal=0;
  writeDisplay();
}


