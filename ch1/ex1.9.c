#include <stdio.h>

/* count characters in input */

int main() {
  int c;
  
  while ((c = getchar()) != EOF) {
    putchar(c);
    if (c == ' '){ 
      while ((c = getchar()) == ' '){ /* eat up all the other spaces */
        ;
      }  
      putchar(c);
    }
  }
}
  
