#include <stdio.h>

/* write function setbits(x,p,n,y) that returns x with 
   the n bits that begin at position p set to the rightmost 
   n bits of y, leaving the other bits unchanged */


unsigned setbits(unsigned x, int p, int n, unsigned y) ;


int main()
{ 
  unsigned int x, y, r;
  x = 1363;
  y = 11111;
  r = setbits(x,9,7,y);
  printf("%u\n",r);
  
}


unsigned setbits(unsigned x, int p, int n, unsigned y) 
{
  unsigned int y0, x0;
  /* move y bits to desired range */
  y0 = (~(~0 << n) & y) << (p+1-n);
  /* zero out desired range in x */
  x0 = ~(~(~0 << n) << (p+1-n)) & x; 
  /* combine */
  return y0 | x0;
}
