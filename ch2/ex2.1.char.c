#include <stdio.h>

/* determine ranges of char, short, int, long,
   both signed and unsigned
   bonus: all float types */

#define MAXIT 100000000

int main()
{
  /* char */
  int i = 0;
  char next = 0, last = 0;
  /* going up */
  next = last + 1;
  while ((next > last) && (i < MAXIT)) {
    last = next;
    ++next;
    ++i;
  }
  printf("biggest char: %c\n", last);
  printf("int value: %d\n", last);

  /* going down */
  next = 0; last = 0;
  next = last - 1;
  while ((next < last) && (i < MAXIT)) {
    last = next;
    --next;
    ++i;
  }
  printf("smallest char: %c\n", last);
  printf("int value: %d\n", last);

  /* signed char */
  i = 0;
  unsigned char snext = 0, slast = 0;

  /* going up */
  snext = slast + 1;
  while ((snext > slast) && (i < MAXIT)) {
    slast = snext;
    ++snext;
    ++i;
  }
  printf("biggest unsigned char: %c\n", slast);
  printf("int value: %d\n", slast);

  /* going down */
  snext = 0; slast = 0;
  snext = slast - 1;
  while ((snext < slast) && (i < MAXIT)) {
    slast = snext;
    --snext;
    ++i;
  }
  printf("smallest unsigned char: %c\n", slast);
  printf("int value: %d\n", slast);


  /* unsigned int */
  unsigned int unext = 0, ulast = 0;
  /* going up */
  unext = ulast + 1;
  while (unext > ulast) {
    if (unext <10)
      printf("unext: %u, ulast: %u\n",unext,ulast);
    ulast = unext;
    ++unext;
  }
  printf("biggest unsigned int: %u\n", ulast);

  /* going down */
  unext = 0; ulast = 0;
  unext = ulast - 1;
  while (unext < ulast) {
    ulast = unext;
    --unext;
  }
  printf("smallest unsigned int: %u\n", ulast);


}
