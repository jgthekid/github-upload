#include <stdio.h>
/* define a macro swap(t,x,y) that interchanges two arguments of type t. */

/* assuming x and y are variables so dont need () */
#define swap(t,x,y) { t tmp; tmp = x; x = y; y = tmp;} 

#define SQUARE(x) (x) * (x)

/* concatenate */
#define paste(front, back) front ## back

int main()
{
  int N = 10;
  int M = 100;

  printf("%d %d\n", N, M);
  swap(int, N, M);
  printf("%d %d\n", N, M);

}
