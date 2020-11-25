#include <stdio.h>
/* play with #define */

#define SQUARE(x) (x) * (x)

/* concatenate */
#define paste(front, back) front ## back

int main()
{
  printf("%d\n",SQUARE(3+1));

  int name1 = 1;
  paste(name,1) = 3;
  printf("%d\n", name1);

}
