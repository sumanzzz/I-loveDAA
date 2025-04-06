//Algorithm MergeSort(A[0..n-1])
//Sorts Array A[0..n-1] by Divide and Conquer Merge Sort
//Input : Array A[0..n-1] of orderable elements
//Output : Array A[0..n-1] sorted in non decreasing order
/*
    if n > 1
        copy A[0...[n/2] -1] to B[0...[n/2] -1]
        copy A[0...[n/2] -1] to C[0...[n/2] -1]
        MergeSort(B[0...[n/2] -1])
        MergeSort(C[0...[n/2] -1])
        Merge(B , C , A)
*/

//Algorithm Merge(B[0...p-1],C[0...q-1],A[0...p+q-1])
//Merges two sorted arrays into one sorted array
//Input : Arrays B[0...p-1] and C[0...q-1] both sorted
//Output : Sorted array A[0...p+q-1] of elements from Arrays B and C
/*
    i <- 0
    j <- 0
    k <- 0
    while i < p and j < q do
        if B[i] <= C[j]
            A[k] = B[i]
            i <- i + 1
        else
            A[k] = C[j]
            j <- j + 1
        k <- k + 1

        if i == p
            copy C[j...q -1] to A[k...p+q -1]
        else
            copy B[j...q -1] to A[k...p+q -1]


Time Complexity : θ(nlogn)
*/

#include <stdio.h>
#include <stdlib.h>
void MergeSort(int A[],int l,int h){
    int mid;
    if(l<h){
        mid = (l + h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);

    }
}
void Merge(int A[],int l,int mid,int h ){
    int i,j,k;
    int B[50];
    i=l;
    j=mid+1;
    k=l;
    while (i<=mid && j<=h){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++;
        }
        else{
            B[k] = A[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        B[k] = A[i];
        k++;
        i++;
    }
    while(j<=h){
        B[k] = A[j];
        k++;
        j++;
    }
    for(i =l;i<=h;i++){
        A[i] = B[i];
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
    int A[50],n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the Elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    MergeSort(A,0,n-1);
    Display(A,n);
    return 0;
    
}
