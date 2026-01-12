#include <Arduino.h>
#include <FastLED.h>

#include "STM32_CAN.h"


#define RGB1 PB12
#define RGB1 PB13

#define BTN1 PB7
#define BTN2 PB6

#define LS0 PA0
#define LS1 PA1
#define LS2 PA2
#define LS3 PA3
#define LS4 PA4
#define LS5 PA5
#define LS6 PA6
#define LS7 PA7
#define LS8 PB0
#define LS9 PB1

STM32_CAN Can( CAN1, DEF );

int sensors[] = {LS1, LS2, LS3, LS4, LS5, LS6, LS7, LS8, LS9 };

CRGB leds_A[5];
CRGB leds_B[5];

uint32_t line_sensors[10];

int init_leds() {
  FastLED.addLeds<WS2812B, PB12>(leds_A, 5);
  FastLED.addLeds<WS2812B, PB13>(leds_B, 5);
}

void update_line_sensors(int* sensors, uint32_t*  values) {
   for (size_t i = 0; i < 10; i++)
  {
    values[i] = analogRead(sensors[i]);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);  

}

void loop() {
  // put your main code here, to run repeatedly:
}