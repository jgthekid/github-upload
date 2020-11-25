#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Write a function expand(s1,s2) that expands 
   shorthand notations like a-z in the string s1 
   into the equivalent abc...xyz */

/* problem statement is kind of cryptic.. assumptions: 
   + a range of zero length returns only the LHS (eg "a-a" -> "a") 
   + bigger LHS than RHS decrements (eg "0-4" -> "43210")
   + mismatching types returned literally  (eg "a-0" -> "a-0")
   + no error catching for s2 length - assumes user knows how long it needs to be 
*/

void expand(char s1[], char s2[]);

int main()
{
  char u1[] = "0-3ummagumma -g-a0-4- loopa";
  char u2[1]; /* not sure why this is working */
  printf("%s\n", u1);
  expand(u1,u2);
  printf("%s\n", u2);
}

void expand(char s1[], char s2[])
{
  s2[0] = s1[0];
  char c;
  int i,j;
  i = j = 0;
  
  for (i=0, j=0; s1[i] != '\0'; i++)
    if (s1[i] == '-') {
      /* check if bounds match type (eg lowercase on left and right) */
      if (
          (isdigit(s1[i+1]) && isdigit(s1[i-1])) ||
          ( ('A' <= s1[i-1] && 'Z' >= s1[i-1]) &&
            ('A' <= s1[i+1] && 'Z' >= s1[i+1]) ) ||
          ( ('a' <= s1[i-1] && 'z' >= s1[i-1]) &&
            ('a' <= s1[i+1] && 'z' >= s1[i+1]) ) 
          )
        {
        /* check range, expand */
        if (s1[i-1] < s1[i+1]) {
          c = ++s1[i-1];
          while (c <= s1[i+1])
            s2[j++] = c++;
        }
        else if (s1[i-1] > s1[i+1]) { /* decrement mode */
          c = --s1[i-1];
          while (c >= s1[i+1])
            s2[j++] = c--;
        }
        /* no else: trivial range is just 1 character */
        i++; /* skip right hand side and - in s2 */
      }
      else /* insert - if not a valid range */
        s2[j++] = s1[i];
    }
    else 
      s2[j++] = s1[i];
  s2[j] = '\0';
}
