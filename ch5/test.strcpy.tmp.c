#include <ctype.h>
#include <stdio.h>

/* testing fourth strcpy given on p 106 */

void STRCPY(char *s, char *t); //name conflict

/* STRCPY: copy t to s; pointer version 3 */
void STRCPY(char *s, char *t)
{
  int i;

  i = 0;
  while ((s[i] = t[i]) != '\0') {
    i++;
  }
}

int main()
{
  char sd[] = "wxyz";
  char sc[] = "abcdefghijklm";

  STRCPY(sd, sc);

  printf("%s\n",sd);
  printf("%s\n",sc); //why does this pointer no longer point to the beginning?
}
