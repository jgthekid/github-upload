#include <stdio.h>

/* what if we repeat getchar() without putchar()? */

int main() {
  /*  int c;
  
  c = getchar();
  c = getchar();
  putchar(c);
  */
  /* what if we repeat putchar? */
  int d; 
  d = getchar();
  putchar(d);
  putchar(d);
}
  
