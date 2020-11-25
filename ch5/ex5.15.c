#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

/* 
   Add (to sort program) the option -f to fold upper and lower case together, 
   so that case distinctions are not made during sorting; 
   for example, a and A compare equal. 
*/

// to do this, flip sign in qsort 

/* 
   bug?: qsort does not replace middle element if no changes. 
   this only shows up when multiple lines same except for case. 
   eg
i have something to say
I HAVE SOMETHING TO SAY
I HAVE something TO SAY

returns as 

I HAVE SOMETHING TO SAY
i have something to say
I HAVE something TO SAY

when it should probably be exactly the same as input. 

Not bothering to fix this.
*/

#define MAXLINES 5000 /* max # of lines to be sorted */
#define MAXLEN 1000 // max length of any input line 

char *lineptr[MAXLINES]; /* pointers to text lines */

char *alloc(int n);
int getLine(char *s, int max); // L: name conflict
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void QSORT(void *lineptr[], int left, int right,  // QSORT: name conflict in stdlib
           int (*comp)(void *, void *), int reverse); // added rev arg: -1 for reverse, else 1
int numcmp(char *, char *);
void swap(void *v[], int i, int j);
int STRCMP(char *s, char *t); // name conflict in string.h
int FSTRCMP(char *s, char *t); // folded case comparison
int CAP(char a); // capitalize char

/* sort input lines */
int main(int argc, char *argv[])
{
  int nlines;       /* number of input lines read */
  int numeric = 0;  /* 1 if numeric sort */
  int rev = 1;      /* -1 if reverse sort */
  int fold = 0;     // 1 if fold case
  int c;

  printf("%d\n",argc);
  while (--argc > 0 && (*++argv)[0] == '-') {
    printf("yes?\n");
    printf("%c\n",*(argv[0]+1));
    while (c = *++argv[0]) {
      printf("%c\n", c);
      switch(c) {
      case 'r':
        rev = -1;
        break;
      case 'f':
        fold = 1;
        break;
      case 'n':
        numeric = 1;
        break;
      default:
        printf("sort: illegal option %c\n", c);
        argc = 0;
        break;
      }
    }
  }
  //  if (argc > 1 && strcmp(argv[1], "-n") == 0)
  //  numeric = 1;

  printf("num: %d; rev: %d; fold: %d\n", numeric, rev, fold);
  printf("\n");

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    QSORT((void **) lineptr, 0, nlines-1, 
          (int (*)(void*, void*))(numeric ? numcmp : (fold ? FSTRCMP : STRCMP)), 
          rev);

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
           int (*comp)(void *, void*), int reverse)
{
  int i, last;
  //void swap(char *v[], int i, int j);

  static int k = 0; // track swaps
  if (left >= right) 
    return;
  swap(v, left, (left+right)/2); k++;
  printf("init swap:%s for %s\n", v[left], v[(left+right)/2]);
  last = left;
  for (i = left+1; i <= right; i++)
    if (reverse * (*comp)(v[i], v[left]) < 0) {
      swap(v, ++last, i); 
      printf("comp swap:%s for %s\n", v[last], v[i]);
      k++;
    }
  swap(v, left, last); k++;
  printf("end swap:%s for %s\n", v[last], v[left]);
  QSORT(v, left, last-1, comp, reverse);
  QSORT(v, last+1, right, comp, reverse);
  printf("swaps: %d\n", k);
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

/* strcmp: return <0 if s<t 0 if s==t, >0 if s>t */
int STRCMP(char *s, char *t)
{
  for ( ; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t ;
}

/* FSTRCMP: compare strings, fold cases, ie a == A and a < B etc
   return <0 if s<t 0 if s==t, >0 if s>t 
*/
int FSTRCMP(char *s, char *t)
{
  for ( ; CAP(*s) == CAP(*t); s++, t++)
    if (*s == '\0')
      return 0;
  printf("s: %c t: %c diff: %d\n", *s, *t, CAP(*s) - CAP(*t));
  return CAP(*s) - CAP(*t) ;
}


/* CAP: if lowercase letter, return capitalized, else do nothing */
int CAP(char a)
{
  if ( a >= 'a' && 'a' <= 'z')
    return 'A' - 'a' + a; 
  else 
    return a;
}
