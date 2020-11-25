#include <stdio.h>

/* swap variables using pointers. */

void swap(int *px, int *py); /* interchange *px and *py */

int main()
{
  int x, y;
  x = 1;
  y = 0;

  printf("%d %d\n",x ,y);
  swap(&x, &y);
  printf("%d %d\n",x ,y);
}


void swap(int *px, int *py)
{
  int temp;
  
  temp = *px;
  *px = *py;
  *py = temp;
}

