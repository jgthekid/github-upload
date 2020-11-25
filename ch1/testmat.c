#include <stdio.h>

/* double array ~= matrix ? */

int main()
{
  int m[10][10];
  int i, j;

  for (i=1; i<5; ++i) {
    for (j=1; j<5; ++j) {
      if (i<j) 
        m[i][j] = i*i;
      else
        m[i][j] = j*j;
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }     
}

