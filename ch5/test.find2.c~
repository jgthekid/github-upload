#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

/* revisit babygrep, p 116 */

/* need different name for getline to avoid stdio.h conflict */
int getLine(char *s, int max);

int main(int argc, char *argv[])
{
  char line[MAXLINE];
  int found = 0;

  if (argc != 2)
    printf("Usage: find pattern\n");
  else
    while (getLine(line, MAXLINE) > 0)
      if (strstr(line, argv[1]) != NULL) {
        printf("%s", line);
        found++;
      }
  return found;
}

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
