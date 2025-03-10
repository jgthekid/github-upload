#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/* itob(n,s,b): convert int n into a base b character 
 representation in the string s. */

/* specs/assumptions:
   + s is big enough
   + max base is 36 
*/


void itob(int n, char s[], int b);
void itobits(int x, char s[]);
void reverse(char s[]);

int main()
{
  int n = 56;
  char v[20];
  char bits[33];
  
  /* test itob */
  n = 277;
  itob(n, v, 9);
  printf("%d : %s\n", n, v); 
    
}

/* itoa: convert n to characters in s */
void itob(int n, char s[], int b)
{
  int i, sign;
  unsigned int m, tmp;

  if ((sign = n) < 0)  /* record sign */
    m = -n ;    /* make n positive */
  else
    m = n;
  i = 0;
  do {  /* generate digits in reverse order */
    if ((tmp = m % b) > 9) 
      s[i++] = tmp - 10 + 'a'; /* need letter to represent big digits */
    else 
      s[i++] = tmp + '0'; /* else use digit */
  } while ((m /= b) > 0);  /* delete that digit */
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}


/* pulled from earlier this chapter */
void reverse(char s[])
{
  int c, i, j;
  
  for (i=0, j=strlen(s)-1; i < j; i++, j--) {
    c = s[i]; 
    s[i] = s[j];
    s[j] = c;
  }
}

/* return string of bit representation of int x */
void itobits(int x, char s[])
{
  int i = 0;
  unsigned int z = ~0;

  do {
    s[i++] = (x & 1) + '0';
    x >>= 1;
  } while ( (z >>= 1) != 0 );
  s[i] = '\0';
  reverse(s);
}

