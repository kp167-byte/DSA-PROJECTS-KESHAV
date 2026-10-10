/*
 * Question 14: Implement two stacks in a single array (space optimization)
 *              with push and pop for both. (10 marks)
 * Language: C (C99 standard)
 * 
 * Space Optimization Technique:
 * -----------------------------
 * Instead of dividing the array into two fixed halves (which causes overflow
 * when one stack is full even if the other has space), we use an opposing-ends strategy:
 *   - Stack 1 starts at index 0 and grows rightwards: top1 = -1, increment on push.
 *   - Stack 2 starts at index (CAPACITY - 1) and grows leftwards: top2 = CAPACITY, decrement on push.
 *   - Overflow Condition: top1 + 1 == top2 (stacks meet each other).
 *   - Underflow Conditions:
 *       - Stack 1 underflow: top1 == -1
 *       - Stack 2 underflow: top2 == CAPACITY
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:
 *   - push1(), pop1(): O(1)
 *   - push2(), pop2(): O(1)
 * Space Complexity: O(n) total capacity utilized without internal fragmentation.
 */

#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 10

typedef struct {
    int arr[CAPACITY];
    int top1;
    int top2;
} TwoStacks;

// Initialize both stacks
void initTwoStacks(TwoStacks *ts) {
    ts->top1 = -1;
    ts->top2 = CAPACITY;
}

// Push to Stack 1
bool push1(TwoStacks *ts, int val) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[++(ts->top1)] = val;
        printf("Push1(%d) -> Success (top1 = %d)\n", val, ts->top1);
        return true;
    } else {
        printf("Push1(%d) -> STACK OVERFLOW! No space left in shared array.\n", val);
        return false;
    }
}

// Push to Stack 2
bool push2(TwoStacks *ts, int val) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[--(ts->top2)] = val;
        printf("Push2(%d) -> Success (top2 = %d)\n", val, ts->top2);
        return true;
    } else {
        printf("Push2(%d) -> STACK OVERFLOW! No space left in shared array.\n", val);
        return false;
    }
}

// Pop from Stack 1
int pop1(TwoStacks *ts) {
    if (ts->top1 >= 0) {
        int val = ts->arr[(ts->top1)--];
        printf("Pop1() -> %d (top1 is now %d)\n", val, ts->top1);
        return val;
    } else {
        printf("Pop1() -> STACK 1 UNDERFLOW!\n");
        return -1;
    }
}

// Pop from Stack 2
int pop2(TwoStacks *ts) {
    if (ts->top2 < CAPACITY) {
        int val = ts->arr[(ts->top2)++];
        printf("Pop2() -> %d (top2 is now %d)\n", val, ts->top2);
        return val;
    } else {
        printf("Pop2() -> STACK 2 UNDERFLOW!\n");
        return -1;
    }
}

// Display the state of the shared array
void displaySharedArray(const TwoStacks *ts) {
    printf("\nShared Array View (Capacity = %d):\n", CAPACITY);
    printf("Index: ");
    for (int i = 0; i < CAPACITY; i++) printf("%3d ", i);
    printf("\nValue: ");
    for (int i = 0; i < CAPACITY; i++) {
        if (i <= ts->top1) {
            printf("[%d]", ts->arr[i]);
        } else if (i >= ts->top2) {
            printf("{%d}", ts->arr[i]);
        } else {
            printf(" .  ");
        }
    }
    printf("\nLegend: [x] = Stack 1, {x} = Stack 2, . = Free Space\n");
    printf("top1 = %d, top2 = %d, Free slots = %d\n\n",
           ts->top1, ts->top2, (ts->top2 - ts->top1 - 1));
}

int main(void) {
    printf("=========================================================================\n");
    printf("  QUESTION 14: TWO STACKS IN A SINGLE ARRAY (SPACE-OPTIMIZED) (10 MARKS) \n");
    printf("=========================================================================\n\n");

    TwoStacks ts;
    initTwoStacks(&ts);

    printf("--- Phase 1: Pushing elements to Stack 1 and Stack 2 ---\n");
    push1(&ts, 11);
    push1(&ts, 12);
    push1(&ts, 13);

    push2(&ts, 99);
    push2(&ts, 98);
    push2(&ts, 97);
    push2(&ts, 96);

    displaySharedArray(&ts);

    printf("--- Phase 2: Further pushes to demonstrate full capacity usage ---\n");
    push1(&ts, 14);
    push1(&ts, 15);
    push2(&ts, 95); // Now array should have 3 + 4 + 2 + 1 = 10 elements (completely full)

    displaySharedArray(&ts);

    printf("--- Phase 3: Triggering Stack Overflow on both stacks ---\n");
    push1(&ts, 16); // Should fail with overflow
    push2(&ts, 94); // Should fail with overflow

    printf("\n--- Phase 4: Popping elements ---\n");
    pop1(&ts);
    pop1(&ts);
    pop2(&ts);

    displaySharedArray(&ts);

    printf("--- Phase 5: Pushing after pops (dynamic space reuse) ---\n");
    push2(&ts, 88);
    push2(&ts, 77);

    displaySharedArray(&ts);

    printf("=========================================================================\n");
    printf("COMPLEXITY:\n");
    printf("  - Push / Pop Time Complexity: O(1) for both Stack 1 and Stack 2\n");
    printf("  - Space Complexity:           O(n) with 100%% utilization efficiency\n");
    printf("=========================================================================\n");

    return 0;
}
