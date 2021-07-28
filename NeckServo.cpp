#include "NeckServo.hpp"

NeckServo::NeckServo(){
  joystickXPin = A0;
  joystickYPin = A1;
  buttonPin = 8;  
  servoXPin = 10;
  servoYPin = 11; 
  
  initializePins();

  setupVariables();
}

NeckServo::NeckServo(int joystickXPinNew, int joystickYPinNew, int buttonPinNew, int servoXPinNew, int servoYPinNew){
  joystickXPin = joystickXPinNew;
  joystickYPin = joystickYPinNew;
  buttonPin = buttonPinNew; 

  servoXPin = servoXPinNew;
  servoYPin = servoYPinNew;

  initializePins();

  setupVariables();
}

void NeckServo::initializePins(){
  pinMode(joystickXPin, INPUT);
  pinMode(joystickYPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  neckServoX.attach(servoXPin);
  neckServoY.attach(servoYPin);
}

void NeckServo::handleNeckServo(){
  buttonValue = digitalRead(buttonPin);
  
  if(buttonValue == false){
    lockState = !lockState;
    delay(delayTime);
  }

  if(lockState == false){
  neckXValue = map(analogRead(joystickXPin), 0, 1023, 0, 180);
  neckYValue = map(analogRead(joystickYPin), 0, 1023, 0, 180);
  }
 
  neckServoX.write(neckXValue);
  neckServoY.write(neckYValue);

  Serial.print("X-VALUE:  ");
  Serial.print(neckXValue);
  Serial.print("  ;  ");
  Serial.print("Y-VALUE:  ");
  Serial.println(neckYValue);
}

void NeckServo::setupVariables(){
  neckXValue = 0;
  neckYValue = 0;

  buttonValue = digitalRead(buttonPin);
  lockState = false;

  
}
