#include <Servo.h>

Servo myservo;

const int sensorMin = 0;    
const int sensorMax = 600;
const int LED = 9;

void setup() {
  pinMode(LED, OUTPUT);
  myservo.attach(11);
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(A1);
  Serial.println(sensorReading);
  delay(500);
  // map the sensor range to a range of four options:
  int range = map(sensorReading, sensorMin, sensorMax, 3, 0);

  switch (range) {
    case 0:  // your hand is on the sensor
      Serial.println("dark");
      myservo.write(90);
      break;
    case 1:  // your hand is close to the sensor
      Serial.println("dim");
      myservo.write(0);
      break;
    case 2:  // your hand is a few inches from the sensor
      Serial.println("medium");
      myservo.write(0);
      break;
    case 3:  // your hand is nowhere near the sensor
      Serial.println("bright");
      myservo.write(0);
      break;
  }
  // if (sensorReading >= 600){
  //   myservo.write(90);
  // }
  // else{
  //   myservo.write(0);
  // }
  delay(1); 
}
