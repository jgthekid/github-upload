#include <stdio.h>

/* exercise 1.19 */
/* reverse input a line at a time */
/* idea: grab each line then reverse each line */
/* edited getLine to always end with \n */

#define MAXLINE 1000 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char line[], char rev[], int len);

int main()
{
  int len;  /* current line length */ 
  char line[MAXLINE];
  char rev[MAXLINE];
  
  while ((len = getLine(line, MAXLINE)) >0) {
    reverse(line, rev, len);
    printf("%s", rev); 
  }
}

/* getLine: read a line into s, return length */

int getLine(char s[], int lim)
{
  int c, i;
  
  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}


/* edit: always end with \n */
/*
int getLine(char s[], int lim)
{
  int c, i;
  
  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;

  s[i] = '\n'; 
  ++i;
  s[i] = '\0';
  return i;
}
*/

 /* reverse: reverse input line */
 /* assumes input line ends in /0 and only has \n right before \0 */
void reverse(char s[], char r[], int len) 
{
  int i;
  int n = len-2; /* last char before \0 */
  for (i=0; i<=n ; ++i) 
    r[i] = s[n-i];
  r[n+1] = '\n';
  r[n+2] = '\0';
  /* yields extra \n on last line if none given but
     that's OK bc I always want trailing \n in shell programs */
}


