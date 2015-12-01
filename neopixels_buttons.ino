#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include "sn3218.h"

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, PIN);

int maxBrightness = 140;
int minBrightness = 50;
int fadeSpeed = 15;

void setup() {
  strip.begin();
  strip.show();
  sn3218.begin();
  sn3218.enable_leds(SN3218_CH_ALL);
}

void pulseColor(uint32_t c, uint8_t wait) {
  for(int i=minBrightness; i<maxBrightness; i++) {
      strip.setBrightness(i);
      for(int x=0; x<strip.numPixels(); x++){
        strip.setPixelColor(x,c);
      }
      strip.show();
      delay(wait);
  }
  for(int i=maxBrightness; i>minBrightness; i--) {
       strip.setBrightness(i);
      for(int x=0; x<strip.numPixels(); x++){
        strip.setPixelColor(x,c);
      }
      strip.show();
      delay(wait);
  }
}

void loop() {
  int i;
  for( i = 0; i < SN3218_NUM_CHANNELS; i++ ){
    sn3218.set(i,255);
    }
  sn3218.update();
  pulseColor(strip.Color(110, 40, 210), fadeSpeed);
}
