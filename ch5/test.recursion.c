#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* what if we return a value inside a recursive function call? */

int TESTER(int k) 
{
  k += 1;
  if (k == 7)
    return 123;
  int j = TESTER(k);
  return k;
}

int main()
{
  int i = TESTER(5);
  printf("%d\n",i);
}

/* as expected, return only sends value to inner call, 
   not outer function call in main */
