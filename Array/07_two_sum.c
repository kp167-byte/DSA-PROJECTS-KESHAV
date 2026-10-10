/*
 * Question 7: Solve the Two Sum problem using brute force and using hashing.
 *             Compare time and space complexity. (10 marks)
 * Language: C (C99 standard)
 * 
 * Problem Statement:
 * Given an array of integers 'arr' and an integer 'target', find two distinct
 * indices (i, j) such that arr[i] + arr[j] == target.
 * 
 * ============================================================================
 * METHOD 1: BRUTE FORCE APPROACH
 * ============================================================================
 * - Description: Check every possible pair (i, j) where 0 <= i < j < n.
 * - Time Complexity:  O(n^2) - Two nested loops evaluating n*(n-1)/2 pairs.
 * - Space Complexity: O(1)   - Requires no additional data structures.
 * 
 * ============================================================================
 * METHOD 2: HASH TABLE APPROACH
 * ============================================================================
 * - Description:
 *     Maintain a hash table of visited numbers (key = number, value = index).
 *     For each element arr[i], compute complement = target - arr[i].
 *     If complement already exists in hash table, we found our pair!
 *     Otherwise, insert (arr[i], i) into the hash table.
 * - Time Complexity:  O(n) average - Each lookup and insertion is O(1) on average.
 * - Space Complexity: O(n) - Hash table stores up to n elements.
 * 
 * ============================================================================
 * COMPLEXITY COMPARISON TABLE
 * ============================================================================
 * +---------------+-------------------+--------------------+------------------------+
 * | Approach      | Time Complexity   | Space Complexity   | Trade-off              |
 * +---------------+-------------------+--------------------+------------------------+
 * | Brute Force   | O(n^2)            | O(1)               | Slow for large n, O(1) |
 * | Hashing       | O(n) [avg]        | O(n)               | Fast, uses extra memory|
 * +---------------+-------------------+--------------------+------------------------+
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 10007 // Prime number for hash table capacity

// Structure for hash table entry (Chaining for collision resolution)
typedef struct HashNode {
    int key;
    int index;
    struct HashNode *next;
} HashNode;

typedef struct {
    HashNode *buckets[HASH_SIZE];
} HashTable;

// Compute hash index supporting negative keys
int hashFunction(int key) {
    int h = key % HASH_SIZE;
    if (h < 0) {
        h += HASH_SIZE;
    }
    return h;
}

// Initialize hash table
void initHashTable(HashTable *ht) {
    for (int i = 0; i < HASH_SIZE; i++) {
        ht->buckets[i] = NULL;
    }
}

// Insert key-index pair into hash table
void hashInsert(HashTable *ht, int key, int index) {
    int bucket = hashFunction(key);
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->index = index;
    newNode->next = ht->buckets[bucket];
    ht->buckets[bucket] = newNode;
}

// Search key in hash table; returns index if found, -1 otherwise
int hashSearch(const HashTable *ht, int key) {
    int bucket = hashFunction(key);
    HashNode *curr = ht->buckets[bucket];
    while (curr != NULL) {
        if (curr->key == key) {
            return curr->index;
        }
        curr = curr->next;
    }
    return -1;
}

// Free allocated memory of hash table
void freeHashTable(HashTable *ht) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *curr = ht->buckets[i];
        while (curr != NULL) {
            HashNode *temp = curr;
            curr = curr->next;
            free(temp);
        }
        ht->buckets[i] = NULL;
    }
}

// Method 1: Brute Force
bool twoSumBruteForce(const int arr[], int n, int target, int *outIdx1, int *outIdx2) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                *outIdx1 = i;
                *outIdx2 = j;
                return true;
            }
        }
    }
    return false;
}

// Method 2: Hashing
bool twoSumHashing(const int arr[], int n, int target, int *outIdx1, int *outIdx2) {
    HashTable ht;
    initHashTable(&ht);

    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        int foundIdx = hashSearch(&ht, complement);
        if (foundIdx != -1) {
            *outIdx1 = foundIdx;
            *outIdx2 = i;
            freeHashTable(&ht);
            return true;
        }
        hashInsert(&ht, arr[i], i);
    }

    freeHashTable(&ht);
    return false;
}

// Helper to print array
void printArray(const int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main(void) {
    printf("=========================================================================\n");
    printf("   QUESTION 7: TWO SUM PROBLEM - BRUTE FORCE vs. HASHING (10 MARKS)      \n");
    printf("=========================================================================\n\n");

    int arr[] = {2, 7, 11, 15, -3, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 8; // Expected: 11 + (-3) = 8 OR 2 + 6 = 8

    printf("Input Array: ");
    printArray(arr, n);
    printf("Target Sum:  %d\n\n", target);

    // 1. Run Brute Force
    printf("--- 1. Testing Brute Force Approach ---\n");
    int bf_idx1 = -1, bf_idx2 = -1;
    if (twoSumBruteForce(arr, n, target, &bf_idx1, &bf_idx2)) {
        printf("Found solution at indices: (%d, %d)\n", bf_idx1, bf_idx2);
        printf("Verification: arr[%d] (%d) + arr[%d] (%d) = %d\n",
               bf_idx1, arr[bf_idx1], bf_idx2, arr[bf_idx2], arr[bf_idx1] + arr[bf_idx2]);
    } else {
        printf("No two sum solution found.\n");
    }

    // 2. Run Hashing
    printf("\n--- 2. Testing Hash Table Approach ---\n");
    int hash_idx1 = -1, hash_idx2 = -1;
    if (twoSumHashing(arr, n, target, &hash_idx1, &hash_idx2)) {
        printf("Found solution at indices: (%d, %d)\n", hash_idx1, hash_idx2);
        printf("Verification: arr[%d] (%d) + arr[%d] (%d) = %d\n",
               hash_idx1, arr[hash_idx1], hash_idx2, arr[hash_idx2], arr[hash_idx1] + arr[hash_idx2]);
    } else {
        printf("No two sum solution found.\n");
    }

    // 3. Detailed Comparison
    printf("\n=========================================================================\n");
    printf("                    TIME & SPACE COMPLEXITY COMPARISON                   \n");
    printf("=========================================================================\n");
    printf("| Feature              | Brute Force Method    | Hash Table Method      |\n");
    printf("|----------------------|-----------------------|------------------------|\n");
    printf("| Time Complexity      | O(n^2)                | O(n) average           |\n");
    printf("| Space Complexity     | O(1)                  | O(n)                   |\n");
    printf("| Comparisons Made     | n*(n-1)/2 comparisons | Single linear scan     |\n");
    printf("| Data Structure Used  | None (Nested loops)   | Hash Table (Chaining)  |\n");
    printf("| Performance on 10^5  | ~10^10 operations     | ~10^5 operations       |\n");
    printf("| Best Use Case        | Memory-critical tasks | Speed-critical tasks   |\n");
    printf("=========================================================================\n");

    return 0;
}
