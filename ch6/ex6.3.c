#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>

/* Write a cross-referencer that prints a list of all words in 
a document, and, for each word, a list of the line numbers on which it occurs. 
*/

/* borrows heavily from test.countWords.c 

To do this, add an array to each tree node containing line# of each occurrence. 
Also need to keep track of index of this array. 
Seems like this will use alot of empty storage: need to allocate space for lots of 
entries for each word. 

Another possibility would be to allow duplicate entries in the binary tree. 
That would sort on word, then on line number, with the second sort coming 
automatically since lines are sorted beforehand. 
But wait what about printing?
Im prob not gonna do this but that might be a nice idea. 

** NOTE: functions edited here so if borrowing for future use check against 
versions in test.countWords.c 
*/

#define MAXWORD 100
#define MAXCOUNT 100

/* struct defining node of binary tree holding words and their counts */
struct tnode {  // the tree node
  char *word;   // points to the text
  int idx;   // current index in count array
  int lineArr[MAXCOUNT]; // line# of each occurrence
  struct tnode *left; // left child
  struct tnode *right; // right child
};


int getword(char *, int, int *);
char *STRDUP(char *);  // name conflict in string.h
void treeprint(struct tnode *p);
struct tnode *talloc(void);
struct tnode *addtree(struct tnode *p, char *w, int l); 

int main()
{
  struct tnode *root;
  char word[MAXWORD];
  int lineNo = 1;

  root = NULL;
  while (getword(word, MAXWORD, &lineNo) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word, lineNo);
  treeprint(root);
  return 0;
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int l)
{
  int cond;

  // need binary search against noise words here: 
  if (p == NULL ) {  // a new word has arrived
    p = talloc();   // make a new node
    p->word = STRDUP(w);
    p->idx = 0;
    p->lineArr[p->idx] = l;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    { // does not error check idx == MAXCOUNT case
      if (p->lineArr[p->idx] != l) // repeated word on new line 
        p->lineArr[++p->idx] = l; 
    } // ignore repeated words on same line
  else if (cond < 0)  //less than into left subtree
    p->left = addtree(p->left, w, l);
  else
    p->right = addtree(p->right, w, l);
  return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
  int i;
  if (p != NULL) {
    treeprint(p->left);
    printf("%s:", p->word);
    for (i = 0; i < p->idx; i++)
      printf("%d ", p->lineArr[i]);
    printf("%d\n", p->lineArr[p->idx]);
    treeprint(p->right);
  }
}

/* talloc: make a tnode */
// new for ex6.3.c: zero out array of line#s
struct tnode *talloc(void)
{
  struct tnode *t;
  t = (struct tnode *) malloc(sizeof(struct tnode));
  int i;
  for (i = 0; i < MAXCOUNT; i++)
    t->lineArr[i] = 0;
  return t;
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
int getword(char *word, int lim, int *lineCount)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()))
    if (c == '\n')
      (*lineCount)++;
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
