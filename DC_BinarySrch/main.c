//Algorithm BinarySearch(A , key , low , high)
//Searches for a given value in a given Array by Divide and Conquer Binary Search
//Input : An sorted Array A of numbers
//Key : The value to be searched
//low : The starting index of the array
//high : The ending index of the array
/*
    if low > high
        return -1
    mid = low + (high - low)/2

    if a[mid] == key
        return mid
    else if a[mid] > key
        return BinarySearch(A , key , low , mid-1)
    else
        return BinarySearch(A , key , mid+1 , high)


Time Complexity:
Best case: Ω(1)
worst case: O(logN)
Average case : θ(logN)
*/


#include <stdio.h>
#include <stdlib.h>
void BinarySearch(int arr[],int n,int key,int l,int h){
    if(l>h){
        printf("Element not found!");
        return -1;
    }
    int mid = (l + h)/2;

    if(arr[mid]==key){
        printf("Element found at position:%d",mid);
    }
    else if(key>arr[mid]){
        return BinarySearch(arr,n,key,mid+1,h);
    }
    else{
        return BinarySearch(arr,n,key,l,mid-1);
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
    BinarySearch(arr,n,key,0,n-1);
    return 0;
}
