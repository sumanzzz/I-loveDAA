//Algorithm BFS(G)
//Implements a Decrease and Conquer BFS traversal of a given graph
//Input : Graph G ={V,E}
//Output : Graph G with its vertices marked with consecutive integers in the order they are visited by the BFS traversal
/*
    mark each vertex in V with 0 as a mark of being "unvisted"
        count <- 0
        for each vertex v in V do
                if v is marked with 0
                    bfs(v)
*/

//Algorithm bfs(V)
//Visits all the unvisited vertices connected  to vertex v by a path and number them in the order they are visited via global variable count
/*
    count <- count + 1
    while the queue is not empty do
    for each vertex w in V adjacent to the front vertex do
        if w is marked with 0
            count <- count + 1
            add w to the queue
    remove the front vertex from the queue


Time Complexity:
For adjacency matrix representation : O(|V|^2)
For adjacency List represntation : O(|v| + |E|)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void readMat(int adj[MAX][MAX], int n) {
    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}

void displayMat(int adj[MAX][MAX], int n) {
    printf("The adjacency matrix is:\n");
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
}

void bfs(int adj[MAX][MAX], int n, int start, int visited[MAX]) {
    int queue[MAX], front = 0, rear = 0;

    queue[rear] = start; // Enqueue start vertex
    visited[start] = 1;

    printf("BFS Traversal:\n");

    while (front <= rear) {
        int current = queue[front++]; // Dequeue
        printf("%d ", current);

        for (int i = 1; i < n+1; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                queue[++rear] = i; // Enqueue
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int isConnected(int n, int visited[MAX]) {
    for (int i = 1; i < n+1; i++) {
        if (!visited[i]) {
            return 0; // Graph is not connected
        }
    }
    return 1; // Graph is connected
}

int main() {
    int n, start;
    int adj[MAX][MAX];
    int visited[MAX] = {0}; // Initialize all nodes as unvisited

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices. Please enter a value between 1 and %d.\n", MAX);
        return 1;
    }

    readMat(adj, n);
    displayMat(adj, n);

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    if (start < 1 || start > n) {
        printf("Invalid starting vertex. Please enter a value between 1 and %d.\n", n);
        return 1;
    }

    bfs(adj, n, start, visited);

    if (isConnected(n, visited)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected!\n");
    }

    return 0;
}
