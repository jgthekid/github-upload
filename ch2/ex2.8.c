#include <stdio.h>

/* write function rightrot(x,n) returns the value of the integer x 
   rotated to the right by n bit positions */


unsigned rightrot(unsigned x, int n);

int main()
{ 
  unsigned int x, y, r;
  x = 1363;
  r = rightrot(x,6);
  printf("%u\n",r);
  
}

unsigned rightrot(unsigned x, int n)
{
  unsigned int y;
  /* mask for bits to be wrapped */
  y = ~(~0 << n);
  return ((x & y) << (32 - n)) | (x >> n); 
}
