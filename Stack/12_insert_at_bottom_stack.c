/*
 * Question 12: Insert an element at the bottom of a stack using recursion. (5 marks)
 * Language: C (C99 standard)
 * 
 * Algorithm:
 * ----------
 * 1. Base Case: If the stack is empty, push the new item and return.
 * 2. Recursive Case:
 *      a. Pop the top element from the stack and store it in a local variable 'topItem'.
 *      b. Recursively call insertAtBottom(stack, newItem).
 *      c. Once the recursive call returns (meaning newItem has reached the bottom),
 *         push 'topItem' back onto the stack.
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:  O(n) - Unwinds all n elements to reach the bottom and rewinds.
 * Space Complexity: O(n) - Call stack depth is n.
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

// Function to insert element at the bottom of stack recursively
void insertAtBottom(Stack *s, int item) {
    if (isEmpty(s)) {
        push(s, item);
        return;
    }

    int topItem = pop(s);
    insertAtBottom(s, item);
    push(s, topItem);
}

int main(void) {
    printf("============================================================\n");
    printf("  QUESTION 12: INSERT AT BOTTOM OF STACK RECURSIVELY (5M)   \n");
    printf("============================================================\n\n");

    Stack s;
    initStack(&s);

    // Initial stack
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    printf("Original Stack:\n");
    printStack(&s);

    int newItem = 99;
    printf("\n--> Inserting %d at the bottom of the stack...\n", newItem);
    insertAtBottom(&s, newItem);

    printf("Stack after inserting %d at bottom:\n", newItem);
    printStack(&s);

    int anotherItem = 777;
    printf("\n--> Inserting %d at the bottom of the stack...\n", anotherItem);
    insertAtBottom(&s, anotherItem);

    printf("Stack after inserting %d at bottom:\n", anotherItem);
    printStack(&s);

    printf("\n------------------------------------------------------------\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(n)\n");
    printf("  - Space Complexity: O(n) call stack frames\n");
    printf("============================================================\n");

    return 0;
}
