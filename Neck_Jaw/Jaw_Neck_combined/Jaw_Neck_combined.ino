#include <Servo.h>

#define JoystickXPin A0
#define JoystickYPin A1
#define ServoXPin 9
#define ServoYPin 10

#define ButtonPin 5
#define JawServoPin 12

Servo neckServoX;
Servo neckServoY;

Servo jawServo;

float servoPositionX = 90.f;
float servoPositionY = 90.f;

float jawPosition = 30.f;

void updateNeck();
void updateJaw();  

void setup() {
  Serial.begin(9600);
  
  pinMode(JoystickXPin, INPUT);
  pinMode(JoystickYPin, INPUT);

  pinMode(ButtonPin, INPUT_PULLUP);

  neckServoX.attach(ServoXPin);
  neckServoY.attach(ServoYPin);

  jawServo.attach(JawServoPin);
}

void loop() {
  updateNeck();
  updateJaw();

}

void updateNeck(){
  int neckXValue = analogRead(JoystickXPin);
  int neckYValue = analogRead(JoystickYPin);

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

void updateJaw(){
  if(digitalRead(ButtonPin) == LOW){
    if(jawPosition <= 180.f - 2.75f){
      jawPosition += 2.75f;
    }
  }else{
    if(jawPosition >= 0.f + 2.75f){
      jawPosition -= 2.75f;
    }
  }
  
  jawServo.write(jawPosition);
}
