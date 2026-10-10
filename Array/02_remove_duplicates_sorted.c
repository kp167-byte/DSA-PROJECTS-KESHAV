/*
 * Question 2: Remove duplicates from a sorted array in-place. (5 marks)
 * Language: C (C99 standard)
 * 
 * Algorithm: Two-Pointer In-Place Technique
 * -----------------------------------------
 * 1. If size is 0 or 1, return size as no duplicates can exist.
 * 2. Maintain a slow pointer 'k' pointing to the last known unique element (initialized to 0).
 * 3. Use a fast pointer 'i' starting from index 1 to traverse the array.
 * 4. Whenever arr[i] != arr[k], increment k and copy arr[i] to arr[k].
 * 5. Return k + 1, which represents the new count of unique elements.
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:  O(n) - Single linear scan of n elements.
 * Space Complexity: O(1) - Auxiliary space used is constant (in-place modification).
 */

#include <stdio.h>

// Function to print array elements up to a given length
void printArray(const int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("] (Size: %d)\n", size);
}

/*
 * Removes duplicates from sorted array in-place.
 * Returns the new length containing unique elements.
 */
int removeDuplicates(int arr[], int n) {
    if (n <= 1) {
        return n;
    }

    int k = 0; // Index of last unique element placed

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[k]) {
            k++;
            arr[k] = arr[i];
        }
    }

    return k + 1; // New size is index + 1
}

int main(void) {
    printf("============================================================\n");
    printf("  QUESTION 2: REMOVE DUPLICATES FROM SORTED ARRAY (5 MARKS) \n");
    printf("============================================================\n\n");

    // Test Case 1: General sorted array with multiple duplicates
    int arr1[] = {1, 1, 2, 2, 2, 3, 4, 4, 5, 6, 6, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Test Case 1:\n");
    printf("Original Array:\n");
    printArray(arr1, n1);

    int newSize1 = removeDuplicates(arr1, n1);
    printf("Array after in-place duplicate removal (unique elements):\n");
    printArray(arr1, newSize1);

    // Test Case 2: All identical elements
    int arr2[] = {4, 4, 4, 4, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nTest Case 2 (All identical elements):\n");
    printf("Original Array:\n");
    printArray(arr2, n2);

    int newSize2 = removeDuplicates(arr2, n2);
    printf("Array after in-place duplicate removal:\n");
    printArray(arr2, newSize2);

    // Test Case 3: Already distinct elements
    int arr3[] = {10, 20, 30, 40, 50};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    printf("\nTest Case 3 (Already distinct elements):\n");
    printf("Original Array:\n");
    printArray(arr3, n3);

    int newSize3 = removeDuplicates(arr3, n3);
    printf("Array after in-place duplicate removal:\n");
    printArray(arr3, newSize3);

    printf("\n------------------------------------------------------------\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(n)\n");
    printf("  - Space Complexity: O(1) in-place\n");
    printf("============================================================\n");

    return 0;
}
