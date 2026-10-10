/*
 * Question 6: Find the largest and second largest elements in an array in a single traversal. (5 marks)
 * Language: C (C99 standard)
 * 
 * Algorithm: Single-Pass Two-Variable Tracking
 * --------------------------------------------
 * 1. Initialize 'first' (largest) and 'second' (second largest) to INT_MIN.
 * 2. Traverse the array of size n once:
 *      - If current element arr[i] > first:
 *            second = first;
 *            first = arr[i];
 *      - Else if arr[i] > second and arr[i] != first:
 *            second = arr[i];
 * 3. After the loop, if second remains INT_MIN, it indicates all elements are identical
 *    or no distinct second largest element exists.
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:  O(n) - Exactly one pass (single traversal) through the array.
 * Space Complexity: O(1) - Uses only constant auxiliary variables.
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Function to print array elements
void printArray(const int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("] (Size: %d)\n", size);
}

/*
 * Finds the largest and distinct second largest element in a single pass.
 * Returns true if a valid second largest exists, false otherwise.
 */
bool findLargestAndSecondLargest(const int arr[], int n, int *first, int *second) {
    if (n < 2) {
        return false;
    }

    *first = INT_MIN;
    *second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > *first) {
            *second = *first;
            *first = arr[i];
        } else if (arr[i] > *second && arr[i] != *first) {
            *second = arr[i];
        }
    }

    return (*second != INT_MIN);
}

int main(void) {
    printf("============================================================\n");
    printf("  QUESTION 6: LARGEST & SECOND LARGEST (SINGLE PASS) (5M)   \n");
    printf("============================================================\n\n");

    // Test Case 1: Standard unsorted array with positive and negative numbers
    int arr1[] = {12, 35, 1, 10, 34, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int first, second;

    printf("Test Case 1:\nArray: ");
    printArray(arr1, n1);
    if (findLargestAndSecondLargest(arr1, n1, &first, &second)) {
        printf("Result -> Largest: %d, Second Largest: %d\n", first, second);
    } else {
        printf("Result -> No distinct second largest element exists.\n");
    }

    // Test Case 2: Array with duplicate largest values
    int arr2[] = {50, 20, 50, 40, 30};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nTest Case 2 (Duplicate maximums):\nArray: ");
    printArray(arr2, n2);
    if (findLargestAndSecondLargest(arr2, n2, &first, &second)) {
        printf("Result -> Largest: %d, Second Largest: %d\n", first, second);
    } else {
        printf("Result -> No distinct second largest element exists.\n");
    }

    // Test Case 3: All elements identical
    int arr3[] = {7, 7, 7, 7};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    printf("\nTest Case 3 (All elements equal):\nArray: ");
    printArray(arr3, n3);
    if (findLargestAndSecondLargest(arr3, n3, &first, &second)) {
        printf("Result -> Largest: %d, Second Largest: %d\n", first, second);
    } else {
        printf("Result -> No distinct second largest element exists (all elements identical).\n");
    }

    // Test Case 4: Negative values
    int arr4[] = {-15, -3, -8, -1, -20};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);

    printf("\nTest Case 4 (All negative numbers):\nArray: ");
    printArray(arr4, n4);
    if (findLargestAndSecondLargest(arr4, n4, &first, &second)) {
        printf("Result -> Largest: %d, Second Largest: %d\n", first, second);
    } else {
        printf("Result -> No distinct second largest element exists.\n");
    }

    printf("\n------------------------------------------------------------\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(n) - Single loop traversal\n");
    printf("  - Space Complexity: O(1) - Constant auxiliary memory\n");
    printf("============================================================\n");

    return 0;
}
