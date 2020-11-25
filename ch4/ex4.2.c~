#include <ctype.h>
#include <stdio.h> 

/* testing string to float converter given p 71 */
double ATOF(char s[]); /* AVOID NAMING CONFLICT */


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
  double val, power;
  int i, sign;

  for (i=0; isspace(s[i]); i++) /* skip whespace */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  return sign * val / power; 
}
