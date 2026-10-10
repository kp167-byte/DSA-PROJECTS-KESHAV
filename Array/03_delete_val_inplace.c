/*
 * Question 3: Delete all occurrences of a given value from an array in-place. (5 marks)
 * Language: C (C99 standard)
 * 
 * Algorithm: Two-Pointer Overwrite Technique
 * ------------------------------------------
 * 1. Maintain a write index 'k' initialized to 0.
 * 2. Scan through array with read index 'i' from 0 to n - 1.
 * 3. If arr[i] != targetValue, copy arr[i] to arr[k] and increment k.
 * 4. Elements equal to targetValue are simply skipped.
 * 5. Return k as the new length of the valid array elements.
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:  O(n) - Single traversal of the array of size n.
 * Space Complexity: O(1) - Auxiliary space is constant (modified strictly in-place).
 */

#include <stdio.h>

// Function to print array elements up to size
void printArray(const int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("] (Size: %d)\n", size);
}

/*
 * Deletes all occurrences of targetValue from arr in-place.
 * Returns the new size of the array.
 */
int deleteAllOccurrences(int arr[], int n, int targetValue) {
    int k = 0; // Write pointer for non-target elements

    for (int i = 0; i < n; i++) {
        if (arr[i] != targetValue) {
            arr[k] = arr[i];
            k++;
        }
    }

    return k; // New effective size
}

int main(void) {
    printf("============================================================\n");
    printf("  QUESTION 3: DELETE ALL OCCURRENCES OF VALUE IN-PLACE (5M) \n");
    printf("============================================================\n\n");

    // Test Case 1: Array with multiple occurrences
    int arr1[] = {3, 2, 2, 3, 4, 3, 5, 3, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int val1 = 3;

    printf("Test Case 1:\n");
    printf("Original Array:\n");
    printArray(arr1, n1);
    printf("Value to delete: %d\n", val1);

    int newSize1 = deleteAllOccurrences(arr1, n1, val1);
    printf("Array after deleting all occurrences of %d:\n", val1);
    printArray(arr1, newSize1);

    // Test Case 2: Array where all elements match target value
    int arr2[] = {7, 7, 7, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int val2 = 7;

    printf("\nTest Case 2 (All elements are target):\n");
    printf("Original Array:\n");
    printArray(arr2, n2);
    printf("Value to delete: %d\n", val2);

    int newSize2 = deleteAllOccurrences(arr2, n2, val2);
    printf("Array after deleting all occurrences of %d:\n", val2);
    printArray(arr2, newSize2);

    // Test Case 3: Target value not present in array
    int arr3[] = {10, 20, 30, 40};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int val3 = 99;

    printf("\nTest Case 3 (Value not present):\n");
    printf("Original Array:\n");
    printArray(arr3, n3);
    printf("Value to delete: %d\n", val3);

    int newSize3 = deleteAllOccurrences(arr3, n3, val3);
    printf("Array after deleting all occurrences of %d:\n", val3);
    printArray(arr3, newSize3);

    printf("\n------------------------------------------------------------\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(n)\n");
    printf("  - Space Complexity: O(1) in-place\n");
    printf("============================================================\n");

    return 0;
}
