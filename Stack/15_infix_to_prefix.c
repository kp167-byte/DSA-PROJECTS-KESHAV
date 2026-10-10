/*
 * Question 15: Convert an infix expression to prefix, for example (A + B) * C - D,
 *              with a step-by-step table. (10 marks)
 * Language: C (C99 standard)
 * 
 * Algorithm:
 * ----------
 * 1. Step 1: Reverse the given infix expression.
 * 2. Step 2: In the reversed expression, swap all opening '(' and closing ')' brackets.
 * 3. Step 3: Convert the modified expression to postfix using a stack:
 *      - If operand: append directly to postfix output.
 *      - If '(': push onto stack.
 *      - If ')': pop and append to output until '(' is encountered.
 *      - If operator:
 *          While stack not empty, top is not '(', and:
 *            - For operators of equal precedence, left-associative operators become
 *              right-associative when reversed, so we pop only if precedence(top) > precedence(curr)
 *              (or precedence(top) >= precedence(curr) for right-associative like '^').
 *          Push current operator onto stack.
 *      - Pop remaining operators from stack.
 * 4. Step 4: Reverse the postfix expression obtained to get the final Prefix expression.
 * 
 * Step-by-Step Table:
 * -------------------
 * Prints an informative table showing:
 *   [Step] | [Symbol Scanned] | [Operator Stack] | [Output Expression] | [Action]
 * 
 * Complexity:
 *   - Time Complexity:  O(n) - Linear passes over expression of length n.
 *   - Space Complexity: O(n) - Auxiliary stack and string buffers.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 256

// Stack for characters
typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(const Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    s->data[++(s->top)] = c;
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

char peek(const Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

// Return stack contents as a string for tabular printing
void getStackString(const Stack *s, char *buffer) {
    if (isEmpty(s)) {
        strcpy(buffer, "(empty)");
        return;
    }
    int len = 0;
    for (int i = 0; i <= s->top; i++) {
        buffer[len++] = s->data[i];
    }
    buffer[len] = '\0';
}

// Operator precedence
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default:  return 0;
    }
}

// Check associativity
bool isRightAssociative(char op) {
    return (op == '^');
}

// Reverse a string in-place
void reverseString(char *str) {
    int len = (int)strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// Convert Infix to Prefix with detailed step-by-step table
void infixToPrefixWithTable(const char *infix, char *prefix) {
    char modified[MAX];
    int len = (int)strlen(infix);

    // Step 1 & 2: Reverse and swap brackets
    int idx = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (infix[i] == ' ' || infix[i] == '\t') continue; // Skip whitespace

        if (infix[i] == '(') {
            modified[idx++] = ')';
        } else if (infix[i] == ')') {
            modified[idx++] = '(';
        } else {
            modified[idx++] = infix[i];
        }
    }
    modified[idx] = '\0';

    printf("Step 1: Original Infix Expression:           \"%s\"\n", infix);
    printf("Step 2: Reversed & Parenthesis-Swapped Exp:  \"%s\"\n\n", modified);
    printf("Step 3: Conversion to Postfix with Step-by-Step Stack Trace:\n");
    printf("+------+----------------+----------------------+---------------------------+---------------------------------------+\n");
    printf("| Step | Symbol Scanned | Operator Stack       | Intermediate Output       | Action Taken                          |\n");
    printf("+------+----------------+----------------------+---------------------------+---------------------------------------+\n");

    Stack s;
    initStack(&s);
    char postfix[MAX];
    int pIdx = 0;
    postfix[0] = '\0';

    int stepCount = 1;
    char stackBuf[MAX];

    for (int i = 0; modified[i] != '\0'; i++) {
        char ch = modified[i];
        char action[100];

        if (isalnum(ch)) {
            postfix[pIdx++] = ch;
            postfix[pIdx] = '\0';
            snprintf(action, sizeof(action), "Operand '%c' added to output", ch);
        } else if (ch == '(') {
            push(&s, ch);
            snprintf(action, sizeof(action), "Pushed '(' onto stack");
        } else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[pIdx++] = pop(&s);
                postfix[pIdx] = '\0';
            }
            if (!isEmpty(&s)) {
                pop(&s); // Pop '('
            }
            snprintf(action, sizeof(action), "Popped operators until '(' discarded");
        } else {
            // Operator
            while (!isEmpty(&s) && peek(&s) != '(') {
                int topPrec = precedence(peek(&s));
                int currPrec = precedence(ch);

                // When converting reversed infix, condition for popping:
                // If topPrec > currPrec, or (topPrec == currPrec && rightAssociative)
                if (topPrec > currPrec || (topPrec == currPrec && isRightAssociative(ch))) {
                    postfix[pIdx++] = pop(&s);
                    postfix[pIdx] = '\0';
                } else {
                    break;
                }
            }
            push(&s, ch);
            snprintf(action, sizeof(action), "Pushed operator '%c' to stack", ch);
        }

        getStackString(&s, stackBuf);
        printf("| %-4d | %-14c | %-20s | %-25s | %-37s |\n",
               stepCount++, ch, stackBuf, postfix, action);
    }

    // Pop remaining operators
    while (!isEmpty(&s)) {
        char popped = pop(&s);
        if (popped != '(' && popped != ')') {
            postfix[pIdx++] = popped;
            postfix[pIdx] = '\0';
            getStackString(&s, stackBuf);
            char action[100];
            snprintf(action, sizeof(action), "Popped '%c' remaining on stack", popped);
            printf("| %-4d | %-14s | %-20s | %-25s | %-37s |\n",
                   stepCount++, "(end)", stackBuf, postfix, action);
        }
    }
    printf("+------+----------------+----------------------+---------------------------+---------------------------------------+\n\n");

    // Step 4: Reverse postfix to get prefix
    strcpy(prefix, postfix);
    reverseString(prefix);
    printf("Step 4: Postfix Result:                       \"%s\"\n", postfix);
    printf("        Reversed Postfix (Final Prefix):      \"%s\"\n", prefix);
}

int main(void) {
    printf("=========================================================================================\n");
    printf("   QUESTION 15: INFIX TO PREFIX CONVERSION WITH STEP-BY-STEP TABLE (10 MARKS)            \n");
    printf("=========================================================================================\n\n");

    const char *infix1 = "(A + B) * C - D";
    char prefix1[MAX];

    printf("--- EXAMPLE 1: Required in Problem: (A + B) * C - D ---\n\n");
    infixToPrefixWithTable(infix1, prefix1);

    printf("\n=========================================================================================\n");
    printf("--- EXAMPLE 2: A + B * C / D - E ^ F ---\n\n");
    const char *infix2 = "A + B * C / D - E ^ F";
    char prefix2[MAX];
    infixToPrefixWithTable(infix2, prefix2);

    printf("\n=========================================================================================\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(n) - Single scan + two reverses\n");
    printf("  - Space Complexity: O(n) - Operator stack and auxiliary strings\n");
    printf("=========================================================================================\n");

    return 0;
}
