#include <stdio.h> 
#include <ctype.h>
#include <string.h>

/* how do we know how big a general char[] is ? */

struct key {
  char *word;
  int count;
} keytab[] = {
  "auto", 0,
  "break", 0,
  "case", 0,
  "char", 0,
  "const", 0,
  "continue", 0,
  "default", 0,
  "int", 0,
  "unsigned", 0,
  "void", 0,
  "volatile", 0,
  "while", 0
};

#define NKEYS (sizeof(keytab) / sizeof(struct key))

int main()
{
  char *s = "ummagummaummagumma";
  printf("%s\n", s);
  printf("%lu\n",sizeof(s));

  char t[] = "ummagummaummagumma";
  printf("%s\n", t);
  printf("%lu\n",sizeof(t));

  printf("%lu\n", NKEYS);

  int x = 100;
  struct key testkey  = {"testing", 3};
  printf("%lu\n", sizeof(struct key));
  printf("%lu\n", sizeof(testkey));
  printf("%lu\n", sizeof(x));
  printf("%lu\n", sizeof(s));

  // what about -> and arrays?
  struct testarr {
    char *word;
    int idx;
    int numbers[10];
  } ;

  struct testarr t1 = {
    "werechained", 
    0,
    {3, -173, 10, 69, 690, 7, 102109, 72, 54, 2222}};

  printf("%s ; %d\n", t1.word, t1.numbers[t1.idx]);

  struct testarr *t2;
  t2 = &t1;
  printf("%s ; %d\n", t2->word, t2->numbers[++t2->idx]);

  int y = 72;
  int *yy = &y;
  (*yy)++;
  printf("*yy:%d y:%d\n", *yy, y);

  /*
  // whats in an empty array again?
  int arr[10];
  int i;
  for (i=0; i < 10; i++)
    if (arr[i] > 0 )
    printf("%d\n", arr[i]);
  */
  
  
}


