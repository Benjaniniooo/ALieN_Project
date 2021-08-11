/*----------------------
File:     NeckServo.hpp
Author:   MaderDash, Benjaniniooo, ALieN
Date:     29.07.2021
Revision: 16
----------------------*/

//[INFO] Add the libraries the class is dependent of  
#include <Servo.h>
#include <Arduino.h>

//[INFO] Declare the class and it's functions/variables
class NeckServo {
  public:
    
    //[INFO] Global constructor
    NeckServo();

    //[INFO] Handle the neck servos according to the joystick's position
    void handleNeckServo();

    //[INFO] Setup the variables and the servo's for proper functioning
    void setup();

    //[INFO] Lock the servos -> no movement
    void lock();

  protected:
    
    //[INFO] Declare the servos
    Servo neckServoX;
    Servo neckServoY;

    //[INFO] Declare the values for the neck's rotation
    //[NOTE] Range from 0 -> 180
    int neckYValue;
    int neckXValue;

    //[INFO] Declare the lock state
    //[NOTE] If true, don't move the servo's
    bool lockState;

  private:
    //[INFO] Declare the pin for the joystick's x and y axis
    int joystickXPin;
    int joystickYPin;

    //[INFO] Declare the pins for the servo's
    int servoXPin;
    int servoYPin;

    //[INFO] Function to initialize the pins for the neck - servo handler
    void initializePins();

    //[INFO] function to set up the variables
    //[NOTE] sets everything to default
    void setupVariables();
};
