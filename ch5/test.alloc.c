#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;   /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
    allocp += n;
    return allocp - n; /* old p */
  } else   /* not enough room */ 
    return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

/* 
not sure how to test this.. doesn't the line 

static char allocbuf[ALLOCSIZE]; 

allocate the needed space?? 

yes but this function will be needed for hairier times..
*/

int main()
{
  int N = 10;
  int i;

  char *pp;
  pp = alloc(N);

  for (i=0; i < N; i++) {
    *pp = 'a' + i;
    pp++;
  }
  printf("%c\n", *(pp-N+1));
  
  afree(pp);
  for (i=0; i < N; i++) {
    *pp = '0' + i;
    pp++;
  }
  
  printf("%c\n", *(pp-N+1));

}
