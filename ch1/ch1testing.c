#include <stdio.h>
int main() 
{
  short n = 10000;
  printf("fuck the world\n");
  printf("a string: %s \n","aaa");
  printf("a short int: %d \n", n);
  printf("how big can a short be on this computer? \n");
  printf("let's try powers of 2..");
  short next = 128;
  short last = 64;
  while (next > last) {
    printf("next: %d\t last: %d \n",next, last);
    last = next;
    next = next*2;
  }
  printf("now add 1 to see if largest short must be power of 2: %d \n", next+1);
}
