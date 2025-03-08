//Algorithm BubbleSort(A[0....n-1])
//Sorts Array of elements using Bruteforce BubbleSort
//Input:An array A[0..n-1] of orderable elements
//Output:Array A[0..n-1] sorted in Non decreasing order
/*
     for i <- 0 to n-2 do
        for j <- 0 to n-i-2 do
            if A[j] > A[j+1]
                swap A[j] and A[j+1]


Time Complexity: θ(n^2)
Key Swaps : θ(n^2)

*/



#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b=temp;
}
void BubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
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

    BubbleSort(arr,n);
    Display(arr,n);
    return 0;
}
