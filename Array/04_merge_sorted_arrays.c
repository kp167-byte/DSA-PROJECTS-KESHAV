/*
 * Question 4: Merge two sorted arrays into one sorted array. (5 marks)
 * Language: C (C99 standard)
 * 
 * Algorithm: Two-Pointer Linear Merge (similar to Merge Sort's merge step)
 * ------------------------------------------------------------------------
 * 1. Initialize pointers i = 0 (for array A), j = 0 (for array B), and k = 0 (for array C).
 * 2. Compare A[i] and B[j]:
 *      - If A[i] <= B[j], place A[i] into C[k], increment i and k.
 *      - Else, place B[j] into C[k], increment j and k.
 * 3. Copy any remaining elements of array A to C.
 * 4. Copy any remaining elements of array B to C.
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:  O(m + n) - Each element from both arrays is visited and merged exactly once.
 * Space Complexity: O(m + n) - For storing the merged sorted array C of size m + n.
 */

#include <stdio.h>

// Function to print array elements
void printArray(const int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("] (Size: %d)\n", size);
}

/*
 * Merges sorted array A (size m) and sorted array B (size n) into array C (size m + n).
 */
void mergeSortedArrays(const int A[], int m, const int B[], int n, int C[]) {
    int i = 0; // Pointer for array A
    int j = 0; // Pointer for array B
    int k = 0; // Pointer for merged array C

    while (i < m && j < n) {
        if (A[i] <= B[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }

    // Append remaining elements of A, if any
    while (i < m) {
        C[k++] = A[i++];
    }

    // Append remaining elements of B, if any
    while (j < n) {
        C[k++] = B[j++];
    }
}

int main(void) {
    printf("============================================================\n");
    printf("     QUESTION 4: MERGE TWO SORTED ARRAYS (5 MARKS)          \n");
    printf("============================================================\n\n");

    // Test Case 1: Standard sorted arrays with overlapping values
    int A1[] = {1, 3, 5, 7, 9};
    int m1 = sizeof(A1) / sizeof(A1[0]);
    int B1[] = {2, 4, 6, 8, 10, 12};
    int n1 = sizeof(B1) / sizeof(B1[0]);
    int C1[m1 + n1];

    printf("Test Case 1:\n");
    printf("Array A: ");
    printArray(A1, m1);
    printf("Array B: ");
    printArray(B1, n1);

    mergeSortedArrays(A1, m1, B1, n1, C1);
    printf("Merged Array C: ");
    printArray(C1, m1 + n1);

    // Test Case 2: One array elements completely greater than the other
    int A2[] = {10, 20, 30};
    int m2 = sizeof(A2) / sizeof(A2[0]);
    int B2[] = {40, 50, 60, 70};
    int n2 = sizeof(B2) / sizeof(B2[0]);
    int C2[m2 + n2];

    printf("\nTest Case 2 (Non-overlapping ranges):\n");
    printf("Array A: ");
    printArray(A2, m2);
    printf("Array B: ");
    printArray(B2, n2);

    mergeSortedArrays(A2, m2, B2, n2, C2);
    printf("Merged Array C: ");
    printArray(C2, m2 + n2);

    printf("\n------------------------------------------------------------\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(m + n)\n");
    printf("  - Auxiliary Space:  O(m + n) for merged array storage\n");
    printf("============================================================\n");

    return 0;
}
