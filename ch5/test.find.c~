#include <stdio.h>
#include <string.h>

/* rewrite the routines day_of_year and month_day with pointers instead of indexing */

/*
char daytab[2][13] {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
*/

char y0[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char y1[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *daytab[] = {y0, y1};


/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
  int i, leap;
  
  if (year < 0 ){
    printf("error: given year before Christ.\n");
    return -1;
  }
    
  char *p;
  // leap year?
  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0 ? 1 : 0;
  p = leap ? *(daytab+1) : *daytab; 
  char *m = &p[month]; // address of desired month

  /* check if day of month makes sense */
  if ( day > *m ) { 
    printf("error: input out of range\n");
    return -1;
  }

  p++; //start at position 1 in month array
  while (p <= m) {
    day += *p++;
  }
  return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  if (year < 0 ){
    printf("error: given year before Christ.\n");
    return;
  }

  char *p;
  // leap year?
  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0 ? 1 : 0;
  p = leap ? *(daytab+1) : *daytab; 
  
  if (yearday > 365 + leap || yearday < 1) {
    printf("error: input out of range\n");
    return;
  }

  char *p0 = p; // mark start for subtraction at end
  p++; //start at position 1 in month array

  while (yearday > *p)
    yearday -= *p++;

  *pmonth = p - p0;
  *pday = yearday;
}

int main()
{
  int m = 9;
  int d = 3;
  int y = 2019;

  int yd = 0;
  // test day_of_year
  yd = day_of_year(y, m, d);
  printf("%d-%d-%d -> %d\n", m, d, y, yd);

  m = 1; d = 1; yd = 100;
  // test month_day
  printf("testing month_day for date y:%d yd:%d, starting m:%d d:%d\n", y, yd, m, d);
  month_day(y, yd, &m, &d);
  printf("%d-%d -> %d %d\n", y, yd, m, d);
}
