#include <stdio.h> 
#include <ctype.h> 
#include <stdlib.h> /* for atof() */


/* if we increment a pointer in a function will the pointer be advanced in main? */

void plusplus(char *s) 
{
  *s++ = '1';
}

int main()
{
  char s[] = "abcdef";
  printf("%c\n",*s);
  plusplus(s);
  printf("%c\n",*s);
  printf("%s\n",s);
}

