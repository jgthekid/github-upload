#include <ctype.h>
#include <math.h> 
#include <stdio.h> 


/* extend atof to handle scientific notation of the form 
   123.45e-6 
   where a floating-point number may be followed by e or E
   and an optionally signed exponent 
*/

/* [modified] string to float converter given p 71 */
double ATOF(char s[]);


/* commenting this region to avoid main clash in test.calc1 
   so that I can use this ATOF in that program */
/* int main() */
/* { */
/*   char num1[] = "+10000.192"; */
/*   double f1 = ATOF(num1); */
/*   printf("%f\n",f1); */

/*   char num2[] = "  -10.192"; */
/*   double f2 = ATOF(num2); */
/*   printf("%f\n",f2); */

/*   char num3[] = "  +-10.192"; */
/*   double f3 = ATOF(num3); */
/*   printf("%f\n",f3); /\*should not and does not work *\/ */
/* } */

/* ATOF: convert string s to double */
double ATOF(char s[])
{
  double val;
  int i, sign, power;
  int atoi(char[]), POW(int base, int n); 

  for (i=0; isspace(s[i]); i++) /* skip whespace */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
    printf("%d\n", power);
  }
  /* if scinotation, collect into string, use atoi, 
   then multiply power by 10^-atoi() */
  if (s[i] == 'e' || s[i] == 'E' ) {   
    ++i;
    char expa[5];
    int k = 0;
    if (s[i] == '-' || s[i] == '+' )
      expa[k++] = s[i++]; // else must be a digit 
    while (isdigit(s[i])) {
      expa[k++] = s[i++] ;
    }
    power *= POW(10, -(atoi(expa)));
    printf("%d : %d\n", power, POW(10, -(atoi(expa))));
  }
  return sign * val / (double) power; 
}
