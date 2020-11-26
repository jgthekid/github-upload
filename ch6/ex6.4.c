#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>

/* Write a program that prints the distinct words in its input
 sorted into decreasing order of frequency of occurrence. */

/* gather words into tree w/ counts like in countWords, 
   then build array of pointers to tnodes,
   then sort, then print
*/

/* 
   NOTE: functions altered from countWords
*/

#define MAXWORD 100 // max word length
#define ARRLEN 10000 // max number of (unique) words

/* struct defining node of binary tree holding words and their counts */
struct tnode {  // the tree node
  char *word;   // points to the text
  int count;    // number of occurrences 
  struct tnode *left; //left child
  struct tnode *right; //right child
};


int getword(char *, int);
char *STRDUP(char *);  // name conflict in string.h
void treeprint(struct tnode *p[], int n);
struct tnode *talloc(void);
struct tnode *addtree(struct tnode *p, char *w); 
int treetransfer(struct tnode *t, struct tnode *p[]);
void QSORT(void *v[], int left, int right, int (*comp)(void *, void*));
int tcmp(struct tnode *t1, struct tnode *t2);
void swap(void *v[], int i, int j);

int main()
{
  struct tnode *root; 
  char word[MAXWORD];
  int wordcount; // total number of words
  struct tnode *treeptr[wordcount]; // pointers to tnodes  

  root = NULL;


  // parse input and count words
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0])) {
      root = addtree(root, word);
    }
    
  // create array of tnode pointers
  wordcount = treetransfer(root, treeptr);

  // sort array
  QSORT((void **) treeptr, 0, wordcount-1, 
        (int (*)(void*, void*))(tcmp) );

  //print 
  treeprint(treeptr, wordcount);

  return 0;
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL) {  // a new word has arrived
    p = talloc();   // make a new node
    p->word = STRDUP(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;   // repeated word
  else if (cond < 0)  //less than into left subtree
    p->left = addtree(p->left, w);
  else
    p->right = addtree(p->right, w);
  return p;
}

/* treetransfer: build array of pointers to tnodes */
int treetransfer(struct tnode *t, struct tnode *p[])
{
  static int i = 0; // track # of tnodes

  if (t != NULL) {
    treetransfer(t->left, p);
    if (i < ARRLEN) {
      p[i++] = t;
    } else {
      printf("too many words\n"); 
      return 0;
    }
    // printf("%4d %s\n", t->count, t->word);
    treetransfer(t->right, p);
  }
  return i;
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

char *STRDUP(char *s)  // make a duplicate of s 
{
  char *p;

  p = (char *) malloc(strlen(s)+1);  // +1 for '\0'
  if (p != NULL)
    strcpy(p, s);
  return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()))
    ;
  if (c != EOF)
    *w++ = c;
  if(!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}


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

/* tcmp: compare tnodes based on count */
int tcmp(struct tnode *t1, struct tnode *t2)
{
  return t2->count - t1->count;
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

/* treeprint: print tnodes from array of pointers */
void treeprint(struct tnode *p[], int n) 
{
  int i = 0;

  for (i = 0; i < n; i++)
    printf("%d: %s\n", p[i]->count, p[i]->word);
}
