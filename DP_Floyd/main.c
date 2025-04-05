/*
ALGORITHM Floyd(W[1..n, 1..n])

// Implements Floyd’s algorithm for the all-pairs shortest-paths problem
// Input: The weight matrix W of a graph with no negative-length cycle
// Output: The distance matrix of the shortest paths’ lengths

D ← W  // Initialize distance matrix (copy of W)

for k ← 1 to n do
    for i ← 1 to n do
        for j ← 1 to n do
            D[i, j] ← min(D[i, j], D[i, k] + D[k, j])
return D  // Return the final distance matrix

Time complexity:θ(n^3)
*/

#include <stdio.h>

int min (int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}

void Floyd(int A[10][10], int nv, int D[10][10])
{
    int i, j, k;
    for (i = 1; i <= nv; i++)
        for (j = 1; j <= nv; j++)
            D[i][j] = A[i][j];

    for (k = 1; k <= nv; k++)
        for (i = 1; i <= nv; i++)
            for (j = 1; j <= nv; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}

void main()
{
    int A[10][10], D[10][10], nv, ne, v1, v2, i, j, w;
    printf("Enter number of vertices: \n");
    scanf("%d", &nv);

    printf("Enter number of edges: \n");
    scanf("%d", &ne);

    for (i = 1; i <= nv; i++)
    for (j = 1; j <= nv; j++)
    {
        if (i == j)
            A[i][j] = 0;
        else
            A[i][j] = 999;
    }

    printf("Enter edges with distance one by one: \n");
    for (i = 1; i <= ne; i++)
    {
        printf("Edge (v1, v2, w):\n");
        scanf("%d %d %d", &v1, &v2, &w);
        A[v1][v2] = w;
    }

    Floyd(A, nv, D);

    printf("Given digraph: \n");
    for (i = 1; i <= nv; i++)
    {
        for (j = 1; j <= nv; j++)
            printf("%d\t", A[i][j]);
        printf("\n");
    }

    printf("Result: \n");
    for (i = 1; i <= nv; i++)
    {
        for (j = 1; j <= nv; j++)
            printf("%d\t", D[i][j]);
        printf("\n");
    }
}
