#include <stdio.h>

/* write function invert(x,p,n) taht returns x with the n bits 
   that begin at position p inverted, leaving the others unchanged */


unsigned invert(unsigned x, int p, int n);

int main()
{ 
  unsigned int x, y, r;
  x = 1363;
  y = 11111;
  r = invert(x,8,6);
  printf("%u\n",r);
  
}


unsigned invert(unsigned x, int p, int n) 
{
  unsigned int y0, x0;
  /* mask in desired range (this might be safer with 0U) */
  x0 = ~(~0 << n) << (p+1-n);
  /* combine and flip */
  return ~(x0 ^ ~x);
}
