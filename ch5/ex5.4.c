#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* write the function strend(s,t), 
which returns 1 if the string t occurs at the end of the string s, 
and zero otherwise. 
*/

/* ASSUMPTION: t nonempty */

int strend(char *s, char *t) //caps to avoid name conflict
{
  while ((*s != *t) && (*s != '\0')) // find beginning of t in s
    s++; // don't overshoot!
  if (*s == '\0')
    return 0;
  int i = 0;
  while (*s == *(t+i)) {
    if (*(t+i) == '\0') { //both strings at null -> success
      return 1;
    }
    s++;
    i++;
  } // t or s ended, start over 
  int result = strend(s, t);
  return result;
}

int main()
{
  char a[] = "UMMAG is like ummag but capitalized ummagummag has ummagummag1";
  char b[] = "ummagummag";


  printf("search for: %s\n", b);
  printf("at the end of: %s\n", a);
  int i = strend(a, b);
  printf("%d\n", i);


}
