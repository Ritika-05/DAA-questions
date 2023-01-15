#include <stdio.h>  
int getMax(int a[], int n) // function to get maximum element from the given array  
{  
  int max = a[0];  
  for (int i = 1; i < n; i++)  
    if (a[i] > max)  
      max = a[i];  
  return max;  
}  
void bucket(int a[], int n) // function to implement bucket sort  
{  
  int max = getMax(a, n); //max is the maximum element of array  
  int bucket[max], i;  
  for (int i = 0; i <= max; i++)  
  {  
    bucket[i] = 0;  
  }  
  for (int i = 0; i < n; i++)  
  {  
    bucket[a[i]]++;  
  }  
  for (int i = 0, j = 0; i <= max; i++)  
  {  
    while (bucket[i] > 0)  
    {  
      a[j++] = i;  
      bucket[i]--;  
    }  
  }  
}  
void printArr(int a[], int n) // function to print array elements  
{  
  for (int i = 0; i < n; ++i)  
    printf("%d  ", a[i]);  
}  
int main()  
{  
  int a[] = {55, 22, 88, 58, 69, 41, 91, 95};  
  int n = sizeof(a) / sizeof(a[0]); // n is the size of array  
  printf("Before sorting array elements are - \n");  
  printArr(a, n);  
  bucket(a, n);  
  printf("\nAfter sorting array elements are - \n");  
  printArr(a, n);  
}  