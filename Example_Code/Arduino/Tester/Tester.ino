#include <Adafruit_NeoPixel.h>
#include <ESP32Servo.h>

#define RING_PIN 17     //D8
#define LED_COUNT 12    //Number of leds on ring

#define SERVO_PIN 8     //D5
#define BUZZER_PIN D1    

#define TRIGGER_PIN A5
#define ECHO_PIN A6

#define LED_PIN D2       //D2
#define BUTTON_PIN D4    //D5

Adafruit_NeoPixel ring(LED_COUNT, RING_PIN, NEO_GRB + NEO_KHZ800); //Ring is transmitted Green, Red, Blue at 800 kHz
Servo servo;

unsigned long count = 5000;

long duration;
float distanceCm;

void alarm_tone();
void calm_tone();

void alarm_ring();
void calm_ring();

void measure_ultrasonic();

volatile bool button_pressed = false;
bool alarm_mode = false;
unsigned long alarm_time = 0;

void IRAM_ATTR button(){
    button_pressed = true;
    alarm_time = count;
}

void setup(){
    ring.begin();   //Initializes ring
    ring.show();    //Pushes current LED setup to ring, as nothing has been setup yet, LED is blank

    servo.setPeriodHertz(50);               //Servos run at 50 Hz
    servo.attach(SERVO_PIN, 500, 2400);    //The servo sends pulses for between 1000 and 2000 microseconds.
    servo.write(180);

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),button,FALLING);

    pinMode(TRIGGER_PIN,OUTPUT);
    pinMode(ECHO_PIN,INPUT);

    pinMode(BUZZER_PIN, OUTPUT);

    Serial.begin(9600);
}

void loop(){
  if(count % 100 == 0){
    measure_ultrasonic();
    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");
    if(distanceCm < 10 || distanceCm > 40){
      digitalWrite(LED_PIN,HIGH);
    }else{
      digitalWrite(LED_PIN,LOW);
    }
  }
  alarm_ring();
  alarm_tone();
  ring.show();

  if(button_pressed){
    servo.write(0);
  }

  count++;
  delay(10);
}

void alarm_tone(){
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

void calm_tone(){
  noTone(BUZZER_PIN);
  long count_div = (count/10)%100; //Change every 100 ms

  tone(BUZZER_PIN,2500 + 10*abs(count_div-50));
}

void alarm_ring(){
  long count_div = (count/100)%10; //Change every second

  ring.fill(ring.Color(100,90-count_div*10,90-count_div*10),0,12);
}

void calm_ring(){
  long count_div = (count/10)%100; //Change every 100 ms

  ring.fill(ring.Color(100-count_div,100,100-count_div),0,12);
}

void measure_ultrasonic(){
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH);

    distanceCm = duration * 0.0343 / 2;
}