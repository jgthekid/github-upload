#include <stdio.h>

/*  adapt the ideas of printd to write a recursive version of itoa.  */ 

int itoaR(char s[], int n, int i);

int main() 
{
  char X[20];
  int x = 666948;

  itoaR(X, x, 0);
  printf("%s\n",X);
}

/* itoaR: convert int to string, */
/* starting at position i */
/* i thought about using a static i but what if we call the function twice? */
int itoaR(char s[], int n, int i)
{
  if (n < 0) {
    s[i++] = '-';
    n = -n;
  }
  if (n / 10) {
    i = itoaR(s, n / 10, i);
  }
  s[i++] = n % 10 + '0'; 
  s[i] = '\0';
  return i;
} // fun!
