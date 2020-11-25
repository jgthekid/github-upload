#include <stdio.h>

/* print fahrenheit - celsius conversion table
for fahr = 300, 280, ..., 0 */

# define UPPER 300
# define LOWER 0
# define STEP 20

int main() 
{
  float fahr;
  for (fahr = UPPER; fahr >= LOWER ; fahr = fahr - STEP){
    printf("%6.1f %6.1f\n", fahr, (5.0/9.0)*(fahr-32.0));
  }
}
