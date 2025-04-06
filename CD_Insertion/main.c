//ALgorithm InsertionSort(A[0...n-1])
//Sorts a given array by Decrease and Conquer Insertion Sort
//Input : An array A[0...n-1] of orderable elements
// output : Array A[0..n-1] sorted in non decreasing order
/*
    for i <- 1 to n-1 do
        v <- A[i]
        j <- i-1
        while j >=0 and A[j] > v do
            A[j + 1] <- A[j]
            j <- j - 1
        A[j + 1] <- v


Time Complexity:
Best case: Ω(n)
worst case: O(n^2)
Average case : θ(n^2)

*/

#include <stdio.h>
#include <stdlib.h>
void InsertionSort(int arr[],int n){
    int v,j;
    for(int i=1;i<n;i++){
        v = arr[i];
        j=i-1;
        while(j>=0 && arr[j] > v){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=v;
    }
}
void Display(int arr[],int n){
    printf("Array in Sorted order:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
int main()
{
    int arr[50],n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the Elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    InsertionSort(arr,n);
    Display(arr,n);
    return 0;
}
