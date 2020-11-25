#include <stdio.h> 

#define TAU 0.000001

/* babylon method for square root */

double babyroot(double S);
double ABS(double x) ;

/* test */
int main() 
{
  double s = -11;
  printf("input: %f , output: %f\n", s, babyroot(s));
}
/* ATOF: convert string s to double */
double babyroot(double S)
{
  double x1, x0, tmp;
  x1 = 1.0;
  x0 = 1.0; /* consider improving initial guess.. */

  do {
    tmp = x1;
    x1 = x1/2.0 + S/(x1*2.0);
    x0 = tmp; 
    printf("new: %f , old: %f\n", x1, x0);
  } while (ABS(x1 - x0) > TAU) ;
  return x1;
}

double ABS(double x) 
{
  if ( x < 0 ) 
    return -x;
  else 
    return x; 
}
