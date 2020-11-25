#include <stdio.h>

/* define a ^ operator and use it */

int power(int m, int n);

int main() 
{
  int i;

  for (i=0; i<10; ++i)
    printf("%d %d %d\n", i, power(2,i), power(-3,i));
  return 0;
}

/* define power function (requires n>0 and int) */

int power(int base, int n)
{
  int p;
  
  p = 1;
  for (p=1; n>0; --n)
    p = p*base;
  return p;
}

