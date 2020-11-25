#include <stdio.h>

/* verify that the expression getchar() != EOF is 0 or 1. */

int main() {
  int c = (getchar() != EOF);
  printf("%d \n",c);

  /*also print value of EOF */
  int x = EOF;
  printf("%d \n",x);

}
  
