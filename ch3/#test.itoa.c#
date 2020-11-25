#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/* testing itoa (convert int to char[]) given on p 64 */

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
  /* make sure n /= 10 does what I think it does */
  int n = pow(2,31)-1;
  char v[200];
  printf("%d\n",n);

  n += 1;
  printf("%d\n",n);
  /* yes */

  n = ~0 >> 2;
  printf("%d\n",n);

  /* test itoa */
  n = 10;
  itoa(n, v);
  printf("%d : %s\n", n, v); 
  /* interesting that this void function edits v but not n... */
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
  int i, sign;
  
  if ((sign = n) < 0)  /* record sign */
    n = -n ;    /* make n positive */
  i = 0;
  do {  /* generate digits in reverse order */
    s[i++] = n % 10 + '0';  /* get next digit */
  } while ((n /= 10) > 0);  /* delete it */
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
