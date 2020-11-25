#include <stdio.h>

/* alternate binary search fnc w 1 test inside loop */
/* this version uses the original KR binsearch for benchmarking */

int binsearch1(int x, int v[], int n);
int binsearch2(int x, int v[], int n);
int binsearchKR(int x, int v[], int n);
int power(int base, int n);

int main()
{ 
  /* using fib sequence as test */
  int i; 
  long n;
/*   n = 35; /\* need n at least 2 *\/ */
/*   int v[n]; */
/*   v[0] = 0; */
/*   v[1] = 1; */
/*   printf("%d %d ",v[0],v[1]); */
/*   for (i = 2; i < n; ++i){ */
/*     v[i] = v[i-1] + v[i-2]; */
/*     printf("%d%s",v[i],((i==n-1)? "\n": " ")); */
/*   } */


  /* try a different sequence */
  n = 2059000;
  int z[n];
  for (i=0; i<n; ++i) {
    z[i] = 2*i;
  }  

  int l;

  l = binsearchKR(19999999, z, n);
/*   k = binsearch2(987, v, n); */
/*   printf("l:%d v[l]:%d\n",k,v[k]); */
/*   j = binsearchKR(987, v, n); */
/*   printf("l:%d v[l]:%d\n",j,v[j]); */
  

  /* big automated test: 
     run search on all i=1..big,
     (test for correctness and) time it in shell 
     (since I don't have a clock in C yet) */


/*   int test = 1; */
/*   if (test == 1) { */
/*     int k;  */
/*     for (i=-200; i < z[n-1]+2; ++i) { */
/*       l = binsearch1(i, z, n); */
/*       /\* if (k != l) */
/*       printf("ERROR: l:%d k:%d i:%d\n",l,k,i);  */
/*       *\/ */
/*     } */
/*   } */

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
    /*    printf("%d  %d  %d \n",low,mid,high);*/
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



/* define power function (requires n>0) */
int power(int base, int n)
{
  int i, p;
  
  p = 1;
  for (i=1; i<=n; ++i)
    p = p*base;
  return p;
}

