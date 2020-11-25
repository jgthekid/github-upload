#include <stdio.h>

/* can we return two vars at once? */
char[2],int twoOuts();

int main(){
  char st[4] ;
  st[0] = '1';
  st[1] = '2';
  st[2] = st[3] = '\0';
  printf("%s,end\n",st);
  
  char[2] x;
  int y;
  x,y = twoOuts;
  printf("%s, and %d",x,y)
}

char[], int twoOuts(){
  char[2] s;
  int i = 1;
  s[0] = 'f';
  s[1] = 'g';
  return s,i;
}
  
