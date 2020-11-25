#include <stdio.h>

/* testing pre vs post fix in for loop */
/* it could matter but i dont think it does */

int main()
{ 
  int i;
  
  for (i = 0; i < 5 ; i++) {
    printf("%d\n",i);
  }
  for (i = 0; i < 5 ; ++i) {
    printf("%d\n",i);
  }
}
