#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* exercise 4.11: modify getop sothat it doesn't need to use ungetch.
   Hint: use an internal static variable */

/* seems like this also makes getch obsolete... */

/* note: this program requires that declared but unititialized
 variables have value zero. 
 That seems to work on this machine but could be implementation specific */

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;

  static int hold; // single-char buffer

  c = hold; 
  
  if (c == 0 || c == ' ' || c == '\t') { // buffer was empty or whitespace
    while ((s[0] = c = getchar()) == ' ' || c == '\t')
      ;
  }
  s[1] = '\0';
  if (!isdigit(c) && c != '.') {
    hold = 0;
    return c; // not a number
  }
  i = 0;
  if (isdigit(c)) // collect integer part
    while (isdigit(s[++i] = c = getchar()))
      ;
  if (c == '.')  // collect fraction part
    while (isdigit(s[++i] = c = getchar()))
    ;
  s[i] = '\0';

  if (c != EOF)
    hold = c; // set c aside for later
  return NUMBER;
}
