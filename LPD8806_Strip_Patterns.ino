//Collection of LPD8806 LED Strip Patterns
//Chase, Dither, Wipe, Scanner, Wave patterns from the examples of the Adafruit Library for LPD8806
//Phasing patterns from https://github.com/MarkEMarkEMark/LPD8806Interference/blob/master/Interference.pde
//Bash, Blend, Pulse by Luis E. Fraguada http://datable.net
//2013.06.04

#include "LPD8806.h"
#include "SPI.h"

// Number of RGB LEDs in strand:
int nLEDs = 12;

// Chose 2 pins for output; can be any valid output pins:
int dataPin = 16;
int clockPin = 15;

// First parameter is the number of LEDs in the strand. The LED strips
// are 32 LEDs per meter but you can extend or cut the strip. Next two
// parameters are SPI data and clock pins:
LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);

// You can optionally use hardware SPI for faster writes, just leave out
// the data and clock pin parameters. But this does limit use to very
// specific pins on the Arduino. For "classic" Arduinos (Uno, Duemilanove,
// etc.), data = pin 11, clock = pin 13. For Arduino Mega, data = pin 51,
// clock = pin 52. For 32u4 Breakout Board+ and Teensy, data = pin B2,
// clock = pin B1. For Leonardo, this can ONLY be done on the ICSP pins.
//LPD8806 strip = LPD8806(nLEDs);

void setup() {
  // Start up the LED strip
  strip.begin();

  uint8_t i;
  // Start by turning all pixels off:
  for(i=0; i<strip.numPixels(); i++) strip.setPixelColor(i, 0);

  // Update the strip, to start they are all 'off'
  strip.show();
  
  Serial.begin(9600);
}

void loop() {
  
  // ColorPhasing(10);
  // colorWipe(strip.Color(255,0,255),100);
  // colorChase(strip.Color(255,0,255),100);
  // scanner(255,0,255,100);
  // dither(strip.Color(255,0,255),100);
  //  wave(strip.Color(255,0,255),2,100);
  //  colorBash(strip.Color(255,0,255));
  //pulse(127,127,127,100, 10); //r from 0 to 127, g from 0 to 127, b from 0 to 127, steps, wait
 blend(strip.Color(127,0,127),strip.Color(0,127,127),100,10);
}


















