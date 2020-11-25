#include <stdio.h>
#include <ctype.h>

/* convert string of hex digits to int */

int testchar(char a);
long int jghtoi(char h[]);

int main()
{ 
  char a[] = "0xfd90c22";
  long int b = jghtoi(a);
  printf("%ld\n",b);
}

/* this function is the exercise
   warning: no explicit checks on input string */
long int jghtoi(char h[])
{
  int i,k;
  long int r;
  /* skip that pesky leading '0x' */
  if (h[1] == 'x' || h[1] == 'X') 
    k = 2;
  else 
    k = 0;
  
  r = 0;
  for (i=k; (isdigit(h[i])) || 
         (h[i] >= 'a' && h[i] <= 'f') ||
         (h[i] >= 'A' && h[i] <= 'F');
       ++i ) 
    {
    if (isdigit(h[i]))
      r = r * 16 + h[i] - '0' ;
    else if (h[i] >= 'a' && h[i] <= 'f')
      r = r * 16 + h[i] - 'a' + 10;
    else 
      r = r * 16 + h[i] - 'A' + 10;
    }
  return r;

}
  

/* htoi: convert string of hex digits to int */
/*int htoi(char[] h)
{
  
  if (h[i] >= 'A' && h[i] <= 'F')
    return h[i]-0;
}
*/


/* testchar: testing char to int conversion */
/* what is the integer value of 'a'? */
int testchar(char a)
{
  int b = a-'a'+10;
  return b;
}
