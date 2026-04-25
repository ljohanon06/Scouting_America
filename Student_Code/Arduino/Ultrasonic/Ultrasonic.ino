//TODO: Add pin definitions
#define /*TODO*/ A5
#define /*TODO*/ A6

#define LED_PIN D2

unsigned long count;

//TODO: Name variables
long /*TODO*/; //Variable will store the length of the echo pulse in microsecond
float /*TODO*/; //Variable will store the calculated distance to the object

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  pinMode(/*TODO*/,/*TODO*/); //Set the trigger pin as an input or output
  /*TODO*/                    //Set the echo pin as an input or output

  Serial.begin(9600);
}

void loop() {
  if(count % 100 == 0){
    measure_ultrasonic();
    //TODO: Print the distance to the object
    Serial.print("Distance: ");
    Serial.print(/*TODO*/);
    Serial.println(" cm");

    //TODO: Check if the object is in a certain area
    if(/*TODO*/ < /*TODO*/ || /*TODO*/ > /*TODO*/){
      digitalWrite(LED_PIN,HIGH); //Object is gone
    }else{
      digitalWrite(LED_PIN,LOW);
    }
  }

  count++;
  delay(10);
}


void measure_ultrasonic(){
    //TODO: Send a pulse on the trigger pin
    digitalWrite(/*TODO*/, /*TODO*/);
    delayMicroseconds(2);

    digitalWrite(/*TODO*/, /*TODO*/);
    delayMicroseconds(10);
    digitalWrite(/*TODO*/, /*TODO*/);

    //TODO: Measure response on echo pin
    /*TODO*/ = pulseIn(/*TODO*/, HIGH);

    //TODO: Calculate the distance to the object from the duration that the echo pin is high
    
}
