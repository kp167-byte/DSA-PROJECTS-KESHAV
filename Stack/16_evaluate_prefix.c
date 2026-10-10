/*
 * Question 16: Evaluate a prefix expression using a stack, for example - * + 4 3 2 5. (10 marks)
 * Language: C (C99 standard)
 * 
 * Algorithm for Prefix Evaluation:
 * --------------------------------
 * 1. Scan the prefix expression from right to left (end to start).
 * 2. If the current token is an operand:
 *      Push it onto the stack.
 * 3. If the current token is an operator (+, -, *, /, ^):
 *      a. Pop the first operand from the stack:  op1 = pop() (Left operand)
 *      b. Pop the second operand from the stack: op2 = pop() (Right operand)
 *      c. Compute result = (op1 operator op2).
 *      d. Push the computed result back onto the stack.
 * 4. At the end of traversal, the single value remaining on the stack is the final result.
 * 
 * Step-by-Step Evaluation of "- * + 4 3 2 5":
 * -------------------------------------------
 * Tokens scanned right-to-left:
 *   1. '5' -> Push 5.                   Stack: [5]
 *   2. '2' -> Push 2.                   Stack: [5, 2]
 *   3. '3' -> Push 3.                   Stack: [5, 2, 3]
 *   4. '4' -> Push 4.                   Stack: [5, 2, 3, 4]
 *   5. '+' -> op1 = 4, op2 = 3. 4 + 3 = 7. Push 7. Stack: [5, 2, 7]
 *   6. '*' -> op1 = 7, op2 = 2. 7 * 2 = 14. Push 14. Stack: [5, 14]
 *   7. '-' -> op1 = 14, op2 = 5. 14 - 5 = 9. Push 9. Stack: [9]
 * Final Answer: 9
 * 
 * Complexity:
 *   - Time Complexity:  O(n) - Single right-to-left scan of n tokens.
 *   - Space Complexity: O(n) - Operand stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Double/Integer Stack for arithmetic precision
typedef struct {
    double data[MAX_SIZE];
    int top;
} NumStack;

void initStack(NumStack *s) {
    s->top = -1;
}

bool isEmpty(const NumStack *s) {
    return s->top == -1;
}

void push(NumStack *s, double val) {
    s->data[++(s->top)] = val;
}

double pop(NumStack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return 0.0;
}

// Print stack state
void getStackContents(const NumStack *s, char *buffer, size_t bufSize) {
    if (isEmpty(s)) {
        snprintf(buffer, bufSize, "[]");
        return;
    }
    char temp[32];
    snprintf(buffer, bufSize, "[ ");
    for (int i = 0; i <= s->top; i++) {
        snprintf(temp, sizeof(temp), "%.0f ", s->data[i]);
        strncat(buffer, temp, bufSize - strlen(buffer) - 1);
    }
    strncat(buffer, "]", bufSize - strlen(buffer) - 1);
}

// Perform arithmetic calculation
double applyOp(char op, double op1, double op2) {
    switch (op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': 
            if (op2 == 0) {
                printf("Error: Division by zero!\n");
                return 0;
            }
            return op1 / op2;
        case '^': return pow(op1, op2);
        default:  return 0;
    }
}

// Evaluate space-delimited or character prefix expression
double evaluatePrefix(const char *expr) {
    NumStack s;
    initStack(&s);

    int len = (int)strlen(expr);

    printf("+------+---------------+--------------------------+-----------------------------------------+\n");
    printf("| Step | Token Scanned | Operand Stack State      | Action / Evaluation Details             |\n");
    printf("+------+---------------+--------------------------+-----------------------------------------+\n");

    int step = 1;
    char stackStr[128];

    // Traverse from right to left
    int i = len - 1;
    while (i >= 0) {
        // Skip spaces
        if (expr[i] == ' ' || expr[i] == '\t') {
            i--;
            continue;
        }

        // If operand (handle multidigit or single digit)
        if (isdigit(expr[i])) {
            // Find start of the number going leftwards
            int end = i;
            while (i >= 0 && isdigit(expr[i])) {
                i--;
            }
            int start = i + 1;
            char numBuf[32];
            int k = 0;
            for (int j = start; j <= end; j++) {
                numBuf[k++] = expr[j];
            }
            numBuf[k] = '\0';
            double num = atof(numBuf);
            push(&s, num);

            getStackContents(&s, stackStr, sizeof(stackStr));
            char action[64];
            snprintf(action, sizeof(action), "Pushed operand %.0f onto stack", num);
            printf("| %-4d | %-13s | %-24s | %-39s |\n", step++, numBuf, stackStr, action);
        } else {
            // Operator (+, -, *, /, ^)
            char op = expr[i];
            char opStr[4] = {op, '\0'};

            double op1 = pop(&s); // Left operand
            double op2 = pop(&s); // Right operand
            double res = applyOp(op, op1, op2);
            push(&s, res);

            getStackContents(&s, stackStr, sizeof(stackStr));
            char action[64];
            snprintf(action, sizeof(action), "%.0f %c %.0f = %.0f, push %.0f", op1, op, op2, res, res);
            printf("| %-4d | %-13s | %-24s | %-39s |\n", step++, opStr, stackStr, action);
            i--;
        }
    }

    printf("+------+---------------+--------------------------+-----------------------------------------+\n");
    return pop(&s);
}

int main(void) {
    printf("=========================================================================================\n");
    printf("     QUESTION 16: EVALUATE PREFIX EXPRESSION USING A STACK (10 MARKS)                    \n");
    printf("=========================================================================================\n\n");

    // Test Case 1: Expression from question prompt: "- * + 4 3 2 5"
    const char *expr1 = "- * + 4 3 2 5";
    printf("Expression 1: \"%s\"\n", expr1);
    printf("Mathematical interpretation: ((4 + 3) * 2) - 5 = (7 * 2) - 5 = 14 - 5 = 9\n\n");

    double result1 = evaluatePrefix(expr1);
    printf("\nFinal Result of \"%s\": %.0f\n\n", expr1, result1);

    // Test Case 2: "+ 9 * 2 6" -> 9 + (2 * 6) = 21
    const char *expr2 = "+ 9 * 2 6";
    printf("=========================================================================================\n");
    printf("Expression 2: \"%s\"\n", expr2);
    printf("Mathematical interpretation: 9 + (2 * 6) = 9 + 12 = 21\n\n");

    double result2 = evaluatePrefix(expr2);
    printf("\nFinal Result of \"%s\": %.0f\n", expr2, result2);

    printf("\n=========================================================================================\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(n) - Single right-to-left scan of tokens\n");
    printf("  - Space Complexity: O(n) - Operand stack storage\n");
    printf("=========================================================================================\n");

    return 0;
}
