#include <stdio.h>

/* count lines in input */

int main() {
  long n;
  int c;
  
  n = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++n;
    }
  }
  printf("%ld\n",n);
  
}
  
