//Algorithm QuickSort(A[l...r])
//Sorts a Subarray by Divide and Conquer Quick Sort
//Input : Subarray of Array A[0..n-1],defined by its left and right indices l and r
//Output : Subarray A[l...r] sorted in non decreasing order
/*
    if l < r
        s <- Partition(A[l...r])
        QuickSort(A[l...s-1])
        QuickSort(A[s+1...r])
*/
//Algorithn HoarePartition(A[l...r])
//Partitions a subarray by Hoare's algorithn using first element as pivot
//Input : Subarray of array A[0..n-1] defined by its left and right indices l  and r
//output : Partion of A[l...r] with split position returned as this functions value
/*
        p = A[l]
        i = l
        j = r + 1
        repeat
            repeat i = i + 1 until A[i] >= p
            repeat j = j + 1 until A[j] >= p
            Swap(A[i],A[j])
        until i>=j
        SSwap(A[i],A[j])
        Swap(A[l],A[j])
        return j


Time complexity:
Best case: Ω(nlogn)
worst case: O(n^2)
Average case : θ(nlogn)

*/


#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b=temp;
}
void QuickSort(int arr[],int l, int r){
    int s;
    if(l < r){
        s = partition(arr,l,r);
        QuickSort(arr,l,s-1);
        QuickSort(arr,s+1,r);
    }
}
int partition(int arr[],int l,int r){
    int i,j,p;
    p = arr[l];
    i=l;
    j=r+1;

    do{
        do{
            i++;
        }
        while(arr[i]<=p && i<=r);
        do{
            j--;
        }
        while(arr[j]>p && j>=l);
        if(i<j){
           swap(&arr[i],&arr[j]);
        }

    }
    while(i<j);

    swap(&arr[l],&arr[j]);
    return j;

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

    QuickSort(arr,0,n-1);
    Display(arr,n);
    return 0;
}
