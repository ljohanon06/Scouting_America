#include <Adafruit_NeoPixel.h>
#include <ESP32Servo.h>

#define LED_PIN 1       //Pin on arduino
#define LED_COUNT 12    //Number of leds on ring

#define SERVO_PIN 2     //Pin on arduino
#define BUZZER_PIN 3    //Pin on arduino

#define TRIGGER_PIN 4
#define ECHO_PIN 5

#define LED_PIN 6
#define BUTTON_PIN 7

Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800); //Ring is transmitted Green, Red, Blue at 800 kHz

Servo servo;

volatile bool button_pressed = false;

void IRAM_ATTR button(){
    button_pressed = true;
}

void setup(){
    ring.begin();   //Initializes ring
    ring.show();    //Pushes current LED setup to ring, as nothing has been setup yet, LED is blank

    for(int i = 0; i<12; i++){
        ring.setPixelColor(i,10*i,120-10*i,0);
    }
    ring.show();

    servo.setPeriodHertz(50);               //Servos run at 50 Hz
    servo.attach(SERVO_PIN, 1000, 2000);    //The servo sends pulses for between 1000 and 2000 microseconds.

    servo.write(0);
    delay(1000);
    servo.write(90);
    delay(1000);
    servo.write(180);

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),button,FALLING);
}

void loop(){
    if(button_pressed){
        digitalWrite(LED_PIN, HIGH);
        delay(1000);
        digitalWrite(LED_PIN, LOW);
        button_pressed = false;
    }
}

