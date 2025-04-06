//Algorithm SelectionSort(A[0..n-1])
//Sort a given Array A[0..n-1] by Bruteforce Selection sort
//Input: An Array A[0...n-1] of orderable elements
//output: Array A[0..n-1] in non decreasing order
/*
    for i <- 0 to n-2 do
        min <- i
        for j <-i+1 to n-1 do
            if A[j] < A[min]
                min <- j

         Swap A[j] and A[min]


Time Complexity : θ(n^2)
Key Swaps : θ(n)

*/



#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])
                min = j;
        }
        swap(&arr[i],&arr[min]);

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

    SelectionSort(arr,n);
    Display(arr,n);
    return 0;
}
