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

#define MAX 20

int graph[MAX][MAX]; // Adjacency matrix
int visited[MAX];     // Visited array
int n;               // Number of vertices

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 1; i < n+1; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

void DFS(void) {
    for (int i = 1; i < n+1; i++) {
        visited[i] = 0;  // Initialize all nodes as unvisited
    }

    printf("DFS Traversal:\n");
    for (int i = 1; i < n+1; i++) {
        if (visited[i] == 0) {
            printf("\nStarting new DFS from node %d\n", i);
            dfs(i);
        }
    }
}

int main() {
    int start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal starting from vertex %d:\n", start);
    dfs(start);

    printf("\n");

    return 0;
}
