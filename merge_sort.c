#include <stdio.h>
// creating merge function
void merge(int bp[], int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    int A[n1], B[n2];

    for (int i = 0; i < n1; i++)
        A[i] = bp[p + i];
    for (int j = 0; j < n2; j++)
        B[j] = bp[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (A[i] <= B[j])
        {
            bp[k] = A[i];
            i++;
        }
        else
        {
            bp[k] = B[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        bp[k] = A[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        bp[k] = B[j];
        j++;
        k++;
    }
}
// merge sort function
void mergeSort(int bp[], int low, int high)
{
    if (low < high)
    {

        int mid = (high + low) / 2;

        mergeSort(bp, low, mid);
        mergeSort(bp, mid + 1, high);

        merge(bp, low, mid, high);
    }
}

// Printing the array
void printArray(int bp[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", bp[i]);
    printf("\n");
}
//main function
int main()
{
    // blood pressure array
    int bp[] = {78, 72, 76, 82, 85, 101, 89, 73, 90, 92};
    //size of the array
    int size = sizeof(bp) / sizeof(bp[0]);
// printing the unsorted array
    printArray(bp, size);
// applying the merge sort
    mergeSort(bp, 0, size - 1);
    //printint the sorted array
    printf("Blood Pressure in increasing order! \n");
    printArray(bp, size);
}