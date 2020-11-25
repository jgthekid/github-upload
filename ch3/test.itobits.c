#include <stdio.h>
#include <string.h>
#include <math.h>

/* i want a function that prints the binary representation of a given variable */

void itobits(int x, char s[]);
void reverse(char s[]);

int main()
{
  char v[40];
  int n = ~(~0U >> 1);
  v[0] = (n & 1) + '0';
  printf("%d\n",n);
  itobits(n, v); 
  printf("%s\n",v);
}

void itobits(int x, char s[])
{
  int i = 0;
  unsigned int z = ~0;

  do {
/*     z = z << 1; */
/*     printf("%d\n",z); */
    s[i++] = (x & 1) + '0';
    x >>= 1;
  } while ( (z >>= 1) != 0 );
/*   } while (i < 32); */
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
