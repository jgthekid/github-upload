#include <stdio.h>

/* need different name for getline to avoid stdio.h conflict */
int getLine(char *s, int max);

/* getLine: get line into s, return length, pointer version */
int getLine(char *s, int lim)
{
  int c, i;
  char *s0 = s;

  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    *s++ = c;
  if (c == '\n')
    *s++ = c;
  *s = '\0';
  return s - s0;
}
