#include <stdio.h>

/* copy input to output */
/* grabs keyboard input after executing 
   not sure how to send EOF to terminal */

int main() {
  int c;

  while ((c = getchar()) != EOF){
    putchar(c);
  }

}
  
