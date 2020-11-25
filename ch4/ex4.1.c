#include <stdio.h>

/* write the function strrindex(s,t), 
which returns of the _rightmost_ occurrence of t in s, 
or -1 if there is none */

/* as simple as moving the match test outside the loop? */
/* even simpler? add another variable to allow loop to pass over the first match */

int strrindex(char source[], char searchfor[]);

/* strindex: return index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
  int i, j, k;
  int match = -1;

  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      match = i; /* if match, mark starting point */
  }
  
  return match;
}
