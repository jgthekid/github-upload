#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>

/* Write a program that prints the distinct words in its input
 sorted into decreasing order of frequency of occurrence. */

/* gather words into tree w/ counts like countWords, 
   then build new tree from that one sorted on count 
*/

/* 
   NOTE: functions altered from countWords
*/

#define MAXWORD 100

/* struct defining node of binary tree holding words and their counts */
struct tnode {  // the tree node
  char *word;   // points to the text
  int count;    // number of occurrences 
  struct tnode *left; //left child
  struct tnode *right; //right child
};


int getword(char *, int);
struct tnode *taloc(void);
char *STRDUP(char *);  // name conflict in string.h
void treeprint(struct tnode *p);
struct tnode *talloc(void);
struct tnode *addtree(struct tnode *p, char *w); 

int main()
{
  struct tnode *root1;
  char word[MAXWORD];

  root1 = NULL;

  // parse input and count words
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root1 = addtree(root1, word);

  // sort by count
  struct tnode *root2;
  root2 = NULL;
  treetransfer(root1, root2);

  treeprint(root2);
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

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
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

/* treetransfer: create tree sorted on count instead of alpha */
void treetransfer(struct tnode *p1, struct tnode *p2)
{
  // parse p1 while filling p2
  // testing some edits

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
