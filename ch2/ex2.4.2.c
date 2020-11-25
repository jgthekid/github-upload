#include <stdio.h>

/* squeeze alternate: delete each character
 in string s1 that matches any character in s2 */

/* crude idea: apply squeeze to each char in s1 */
/* this appears to work just fine... */

  
void squeeze(char s[], int c);
void squeeze2(char s1[], char s2[]);
void squeze(char s1[], char s2[]);

int main()
{ 
  char x[] = "where are we going?";
  char y[] = "when will we be there?";
  squeze(x,y);
  printf("%s\n",x);
}


/* more efficient? combine into one function */
void squeze(char s1[], char s2[])
{
  int i, j, k;
  int MATCH = 0;
  
  for (i = j = 0; s1[i] != '\0'; i++) 
    {
    for (k = 0; s2[k] != '\0'; k++) 
      {
      if (s1[i] == s2[k]) /* have a match, dont write */
        MATCH = 1; 
      /* still don't know how to break */
      }
    if (MATCH == 0)
      s1[j++] = s1[i];
    MATCH = 0;
    }
  s1[j] = '\0';
}
  
/* still an n^2 alg but at least its one function */
/* would be more efficient than first attempt with break */
/* (i could prob figure that out but Im playing along with the book) */


