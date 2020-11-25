#include <stdio.h>
#include <string.h>

/* rewrite readlines to store lines in an array supplied by main, 
rather than calling alloc to maintain storage. 
How much faster is the program?
culled from test.sort.c: sort input text - begin p 108
 */


#define MAXLINES 5000 // max #lines to be sorted 
#define MAXLEN 1000 // max length of any input line 
#define MAXCHAR MAXLINES*MAXLEN // max #characters in input 

char *alloc(int); 
int getLine(char *s, int max); // L: name conflict
int readlines(char *lineptr[], char *buf);
void writelines(char *lineptr[], int nlines);
void qsort(char *v[], int left, int right);
void swap(char *v[], int i, int j);


int main()
{
  int nlines; // number of input lines read
  char buffer[MAXCHAR]; // stores all input
  char *lineptr[MAXLINES]; // pointers to text lines

  if ((nlines = readlines(lineptr, buffer)) >= 0) {
    qsort(lineptr, 0, nlines-1);
    writelines(lineptr, nlines);
    return 0;

  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

/* readlines: read (all) input lines  */
int readlines(char *lineptr[], char *buf)
{
  int len, nlines;
  char line[MAXLEN];

  nlines = 0;
  while ((len = getLine(line, MAXLEN)) > 0) {
    if ( len > MAXCHAR || nlines >= MAXLINES) // make sure new line fits
      return -1;
    else {
      line[len-1] = '\0'; // delete newline
      strcpy(buf, line);
      lineptr[nlines++] = buf;
      buf += len;
    }
  }
  return nlines;
}


/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

/* getLine: get line into s, return length, pointer version */
int getLine(char *s, int lim)
{
  int c, i;
  char *s0 = s;

  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    *s++ = c;
  if (c == '\n')
    *s++ = c;
  *s = '\0';
  return s - s0;
}


/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
  int i, last;
  // void swap(char *v[], int i, int j);

  if (left >= right) 
    return;
  swap(v, left, (left+right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
