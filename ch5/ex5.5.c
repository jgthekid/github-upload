#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* 
write versions of the library functions strncpy, strncat, and strncmp.
*/

/* 
   when I first read the problem I thought 'copy' meant 'cat'
   now assuming copy means to put source string at the beginning of target 
*/

/* STRNCPY: copy at most n characters of t to s; 
pad with '\0's if t has fewer than n characters
*/
char *STRNCPY(char *s, char *t, int n) //caps to avoid name conflict
{
  char *s0 = s; // i guess this is supposed to return the pointer we started at
  int i;
  for (i = 0; i < n ; i++) {
    if ( *t != '\0') {
      *s++ = *t++;
    }
    else { break; }
  } 
  if ( i < n ) { // pad with '\0'
    for ( ; i < n; i++) {
      *s++ = '\0';
    }
  } else { *s = '\0'; } //finished, tie off
  return s0;
}


/* 
STRNCAT: concatenate string ct to end of string s; return s.
*/
char *STRNCAT(char *s, char *t, int n)
{
  char *s0 = s; 
  while ((*s)) // find end of s
    s++;
  int i;
  for (i = 0; i < n ; i++) {
    if ( *t != '\0') {
      *s++ = *t++;
    }
    else { break; }
  } 
  if ( i < n ) { // pad with \0
    for ( ; i < n; i++) {
      *s++ = '\0';
    }
  } else { *s = '\0'; } //finished, tie off
  return s0;
}

/*
STRNCMP: compare at most n characters of string cs to string ct; 
return <0 if cs<ct, 0 if cs==ct, >0 if cs>ct.
*/
int STRNCMP(char *cs, char *ct, int n)
{
  int i;

  for(i = 0; (*cs == *ct) && (i < n); cs++, ct++, i++) {
    if ( *cs == '\0' ) 
      return 0;
  }
  if (i == n) { return 0;} 
  return *cs - *ct;
}
  


int main()
{

  char a[200] ;
  a[0] = 's';
  a[1] = 't';
  a[2] = '\0';
  char b[] = "ummagummag";


  // strncpy test
  // NOTE: we should really leave extra room in target string, but this appears to work 
  printf("testing STRNCPY\n");
  printf("target: %s\n", a);
  printf("source: %s\n", b);
  STRNCPY(a, b, 7);
  printf("result: %s\n", a);


  // strncat test
  printf("testing STRNCAT\n");
  char c[] = "saucer full of secrets";
  printf("target: %s\n", a);
  printf("source: %s\n", c);
  STRNCAT(a, c, 5);
  printf("result: %s\n", a);

  // strncmp test
  char aa[] = "hallelujiah amen";
  char bb[] = "hallelujiahhh";
  int i = STRNCMP(aa, bb, 14);
  printf("testing STRNCMP\n");
  printf("target: %s\n", aa);
  printf("source: %s\n", bb);
  printf("result: %d\n", i);

}
