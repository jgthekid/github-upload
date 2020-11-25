#include <stdio.h>
#include <string.h>

/* testing bitwise operators, see sec 2.9, p48 */
/* includes function getbits() given on p49 */

unsigned getbits(unsigned x, int p, int n) ;
void itobits(int x, char s[]);
void reverse(char s[]);

int main()
{ 
  int i, y1;

  unsigned int x = 279; /* = 2^8 + 13 */
  x = x & 0177; 
  printf("%u\n",x);
  x = ~0;
  printf("%u\n",x);
  x = 269;
  x = ~x;
  printf("%u\n",x);
  int y = 25;
  printf("%d\n",y);
  y = ~y;
  printf("%d\n",y);
  /* ~ appears to be flipping sign then subtracting 1, 
     not what I expected */

  /* so far my expectations are only met for unsigned int */

  /* let's try out getbits and see if we can clarify things */
  y = 5;
  y1 = getbits(~y,25,5);
  printf("%d\n",y1);

  unsigned x1;
  x = 27;
  x1 = getbits(x,5,6);
  printf("%u\n",x1);

  /* two's complement!! negative ints are the opposite and offset by 1 */
  y = 5;
  printf("%d\n",~y);

  /* play with << and >> */
  printf("play with << and >>\n");
  /* what does my compiler do with signed? */
  x = 24;
  x = x >> 3;
  printf("%u\n",x);


  y = -24;
  char s[33];
  itobits(y, s);
  printf("%s\n",s);
  y = y >> 3;
  printf("%u\n",y);
  itobits(y, s);
  printf("%s\n",s);
  /* appears to be doing "arithmetic shift", 
     leaving 1 for vacated bit in >> on signed ints */
  
}


/*getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) 
/* n and p dont have to be positive?!? test that */
{
  return (x >> (p+1-n)) & ~(~0 << n);
}


/* itobits created while reading ch3 */
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






