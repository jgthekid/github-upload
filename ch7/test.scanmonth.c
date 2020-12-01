#include <stdio.h>

/* testing scanf, sscanf */

int main()
{
  int day, month, year;
  char monthname[20];
  char line[100];
  int getLine(char *s, int max);


  while (getLine(line, sizeof(line)) > 0) {
    if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3) {
      printf("valid: %s", line); 
      printf("values: %d %s %d\n", day, monthname, year); 
    }
    else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3) {
      printf("valid: %s", line);
      printf("values: %d %d %d\n", month, day, year);
    }
    else
      printf("invalid: %s\n", line);
  }

  return 0;
}


/* 
turns out this breaks pretty easily for bad user input
eg a line "10 / 100 / 10 / 92" will be processed into 
valid: 10 / 100 / 10 / 92 
values: 10 / 100
since " / 100 " is read as the monthname string. 

*/
