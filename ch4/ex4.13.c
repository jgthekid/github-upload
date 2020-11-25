#include <stdio.h>
#include <string.h>

# define BIG "1000"

/*  recurseive version of reverse(s).  */ 

void reverse(char s[], int left, int right);

int main() 
{
  char X[] = "ummagumma da loopa 123";
  printf("%s\n",X);
  printf("string length: %lu\n", strlen(X)-1);
  reverse(X, 0, strlen(X)-1);
  printf("%s\n",X);
  printf("%s\n",BIG);
}

void reverse(char s[], int left, int right)
{
  char tmp;

  if (left < right) {
    tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;
    reverse(s, ++left, --right);
  }
}
