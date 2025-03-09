//Algorithm DFS(G)
//Implements a DFS traversal of a given graph
//Input : A graph G = (V,E)
//Output : Graph G with its vertices marked with consecutive integers in the order they are first encountered by the traversal . Mark each vertex in V with 0
// as to mark of being "unvisited"
/*
    count <- 0
    for each vertex v in V do
            if v is marked with 0
                dfs(V)
*/

//Algorithm dfs(V)
//visits recursively all the unvisited vertices connected to vertex v by a path and numbers them in the order they are encountered via global variable count
/*
    count <- count +1;
    for each vertex w in v adjacent to v do
        if w is marked with 0
            dfs(w)



Time Complexity:
For adjacency matrix representation : O(|V|^2)
For adjacency List represntation : O(|v| + |E|)

*/


#include <stdio.h>
#include <stdlib.h>
int Graph[20][20],visited[10],i,j,n,start;
void matread(){

    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=1;i<n+1;i++){
        for(j=1;j<n+1;j++){
            scanf("%d",&Graph[i][j]);
        }
    }
}
void matdisp(){
    printf("Entered adjacency matrix is:\n");
    for(i=1;i<n+1;i++){
        for(j=1;j<n+1;j++){
            printf("%d\t",Graph[i][j]);
        }
        printf("\n");
    }
}
void DFS(int v){
    visited[v]=1;

    printf("%d\t",v);
    for(i=1;i<n+1;i++){
        if(Graph[v][i]==1 && !visited[i]){

            DFS(i);
        }
    }
}
int isConnected() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) 
            return 0;
    }
    return 1; 
}
int main()
{

    matread();
    matdisp();
    printf("Enter the starting vertex:");
    scanf("%d",&start);
    printf("\nDFS traversal is:\n");

    DFS(start);
    if(isConnected()){
        printf("\nThe graph is connected.");
    }
    else{
        printf("\nThe graph is not connected!");
    }


    return 0;
}
