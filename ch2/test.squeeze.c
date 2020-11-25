#include <stdio.h>

/* testing the squeeze function given in sec 2.8 p47 */
void squeeze(char s[], int c);

int main()
{ 
  char x[] = "where are we going?";
  squeeze(x, ' ');
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
