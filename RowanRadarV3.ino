//Author: Rowan
//Date: 11/08 2023
//Description: it dims light. oh ya and it has an lcd and other stuff
const int g = 6;
const int r = 9;

#include <Servo.h>

//Two ways of doing the same thing

//int trig, echo;
//trig = 3;
//echo = 2;

//trig pin sends out wave, echo pin measures amount of time
int trig = 3;
int echo = 5;
float distance, duration;

Servo myServo;


void setup() {
  // put your setup code here, to run once:
  myServo.attach(11);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  pinMode(g, INPUT);
  pinMode(r, INPUT);
  pinMode(g, OUTPUT);
  pinMode(r, OUTPUT);

}
void loop() {
  controlBrightness(9);
}
void sense() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);// set trig to HIGH
  delayMicroseconds(10);// wait 10 microseconds
  digitalWrite(trig, LOW);// set trig to LOW
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.0343;
  Serial.print("Distance: ");// print "Distance: "
  Serial.print(distance);// print the value of distance
  Serial.println(" cm");// print " cm"
  delay(500);// wait half a second

}

void servoStart() {
  myServo.write(57);
}

void controlBrightness(int ledPin) {
  int brightness = 0;
  if (brightness < 255) {
    brightness += 51;
    analogWrite(ledPin, brightness);

  }

  else {
    brightness -= 51;
    analogWrite(ledPin, brightness);
  }

}
