#include <stdio.h>

/* testing bitcount() given in sec 2.10, p 50 */

int bitcount(unsigned x);

int main()
{ 
  unsigned int x, y, r;
  x = 1363;
  r = bitcount(x);
  printf("%u\n",r);

}

int bitcount(unsigned x)
{
  int b = 0;
  
  while (x != 0 ) {
    x &= (x-1);
    ++b;
  }
  return b;
}
