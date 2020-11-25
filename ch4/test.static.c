#include <stdio.h>

/* what does a variable start with? */

int main() 
{
  static int x;
  
  if (x == 0)
    printf("yes\n");

}
