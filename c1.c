#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int middle, int right)
{
  int i, j, k;
  int n1 = middle - left + 1;
  int n2 = right - middle;
  int *leftArray = (int *)malloc(n1 * sizeof(int));
  int *rightArray = (int *)malloc(n2 * sizeof(int));

  for (i = 0; i < n1; i++)
    leftArray[i] = arr[left + i];
  for (j = 0; j < n2; j++)
    rightArray[j] = arr[middle + 1 + j];

  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2)
  {
    if (leftArray[i] <= rightArray[j])
    {
      arr[k] = leftArray[i];
      i++;
    }
    else
    {
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = leftArray[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    arr[k] = rightArray[j];
    j++;
    k++;
  }

  free(leftArray);
  free(rightArray);
}

void mergeSort(int arr[], int left, int right)
{
  if (left < right)
  {
    int middle = left + (right - left) / 2;

    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);

    merge(arr, left, middle, right);
  }
}

void printArray(int arr[], int size)

{
  int i;
  for ( i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  printArray(arr, n);
  mergeSort(arr, 0, n - 1);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}
