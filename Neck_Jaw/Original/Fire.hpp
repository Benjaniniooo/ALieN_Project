/*----------------------
File:     Fire.hpp
Author:   MaderDash, Benjaniniooo, ALieN
Date:     01.08.2021
Revision: 16
----------------------*/

#include <Arduino.h>
#include <avr/pgmspace.h>
#include <FastLED.h>

#define WIDTH 16
#define HEIGHT 16

#define LED_PIN 7

#define LED_COUNT 150

class Fire{
  public:
    Fire();

    void setup();  
    void update();

    void setSource(int strength);

    byte fireValues[WIDTH][HEIGHT];
    static const byte palette[37][3] PROGMEM; 

    void render();

  protected:
    CRGB leds[LED_COUNT];
};
