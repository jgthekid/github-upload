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
  int b;
  
  for (b = 0; x != 0; x >>= 1)
    if (x & 01) /* not sure why they use 01 */
      ++b;
  return b;
}
