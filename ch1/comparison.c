#include <stdio.h>

int main() 
{
  /*  printf("test float against int comparison \n");
  int x = 0;
  float y = 0.0;
  if (x<y){
    printf("%d < %f \n", x, y);
  }
  if (x>y){
    printf("%d > %f \n", x, y);
  }
  if (x==y){
    printf("%d = %f \n", x, y);
  }
  printf("how to break this? \n");
  */
  float x = 1.0, y = 3.0;
  float z = (x+1)*2/y;
  z = z/2.0;
  float a = 2.0/3.0;
  if (z == a){printf("%f = %f \n",z,a);}
  if (z < a){printf("%f < %f \n",z,a);}
  if (z > a){printf("%f > %f \n",z,a);}
  
}   

