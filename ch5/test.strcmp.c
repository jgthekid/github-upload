#include <ctype.h>
#include <stdio.h>

/* testing pointer version of STRCMP given on p 106 */

/* STRCMP: return <0 if s<t, 0 if s==t, >0 if s>t */
int STRCMP(char *s, char *t)
{
  for ( ; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}


int main()
{
  char sd[] = "wxyz";
  char sc[] = "abcdefghijklm";

  int i = STRCMP(sd, sc);

  printf("%d\n", i);
  printf("%s\n", sd);
  printf("%s\n", sc); //why does this pointer no longer point to the beginning?
}
