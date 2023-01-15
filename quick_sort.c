#include<stdio.h>
// printing  the array
void printArray(int*bp, int n){
    for(int i=0; i<n;i++){
        printf("%d  ",bp[i]);
    }
    printf("\n");
}
// quicksort
void quickSort(int bp[], int low, int high){
    int partitionIndex;
    if(low<high){
        partitionIndex = partition(bp, low, high);
        quickSort(bp,low, partitionIndex-1);
        quickSort(bp, partitionIndex+1,high);
    }
}
// partition
int partition( int bp[], int low, int high){
    int pivot =bp[low];
    int i=low+1;
    int j= high;
    int temp;
    do
    {
    while (bp[i]<=pivot)
    {
    i++;
    }
    while (bp[j]>=pivot)
    {
        j--;
    }
    if (i<j)
    {
        temp=bp[i];
        bp[i]=bp[j];
        bp[j]=temp;
    }
    } while (i<j);
    // swapping 
    temp=bp[low];
    bp[low]=bp[j];
    bp[j]=temp;
    return j;
}
//main function
int main(){
    // blood pressure array
    int bp[]={78,72,76,82,85,101,89,73,90,92};
    //no of elements
    int n = 10;
    // print the unsorted array
    printArray(bp,n);
    //applying the quick sort 
    quickSort(bp,0,n-1);
    printf("blood pressure in incresing order! \n ");
    //printing the sorted array
    printArray(bp,n);
    return 0;
}