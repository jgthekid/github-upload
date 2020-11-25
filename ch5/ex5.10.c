#include <stdio.h> 
#include <ctype.h> 
#include <stdlib.h> /* for atof() */

/* Write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument */

/* Grabbed code from ch4/test.polish.c */
/* argv[] and pointer magic makes getch/ungetch obsolete */


#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100 

int getop(char[]);
void push(double);
double pop(void);
int getop(char s[]);
int getch(void);
void ungetch(int c);

/* external variables */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* reverse polish calculator */
int main(int argc, char *argv[])
{
  int type;
  double op2;
  char s[MAXOP];
  
  while (--argc > 0) { // WHAT IF 1 ARG HAS MULTIPLE OPS? eg 2+1
    printf("%s\n", *(argv+1));
    type = getop(*++argv);
    printf("%c\n", type);
    switch (type) {
    case NUMBER:
      push(atof(s));
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
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unkown command %s\n", s);
      break;
    }
  }
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

/* getop: get next operator or numeric operand */
int getop(char *s)
{
  int i, c;

  if (!isdigit(*s) && *s != '.')
    return *s; // not a number
  if (isdigit(*s)) //collect integer part
    while (isdigit(*++s))
      ;
  if (*s == '.')  // collect fraction part
    while (isdigit(*++s))
    ;
  *s = '\0';
  return NUMBER;
}

