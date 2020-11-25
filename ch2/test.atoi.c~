#include <stdio.h>

/* testing atoi function given in sec2.7 p.43 */

int atoi(char s[]);

int main()
{ 
  char strr[] = "698072";
  int str2 = atoi(strr);
  printf("%d\n",str2);
}


/* atoi: convert s to integer */
int atoi(char s[])
{
  int i, n; 

  n = 0;
  for (i=0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10*n + (s[i]-'0');
  return n;
}
