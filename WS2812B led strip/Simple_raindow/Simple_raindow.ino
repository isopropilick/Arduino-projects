#include "FastLED.h"
#define LED_DT 7
#define NUM_LEDS 8
struct CRGB leds[NUM_LEDS];
int r=255;
int b=0;
int g=0;
void setup() {
  LEDS.addLeds<WS2812B,7>(leds, NUM_LEDS);
}
void loop () {
  for(int i=0;i<NUM_LEDS;i++){leds[i].setRGB(b,g,r);}
  if (r!=0 && b==0){r--;g++;}
  if (r==0 && g!=0){g--;b++;}
  if (b!=0 && g==0){b--;r++;}
  FastLED.show();
  delay(50);
}
