/*
-> add all nodes with in-degree 0 to a queue

-> while the queue is not empty:

        - Remove a node from the queue

        - For each outgoing edge from the removed node ,decrement the in-degree of the destination node by 1

        - if the in-degree of a destination node becomes 0, add it to the queue

-> if the queue is empty and there still nodes in the graph, the graph contains a cycle and cannot be topologically sorted

-> The nodes in the queue represents the topological ordering of the graph.



Time Complexity:
For Matrix representation : O(|V|^2)
For List Representation : O(|V| + |E|)
*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int Graph[MAX][MAX], inDegree[MAX];

void TopologicalSort(int v) {
    int count = 0, queue[MAX], front = 0, rear = 0;

    // Initialize in-degree array
    for (int i = 0; i < v; i++){
        inDegree[i] = 0;
    }

    // Compute in-degrees of all vertices
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            if (Graph[i][j] == 1){
                inDegree[j]++;
            }
        }
    }



    // Enqueue vertices with zero in-degree
    for (int i = 0; i < v; i++){
        if (inDegree[i] == 0){
            queue[rear++] = i;
        }

    }

    // Process vertices in queue
    while (front < rear) {
        int current = queue[front++];
        printf("%d\t", current);
        count++;

        for (int i = 0; i < v; i++){
            if (Graph[current][i] == 1 && --inDegree[i] == 0){
                 queue[rear++] = i;
            }

        }

    }

    // Check for cycles
    if (count != v){
        printf("\nGraph has a Cycle! Topological Sort not possible.");
    }

    else{
        printf("\nTopological sort complete.");
    }

}

int main() {
    int v, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // Initialize adjacency matrix
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            Graph[i][j] = 0;

    // Read edges
    for (int i = 0; i < e; i++) {
        int u, v;
        printf("Enter the Edge (u,v):\n");
        scanf("%d %d", &u, &v);
        Graph[u][v] = 1;
    }

    printf("Topological Sort:\n");
    TopologicalSort(v);

    return 0;
}
