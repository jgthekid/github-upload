#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/* modify itoa() to handle -2^{N-1} */

void itoa(int n, char s[]);
void itobits(int x, char s[]);
void reverse(char s[]);

int main()
{
  /* sanity checks */
  int n = ~(~0U >> 1);
  char v[200];
  char bits[33];

  printf("%d\n",n);
  itobits(n, bits);
  printf("%s\n", bits);


  printf("%d\n",n);


  /* test itob */

  n = ~(~0U >> 1);
  itoa(n, v);
  printf("%d : %s\n", n, v); 
    
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
  int i, sign;
  unsigned int m;

  if ((sign = n) < 0)  /* record sign */
    m = -n ;    /* make n positive */
  else
    m = n;
  i = 0;
  do {  /* generate digits in reverse order */
    s[i++] = m % 10 + '0'; /* get next digit */
  } while ((m /= 10) > 0);  /* delete it */
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

