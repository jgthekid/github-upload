#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* testing reverse function given p 62 */

void reverse(char s[]);

int main()
{
  char u[] = "ummagumma da loopa";
  printf("%s\n", u);
  reverse(u);
  printf("%s\n", u);
}

void reverse(char s[])
{
  int c, i, j;
  
  for (i=0, j=strlen(s)-1; i < j; i++, j--) {
    c = s[i]; 
    s[i] = s[j];
    s[j] = c;
  }
}
