#include <ctype.h>
#include <stdio.h>

/* loop executing getint p 96 */

#define SIZE 10

int main()
{

  int n, array[SIZE], int getfloat(double *);
  
  for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
    printf("%d ", array[n]);
  printf("\n");

}
