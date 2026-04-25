#include <Adafruit_NeoPixel.h>

#define BUTTON_PIN D4

#define RING_PIN 17
#define LED_COUNT 12

Adafruit_NeoPixel ring(LED_COUNT, RING_PIN, NEO_GRB + NEO_KHZ800); //Ring is transmitted Green, Red, Blue at 800 kHz

unsigned long count = 0;

volatile bool button_pressed = false;

void IRAM_ATTR button_ISR(){ //ISR = Interrupt Service Routine
    button_pressed = true;
}

void alarm_ring();
void calm_ring();

void setup() {
  ring.begin();   //Initializes ring
  ring.show();    //Pushes current LED setup to ring, as nothing has been setup yet, LED is blank

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),button_ISR,FALLING);

}

void loop() {
  if(button_pressed){
    alarm_ring();
  }else{
    calm_ring();
  }
  ring.show();

  count++;
  delay(10);
}

void alarm_ring(){
  long count_div = (count/50)%3; 

  switch(count_div){
    case 0: ring.fill(ring.Color(100,0,0),0,4); break;
    case 1: ring.fill(ring.Color(0,100,0),4,8); break;
    case 2: ring.fill(ring.Color(0,0,100),8,12); break;
  }
}

void calm_ring(){
  long count_div = (count/10)%100; 

  int r_b = 90-count_div;

  ring.fill(ring.Color(r_b,100,r_b),0,12);
}
