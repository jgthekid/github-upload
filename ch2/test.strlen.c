#include <stdio.h>

/* test function strlen given in text */

int krstrlen(char s[]);

int main() 
{
  char line[] = "ummagumma";
  printf("%d\n", krstrlen(line));
}

/* strlen taken, calling this krstrlen */
int krstrlen(char s[])
{
  int i;
  
  i = 0;
  while (s[i] != '\0')
    ++i;
  return i;
}
