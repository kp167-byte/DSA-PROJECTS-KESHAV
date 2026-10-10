/*
 * Question 10: Check whether a string is a palindrome using a stack. (5 marks)
 * Language: C (C99 standard)
 * 
 * Algorithm:
 * ----------
 * 1. Push all characters of the input string onto a stack.
 * 2. Traverse the string again from left to right:
 *      a. Pop the top character from the stack.
 *      b. Compare the popped character with the current character of the string.
 *      c. If they mismatch at any position, the string is NOT a palindrome.
 * 3. If all characters match until the end, the string IS a palindrome.
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:  O(n) - Two linear passes of length n (push pass and pop/compare pass).
 * Space Complexity: O(n) - Stack stores n characters.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 256

// Character Stack Structure
typedef struct {
    char data[MAX_SIZE];
    int top;
} CharStack;

void initCharStack(CharStack *s) {
    s->top = -1;
}

bool isStackFull(const CharStack *s) {
    return s->top == MAX_SIZE - 1;
}

bool isStackEmpty(const CharStack *s) {
    return s->top == -1;
}

void pushChar(CharStack *s, char c) {
    if (!isStackFull(s)) {
        s->data[++(s->top)] = c;
    }
}

char popChar(CharStack *s) {
    if (!isStackEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

// Function to check palindrome using stack
bool isPalindrome(const char *str) {
    CharStack s;
    initCharStack(&s);

    int len = (int)strlen(str);

    // Push all characters onto stack
    for (int i = 0; i < len; i++) {
        pushChar(&s, str[i]);
    }

    // Pop and compare with original string characters
    for (int i = 0; i < len; i++) {
        char popped = popChar(&s);
        if (str[i] != popped) {
            return false;
        }
    }

    return true;
}

int main(void) {
    printf("============================================================\n");
    printf("  QUESTION 10: PALINDROME CHECK USING STACK (5 MARKS)       \n");
    printf("============================================================\n\n");

    const char *testStrings[] = {
        "racecar",
        "madam",
        "radar",
        "level",
        "hello",
        "datastructure",
        "noon",
        "a"
    };
    int count = sizeof(testStrings) / sizeof(testStrings[0]);

    for (int i = 0; i < count; i++) {
        bool res = isPalindrome(testStrings[i]);
        printf("String: \"%-15s\" -> %s\n", testStrings[i], res ? "PALINDROME" : "NOT A PALINDROME");
    }

    printf("\n------------------------------------------------------------\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(n)\n");
    printf("  - Space Complexity: O(n) for stack storage\n");
    printf("============================================================\n");

    return 0;
}
