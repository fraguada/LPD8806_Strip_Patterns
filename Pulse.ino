//pulse
void pulse(uint8_t r, uint8_t g, uint8_t b, uint8_t steps, uint8_t wait)
{
  int t = 0;
  float lev = 0;
  boolean dir = true;
  byte r2, g2, b2;

  while(1){

    if(t < steps && dir)
    {
      t++;
      lev = ((float)t / (float)steps);

    }
    else
    {
      dir = false;
      if(t > 0){
        t--;
        lev = ((float)t / (float)steps);
      } 
      else {
        dir = true;
      }
    }

    for(int i=0; i<strip.numPixels(); i++) {
      r2 = (byte)((float)r * lev);
      g2 = (byte)((float)g * lev);
      b2 = (byte)((float)b * lev);
      strip.setPixelColor(i, r2, g2, b2);
    }
    strip.show();
    delay(wait);
  }
}

