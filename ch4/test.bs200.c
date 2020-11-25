#include <stdio.h> 
/* what is '\200' ? */

int main()
{
  char x[] = "\200";
  printf("%s \n", x);
}
