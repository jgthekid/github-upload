#include <stdio.h>

/* count each character */

#define AC 128

int main() 
{
  int c, i; 
  int nchar[AC];
  
  for (i=0; i<AC; ++i)
    nchar[i] = 0;

  while((c = getchar()) != EOF)
    ++nchar[c];
    
  for (i=0; i<AC; ++i) {
    putchar(i);
    printf(" %d %d\n", i, nchar[i]);
  }
}
