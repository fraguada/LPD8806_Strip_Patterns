//pulse
void blend(uint32_t c1,uint32_t c2, uint8_t steps, uint8_t wait)
{
  int t = 0;
  float lev,lev_;
  boolean dir = true;

  byte  r1, g1, b1, r2, g2, b2, r_, g_, b_;

  // Need to decompose color into its r, g, b elements
  g1 = (c1 >> 16) & 0x7f;
  r1 = (c1 >>  8) & 0x7f;
  b1 =  c1        & 0x7f;
  g2 = (c2 >> 16) & 0x7f;
  r2 = (c2 >>  8) & 0x7f;
  b2 =  c2        & 0x7f;

  while(1){

    if(t < steps && dir)
    {
      t++;
      lev = ((float)t / (float)steps);
      lev_ = ((float)(steps-t) / (float)steps);

    }
    else
    {
      dir = false;
      if(t > 0){
        t--;
        lev = ((float)t / (float)steps);
        lev_ = ((float)(steps-t) / (float)steps);
      } 
      else {
        dir = true;
      }
    }

    for(int i=0; i<strip.numPixels(); i++) {
      r_ = (byte)((float)r1 * lev)+(byte)((float)r2 * lev_);
      g_ = (byte)((float)g1 * lev)+(byte)((float)g2 * lev_);
      b_ = (byte)((float)b1 * lev)+(byte)((float)b2 * lev_);
      strip.setPixelColor(i, r_, g_, b_);
    }
    strip.show();
    delay(wait);
  }
}


