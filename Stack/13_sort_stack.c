/*
 * Question 13: Sort a stack using a temporary stack. (5 marks)
 * Language: C (C99 standard)
 * 
 * Algorithm:
 * ----------
 * Given input stack 's':
 * 1. Create a temporary stack 'tmpStack'.
 * 2. While 's' is not empty:
 *      a. Pop an element: tmp = pop(s)
 *      b. While 'tmpStack' is not empty and top(tmpStack) > tmp:
 *             pop the top of tmpStack and push it back onto 's'.
 *      c. Push 'tmp' onto 'tmpStack'.
 * 3. The elements in 'tmpStack' are now in sorted order (smallest at bottom, largest at top).
 * 4. Transfer elements from tmpStack back to 's' so 's' is sorted with smallest at top.
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:  O(n^2) - In worst case (reverse sorted), elements are shifted back and forth.
 * Space Complexity: O(n)   - Auxiliary storage for temporary stack.
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

int peek(const Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1;
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
    printf("<- Top ]\n");
}

// Function to sort stack using temporary stack
void sortStack(Stack *s) {
    Stack tmpStack;
    initStack(&tmpStack);

    while (!isEmpty(s)) {
        int tmp = pop(s);

        // While temporary stack is not empty and top of tmpStack > tmp
        while (!isEmpty(&tmpStack) && peek(&tmpStack) > tmp) {
            push(s, pop(&tmpStack));
        }

        // Place tmp at correct position in tmpStack
        push(&tmpStack, tmp);
    }

    // Copy elements back to original stack so that smallest element is at top
    // (tmpStack has smallest at bottom, largest at top; popping into s reverses it)
    while (!isEmpty(&tmpStack)) {
        push(s, pop(&tmpStack));
    }
}

int main(void) {
    printf("============================================================\n");
    printf("   QUESTION 13: SORT A STACK USING A TEMP STACK (5 MARKS)   \n");
    printf("============================================================\n\n");

    Stack s;
    initStack(&s);

    // Push elements in arbitrary order
    push(&s, 34);
    push(&s, 3);
    push(&s, 31);
    push(&s, 98);
    push(&s, 92);
    push(&s, 23);

    printf("Original Stack before sorting:\n");
    printStack(&s);

    sortStack(&s);

    printf("\nStack after sorting (Smallest at Top, Ascending towards Top):\n");
    printStack(&s);

    printf("\nPopping sorted elements from top to bottom:\n");
    while (!isEmpty(&s)) {
        printf("%d ", pop(&s));
    }
    printf("\n");

    printf("\n------------------------------------------------------------\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(n^2)\n");
    printf("  - Auxiliary Space:  O(n) for the temporary stack\n");
    printf("============================================================\n");

    return 0;
}
