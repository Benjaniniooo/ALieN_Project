/*----------------------
File:     JawServo.hpp
Author:   MaderDash, Benjaniniooo, ALieN
Date:     29.07.2021
Revision: 16
----------------------*/

#include <Arduino.h>
#include <Servo.h>

class JawServo{
public:
  JawServo();

  void handleJawServo();

  void setup();

   void lock();

protected:
  Servo jawServo;

  int jawValue;

  void initializePins();

private:
  int audioInputPin;
  
  int servoPin; 

  bool lockState;
};
