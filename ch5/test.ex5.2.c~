#include <ctype.h>
#include <stdio.h>

/* loop executing getint p 96 */

#define SIZE 10

int main()
{

  int n, d, array[SIZE], getint(int *);
  
  for (n = 0; n < SIZE && (d = getint(&array[n])) != EOF; n++)
    printf("c%c d%d ", d, array[n]);

  printf("\n");
}
