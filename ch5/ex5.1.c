#include <ctype.h>
#include <stdio.h>

/* as written, getint treats a + or - not followed by a digit 
   as a valid representation of zero. fix it to push such a 
   character back on the input. */

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getch())) /* skip whitespace */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);  /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
    if (!isdigit(c)) {
      ungetch(c);
      (sign == -1) ? ungetch('-') : ungetch('+');
      return 0;
    }
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}
