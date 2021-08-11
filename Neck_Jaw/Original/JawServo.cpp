/*----------------------
File:     JawServo.cpp
Author:   MaderDash, Benjaniniooo, ALieN
Date:     29.07.2021
Revision: 16
----------------------*/

//[INFO] Include the file where the original class is located in 
#include "JawServo.hpp"

//[INFO] Default constructor
JawServo::JawServo(){}

void JawServo::setup(){
  audioInputPin = A3;
  servoPin = 11;

  initializePins();

  lockState = false;
}

void JawServo::initializePins(){
  pinMode(audioInputPin, INPUT);

  jawServo.attach(servoPin);
}

void JawServo::handleJawServo(){
  if(lockState == false){
    jawValue = analogRead(audioInputPin);

    jawValue = map(jawValue, 0, 128, 0, 180);

    jawServo.attach(servoPin);

    jawServo.write(jawValue);
  }
}

void JawServo::lock(){
  lockState = !lockState;
}
