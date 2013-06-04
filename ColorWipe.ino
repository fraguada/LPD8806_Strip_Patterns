// fill the dots one after the other with said color
// good for testing purposes
void colorWipe(uint32_t c, uint8_t wait) {
  int i;
  float y;
  byte  r, g, b, r2, g2, b2;

  // Need to decompose color into its r, g, b elements
  g = (c >> 16) & 0x7f;
  r = (c >>  8) & 0x7f;
  b =  c        & 0x7f;

  for (i=0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, r,g,b);
    strip.show();
    delay(wait);
  }
}
