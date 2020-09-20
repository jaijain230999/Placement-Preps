#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"
int i, n;

// Print Array
void print(int a[])
{
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
}

// **************************************************************************************************** //
// **************************************************************************************************** //
// **************************************************************************************************** //

// Method 1
// Direct Sort
int method1(int a[])
{
  mergeSort(a, n);
  print(a);
}

// **************************************************************************************************** //
// **************************************************************************************************** //
// **************************************************************************************************** //

// Method 2
// Counting Sort
void countingSort(int a[])
{
  int zero = 0;
  int one = 0;
  int two = 0;
  for (i = 0; i < n; i++)
  {
    if (a[i] == 0)
      zero++;
    else if (a[i] == 1)
      one++;
    else if (a[i] == 2)
      two++;
  }
  while (zero-- > 0)
    printf("0 ");
  while (one-- > 0)
    printf("1 ");
  while (two-- > 0)
    printf("2 ");
}

// **************************************************************************************************** //
// **************************************************************************************************** //
// **************************************************************************************************** //

// Method 3
// Dutch National Flag Algorithm
void dnfa(int a[])
{
  int low = 0, mid = 0, high = n - 1, temp;
  while (mid <= high)
  {
    switch (a[mid])
    {
    case 0:
      temp = a[low];
      a[low] = a[mid];
      a[mid] = temp;
      low++;
      mid++;
      break;
    case 1:
      mid++;
      break;
    case 2:
      temp = a[high];
      a[high] = a[mid];
      a[mid] = temp;
      high--;
      break;
    default:
      break;
    }
  }
  print(a);
}

// **************************************************************************************************** //
// **************************************************************************************************** //
// **************************************************************************************************** //

int main()
{
  scanf("%d", &n);
  int *a = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  // Method 1
  // method1(a);
  // Method 2
  // countingSort(a);
  // Method 3
  dnfa(a);
}