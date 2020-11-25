#include <stdio.h>

/* test binary search fnc given sec 3.3 p58 */

int binsearch(int x, int v[], int n);
int power(int base, int n);

int main()
{ 
  /* using fib sequence as test */
  int i,n; 
  n = 20; /* need n at least 2 */
  int x[n];
  x[0] = 0;
  x[1] = 1;
  for (i = 2; i < n; ++i){
    x[i] = x[i-1] + x[i-2];
    printf("%d%s",x[i],((i==n-1)? "\n": " "));
  }
  

  int l;
  l = binsearch(5000, x, n);
  printf("%d \n",l);
  printf("%d\n",x[l]);
}



/* binsearch: find x in v[0] <= v[1] <= ... v <= v[n-1] */
int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n-1;
  while (low <= high) {
    mid = (low+high)/2;
    if (x < v[mid])
      high = mid-1;
    else if (x > v[mid])
      low = mid+1;
    else /* found match */
      return mid;
  }
  return -1; /* no match */
}



/* define power function (requires n>0 */
int power(int base, int n)
{
  int i, p;
  
  p = 1;
  for (i=1; i<=n; ++i)
    p = p*base;
  return p;
}
