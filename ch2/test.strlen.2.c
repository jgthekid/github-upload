#include <stdio.h>

/* test function strlen given in text */
/* also testing const in function argument (see p.40) */
/* this does not work bc attempts to reassign const */

int krstrlen(const char s[]);

int main() 
{
  int i,l;
  char line[] = "ummagumma";
  l = krstrlen(line);
  printf("%d\n", l );
  for (i=0; i < l ; ++i) 
    printf("%c", line[i]);
    printf("\n");
}

/* strlen taken, calling this krstrlen */
int krstrlen(const char s[])
{
  int i;
  
  i = 0;
  while (s[i] != '\0')
    ++i;
  return i;
}
