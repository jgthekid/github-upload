#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

/* extend find to take command line arguments, p 117 */

/* need different name for getline to avoid stdio.h conflict */
int getLine(char *s, int max);

int main(int argc, char *argv[])
{
  char line[MAXLINE];
  long lineno = 0;
  int c, except = 0, number = 0, found = 0;

  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0]) {
      switch(c) {
      case 'x': 
        except = 1;
        break;
      case 'n':
        number = 1;
        break;
      default:
        printf("find: illegal option %c\n", c);
        argc = 0;
        found = -1;
        break;
      }
    }
  if (argc != 1)
    printf("Usage: find -x -n pattern\n");
  else 
    while (getLine(line, MAXLINE) > 0) {
      lineno++;
      if ((strstr(line, *argv) != NULL) != except) {
        if (number)
          printf("%ld:", lineno);
        printf("%s", line);
        found++;
      }
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
