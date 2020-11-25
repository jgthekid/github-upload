#include <stdio.h>

/* squeeze alternate: delete each character
 in string s1 that matches any character in s2 */

/* crude idea: apply squeeze to each char in s1 */
/* this appears to work just fine... */

  
void squeeze(char s[], int c);
void squeeze2(char s1[], char s2[]);

int main()
{ 
  char x[] = "where are we going?";
  char y[] = "when will we be there?";
  squeeze2(x,y);
  printf("%s\n",x);
}


/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
  int i, j;
  
  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}


/* squeeze2: delete all matches in s2 from s1 */
void squeeze2(char s1[], char s2[])
{
  int i;
  
  for (i = 0; s2[i] != '\0'; i++)
    squeeze(s1, s2[i]);
}
