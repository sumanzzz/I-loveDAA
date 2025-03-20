/*
Algorithm HeapBottomUp(H[1...n])

//constructs a heap from elements of a given array by the bottom up algorithm
//Input: An array H[1..n] of orderable elements
//Output: A heap H[1..n]

    for i <- [n/2] down to 1 do
        K  <- I; V <- h[K]
        heap <- false
        while not heap and 2 * k <= n do
            j <- 2*k
            if j < n
                if H[j] < H[j+1]  j <- j+1
            if v >= H[j]
                heap <- true
            else H[k] <- B[j]  k <- j
        H[k] <- v


Time complexity : O(nlogn)
*/

#include <stdio.h>
#include <stdlib.h>

// Function to build a max heap from an unsorted array
void heapify(int H[], int n) {
    int i, k, v, heapify, j;

    // Start from the last non-leaf node and heapify each node up to the root
    for (i = n / 2; i >= 1; i--) {
        k = i;
        v = H[k];
        heapify = 0;

        // Percolate down to maintain heap property
        while (heapify == 0 && 2 * k <= n) {
            j = 2 * k;  // Left child

            // Choose the larger child if right child exists
            if (j < n && H[j] < H[j + 1]) {
                j = j + 1;  // Move to right child
            }

            // If parent is already larger than child, stop
            if (v > H[j]) {
                heapify = 1;
            } else {
                // Swap parent with the larger child
                H[k] = H[j];
                k = j;
            }
        }

        // Place the original value in its correct position
        H[k] = v;
    }
}

// Function to perform heap sort by deleting max elements
void maxDeletion(int H[], int n) {
    int i, temp;

    // Swap the first (largest) element with the last and reduce heap size
    for (i = n; i > 1; i--) {
        temp = H[1];
        H[1] = H[i];
        H[i] = temp;

        // Reheapify the reduced heap
        heapify(H, i - 1);
    }
}

int main() {
    int H[20], i, n;

    // Taking input from user
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &H[i]);
    }

    // Display input array before sorting
    printf("Array before sorting:\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t", H[i]);
    }

    // Convert the array into a max heap
    heapify(H, n);

    // Perform heap sort
    maxDeletion(H, n);

    // Display sorted array
    printf("\nSorted array:\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t", H[i]);
    }

    return 0;
}
