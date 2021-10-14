
#include <Pixy2.h>
#include <PIDLoop.h>
#include <Servo.h>

Pixy2 pixy;

int onButtonPin = 25;
int offButtonPin = 23;
//#define trigPin 41
//#define echoPin 43
int echoPin = 43;
int trigPin = 41;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // begin serial connection with the serial monitor
  Serial.print("Starting...\n");
  pinMode(onButtonPin, INPUT_PULLUP);
  pinMode(offButtonPin, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  // Serial.print(distance);
  //  print(distance);
  long distance, duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  // put your main code here, to run repeatedly:
  if (distance >= 50 || distance <= 0) {

    Serial.println("Out of range");
    //TURN OFF MAGIC MIRROR
  }
  else {

    Serial.print(distance); Serial.println(" cm");
    //LET THE MAGIC MIRROR RUN
    
  } delay(500);


  //if (digitalRead(onButtonPin)==LOW)

}
