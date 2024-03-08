#include "Arduino.h"
#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo;

const int IN1 = 7;
const int IN2 = 6;

void setup() {

  Serial.begin(9600);

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);

  myservo.attach(5);
  myservo.write(75);
}

char dataByte;
int angle = 0;
void loop() {

  while(Serial.available()) {
    dataByte = Serial.read();
    
    switch (dataByte) {
      case 'S':
      angle=75;
      myservo.write(angle);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    break;
    
  case 'G':
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      angle=30;
      myservo.write(angle);
    break;
    case 'I':
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      angle=120;
      myservo.write(angle);
    break;
    case 'H':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      angle=30;
      myservo.write(angle);
    break;
    case 'J':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      angle=120;
      myservo.write(angle);
    break;
    case 'F':
      angle=75;
      myservo.write(angle);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    break;
  case 'B':
      angle=75;
      myservo.write(angle);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    break;
    case 'L':
      angle=30;
      myservo.write(angle);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    break;
    case 'R':
      angle=120;
      myservo.write(angle);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    break;
    
  default:
      
      
    break;
}
  }
  
  
  
}
