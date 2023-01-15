#include <stdio.h>

// printing the array
void printArray(int bp[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", bp[i]);
  }
  printf("\n");
}

void insertionSort(int bp[], int size) {
  for (int step = 1; step < size; step++) {
    int key = bp[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
   
    while (key < bp[j] && j >= 0) {
      bp[j + 1] = bp[j];
      --j;
    }
    bp[j + 1] = key;
  }
}

// main function
int main() {
  int bp[] = {78,72,76,82,85,101,89,73,90,92};
  int size = sizeof(bp) / sizeof(bp[0]);
  printArray(bp, size);
  insertionSort(bp, size);
  printf("blood pressure in increasing order! \n");
  printArray(bp, size);
}