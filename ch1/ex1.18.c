#include <stdio.h>

/* exercise 1.18 */
/* remove trailing blanks and tabs from input, delete entirely blank lines */
/* idea: grab each line then trim trailing whitespace, only print if nonempty */

#define MAXLINE 1000 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
void trimLine(char line[], int len, int lim);

int main()
{
  int len;  /* current line length */ 
  char line[MAXLINE+1];  /* current input line, with extra space to grab whatever an empty slot is..
                          still not sure how to "delete" an element of array or what an empty entry is */
  
  while ((len = getLine(line, MAXLINE)) >0){
    trimLine(line, len, MAXLINE);
    if (line[0] != '\0')
      printf("%s\n", line);
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
  /* note that if we hit MAXLINE we don't get trailing \n */
}


/* trimLine: delete trailing whitespace */
void trimLine(char s[], int len, int lim) 
{
  int i = len-1;
  while(s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
    s[i] = s[lim+1]; /* deleting by inserting empty char? */
    --i;
  }
  s[i+1] = '\0';
}
