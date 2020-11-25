#include <stdio.h>

/* exercise 1.18 */
/* remove trailing whitespace, delete empty lines */

#define IN 1 /* in text */
#define OUT 0 /* in whitespace */
#define MAXLINE 1000 /* maximum input line size */


int getTrimLine(char line[], int maxline);

int main()
{
  int len;  /* current line length */ 
  char line[MAXLINE];  /* current input line */
  
  while ((len = getTrimLine(line, MAXLINE)) >0){
    if (line[0] != '\n')
      printf("%s", line);
  }
}

/* getTrimLine: read a line into s, return length, ignore trailing whitespace */
int getTrimLine(char s[], int lim)
{
  char tmp[MAXLINE];
  int state, c, i, j, k;
  c = 0;
  state = OUT;
  j = 0;
  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
      tmp[i] = c;
      if (c != ' ' && c != '\t') {
        state = IN;
        for (k=j; k<=i ; ++k)
          s[k] = tmp[k];
      }
      else if (state == IN) {
        state = OUT;
        j = i;
      }
  }
  
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
  /* note that if we hit MAXLINE we don't get trailing \n */
}
