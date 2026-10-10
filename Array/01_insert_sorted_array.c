/*
 * Question 1: Insert an element into a sorted array so that it stays sorted. State the complexity. (5 marks)
 * Language: C (C99 standard)
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:
 *   - Best Case: O(1) - when the new element is greater than all existing elements (inserted at the end, 0 shifts).
 *   - Worst Case: O(n) - when the new element is smaller than all existing elements (inserted at index 0, shifting all n elements).
 *   - Average Case: O(n) - on average, n/2 elements are shifted.
 * 
 * Space Complexity:
 *   - Auxiliary Space: O(1) - in-place insertion with constant extra memory.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_CAPACITY 100

// Function to print array elements
void printArray(const int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("] (Size: %d)\n", size);
}

/*
 * Inserts 'key' into a sorted array 'arr' of current 'size' and maximum 'capacity'.
 * Returns true if insertion was successful, false if array is full.
 */
bool insertSorted(int arr[], int *size, int capacity, int key) {
    if (*size >= capacity) {
        printf("Error: Array capacity reached (%d). Cannot insert %d.\n", capacity, key);
        return false;
    }

    int i = *size - 1;

    // Shift elements of arr[0..size-1] that are greater than key to one position ahead
    while (i >= 0 && arr[i] > key) {
        arr[i + 1] = arr[i];
        i--;
    }

    // Insert key at its sorted position
    arr[i + 1] = key;
    (*size)++;
    return true;
}

int main(void) {
    int arr[MAX_CAPACITY] = {10, 20, 30, 40, 60, 70};
    int size = 6;

    printf("============================================================\n");
    printf("   QUESTION 1: INSERT ELEMENT INTO SORTED ARRAY (5 MARKS)   \n");
    printf("============================================================\n\n");

    printf("Initial sorted array:\n");
    printArray(arr, size);

    int elementsToInsert[] = {50, 5, 80, 25};
    int numInserts = sizeof(elementsToInsert) / sizeof(elementsToInsert[0]);

    for (int k = 0; k < numInserts; k++) {
        int key = elementsToInsert[k];
        printf("\n--> Inserting %d into sorted array...\n", key);
        insertSorted(arr, &size, MAX_CAPACITY, key);
        printf("Array after inserting %d:\n", key);
        printArray(arr, size);
    }

    printf("\n------------------------------------------------------------\n");
    printf("COMPLEXITY SUMMARY:\n");
    printf("  - Time Complexity: O(n) worst/average case (due to shifting elements)\n");
    printf("                     O(1) best case (insert at the end)\n");
    printf("  - Auxiliary Space: O(1) in-place\n");
    printf("============================================================\n");

    return 0;
}
