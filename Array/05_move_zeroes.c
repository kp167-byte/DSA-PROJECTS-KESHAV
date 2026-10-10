/*
 * Question 5: Move all zeroes to the end of an array while keeping the order of other elements. (5 marks)
 * Language: C (C99 standard)
 * 
 * Algorithm: Two-Pointer In-Place Stable Partition
 * -------------------------------------------------
 * 1. Maintain a pointer 'nonZeroIdx' initialized to 0.
 * 2. Traverse the array with index 'i' from 0 to n - 1.
 * 3. Whenever arr[i] != 0, if i != nonZeroIdx, swap arr[i] and arr[nonZeroIdx].
 *    Then increment nonZeroIdx.
 * 4. This guarantees all non-zero elements are moved forward maintaining their
 *    relative order, while zeroes naturally shift to the end in a single pass.
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:  O(n) - Single traversal of the array of size n.
 * Space Complexity: O(1) - In-place with constant extra memory.
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
 * Moves all zeroes to the end in-place while keeping relative order of non-zero elements.
 */
void moveZeroesToEnd(int arr[], int n) {
    int nonZeroIdx = 0; // Index to place next non-zero element

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            if (i != nonZeroIdx) {
                // Swap arr[i] and arr[nonZeroIdx]
                int temp = arr[i];
                arr[i] = arr[nonZeroIdx];
                arr[nonZeroIdx] = temp;
            }
            nonZeroIdx++;
        }
    }
}

int main(void) {
    printf("============================================================\n");
    printf("     QUESTION 5: MOVE ALL ZEROES TO END IN-PLACE (5 MARKS)  \n");
    printf("============================================================\n\n");

    // Test Case 1: Mixed zeroes and non-zeroes
    int arr1[] = {0, 1, 0, 3, 12, 0, 5, 0, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Test Case 1:\n");
    printf("Original Array:\n");
    printArray(arr1, n1);

    moveZeroesToEnd(arr1, n1);
    printf("Array after moving zeroes to end:\n");
    printArray(arr1, n1);

    // Test Case 2: Array already with no zeroes
    int arr2[] = {4, 5, 6, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nTest Case 2 (No zeroes present):\n");
    printf("Original Array:\n");
    printArray(arr2, n2);

    moveZeroesToEnd(arr2, n2);
    printf("Array after moving zeroes to end:\n");
    printArray(arr2, n2);

    // Test Case 3: Array with all zeroes
    int arr3[] = {0, 0, 0, 0};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    printf("\nTest Case 3 (All zeroes):\n");
    printf("Original Array:\n");
    printArray(arr3, n3);

    moveZeroesToEnd(arr3, n3);
    printf("Array after moving zeroes to end:\n");
    printArray(arr3, n3);

    printf("\n------------------------------------------------------------\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(n)\n");
    printf("  - Space Complexity: O(1) in-place\n");
    printf("============================================================\n");

    return 0;
}
