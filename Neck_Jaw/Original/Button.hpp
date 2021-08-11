/*----------------------
File:     Button.hpp
Author:   MaderDash, Benjaniniooo, ALieN
Date:     29.07.2021
Revision: 16
----------------------*/

#include <Arduino.h>

#define debounceDelayTime 250
#define waitTimeClick 300

class Button{
  public:
    Button();

    void setup();

    int getPressCount();

  protected:
    int checkPress();

  private:
    int buttonPin;
};
