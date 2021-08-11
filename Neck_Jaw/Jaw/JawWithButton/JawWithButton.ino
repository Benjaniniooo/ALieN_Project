/*
 * This code controls the Neck based on some audio input.
 * It will sample the signals 10 times before it gets 
 * mapped to values for the servo to reduce calculation time.
 */

#include <Servo.h>

//#define AUXInputPin A3
#define ButtonPin 5
#define JawServoPin 12

Servo jawServo;
float jawPosition = 30.f;


void setup() {
  Serial.begin(9600);
  
  pinMode(ButtonPin, INPUT_PULLUP);

  jawServo.attach(JawServoPin);

}

void loop() {
  if(digitalRead(ButtonPin) == LOW){
    if(jawPosition <= 105.f - 2.75f){
      jawPosition += 2.75f;
    }
  }else{
    if(jawPosition >= 0.f + 2.75f){
      jawPosition -= 2.75f;
    }
  }
  
  jawServo.write(jawPosition);
}
