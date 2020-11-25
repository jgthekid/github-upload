#include <ctype.h>
#include <stdio.h>

/* testing fourth strcpy given on p 106 */

void STRCPY(char *s, char *t); //name conflict

/* STRCPY: copy t to s; pointer version 3 */
void STRCPY(char *s, char *t)
{
  while ((*s++ = *t++)) //c99 complains if only one set of ()
    ;
}

int main()
{

  char sd[] = "xxx";
  char sc[] = "abcdefghi";

  STRCPY(sd, sc);

  printf("%s\n",sd);
  printf("%s\n",sc); //why does this pointer no longer point to the beginning?
}


/* note: i first tried this with a smaller destination than source, ie

  char sd[] = "xxx";
  char sc[] = "abcdefghi";

when I compiled, the function worked properly in that it copied the source 
into the destination properly, BUT 
shifted the pointer of the initial entry of the source string by the number of 
entries in the destination string before calling strcpy, +1. 
I'm going to say that this behaviour is an implementation-specific error 
due to the mistake of trying to cram too much data into too small of an array, 
and move on. 

*/
