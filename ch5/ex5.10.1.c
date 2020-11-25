#include <stdio.h> 
#include <ctype.h> 
#include <stdlib.h> /* for atof() */

/* Write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument */

/* ASSUMPTIONs:
   -all operators and operands separated by whitespace, eg
   good: 2 3 + 4 *
   bad: 2 3+4 *

   -multiplication requires user wraps * in "" to avoid expansion at command line 
   good: "*" or '*'
   bad: * (like the example for the last assumption)
*/

/* VERSION 1: 
   modify getop to take elements of argv[] 
*/

/* Grabbed code from ch4/test.polish.c */
/* argv[] and pointer magic makes getch/ungetch obsolete */



#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100 

int getop(char *a[]); // a is argv
void push(double);
double pop(void);

/* external variables */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* reverse polish calculator */
int main(int argc, char *argv[])
{
  int type;
  double op2;
  char s[MAXOP];

  while (--argc > 0) {   
    type = getop(++argv);
    printf("*argv: %s\n", *argv);
    switch (type) {
    case NUMBER:
      push(atof(*argv));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor \n");
      break;
    default:
      printf("*argv: %s\n", *argv);
      printf("error: unkown command %s\n", *argv);
      break;
    }
  }
  printf("\t%.8g\n", pop());

  return 0;
}


/* helpers */


/* push: push f onto value stack */ 
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}


/* getop VERSION 2: get operator from argv */
int getop(char *a[]) // a is argv
{
  if (!isdigit(**a) && **a != '.')
    return **a; // not a number  
  else 
    return NUMBER; 
}


/* getop: get next operator or numeric operand */
/*
int getop(char s[])
{
  int i, c;
  
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c; // not a number
  i = 0;
  if (isdigit(c)) //collect integer part
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')  // collect fraction part
    while (isdigit(s[++i] = c = getch()))
    ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

*/
