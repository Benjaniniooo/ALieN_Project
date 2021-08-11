/*
 * This code reads the values of the X and Y axis of the 
 * Joystick conected to pin A0 and A1, maps it to correct
 * values for the Servo and writes the values to the servo.
 * Thus, this code moves the servo according to the joystick.
 */

#include <Servo.h>

#define JoystickXPin A0
#define JoystickYPin A1
#define ServoXPin 9
#define ServoYPin 10


Servo neckServoX;
Servo neckServoY;

float servoPositionX = 90.f;
float servoPositionY = 90.f;

void setup() {
  Serial.begin(9600);
  
  pinMode(JoystickXPin, INPUT);
  pinMode(JoystickYPin, INPUT);

  neckServoX.attach(ServoXPin);
  neckServoY.attach(ServoYPin);
}

void loop() {
  int neckXValue = analogRead(JoystickXPin);
  int neckYValue = analogRead(JoystickYPin);

  Serial.print("Values read: X: ");
  Serial.print(neckXValue);
  Serial.print(", Y: ");
  Serial.print(neckYValue);

  //map the analog input from the joysticks potentiometer
  //to angles that the servo can use to move
  neckXValue = map(neckXValue, 0, 1023, 73, 107);
  neckYValue = map(neckYValue, 0, 1023, 50, 130);

  if(neckXValue - servoPositionX > 3.5f){
    servoPositionX += 2.9f;
  }else if(neckXValue - servoPositionX < -3.5f){
    servoPositionX -= 2.9f;
  }

  if(neckYValue - servoPositionY > 3.5f){
    servoPositionY += 2.9f;
  }else if(neckYValue - servoPositionY < -3.5f){
    servoPositionY -= 2.9f;
  }

  Serial.print(" --> Mapped values: ");
  Serial.print(" X: ");
  Serial.print(servoPositionX);
  Serial.print(", Y: ");
  Serial.println(servoPositionY);

  neckServoX.write(servoPositionX);
  neckServoY.write(servoPositionY);
}
