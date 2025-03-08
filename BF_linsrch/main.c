//Algorithm SequentialSearch(A[0...n-1)
//Searches for a given value in a given Array by Bruteforce Sequential Search
//Input: An Array A[0...n-1] and a search key
//Output: The index of the first element in A that matches k or -1 if there are no matching elements
/*
    i <- 0
    while i<n and A[i] != K do
        i <- i + 1

    if i < n return i
    else return -1


complexity:
Best case: Ω(1)
worst case: O(n)
Average case : θ(n)

*/

#include <stdio.h>
#include <stdlib.h>
void SequentialSearch(int arr[],int n,int key){
    int i=0;
    while(i<n && arr[i]!= key ){
        i++;
    }
    if(arr[i]==key){
        printf("Element found at position:%d",i);
    }
    else{
        printf("Element not found!");
    }
}
int main()
{
    int arr[50],n,key;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the Elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the Element to Search:");
    scanf("%d",&key);
    SequentialSearch(arr,n,key);
    return 0;
}
