#include <stdio.h>

#define MAXLINE 100

/* rudimentary calculator */
/* illustrating declaring non-int-returning function..? */
/* uses atof from previous page */
int main()
{
  double sum, ATOF(char []); /* need this declaration of atof or a prototype */
  char line[MAXLINE];
  int getLine(char line[], int max);
  
  sum = 0;
  while (getLine(line, MAXLINE) > 0)
    printf("%f\t%f\n", ATOF(line), sum += ATOF(line));
  return 0;
}
