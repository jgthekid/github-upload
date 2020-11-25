#include <stdio.h>

/* print fahrenheit - celsius conversion table
for fahr = 0, 20, ..., 300 */

int main() 
{
  float fahr, cels;
  int lower, upper, step;

  lower = 0; /* lower limit of temp table */ 
  upper = 300; /* upper limit of temp table */
  step = 20; /* step size */

  fahr = lower; 
  while (fahr <= upper) {
    cels = (5.0/9.0)*(fahr-32); /*this will round.. */
    printf("%5.1f %6.1f\n", fahr, cels);
    fahr = fahr+step;
  }
}
