#include <stdio.h>

/* count characters in input */

int main() {
  long n;
  
  for (n = 0; getchar() != EOF; ++n)
    ;
  printf("%ld\n",n);
  
}
  
