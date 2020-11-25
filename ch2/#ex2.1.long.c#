#include <stdio.h>

int main() 
{

  /* long int */
  /* brute force method takes forever, 
     need to be a bit cleverer */

  long int next = 2, last = 2;
  /* going up */
  next = next*2;
  while (next > last) {
    last = next; 
    next = next*2;
  }
  printf("biggest long int: %ld \n", (last-1+last));
  printf("what if we add 1: %ld \n", (last+last));

  /* going down */
  next = 2; last = 2;  
  next = -next*2;
  while (next < last) {
    last = next;
    next = next*2;
  }  
  printf("smallest long int: %ld \n", last);
  printf("what if we subtract 1: %ld \n", last-1);
}
