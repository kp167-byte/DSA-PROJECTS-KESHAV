/*
 * Question 11: Delete the middle element of a stack. (5 marks)
 * Language: C (C99 standard)
 * 
 * Algorithm: Recursive Deletion without Auxiliary Data Structures
 * ---------------------------------------------------------------
 * 1. Let total elements in stack be 'n'.
 * 2. Middle position from top (0-indexed) is floor(n / 2).
 * 3. Use recursion to reach the middle:
 *      a. If current recursion depth equals middle index:
 *             pop the element (middle) and DO NOT push it back (deleted).
 *      b. Else:
 *             pop the top element,
 *             recurse for next depth,
 *             push the popped element back onto stack.
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:  O(n) - Visits half the stack elements (n/2 calls) down and unwinds.
 * Space Complexity: O(n) - Due to call stack frames (n/2 depth).
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 50

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(const Stack *s) {
    return s->top == -1;
}

bool isFull(const Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int val) {
    if (!isFull(s)) {
        s->data[++(s->top)] = val;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1;
}

int size(const Stack *s) {
    return s->top + 1;
}

void printStack(const Stack *s) {
    if (isEmpty(s)) {
        printf("[ Empty Stack ]\n");
        return;
    }
    printf("[ Bottom -> ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("<- Top ] (Size: %d)\n", size(s));
}

// Recursive helper to delete middle element
void deleteMiddleRecursive(Stack *s, int currentIdx, int middleIdx) {
    if (isEmpty(s)) {
        return;
    }

    int temp = pop(s);

    if (currentIdx == middleIdx) {
        printf("--> Deleting middle element: %d (at index %d from top)\n", temp, middleIdx);
        return; // Don't push back -> deleted!
    }

    deleteMiddleRecursive(s, currentIdx + 1, middleIdx);

    // Push back while unwinding
    push(s, temp);
}

// Wrapper function
void deleteMiddle(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Nothing to delete.\n");
        return;
    }

    int total = size(s);
    int middleIdx = total / 2; // Middle index from top (0-indexed)
    deleteMiddleRecursive(s, 0, middleIdx);
}

int main(void) {
    printf("============================================================\n");
    printf("  QUESTION 11: DELETE MIDDLE ELEMENT OF A STACK (5 MARKS)   \n");
    printf("============================================================\n\n");

    // Test Case 1: Odd number of elements (5 elements)
    Stack s1;
    initStack(&s1);
    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);
    push(&s1, 40);
    push(&s1, 50);

    printf("Test Case 1 (Odd size = 5):\nOriginal Stack:\n");
    printStack(&s1);
    deleteMiddle(&s1);
    printf("Stack after deleting middle:\n");
    printStack(&s1);

    // Test Case 2: Even number of elements (4 elements)
    Stack s2;
    initStack(&s2);
    push(&s2, 1);
    push(&s2, 2);
    push(&s2, 3);
    push(&s2, 4);

    printf("\nTest Case 2 (Even size = 4):\nOriginal Stack:\n");
    printStack(&s2);
    deleteMiddle(&s2);
    printf("Stack after deleting middle:\n");
    printStack(&s2);

    printf("\n------------------------------------------------------------\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(n)\n");
    printf("  - Space Complexity: O(n) call stack memory\n");
    printf("============================================================\n");

    return 0;
}
