#include <ctype.h>
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

/*   char num2[] = "  -10.192E3"; */
/*   double f2 = ATOF(num2); */
/*   printf("%f\n",f2); */

/*   char num3[] = "  +10.192E-3"; */
/*   double f3 = ATOF(num3); */
/*   printf("%f\n",f3); /\*should not and does not work *\/ */
/* } */

/* ATOF: convert string s to double */
double ATOF(char s[])
{
  double val, power;
  int i, sign;
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
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  /* if scinotation, collect exponent into power 
   */
  if (s[i] == 'e' || s[i] == 'E' ) {   
    ++i;
    int k, exp, sgn; //sgn records exponent sign in 0 or 1
    exp = 0;
    sgn = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') {
      ++i;
    }
    while (isdigit(s[i])) { //atoi loop
      exp = 10 * exp + (s[i++] - '0');
    }
    if (sgn > 0) {
      for (k=0; k < exp; ++k) 
        power /= 10.0;
    }
    else {
      for (k=0; k < exp; ++k) 
        power *= 10.0; // mult inverted bc we divide by power later
    }
  } // else finished
  return sign * val / power; 
}
