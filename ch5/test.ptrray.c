#include <stdio.h>
#include <string.h>

/* is the name of an int array a pointer to the first element like a string? */

int main()
{
  int a[] = {6,9};
  int b[] = {31,13};
  if (*a == a[0])
    printf("%d\n",*a);
  /* yes, appears to work. */

  int *ptr[] = {a, b};
  
  // from month-day malarchy
  char y0[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  char y1[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  char *daytab[] = {y0, y1};
  printf("should be 0: %d\n",*(*(daytab))++  );
  printf("should be 31: %d\n",*(*(daytab))++  );
  printf("should be 28: %d\n",*(*(daytab))++  );

  
}
