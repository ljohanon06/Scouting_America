#include <ESP32Servo.h>

#define SERVO_PIN 8

#define BUTTON_PIN D4

volatile bool button_pressed = false;

unsigned long count = 0;

Servo servo;

void IRAM_ATTR button_ISR(){
    button_pressed = true;
}

void setup() {
  servo.setPeriodHertz(50);               //Servos run at 50 Hz
  servo.attach(SERVO_PIN, 500, 2400);

  servo.write(180);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),button_ISR,FALLING);

}

void loop() {
  if(button_pressed){
    servo.write(0);
  }

  count++;
  delay(10);
}
