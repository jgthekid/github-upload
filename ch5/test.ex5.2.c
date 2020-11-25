#include <ctype.h>
#include <stdio.h>

/* loop executing getint p 96 */

#define SIZE 10

int main()
{

  int n, d, getfloat(double *);
  double array[SIZE];
  
  for (n = 0; n < SIZE && (d = getfloat(&array[n])) != EOF; n++)
    printf("%f ", array[n]);

  printf("\n");
}
