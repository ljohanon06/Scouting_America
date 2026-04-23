#define BUZZER_PIN D1
#define BUTTON_PIN D5

unsigned long count = 0;

volatile bool button_pressed = false;

void IRAM_ATTR button_ISR(){ //ISR = Interrupt Service Routine
    button_pressed = true;
}

void alarm_tone();
void calm_tone();

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),button_ISR,FALLING);

  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  if(button_pressed){
    alarm_tone();
  }else{
    calm_tone();
  }

  count++;
  delay(10);
}

void alarm_ring(){
  long count_div = (count/100)%10; //Change every second
  noTone(BUZZER_PIN);
  switch(count_div){
    case 0: tone(BUZZER_PIN, 2093); break;
    case 1: tone(BUZZER_PIN, 2637); break;
    case 2: tone(BUZZER_PIN, 3136); break;
    case 3: tone(BUZZER_PIN, 4186); break;
    case 4: tone(BUZZER_PIN, 3136); break;
    case 5: tone(BUZZER_PIN, 2637); break;
    case 6: tone(BUZZER_PIN, 2349); break;
    case 7: tone(BUZZER_PIN, 2794); break;
    case 8: tone(BUZZER_PIN, 3520); break;
    case 9: tone(BUZZER_PIN, 3951); break;
  }
}

void calm_ring(){
  noTone(BUZZER_PIN);
  long count_div = (count/10)%100; //Change every 100 ms

  tone(BUZZER_PIN,2500 + 10*abs(count_div-50));
}
