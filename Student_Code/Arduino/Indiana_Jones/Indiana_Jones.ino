#include <Adafruit_NeoPixel.h>
#include <ESP32Servo.h>

#define /*TODO*/ 17     
#define LED_COUNT 12    //Number of leds on ring

#define /*TODO*/ 8      

#define /*TODO*/ A5
#define /*TODO*/ A6

#define /*TODO*/ D2      
#define /*TODO*/ D4    

Adafruit_NeoPixel /*TODO*/(LED_COUNT, /*TODO*/, NEO_GRB + NEO_KHZ800); //Ring is transmitted Green, Red, Blue at 800 kHz
Servo /*TODO*/;

unsigned long count = 0;

long /*TODO*/;
float /*TODO*/;

void alarm_ring();
void calm_ring();

void measure_ultrasonic();

volatile bool /*TODO*/ = false;
bool /*TODO*/ = false; //Variable showing if the object has been taken

void IRAM_ATTR /*TODO*/(){
    /*TODO*/ = true;
}

void setup(){
    //Ring Initialize

    //Servo Initialize

    //Led/Button initialize

    //Ultrasonic Initialize
}

void loop(){
    if(count % 10 == 0 && !/*TODO*/){
        measure_ultrasonic();

        if(/*TODO*/){
            /*TODO*/ = /*TODO*/;
        }
    }
    if(/*TODO*/ || /*TODO*/){ 
        //TODO: What happens in alarm mode
    }else{
        //TODO: What happens in calm mode
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

void measure_ultrasonic(){
    /*TODO*/
}