#include "FastLED.h"
#define LED_DT 7
#define NUM_LEDS 8
struct CRGB leds[NUM_LEDS];
void setup() {
  LEDS.addLeds<WS2812B,7>(leds, NUM_LEDS);
}
void loop () {
  Rider(1, 52, 4, 0x05FF00);//cycles,speed,trace,HEXcolor
}
void Rider(uint16_t cycles, uint16_t speed, uint8_t width, uint32_t color) {
  uint32_t old_val[NUM_LEDS];
  for(int i = 0; i < cycles; i++){
    for (int count = 1; count<NUM_LEDS; count++) {
      leds[count]=color;
      old_val[count] = color;
      for(int x = count; x>0; x--) {
        old_val[x-1] = dimColor(old_val[x-1], width);
        leds[x-1]=old_val[x-1];
      }
      FastLED.show();
      delay(speed);
    }
    for (int count = NUM_LEDS-1; count>=0; count--) {
      leds[count]=color;
      old_val[count] = color;
      for(int x = count; x<=NUM_LEDS ;x++) {
        old_val[x-1] = dimColor(old_val[x-1], width);
        leds[x+1]=old_val[x+1];
      }
      FastLED.show();
      delay(speed);
    }
  }
}
uint32_t dimColor(uint32_t color, uint8_t width) {
   return (((color&0xFF0000)/width)&0xFF0000) + (((color&0x00FF00)/width)&0x00FF00) + (((color&0x0000FF)/width)&0x0000FF);
}
