// Chase a dot down the strip
// good for testing purposes
void colorChase(uint32_t c, uint8_t wait) {
  int i;

  for (i=0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);  // turn all pixels off
  }

  for (i=0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c); // set one pixel
    strip.show();              // refresh strip display
    delay(wait);               // hold image for a moment
    strip.setPixelColor(i, 0); // erase pixel (but don't refresh yet)
  }
  strip.show(); // for last erased pixel
}
