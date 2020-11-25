#include <stdio.h>
#include <string.h>

/* sort input text - begin p 108 */


#define MAXLINES 5000 // max #lines to be sorted 
#define MAXLEN 1000 // max length of any input line 

char *alloc(int); 
int getLine(char *s, int max); // L: name conflict
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *v[], int left, int right);
void swap(char *v[], int i, int j);



int main()
{
  int nlines; // number of input lines read

  /* NOTE: KR has lineptr defined externally... not sure why */
  char *lineptr[MAXLINES]; // pointers to text lines

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines-1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

/* readlines: read (all) input lines  */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getLine(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0'; // delete newline
      strcpy(p, line);
      lineptr[nlines++] = p;
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

/* c/p-d from test.alloc.c: */
#define ALLOCSIZE 50000

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;   /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
    allocp += n;
    return allocp - n; /* old p */
  } else   /* not enough room */ 
    return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

/* end alloc and afree */

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
