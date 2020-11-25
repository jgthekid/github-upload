#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int trim(char s[]);

int main()
{
  char s[] = "";
  int j = trim(s);
  printf("%d:%smuahahah\n",j,s);
}


/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
  int n;
  
  for (n = strlen(s)-1; n >= 0; n--)
    if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
      break; 
  s[n+1] = '\0';
  return n;
}
