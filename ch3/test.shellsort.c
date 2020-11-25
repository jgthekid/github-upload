#include <stdio.h>
#include <ctype.h>

/* shellsort: sort v[0]..v[n-1] into increasing order */
void shellsort(int v[], int n);

int main()
{
  int i, n;
  n = 15;
  int a[] = {6,3,2,5,8,9,5,0,8,1,1,8,6,6,8};

  for (i=0; i<n; i++)
    printf("%d%s",a[i],(i<n-1) ? " " : "\n");

  shellsort(a,n);
  for (i=0; i<n; i++)
    printf("%d%s",a[i],(i<n-1) ? " " : "\n");
}

/* shellsort: sort v[0]..v[n-1] into increasing order */

/* TESTING VERSION: PRINT TO SEE WHATS GOING ON */
/* void shellsort(int v[], int n) */
/* { */
/*   int gap, i, j, temp; */

/*   int k; */

/*   for (gap = n/2; gap > 0; gap /= 2) */
/*     for (i = gap; i < n; i++) */
/*       for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) { */
/*         temp = v[j]; */
/*         v[j] = v[j+gap]; */
/*         v[j+gap] = temp; */
/*         for (k=0; k<n; k++) /\* check status *\/ */
/*           printf("%d%s",v[k],(k<n-1) ? " " : "\n"); */

/*       } */
/* } */




/* void shellsort(int v[], int n) */
/* { */
/*   int gap, i, j, temp; */
  
/*   for (gap = n/2; gap > 0; gap /= 2)  */
/*     for (i = gap; i < n; i++)  */
/*       for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) { */
/*         temp = v[j]; */
/*         v[j] = v[j+gap]; */
/*         v[j+gap] = temp; */
/*       } */
/* } */





/* is the third loop really necessary? 
   why not just use if?? */
void shellsort(int v[], int n)
{
  int gap, i, j, temp;

  int k;

  for (gap = n/2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++) {
      j = i - gap;
      if (j>=0 && v[j] > v[j+gap]) {
        temp = v[j];
        v[j] = v[j+gap];
        v[j+gap] = temp;
        j -= gap;
        for (k=0; k<n; k++) /* check status */
          printf("%d%s",v[k],(k<n-1) ? " " : "\n");
      }
    }
}

/* Testing reveals why: we need the j-=gap bc there may be 
   cases where even though we've already swapped two values, 
   we may need to swap again, to get the lowest value all the way 
   to the bottom
*/
