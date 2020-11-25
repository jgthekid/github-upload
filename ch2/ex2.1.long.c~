#include <stdio.h>

int main() 
{
  /* int */
  int i = 0;
  int inext = 0, ilast = 0;
  /* going up */
  inext = ilast + 1;
  while (inext > ilast) {
    ilast = inext;
    ++inext;
    ++i;
  }
  printf("biggest int: %d\n", ilast);

  /* going down */
  inext = 0; ilast = 0;
  inext = ilast - 1;
  i = 0;
  while (inext < ilast) {
    ilast = inext;
    --inext;
    ++i;
  }
  printf("smallest int: %d\n", ilast);


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


  /* short int */
  short int snext = 0, slast = 0;
  /* going up */
  snext = slast + 1;
  while (snext > slast) {
    slast = snext;
    ++snext;
    ++i;
  }
  printf("biggest short int: %d\n", slast);

  /* going down */
  snext = 0; slast = 0;
  snext = slast - 1;
  i = 0;
  while (snext < slast) {
    slast = snext;
    --snext;
    ++i;
  }
  printf("smallest short int: %d\n", slast);



}
