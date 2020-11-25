#include <stdio.h> 
#include <ctype.h> 
#include <stdlib.h> /* for atof() */

/* 
extend the calculator . 
Add modulus (%) and provisions for negative numbers. 
see test.polish for original
*/


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
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* reverse polish calculator */
int main()
{
  int type;
  double op2;
  char s[MAXOP];
  
  while ((type = getop(s)) != EOF) {
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
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push( (int) pop() % (int) op2); //perhaps heavyhanded...
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
/* ex4.3 edit: allow negative numbers */
int getop(char s[])
{
  int i, c;
  i = 0;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.') {
    if (c == '-') {
      s[0] = c; 
    if (isdigit(s[++i] = c = getch()))
      ; // continue collecting digits
    else
      return s[0]; // not a number
    }
    else 
      return c;
  }
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

/* getch: get a (possibly pushed back) character */
int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

