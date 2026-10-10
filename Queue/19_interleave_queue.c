/*
 * Question 19: Interleave the first half of a queue with the second half. (5 marks)
 * Language: C (C99 standard)
 * 
 * Problem:
 * Given a queue of integers of even length 'n' = 2*k:
 * Input:  [ 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 ]
 * Output: [ 11, 16, 12, 17, 13, 18, 14, 19, 15, 20 ]
 * 
 * Algorithm (Using a Stack):
 * --------------------------
 * 1. Push the first half (k elements) of the queue onto a stack.
 *    Queue: [16, 17, 18, 19, 20], Stack: (top) 15, 14, 13, 12, 11 (bottom)
 * 2. Enqueue all stack elements back into the queue.
 *    Queue: [16, 17, 18, 19, 20, 15, 14, 13, 12, 11]
 * 3. Dequeue the first k elements (which is the original second half) and enqueue them back.
 *    Queue: [15, 14, 13, 12, 11, 16, 17, 18, 19, 20]
 * 4. Again push the first half (k elements) onto the stack.
 *    Queue: [16, 17, 18, 19, 20], Stack: (top) 11, 12, 13, 14, 15 (bottom)
 * 5. While stack is not empty:
 *      Pop from stack and enqueue into queue.
 *      Dequeue from queue and enqueue into queue.
 * 6. Resulting Queue: [11, 16, 12, 17, 13, 18, 14, 19, 15, 20]!
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:  O(n) - Constant number of linear passes over n elements.
 * Space Complexity: O(n) - Stack stores n/2 elements.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Queue ADT
typedef struct {
    int data[MAX];
    int front;
    int rear;
    int count;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isQueueEmpty(const Queue *q) {
    return q->count == 0;
}

void enqueue(Queue *q, int val) {
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = val;
    q->count++;
}

int dequeue(Queue *q) {
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return val;
}

int queueSize(const Queue *q) {
    return q->count;
}

void printQueue(const Queue *q) {
    printf("[ Front -> ");
    int idx = q->front;
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->data[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("<- Rear ]\n");
}

// Stack ADT
typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isStackEmpty(const Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    s->data[++(s->top)] = val;
}

int pop(Stack *s) {
    return s->data[(s->top)--];
}

// Function to interleave queue
void interleaveQueue(Queue *q) {
    int n = queueSize(q);
    if (n % 2 != 0) {
        printf("Error: Queue length must be even to interleave into equal halves.\n");
        return;
    }

    int half = n / 2;
    Stack s;
    initStack(&s);

    // Step 1: Push first half into stack
    for (int i = 0; i < half; i++) {
        push(&s, dequeue(q));
    }

    // Step 2: Enqueue stack elements back into queue
    while (!isStackEmpty(&s)) {
        enqueue(q, pop(&s));
    }

    // Step 3: Dequeue first half and enqueue back
    for (int i = 0; i < half; i++) {
        enqueue(q, dequeue(q));
    }

    // Step 4: Push first half into stack again
    for (int i = 0; i < half; i++) {
        push(&s, dequeue(q));
    }

    // Step 5: Interleave stack and queue elements
    while (!isStackEmpty(&s)) {
        enqueue(q, pop(&s));
        enqueue(q, dequeue(q));
    }
}

int main(void) {
    printf("============================================================\n");
    printf("  QUESTION 19: INTERLEAVE FIRST & SECOND HALF OF QUEUE (5M) \n");
    printf("============================================================\n\n");

    // Test Case 1: Example with 10 elements: 11..20
    Queue q1;
    initQueue(&q1);
    for (int val = 11; val <= 20; val++) {
        enqueue(&q1, val);
    }

    printf("Test Case 1 (10 elements):\n");
    printf("Original Queue:\n");
    printQueue(&q1);

    interleaveQueue(&q1);
    printf("\nInterleaved Queue:\n");
    printQueue(&q1);

    // Test Case 2: Example with 6 elements: 1, 2, 3, 4, 5, 6
    Queue q2;
    initQueue(&q2);
    for (int val = 1; val <= 6; val++) {
        enqueue(&q2, val);
    }

    printf("\nTest Case 2 (6 elements):\n");
    printf("Original Queue:\n");
    printQueue(&q2);

    interleaveQueue(&q2);
    printf("\nInterleaved Queue:\n");
    printQueue(&q2);

    printf("\n------------------------------------------------------------\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(n)\n");
    printf("  - Auxiliary Space:  O(n) for stack holding n/2 elements\n");
    printf("============================================================\n");

    return 0;
}
