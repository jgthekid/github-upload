#include <stdio.h>

/* testing type conversions */

int lower(int c);

int main()
{ 
  int x = '3';
  printf("%c\n",x);
  printf("%d\n",x);
  int y = x - '0';
  printf("%d\n",y);
}


/* lower: convert uppercase char to lowercase */
int lower(int c)
{
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else 
    return c;
}
