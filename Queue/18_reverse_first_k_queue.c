/*
 * Question 18: Reverse the first k elements of a queue. (5 marks)
 * Language: C (C99 standard)
 * 
 * Algorithm:
 * ----------
 * 1. Given a queue of size 'n' and integer 'k' (where 1 <= k <= n):
 * 2. Dequeue the first 'k' elements from the queue and push them onto an auxiliary stack.
 * 3. While the stack is not empty:
 *      Pop each element from the stack and enqueue it back to the rear of the queue.
 *      (At this point, the reversed k elements are at the back of the queue).
 * 4. For the remaining (n - k) elements:
 *      Dequeue each element from the front and immediately enqueue it back to the rear.
 * 5. Result: The first k elements are reversed, and the remaining (n - k) elements
 *    maintain their original order.
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:  O(n) - k elements pushed/popped (O(k)) + (n-k) elements rotated (O(n-k)) = O(n).
 * Space Complexity: O(k) - Auxiliary stack of capacity k.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Queue Structure
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

bool isQueueFull(const Queue *q) {
    return q->count == MAX;
}

void enqueue(Queue *q, int val) {
    if (!isQueueFull(q)) {
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = val;
        q->count++;
    }
}

int dequeue(Queue *q) {
    if (!isQueueEmpty(q)) {
        int val = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
        return val;
    }
    return -1;
}

int queueSize(const Queue *q) {
    return q->count;
}

void printQueue(const Queue *q) {
    if (isQueueEmpty(q)) {
        printf("[ Empty Queue ]\n");
        return;
    }
    printf("[ Front -> ");
    int idx = q->front;
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->data[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("<- Rear ] (Size: %d)\n", q->count);
}

// Stack Structure for reversal
typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int val) {
    s->data[++(s->top)] = val;
}

int pop(Stack *s) {
    return s->data[(s->top)--];
}

bool isStackEmpty(const Stack *s) {
    return s->top == -1;
}

// Function to reverse first k elements of queue
void reverseFirstKElements(Queue *q, int k) {
    if (isQueueEmpty(q) || k <= 0 || k > queueSize(q)) {
        printf("Invalid k (%d) for queue size (%d)!\n", k, queueSize(q));
        return;
    }

    Stack s;
    initStack(&s);
    int n = queueSize(q);

    // Step 1: Dequeue first k elements and push to stack
    for (int i = 0; i < k; i++) {
        push(&s, dequeue(q));
    }

    // Step 2: Pop from stack and enqueue to back of queue
    while (!isStackEmpty(&s)) {
        enqueue(q, pop(&s));
    }

    // Step 3: Dequeue remaining (n - k) elements and enqueue them to the back
    for (int i = 0; i < n - k; i++) {
        enqueue(q, dequeue(q));
    }
}

int main(void) {
    printf("============================================================\n");
    printf("   QUESTION 18: REVERSE FIRST K ELEMENTS OF QUEUE (5 MARKS) \n");
    printf("============================================================\n\n");

    Queue q;
    initQueue(&q);

    // Enqueue 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
    for (int i = 1; i <= 10; i++) {
        enqueue(&q, i * 10);
    }

    printf("Original Queue:\n");
    printQueue(&q);

    int k = 5;
    printf("\n--> Reversing first k = %d elements...\n", k);
    reverseFirstKElements(&q, k);

    printf("Queue after reversing first %d elements:\n", k);
    printQueue(&q);

    int k2 = 3;
    printf("\n--> Reversing first k = %d elements of the current queue...\n", k2);
    reverseFirstKElements(&q, k2);

    printf("Queue after reversing first %d elements:\n", k2);
    printQueue(&q);

    printf("\n------------------------------------------------------------\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(n)\n");
    printf("  - Auxiliary Space:  O(k) for stack holding k elements\n");
    printf("============================================================\n");

    return 0;
}
