#include <stdio.h>

/* testing some scoping properties */

int main() 
{
  int i = 2;

  if (i > 0) {
    int i = 0; // new i scoped inside this if branch
    printf("%d\n", i); 
  }
  printf("%d\n", i); // back to old i

  // and some initialization stuff
  int a[3] = {1, 2, 3, 4};
  a[2] = 3;

  printf("%d\n", a[2]);
}

      
  
