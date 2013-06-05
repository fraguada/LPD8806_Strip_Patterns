void rainbow(uint8_t wait) {
  int i, j;
   
  for (j=0; j < 384; j++) { // 3 cycles of all 384 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel( (i + j) % 384));
    }
    strip.show(); // write all the pixels out
    delay(wait);
  }
}
