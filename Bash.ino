void colorBash(uint32_t c) {

  byte r,g,b;
  // Need to decompose color into its r, g, b elements
  g = (c >> 16) & 0x7f;
  r = (c >>  8) & 0x7f;
  b =  c        & 0x7f;

  for (int i=0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, r,g,b);
  }
  strip.show();
  delay(10);
}
