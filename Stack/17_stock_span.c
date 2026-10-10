/*
 * Question 17: Solve the Stock Span problem using a stack in O(n). (10 marks)
 * Language: C (C99 standard)
 * 
 * Stock Span Definition:
 * ----------------------
 * The span of the stock's price on day 'i' is defined as the maximum number of
 * consecutive days (starting from day 'i' and going backwards) for which the price
 * was less than or equal to the price on day 'i'.
 * 
 * Naive Approach:
 * ---------------
 * For each day i, run an inner loop going backwards to count days <= price[i].
 * Time Complexity: O(n^2), Space Complexity: O(1).
 * 
 * Monotonic Stack Approach - O(n) Time:
 * -------------------------------------
 * 1. Maintain a stack that stores indices of days whose prices are strictly decreasing.
 * 2. For day 0:
 *      span[0] = 1
 *      push index 0 onto stack.
 * 3. For day i from 1 to n - 1:
 *      a. Pop elements from stack while stack is NOT empty and price[stack.top] <= price[i].
 *      b. If stack becomes empty:
 *             price[i] is greater than all previous days, so span[i] = i + 1.
 *         Else:
 *             span[i] = i - stack.top (distance from previous greater price day).
 *      c. Push index i onto stack.
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:  O(n) - Although there is a nested while loop, every element is
 *                          pushed onto the stack once and popped at most once across
 *                          the entire algorithm (amortized 2*n operations).
 * Space Complexity: O(n) - Stack stores at most n indices in the worst case.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_DAYS 100

typedef struct {
    int data[MAX_DAYS];
    int top;
} IndexStack;

void initStack(IndexStack *s) {
    s->top = -1;
}

bool isEmpty(const IndexStack *s) {
    return s->top == -1;
}

void push(IndexStack *s, int idx) {
    s->data[++(s->top)] = idx;
}

int pop(IndexStack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1;
}

int peek(const IndexStack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1;
}

void getStackIndices(const IndexStack *s, char *buf, size_t bufSize) {
    if (isEmpty(s)) {
        snprintf(buf, bufSize, "(empty)");
        return;
    }
    snprintf(buf, bufSize, "[ ");
    char temp[16];
    for (int i = 0; i <= s->top; i++) {
        snprintf(temp, sizeof(temp), "%d ", s->data[i]);
        strncat(buf, temp, bufSize - strlen(buf) - 1);
    }
    strncat(buf, "]", bufSize - strlen(buf) - 1);
}

// Calculate stock span in O(n) and print step-by-step trace
void calculateStockSpan(const int prices[], int n, int span[]) {
    IndexStack s;
    initStack(&s);

    printf("+-----+-------+------------------------+-------------------+-------+---------------------------------------+\n");
    printf("| Day | Price | Popped Smaller Days    | Top Index After   | Span  | Calculation Rule                      |\n");
    printf("+-----+-------+------------------------+-------------------+-------+---------------------------------------+\n");

    for (int i = 0; i < n; i++) {
        char poppedDays[64] = "";
        bool poppedAny = false;

        // Pop elements while stack is not empty and price at top <= current price
        while (!isEmpty(&s) && prices[peek(&s)] <= prices[i]) {
            int poppedIdx = pop(&s);
            char temp[16];
            snprintf(temp, sizeof(temp), "d%d(%d) ", poppedIdx, prices[poppedIdx]);
            strncat(poppedDays, temp, sizeof(poppedDays) - strlen(poppedDays) - 1);
            poppedAny = true;
        }

        if (!poppedAny) {
            strncpy(poppedDays, "None", sizeof(poppedDays));
        }

        char calcRule[64];
        if (isEmpty(&s)) {
            span[i] = i + 1;
            snprintf(calcRule, sizeof(calcRule), "Empty stack -> i + 1 = %d", span[i]);
        } else {
            span[i] = i - peek(&s);
            snprintf(calcRule, sizeof(calcRule), "i - top (%d - %d) = %d", i, peek(&s), span[i]);
        }

        char stackState[64];
        getStackIndices(&s, stackState, sizeof(stackState));

        printf("| %-3d | %-5d | %-22s | %-17s | %-5d | %-37s |\n",
               i, prices[i], poppedDays, stackState, span[i], calcRule);

        // Push current day index
        push(&s, i);
    }
    printf("+-----+-------+------------------------+-------------------+-------+---------------------------------------+\n");
}

int main(void) {
    printf("=========================================================================================\n");
    printf("        QUESTION 17: STOCK SPAN PROBLEM USING STACK IN O(n) (10 MARKS)                   \n");
    printf("=========================================================================================\n\n");

    // Standard classic stock prices test case
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);
    int span[MAX_DAYS];

    printf("Input Stock Prices (over 7 days):\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", prices[i]);
    }
    printf("]\n\n");

    printf("--- MONOTONIC STACK EXECUTION TRACE ---\n");
    calculateStockSpan(prices, n, span);

    printf("\nComputed Stock Spans:\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", span[i]);
    }
    printf("]\n\n");

    printf("=========================================================================================\n");
    printf("COMPLEXITY ANALYSIS:\n");
    printf("  - Time Complexity:  O(n) amortized (each day index pushed once, popped <= once)\n");
    printf("  - Space Complexity: O(n) for monotonic index stack\n");
    printf("=========================================================================================\n");

    return 0;
}
