#include <Adafruit_NeoPixel.h>

#define /*TODO*/ D4 //Button pin

#define /*TOTO*/ 17 //Name the NeoPixel Led Ring pin
#define LED_COUNT 12

Adafruit_NeoPixel /*TODO*/(LED_COUNT, /*TODO*/, NEO_GRB + NEO_KHZ800); //Ring is transmitted Green, Red, Blue at 800 kHz

unsigned long count = 0;

//TODO: Add the button pressed variable and function from earlier

void alarm_ring();
void calm_ring();

void setup() {
  /*TODO*/.begin();   //Initializes ring
  /*TODO*/.show();    //Pushes current LED setup to ring, as nothing has been setup yet, LED is blank

  //TODO:Setup the Button like earlier

}

void loop() {
  if(/*TODO*/){
    /*TOTO*/();
  }else{
    /*TODO*/();
  }
  /*TODO*/.show();

  count++;
  delay(10);
}

void alarm_ring(){
  /*TODO*/
}

void calm_ring(){
  /*TODO*/
}
