/*----------------------
File:     Fire.cpp
Author:   MaderDash, Benjaniniooo, ALieN
Date:     01.08.2021
Revision: 16
----------------------*/

#include "Fire.hpp"

const byte Fire::palette[37][3] PROGMEM = {
{7, 7, 7}, {31, 7, 7}, {47, 15, 7},
{71, 15, 7}, {87, 23, 7}, {103, 31, 7},
{119, 31, 7}, {143, 39, 7}, {159, 47, 7},
{175, 63, 7}, {191, 71, 7}, {199, 71, 7},
{233, 79, 7}, {223, 87, 7}, {223, 87, 7},
{215, 95, 7}, {215, 95, 7}, {215, 103, 15},
{207, 111, 15}, {207, 119, 15}, {207, 127, 15},
{207, 135, 23}, {199, 135, 23}, {199, 143, 23},
{199, 151, 31}, {191, 159, 31}, {191, 159, 31},
{191, 167, 39}, {191, 167, 39}, {191, 175, 47},
{183, 175, 47}, {183, 183, 47}, {183, 183, 55},
{207, 207, 111}, {223, 223, 159}, {239, 239, 199},
{255, 255, 255} 
};

Fire::Fire(){}

void Fire::setup(){
  for(int i = 0; i < WIDTH; i++){
    for(int j = 0; j < HEIGHT; j++){
      fireValues[i][j] = 0;
    }
  }

  randomSeed(analogRead(A5));
  randomSeed(random(5));
  randomSeed(random(20));
  randomSeed(random(100));

  delay(3000);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(200);
}

void Fire::setSource(int strength){
  if(strength < 0){
    strength = 0;
  }else if(strength > 36){
    strength = 36;
  }

  for(int i = 0; i < WIDTH; i++){
    fireValues[i][HEIGHT - 1] = strength;
  }
}

void Fire::update(){
  int decay; 
  int newFireVal;

  for(int j = 0; j < HEIGHT - 1; j++){
    for(int i = 0; i < WIDTH; i++){
      decay = random(3);
      newFireVal = fireValues[i][j+1] - (decay & 1);

      int newJ = i - decay+1;
      newJ = newJ < 0 ? WIDTH - 1 : newJ;
      newJ = newJ >= WIDTH ? 0 : newJ;
      fireValues[newJ][j] = newFireVal >= 0 ? newFireVal : 0;
    }
  }
}

void Fire::render(){
  /*for(int i = 0; i < WIDTH / 2; i++){
    for(int j = 0; j < HEIGHT / 2; j++){
      int avg = fireValues[i * 2][j * 2];
      //int avg = round((fireValues[i * 2][j * 2] + fireValues[i * 2 + 1][j * 2] + fireValues[i * 2][j * 2 + 1] + fireValues[i * 2 + 1][j * 2 + 1]) / 4);

      CRGB color = CRGB((byte) pgm_read_byte(&(Fire::palette[avg][0])), (byte) pgm_read_byte(&(Fire::palette[avg][1])), (byte) pgm_read_byte(&(Fire::palette[avg][2])));
        
      leds[i * (HEIGHT / 2) + j] = color;

      Serial.print((i * (HEIGHT / 2) + j));
      Serial.print(": {");
      Serial.print((byte) pgm_read_byte(&(Fire::palette[avg][0])));
      Serial.print(", ");
      Serial.print((byte) pgm_read_byte(&(Fire::palette[avg][1])));
      Serial.print(", ");
      Serial.print((byte) pgm_read_byte(&(Fire::palette[avg][2])));
      Serial.println("}");
    }
  }*/

  for(int i = 0; i < LED_COUNT; i++){
    led[i] = CRGB(255, 0, 0);
    FastLED.show();
    FastLED.delay(166);
    
    led[i] = CRGB(0, 255, 0);
    FastLED.show();
    FastLED.delay(166);

    led[i] = CRGB(0, 0, 255);
    FastLED.show();
    FastLED.delay(166);
  }
  FastLED.show();
  FastLED.delay(1000);
}
