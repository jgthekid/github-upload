#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int strrindex(char source[], char searchfor[]);
int getLine(char line[], int max);

char pattern[] = "ip"; /* pattern to search for */

/* find all lines matching pattern */
/* this second version used for testing ex4.2.c */

int main()
{
  char line[MAXLINE];
  int found = 0;
  int marker = 0;

  while (getLine(line, MAXLINE) > 0) {
    if ((marker = strrindex(line, pattern)) >= 0) {
      printf("%s", line);
      printf("%d\n", marker);
      found++;
    }
  }
  return found;
}

