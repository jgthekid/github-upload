#include <ctype.h>
#include <stdio.h>

/* write getfloat, the floating-point analog of getint. 
   what type does getfloat return as its function value?. 
still int. 
*/

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getfloat(double *pn)
{
  int c, sign;

  while (isspace(c = getch())) /* skip whitespace */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
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
  if (c == '.') { 
    if (isdigit(c = getch())) {
      double power = 1.0;
      do {
        *pn = 10.0 * *pn + (c - '0') ;
        power *= 10.0;
      } while (isdigit(c = getch()));
      *pn /= power;
      } else {
      ungetch(c);
      ungetch('.');
    }
  }
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}
