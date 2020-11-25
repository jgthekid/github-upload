#include <stdio.h>

/* testing the rand and srand functions from p46 */
/* some ambiguity on scoping in my mind */

int rand(void);
void srand(unsigned int seed);

int main()
{ 
  int x, next;
  next = 1
  x = rand();
  printf("%d",x);

}

/* rand:return pseudo-random int on 0..32767 */
int rand(void) 
{
  next = next*1103515245 + 12345;
  return (unsigned int)(next/65536)%32768;
}

/* srand: set seed for rand() */
void srand(unsigned int seed)
{
  next = seed;
}
/* ????????? */
