/*
ALGORITHM Warshall(A[1..n, 1..n])

// Implements Warshall's algorithm for computing the transitive closure
// Input: The adjacency matrix A of a digraph with n vertices
// Output: The transitive closure of the digraph

R^(0) ← A

for k ← 1 to n do
    for i ← 1 to n do
        for j ← 1 to n do
            R^(k)[i, j] ← R^(k-1)[i, j] or (R^(k-1)[i, k] and R^(k-1)[k, j])

return R^(n)

Time complexity: θ(n^3)
*/

#include <stdio.h>

void warshall(int A[10][10], int nv, int R[10][10])
{
    int i, j, k;
    for (i = 1; i <= nv; i++)
        for (j = 1; j <= nv; j++)
            R[i][j] = A[i][j];

    for (k = 1; k <= nv; k++)
        for (i = 1; i <= nv; i++)
            for (j = 1; j <= nv; j++)
                R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
}

void main()
{
    int A[10][10], R[10][10], nv, ne, v1, v2, i, j;
    printf("Enter the number of vertices:\n");
    scanf("%d", &nv);

    printf("Enter the number of edges:\n");
    scanf("%d", &ne);

    for (i = 1; i <= nv; i++)
        for (j = 1; j <= nv; j++)
            A[i][j] = 0;

    printf("Enter edges one by one:\n");
    for (i = 1; i <= ne; i++)
    {
        printf("Edge %d:\n", i);
        scanf("%d %d", &v1, &v2);
        A[v1][v2] = 1;
    }

    warshall(A, nv, R);

    printf("Given digraph:\n");
    for (i = 1; i <= nv; i++)
    {
        for (j = 1; j <= nv; j++)
            printf("%d\t", A[i][j]);
        printf("\n");
    }

    printf("Transitive closure:\n");
    for (i = 1; i <= nv; i++)
    {
        for (j = 1; j <= nv; j++)
            printf("%d\t", R[i][j]);
        printf("\n");
    }
}
