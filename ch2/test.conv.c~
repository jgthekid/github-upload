#include <stdio.h>

/* testing lower function given in sec2.7 p.43 */

int lower(int c);

int main()
{ 
  int x = 'V';
  x = lower(x);
  printf("%c\n",x);
}


/* lower: convert uppercase char to lowercase */
int lower(int c)
{
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else 
    return c;
}
