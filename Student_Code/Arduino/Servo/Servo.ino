#include <ESP32Servo.h>

#define /*TODO*/ 8 //Name for the servo pin

#define /*TODO*/ D4 //Name for the button pin

volatile bool /*TODO*/ = false; //Variable name storing if the button has been pressed

unsigned long count = 0;

Servo /*TODO*/; //Name for your servo

void IRAM_ATTR /*TODO*/(){
    /*TODO*/ = true;
}

void setup() {
  /*TODO*/.setPeriodHertz(50);               //Servos run at 50 Hz
  /*TODO*/.attach(SERVO_PIN, 500, 2400);

  /*TODO*/.write(180);

  pinMode(/*TODO*/, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(/*TODO*/),/*TODO*/,/*TODO*/);

}

void loop() {
  if(/*TODO*/){
    //TODO: move servo to 0 degrees
  }

  count++;
  delay(10);
}
