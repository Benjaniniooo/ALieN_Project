/*----------------------
File:     ALieN_Project.ino
Author:   MaderDash, Benjaniniooo, ALieN
Date:     29.07.2021
Revision: 16
----------------------*/

#include "NeckServo.hpp"
#include "JawServo.hpp"
#include "Button.hpp"
#include "Fire.hpp"

NeckServo neck = NeckServo();
Button button = Button();
JawServo jaw = JawServo();
Fire fire = Fire();

void setup(){
  Serial.begin(9600);

  button.setup();
  neck.setup();
  jaw.setup();
  fire.setup();
  fire.setSource(10);

}

void loop(){
  neck.handleNeckServo();

  jaw.handleJawServo();
 
  int number = button.getPressCount();

  switch(number){
    case 1:
      break;
    case 2:
      neck.lock();
      break;
    case 3:
      jaw.lock();
      break;
  }

  fire.update();
  fire.render();
 }
