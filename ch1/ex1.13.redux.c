#include <stdio.h>

/* histogram of word lengths */
/* "word" is crudely defined to be a string of non-whitespace characters,
   eg 'end.' is a 4-character word */

#define IN 1 /* in a word */
#define OUT 0 /* outside a word */
#define MAXWORD 20 /* maximum word length */

int main() 
{
  
  int c, state, i;  
  int h[MAXWORD+1];
  for (i=0; i <= MAXWORD+1; ++i) h[i] = 0;
  state = OUT;
  i = 0;

  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      ++h[i];
      i=0;
    }
    else {
      ++i;
      if (state == OUT) {
        state = IN;
      }
    }
  }
  int k;
  for (k=1; k <= MAXWORD+1; ++k) {
    printf("%d: %d\n",k,h[k]);
    }
}
