#define TRIGGER_PIN A5
#define ECHO_PIN A6

#define LED_PIN D2

unsigned long count = 0;

long duration;
float distanceCm;

void measure_ultrasonic();

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  pinMode(TRIGGER_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);

  Serial.begin(9600);
}

void loop() {
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

  count++;
  delay(10);
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
