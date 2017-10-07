
void setupBuzzer(){
    pinMode(P_BUZZER, OUTPUT);
}

void playBuzzer(){
    tone(P_BUZZER, 1000);

    delay(500);

    noTone(P_BUZZER);
  
}

