#include <Adafruit_NeoPixel.h>
#include <ESP32Servo.h>

#define RING_PIN 17     //D8
#define LED_COUNT 12    //Number of leds on ring

#define SERVO_PIN 7     //D4
#define BUZZER_PIN A1    //Pin on arduino

#define TRIGGER_PIN A5
#define ECHO_PIN A6

#define LED_PIN D2       //D2
#define BUTTON_PIN D5    //D5

Adafruit_NeoPixel ring(LED_COUNT, RING_PIN, NEO_GRB + NEO_KHZ800); //Ring is transmitted Green, Red, Blue at 800 kHz

Servo servo;

long duration;
float distanceCm;

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
    servo.attach(SERVO_PIN, 500, 2400);    //The servo sends pulses for between 1000 and 2000 microseconds.

    servo.write(180);
    delay(2000);
    servo.write(0);
    delay(2000);
    servo.write(180);

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),button,FALLING);

    pinMode(TRIGGER_PIN,OUTPUT);
    pinMode(ECHO_PIN,INPUT);

    Serial.begin(9600);
}

void loop(){
    if(button_pressed){
        digitalWrite(LED_PIN, HIGH);
        delay(1000);
        digitalWrite(LED_PIN, LOW);
        button_pressed = false;
    }

    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH);

    distanceCm = duration * 0.0343 / 2;

    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");

    delay(1000);
}

