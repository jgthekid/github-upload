#include <stdio.h>

/* temp conversion redux */
/* use function for conversion formula */

float conv(int fahr);

# define UPPER 300
# define LOWER 0
# define STEP 20

int main() 
{
  float fahr;
  for (fahr = UPPER; fahr >= LOWER ; fahr = fahr - STEP){
    printf("%6.1f %6.1f\n", fahr, conv(fahr));
  }
}

float conv(int fahr)
{
  float cels;
  cels = (5.0/9.0)*(fahr-32.0);
  return cels;
}

