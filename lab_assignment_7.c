/*
Logan Bowers
COP3502C
Lab Assignment 7
*/

#include <stdio.h>
int totalSwaps = 0;//track swaps

typedef struct swapVals {
  int value; //
  int swapCount;
} swapVals;

/*
swaps the values of xp and yp
  */
void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(int arr[], swapVals swaps[], int n) {

  totalSwaps = 0;
  for (int i = 0; i < n - 1; i++) {       // for array
    for (int j = 0; j < n - i - 1; j++) { // for neighboring
      if (arr[j] > arr[j + 1]) {          // if curr greater than next
        // swap elements
        swap(&arr[j], &arr[j + 1]);

        swaps[arr[j]].swapCount++;     // increment curr count
        swaps[arr[j + 1]].swapCount++; // increment next count

        swaps[arr[j]].value = arr[j];
        swaps[j + 1].value = arr[j + i];

        totalSwaps++; // increment total
      }
    }
  }
}

void selectionSort(int arr[], swapVals swaps[], int n) {

  totalSwaps = 0;
  int min_idx;

  // extend array boundary
  for (int i = 0; i < n - 1; i++) {
    // find min
    min_idx = i;
    for (int j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;

    // swap min with first element
    if (min_idx != i) {
      swap(&arr[min_idx], &arr[i]);
      swaps[arr[min_idx]].swapCount++;
      swaps[arr[i]].swapCount++;

      swaps[arr[min_idx]].value = arr[min_idx];
      swaps[i].value = arr[i];

      totalSwaps++;
    }
  }
}

/*
output
  */
void printArray(int arr[], swapVals swaps[], int sz) {
  for (int i = 0; i < sz; i++)
    printf("%d: %d\n", arr[i], swaps[arr[i]].swapCount);
}

int main() {

  int bubbleArray1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int bubbleArray2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

  swapVals swap1[100] = {0};
  swapVals swap2[100] = {0};

  // same arrays will be sorted in different algorithm
  int selectionArray1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int selectionArray2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

  swapVals swap3[100] = {0};
  swapVals swap4[100] = {0};

  // get arr sizes
  int size1 = sizeof(bubbleArray1) / sizeof(bubbleArray1[0]);
  int size2 = sizeof(bubbleArray2) / sizeof(bubbleArray2[0]);

  // BUBBLE SORT
  printf("Array 1 Bubble Sort:\n");
  bubbleSort(bubbleArray1, swap1, size1);
  printArray(bubbleArray1, swap1, size1);
  printf("Total swaps in Bubble Sort: %d\n\n", totalSwaps);

  printf("Array 2 Bubble Sort:\n");
  bubbleSort(bubbleArray2, swap2, size2);
  printArray(bubbleArray2, swap2, size2);
  printf("Total swaps in Bubble Sort: %d\n\n", totalSwaps);

  // SELECTION SORT
  printf("Array 1 Selection Sort:\n");
  selectionSort(selectionArray1, swap3, size1);
  printArray(selectionArray1, swap3, size1);
  printf("Total swaps in Selection Sort: %d\n\n", totalSwaps);

  printf("Array 2 Selection Sort:\n");
  selectionSort(selectionArray2, swap4, size2);
  printArray(selectionArray2, swap4, size2);
  printf("Total swaps in Selection Sort: %d\n\n", totalSwaps);

  return 0;
}