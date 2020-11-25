#include <stdio.h>

int POW(int base, int n); /* caps to avoid library definition of pow() */


int POW(int base, int n)
{
  int i, p;
  
  p = 1;
  for (i=1; i<=n; ++i)
    p = p*base;
  return p;
}
