/*
 * Question 8: Find the maximum subarray sum using Kadane's Algorithm
 *             and dry run it on an example. (10 marks)
 * Language: C (C99 standard)
 * 
 * Kadane's Algorithm Theory:
 * --------------------------
 * At each position i, the maximum sum subarray ending at i is either:
 *   1. Just the element arr[i] itself (start a fresh new subarray), or
 *   2. The previous maximum subarray sum plus arr[i] (extend the existing subarray).
 * 
 * Formula:
 *   curr_max   = max(arr[i], curr_max + arr[i])
 *   max_so_far = max(max_so_far, curr_max)
 * 
 * Complexity:
 *   - Time Complexity:  O(n) - Exactly one pass through the array.
 *   - Space Complexity: O(1) - Constant auxiliary memory.
 * 
 * Dry Run Example: arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 * Maximum Subarray: [4, -1, 2, 1] with Sum = 6.
 */

#include <stdio.h>
#include <limits.h>

// Function to find maximum subarray sum and print dry-run execution table
int kadanesAlgorithmWithDryRun(const int arr[], int n, int *outStart, int *outEnd) {
    int max_so_far = arr[0];
    int curr_max = arr[0];

    int start = 0;
    int end = 0;
    int temp_start = 0;

    printf("+-------+---------+------------+--------------+------------------+-----------------------+\n");
    printf("| Index | Element | curr_max   | max_so_far   | Subarray Window  | Decision / Action     |\n");
    printf("+-------+---------+------------+--------------+------------------+-----------------------+\n");

    // Print initial state (index 0)
    printf("| %-5d | %-7d | %-10d | %-12d | [%d .. %d]         | Initialized with arr[0]|\n",
           0, arr[0], curr_max, max_so_far, start, end);

    for (int i = 1; i < n; i++) {
        char decision[40];

        if (arr[i] > curr_max + arr[i]) {
            curr_max = arr[i];
            temp_start = i;
            snprintf(decision, sizeof(decision), "Start new subarray at %d", i);
        } else {
            curr_max = curr_max + arr[i];
            snprintf(decision, sizeof(decision), "Extend current subarray");
        }

        if (curr_max > max_so_far) {
            max_so_far = curr_max;
            start = temp_start;
            end = i;
        }

        printf("| %-5d | %-7d | %-10d | %-12d | [%d .. %d]         | %-21s |\n",
               i, arr[i], curr_max, max_so_far, start, end, decision);
    }
    printf("+-------+---------+------------+--------------+------------------+-----------------------+\n");

    *outStart = start;
    *outEnd = end;
    return max_so_far;
}

int main(void) {
    printf("=========================================================================================\n");
    printf("   QUESTION 8: MAXIMUM SUBARRAY SUM USING KADANE'S ALGORITHM (10 MARKS)                  \n");
    printf("=========================================================================================\n\n");

    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input Array: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n\n");

    printf("--- STEP-BY-STEP DRY RUN OF KADANE'S ALGORITHM ---\n");
    int startIdx = 0, endIdx = 0;
    int maxSum = kadanesAlgorithmWithDryRun(arr, n, &startIdx, &endIdx);

    printf("\n=========================================================================================\n");
    printf("FINAL RESULTS:\n");
    printf("  - Maximum Subarray Sum: %d\n", maxSum);
    printf("  - Subarray Indices:     From index %d to %d (inclusive)\n", startIdx, endIdx);
    printf("  - Contiguous Subarray:  [ ");
    for (int i = startIdx; i <= endIdx; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    printf("=========================================================================================\n\n");

    printf("DRY RUN EXPLANATION:\n");
    printf("  1. Index 0: arr[0]=-2. curr_max = -2, max_so_far = -2.\n");
    printf("  2. Index 1: arr[1]= 1. 1 > (-2 + 1), so start new subarray at index 1. curr_max = 1, max_so_far = 1.\n");
    printf("  3. Index 2: arr[2]=-3. Extend: 1 + (-3) = -2. curr_max = -2, max_so_far = 1.\n");
    printf("  4. Index 3: arr[3]= 4. 4 > (-2 + 4), so start fresh at index 3. curr_max = 4, max_so_far = 4.\n");
    printf("  5. Index 4: arr[4]=-1. Extend: 4 + (-1) = 3. curr_max = 3, max_so_far = 4.\n");
    printf("  6. Index 5: arr[5]= 2. Extend: 3 + 2 = 5. curr_max = 5, max_so_far updates to 5.\n");
    printf("  7. Index 6: arr[6]= 1. Extend: 5 + 1 = 6. curr_max = 6, max_so_far updates to 6.\n");
    printf("  8. Index 7: arr[7]=-5. Extend: 6 + (-5) = 1. curr_max = 1, max_so_far = 6.\n");
    printf("  9. Index 8: arr[8]= 4. Extend: 1 + 4 = 5. curr_max = 5, max_so_far = 6.\n");
    printf("  Result: Maximum sum is 6 from subarray [4, -1, 2, 1] (indices 3 to 6).\n");
    printf("\nCOMPLEXITY:\n");
    printf("  - Time Complexity:  O(n)\n");
    printf("  - Space Complexity: O(1)\n");
    printf("=========================================================================================\n");

    return 0;
}
