#include <stdio.h>

/* testing printd function which prints an integer as string, 
   using recursion. given p 87 */ 

void printd(int n);

int main() 
{
  int x = -1234;

  printd(x);
  printf("\n");
}

/* printd: print n in decimal */
void printd(int n)
{
  printf("new invocation %d\n",n);
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n / 10)
    printd(n / 10);
  printf("about to putchar with n = %d\n", n);
  putchar(n % 10 + '0');
}
