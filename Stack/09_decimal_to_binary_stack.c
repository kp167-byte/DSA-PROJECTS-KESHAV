/*
 * Question 9: Convert a decimal number to binary using a stack. (5 marks)
 * Language: C (C99 standard)
 * 
 * Algorithm:
 * ----------
 * 1. If decimal number is 0, the binary equivalent is simply "0".
 * 2. While the decimal number > 0:
 *      a. Compute remainder: rem = decimal % 2
 *      b. Push remainder onto stack.
 *      c. Update decimal: decimal = decimal / 2
 * 3. Pop all elements from stack one by one and print. Because stack is LIFO
 *    (Last-In, First-Out), the remainders are printed in reverse order of division,
 *    which corresponds to the correct binary representation (MSB to LSB).
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:  O(log2(n)) - Number of divisions by 2 is proportional to log2(n).
 * Space Complexity: O(log2(n)) - Stack stores at most floor(log2(n)) + 1 bits.
 */

#include <stdio.h>
#include <stdbool.h>

#define STACK_CAPACITY 64

// Stack Structure
typedef struct {
    int data[STACK_CAPACITY];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is full
bool isFull(const Stack *s) {
    return s->top == STACK_CAPACITY - 1;
}

// Check if stack is empty
bool isEmpty(const Stack *s) {
    return s->top == -1;
}

// Push item to stack
bool push(Stack *s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return false;
    }
    s->data[++(s->top)] = val;
    return true;
}

// Pop item from stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->data[(s->top)--];
}

// Function to convert decimal to binary using stack
void decimalToBinary(long long decimal) {
    if (decimal == 0) {
        printf("Decimal: %lld -> Binary: 0\n", decimal);
        return;
    }

    Stack s;
    initStack(&s);

    long long original = decimal;
    while (decimal > 0) {
        int rem = (int)(decimal % 2);
        push(&s, rem);
        decimal /= 2;
    }

    printf("Decimal: %lld -> Binary: ", original);
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

int main(void) {
    printf("============================================================\n");
    printf("  QUESTION 9: DECIMAL TO BINARY USING STACK (5 MARKS)       \n");
    printf("============================================================\n\n");

    long long testCases[] = {0, 1, 2, 7, 10, 19, 45, 128, 255, 1024};
    int count = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < count; i++) {
        decimalToBinary(testCases[i]);
    }

    printf("\n------------------------------------------------------------\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(log2 n)\n");
    printf("  - Space Complexity: O(log2 n) for stack storage\n");
    printf("============================================================\n");

    return 0;
}
