#include <stdio.h>
#include <time.h>
/* alternate binary search fnc w 1 test inside loop */
/* this 'script' tests runtimes of 3 versions */
/* gave up on using BASH - difficult/impossible to isolate ~randomness in 
   time taken to initialize array, 
   which is the bulk of the work */

int binsearch1(int x, int v[], int n);
int binsearch2(int x, int v[], int n);
int binsearchKR(int x, int v[], int n);
int power(int base, int n);

int main()
{ 

  int i,n,l,x; 

  /* setup input array */
  n = 2000000;
  x = 10;
  int z[n];
  for (i=0; i<n; ++i) {
    z[i] = 2*i;
  }  

  clock_t time_taken; 
  
  
  for (i=0, time_taken = clock(); i<10000; ++i) {
    l = binsearch1(i, z, n);
  }
  time_taken = clock() - time_taken;
  printf("binsearch1() took %lu clocks (%f seconds) \n", 
         (unsigned long) time_taken,
         (double) time_taken / CLOCKS_PER_SEC);


  for (i=0, time_taken = clock(); i<10000; ++i) {
    l = binsearch2(i, z, n);
  }
  time_taken = clock() - time_taken;
  printf("binsearch2() took %lu clocks (%f seconds) \n", 
         (unsigned long) time_taken,
         (double) time_taken / CLOCKS_PER_SEC);


  for (i=0, time_taken = clock(); i<10000; ++i) {
    l = binsearchKR(i, z, n);
  }
  time_taken = clock() - time_taken;
  printf("binsearchKR() took %lu clocks (%f seconds) \n", 
         (unsigned long) time_taken,
         (double) time_taken / CLOCKS_PER_SEC);


}



/* altered binsearch: find x in v[0] <= v[1] <= ... v <= v[n-1] */

/* not sure if having another test in while() counts as a test inside the loop */
int binsearch1(int x, int v[], int n)
{
  int low, high, mid, k;

  low = 0;
  high = n-1;
  mid = (low+high)/2;
  while (low < high && x != v[mid]) {
    if (x < v[mid])
      high = mid-1;
    else 
      low = mid+1;
    mid = (low+high)/2;
  }
  return v[mid]== x ? mid : -1 ;
}


/* only one test inside, including at while step */ 
int binsearch2(int x, int v[], int n)
{
  int low, high, mid, k;

  low = 0;
  high = n-1;
  mid = (low+high)/2;
  while (low < high ) {
    if (x <= v[mid])
      high = mid;
    else 
      low = mid+1;
    mid = (low+high)/2;
  }
  return v[mid]== x ? mid : -1 ;
}



/* binsearch given in K&R */
int binsearchKR(int x, int v[], int n)
{
  int low, high, mid, k;

  low = 0;
  high = n-1;
  while (low <= high) {
    mid = (low+high)/2;
    if (x < v[mid])
      high = mid-1;
    else if (x > v[mid])
      low = mid+1;
    else {/* found match */ 
      return mid;
    }
  }
  return -1; /* no match */
}


















