uint32_t blendColors(uint32_t c1, uint32_t c2, float weight)
{
  byte  r1, g1, b1, r2, g2, b2, r_, g_, b_;

  // Need to decompose color into its r, g, b elements
  g1 = (c1 >> 16) & 0x7f;
  r1 = (c1 >>  8) & 0x7f;
  b1 =  c1        & 0x7f;
  g2 = (c2 >> 16) & 0x7f;
  r2 = (c2 >>  8) & 0x7f;
  b2 =  c2        & 0x7f;
  
  r_ = (byte) ((r1 * weight) + (r2 * (1 - weight)));
  g_ = (byte) ((g1 * weight) + (g2 * (1 - weight)));
  b_ = (byte) ((b1 * weight) + (b2 * (1 - weight)));
  
  return strip.Color(r_,g_,b_);
}

