#include <stdio.h>

/* write function rightrot(x,n) returns the value of the integer x 
   rotated to the right by n bit positions */

/* after refusing to do a for loop then settling on the 32 bit hardwire version, 
   I looked up answers online and found a super nifty for loop */

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
  int i;
  while (n > 0) {
       if ((x & 1) == 1) 
         x = (x >> 1) | ~(~0U >> 1);
       else
         x = x >> 1;
       --n; 
  }
  return x;
}
