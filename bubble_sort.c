#include <stdio.h>

// bubble sort function
void bubbleSort(int bp[], int size) {

  //  access each array element
  for (int step = 0; step < size - 1; ++step) {
      
    //  compare array elements
    for (int i = 0; i < size - step - 1; ++i) {
      if (bp[i] > bp[i + 1]) {
        
        // swapping 
        int temp = bp[i];
        bp[i] = bp[i + 1];
        bp[i + 1] = temp;
      }
    }
  }
}

// printing the array
void printArray(int bp[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", bp[i]);
  }
  printf("\n");
}
// main function
int main() {
  //blood pressure array
  int bp[] = {78, 72, 76, 82, 85, 101, 89, 73, 90, 92};
  //no of elements
  int size = sizeof(bp) / sizeof(bp[0]);
  //printing the usorted array
  printArray(bp, size);
  //applying the unsorted array
  bubbleSort(bp, size);
  printf("Blodd pressure in increasing order! \n");
  //printing the sorted array
  printArray(bp, size);
}