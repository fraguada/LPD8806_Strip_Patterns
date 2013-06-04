//pulse
void pulse(uint32_t c1, uint8_t steps, uint8_t wait)
{
  int t = 0;
  boolean cycle = false;
  float lev = 0;
  boolean dir = true;
  byte r2, g2, b2;
  
  byte  r, g, b;

  // Need to decompose color into its r, g, b elements
  g = (c1 >> 16) & 0x7f;
  r = (c1 >>  8) & 0x7f;
  b =  c1        & 0x7f; 

  while(!cycle){

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
        cycle = true;
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

