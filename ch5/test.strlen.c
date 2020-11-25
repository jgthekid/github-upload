#include <ctype.h>
#include <stdio.h>

/* p 99: 
   testing strlen function
*/

int strLen(char *s); //strlen name conflict

int main() 
{
  int n;
  char s[] = "ummagumma";
  
  char *ptr; 
  ptr = s;

  n = strLen(ptr);
  printf("%d\n",n);

  n = strLen(s);
  printf("%d\n",n);

  n = strLen("hello world");
  printf("%d\n",n);

}

int strLen(char *s)
{
  int n;
  
  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}
