//Algorithm StringMatch( T[0...n-1], P[0...n-1])
//Implements Bruteforce String Matching
//Input : An Arry T[0...n-1] of n characters representing Text and Array P[0...n-1] of m characters representing Pattern
//Output: The index of the first character in the Text that Starts
/*
    for i <- 0 to n-m do
        j <- 0
        while j<m and P[j] = T[i+j] do
            j <- j+1
            if j=m
             return
        return -1


Time Complexity:
Best case: Ω(m)
worst case: O(mn)
Average case : θ(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void StringMatch(char T[],char P[],int n,int m){
    int found =0;
    for(int i=0;i<=n-m;i++){
        int j=0;
        while(j<m && P[j]==T[i+j]){
            j++;
        }
        if(j==m){
            printf("Pattern Found at index:%d",i);
            found =1;
        }

    }
    if(!found){
        printf("Pattern not found!");
    }
}
int main()
{
    char T[20],P[20];
    int i,j,m,n;
    printf("Enter the Text:\n");
    gets(T);
    printf("Enter the Pattern:\n");
    gets(P);
    n=strlen(T);
    m=strlen(P);
    StringMatch(T,P,n,m);
    return 0;
}
