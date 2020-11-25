#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* write a pointer version of the function strcat that we showed in chapter 2:
 strcat(s,t) copies the string t to the end of s. */

/* STRCAT: concatenate t onto s; pointer version; s must be big enough */
void STRCAT(char *s, char *t) //caps to avoid name conflict
{
  while ((*s)) //c99 complains if only one set of () 
    s++; // need to wait to increment to avoid passing \0

  while ((*s++ = *t++))
    ;
}

int main()
{
  char sd[20];
  sd[0] = 'x'; sd[1] = 'y'; sd[2] = 'z'; sd[3] = '\0';
  char sc[] = "abcdefghi";

  printf("target: %s\n",sd);
  printf("source: %s\n",sc);
  STRCAT(sd, sc);
  printf("result: %s\n",sd);



}
