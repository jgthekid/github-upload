#include <stdio.h>
#include <string.h>

/* include error checking for day_of_year and month_day */
/* convert by day of the year to month and day, and vice versa; p 111 */

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
  int i, leap;
  
  if (year < 0 ){
    printf("error: given year before Christ.\n");
    return -1;
  }
    
  // leap year?
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  /* check if day of month makes sense */
  if ( day > daytab[leap][month] ) {
    printf("error: input out of range\n");
    return -1;
  }
  for(i = 1; i < month; i++) 
    day += daytab[leap][i];
  return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  if (yearday > 365+leap) {
    printf("error: input out of range\n");
    return;
  }
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}

int main()
{
  int m = 9;
  int d = 32;
  int y = 2020;

  // test day_of_year
  int yd = day_of_year(y, m, d);
  printf("%d-%d-%d -> %d\n", m, d, y, yd);


  m = 1; d = 1; yd = 1000;
  // test month_day
  month_day(y, yd, &m, &d);
  printf("%d-%d -> %d %d\n", y, yd, m, d);
}
