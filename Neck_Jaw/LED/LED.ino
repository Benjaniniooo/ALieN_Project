#include <FastLED.h>

#define WIDTH 16
#define HEIGHT 16

#define LED_PIN 7
#define LED_COUNT 150

const CRGB palette[37] = {
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

CRGB leds[LED_COUNT];
byte fireValues[WIDTH][HEIGHT];

void setupFire();
void setSource(int strength);
void updateFire();
void render();

void setup() {
  Serial.begin(9600);
  
  setupFire();
  setSource(10);
}

void loop() {
  updateFire();
  render();

}

void setupFire(){
  for(int i = 0; i < WIDTH; i++){
    for(int j = 0; j < HEIGHT; j++){
      fireValues[i][j] = 0;
    }
  }

  randomSeed(analogRead(A5));
  randomSeed(random(7));
  randomSeed(random(23));
  randomSeed(random(124));

  delay(2000);
  FastLED.addLeds<WS2812B, LED_PIN, GRB> (leds, LED_COUNT).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(200);
}

void setSource(int strength){
  if(strength < 0){
    strength = 0;
  }else if(strength > 36){
    strength = 36;
  }

  for(int i = 0; i < WIDTH; i++){
    fireValues[i][HEIGHT - 1] = strength;
  }
}

void updateFire(){
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

void render(){
  for(int i = 0; i < WIDTH / 2; i++){
    for(int j = 0; j < HEIGHT / 2; j++){
      int avg = fireValues[i * 2][j * 2];
      //int avg = round((fireValues[i * 2][j * 2] + fireValues[i * 2 + 1][j * 2] + fireValues[i * 2][j * 2 + 1] + fireValues[i * 2 + 1][j * 2 + 1]) / 4);

      CRGB color = palette[avg];
        
      leds[i * (HEIGHT / 2) + j] = color;

      Serial.print((i * (HEIGHT / 2) + j));
      Serial.print(": {");
      Serial.print((byte) palette[avg].red);
      Serial.print(", ");
      Serial.print((byte) palette[avg].green);
      Serial.print(", ");
      Serial.print((byte) palette[avg].blue);
      Serial.println("}");
    }
  }
  FastLED.show();

  /*for(int j = 0; j < HEIGHT; j++){
    for(int i = 0; i < WIDTH; i++){
      Serial.print("{");
      if(String(fireValues[i][j]).length() == 2){
        Serial.print(fireValues[i][j]);
      }else{
        Serial.print(fireValues[i][j]);
        Serial.print(" ");
      }
      Serial.print("} ");
    }
    Serial.println();
  }
  Serial.println();*/

}
