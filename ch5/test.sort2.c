#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

/* modified sort to include numeric sorting */

#define MAXLINES 5000 /* max # of lines to be sorted */
#define MAXLEN 1000 // max length of any input line 

char *lineptr[MAXLINES]; /* pointers to text lines */

char *alloc(int n);
int getLine(char *s, int max); // L: name conflict
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void QSORT(void *lineptr[], int left, int right,  // QSORT: name conflict in stdlib
           int (*comp)(void *, void *));
int numcmp(char *, char *);
void swap(void *v[], int i, int j);

/* sort input lines */
int main(int argc, char *argv[])
{
  int nlines;       /* number of input lines read */
  int numeric = 0;  /* 1 if numeric sort */

  if (argc > 1 && strcmp(argv[1], "-n") == 0)
      numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    QSORT((void **) lineptr, 0, nlines-1, 
          (int (*)(void*, void*))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort \n");
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

/* QSORT: sort v[left]...v[right] into increasing order */
void QSORT(void *v[], int left, int right, 
           int (*comp)(void *, void*))
{
  int i, last;
  //void swap(char *v[], int i, int j);

  if (left >= right) 
    return;
  swap(v, left, (left+right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  QSORT(v, left, last-1, comp);
  QSORT(v, last+1, right, comp);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}



/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2) 
    return -1;
  else if (v1 > v2) 
    return 1; 
  else 
    return 0;
}
