#include <stdio.h>

/* print longest input line */

#define MAXLINE 1000 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);


int main()
{
  int len;  /* current line length */ 
  int max;  /* max length seen so far */
  char line[MAXLINE];  /* current input line */
  char longest[MAXLINE]; /* longest line saved here */
  
  max = 0;
  while ((len = getLine(line, MAXLINE)) >0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)  /* there was a line */
    printf("%s", longest);
  return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim)
{
  int c, i;

  /* this is the part I changed for Ex 2-2 */
  i = 0;
  int k;
  for (k=0; k < lim-1; ++k) {
    if ((c=getchar()) == EOF) {
      i = k;
      k = lim-1; 
    }
    else if (c == '\n') {
      i = k;
      k = lim-1;
    }
    else {
      s[k] = c;
      i = k+1;
    }
  }
  /* end change */
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
  /* note that if we hit MAXLINE we don't get trailing \n */
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;
  
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

