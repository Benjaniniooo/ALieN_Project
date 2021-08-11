/*----------------------
File:     NeckServo.cpp
Author:   MaderDash, Benjaniniooo, ALieN
Date:     29.07.2021
Revision: 16
----------------------*/

//[INFO] Include the file where the original class is located in 
#include "NeckServo.hpp"

//[INFO] Default constructor
NeckServo::NeckServo(){}

//[INFO] Setup function
void NeckServo::setup(){
  //[INFO] set the joystick pins to A0 and A1 for x and y 
  joystickXPin = A0;
  joystickYPin = A1;  

  //[INFO] set the servo pins to 10 and 9 for x and y 
  servoXPin = 10;
  servoYPin = 9; 
 
  //[INFO] call the function initializePins
  initializePins();

  //[INFO] call the function setupVariables
  setupVariables();
}

//[INFO] Function to initialize the pins
void NeckServo::initializePins(){
  //[INFO] set the joystick inputs to inputs
  pinMode(joystickXPin, INPUT);
  pinMode(joystickYPin, INPUT);

  //[INFO] attach the servo pins to their servo class instances
  neckServoX.attach(servoXPin);
  neckServoY.attach(servoYPin);
}

//[INFO] Handle the servos positions according to the joystick's position
void NeckServo::handleNeckServo(){
 //[INFO] check if the servos aren't locked 
 if(lockState == false){
    //[INFO] Read the joystick's input
    neckXValue = analogRead(joystickXPin);
    neckYValue = analogRead(joystickYPin);

    //[INFO] map the input to a length supported by the servo
    //[NOTE] 0 -> 1023 is the analog input value, 10 bits; 0 -> 180 are the angles 
    neckXValue = map(neckXValue, 0, 1023, 0, 180);
    neckYValue = map(neckYValue, 0, 1023, 0, 180);
  }

  //[INFO] Attach the pins to the servo classes again
  neckServoX.attach(servoXPin);
  neckServoY.attach(servoYPin);

  //[INFO] Let the servos move
  //[NOTE] When the lockState is active, the previous input will be used, thus, the servo stops moving
  neckServoX.write(neckXValue);
  neckServoY.write(neckYValue);
}

//[INFO] Setup for the variables
void NeckServo::setupVariables(){
  //[INFO] set the lock state to false, because we want the servos to move at the beginning
  lockState = false;
}

//[INFO] lock / unlock the servos movements
void NeckServo::lock(){
  lockState = !lockState;
}
