/*========================================================================*/

#include <Adafruit_NeoPixel.h>

/*========================================================================*/
//    Basic Settings
/*========================================================================*/

#define PIN 6
#define NUMOFLEDS 25
#define COOLDOWN 5
#define BRIGHTNESS 255
#define POWERPIN 3

/*========================================================================*/

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMOFLEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show();
  
  pinMode (POWERPIN, OUTPUT);
  digitalWrite (POWERPIN, HIGH);
}

void loop() {  
  rainbowCycle(COOLDOWN);
}

void rainbowCycle(uint8_t wait) {

  for(uint16_t j = 0; j < 256 * 5; j++) {
    for(uint16_t i = 0; i < strip.numPixels(); i++) strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    strip.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

/*========================================================================*/
