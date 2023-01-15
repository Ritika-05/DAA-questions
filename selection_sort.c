#include <stdio.h>
// swapping function
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
// selection sort function
void selectionSort(int bp[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < size; j++) {
      if (bp[j] < bp[min_idx])
        min_idx = j;
    }

    // put min at the correct position
    swap(&bp[min_idx], &bp[i]);
  }
}

//print function
void printArray(int bp[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", bp[i]);
  }
  printf("\n");
}
// main function
int main() {
  int bp[] = {78,  72,  76,  82,  85,  101,  89,  73,  90,  92 };
  int size = sizeof(bp) / sizeof(bp[0]);
  printArray(bp, size);
  selectionSort(bp, size);
  printf("Sorted array in Acsending Order:\n");
  printArray(bp, size);
}