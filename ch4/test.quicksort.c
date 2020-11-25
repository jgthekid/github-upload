#include <stdio.h>

/* testing quicksort function given p 87 */ 

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);
void printArray(int v[], int n); 

static int N = 10;

int main() 
{

  int x[] = {12, 3, 3, 2, 14, 9, 8, 10, 7, 4};

  printArray(x, N);
  qsort(x, 0, 9);
  printArray(x, N);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
  int i, last;
  void swap(int v[], int i, int j);

  if (left >= right)  /* do nothing if array contains */
    return;           /* fewer than two elements */
  swap(v, left, (left+right)/2); /* move partition elem */
  printArray(v, N); // testing: print after all swaps
  last = left;                   /* to v[0] */
  for (i = left+1; i <= right; i++)  /* partition */
    if (v[i] < v[left]) {
      swap(v, ++last, i);
      printArray(v, N);
    }
  swap(v, left, last);  /* restore partition elem */
  printArray(v, N);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}


/* swap: intergange v[i] and v[j] */
void swap(int v[], int i, int j)
{
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}


/* for testing purposes. n = array size */
void printArray(int v[], int n)
{
  int i;
  for (i = 0; i < n; ++i)
    printf("%d ", v[i]);
  printf("\n");
}
