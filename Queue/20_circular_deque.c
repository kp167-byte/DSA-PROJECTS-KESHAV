/*
 * Question 20: Implement a deque using a circular array
 *              (insertFront, insertRear, deleteFront, deleteRear). (5 marks)
 * Language: C (C99 standard)
 * 
 * Data Structure: Double Ended Queue (Deque) via Circular Array
 * -------------------------------------------------------------
 * A Deque supports insertion and deletion at both ends in O(1) time.
 * Circular array prevents drift and reclaims vacated slots.
 * 
 * Pointer Operations:
 *   - insertFront: front = (front - 1 + CAPACITY) % CAPACITY
 *   - insertRear:  rear  = (rear + 1) % CAPACITY
 *   - deleteFront: front = (front + 1) % CAPACITY
 *   - deleteRear:  rear  = (rear - 1 + CAPACITY) % CAPACITY
 *   - isFull:      (front == (rear + 1) % CAPACITY)
 *   - isEmpty:     (front == -1)
 * 
 * Complexity:
 *   - Time Complexity:  O(1) for all 4 operations (insertFront, insertRear, deleteFront, deleteRear).
 *   - Space Complexity: O(CAPACITY) fixed contiguous memory.
 */

#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 5

typedef struct {
    int arr[CAPACITY];
    int front;
    int rear;
} Deque;

void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

bool isEmpty(const Deque *dq) {
    return dq->front == -1;
}

bool isFull(const Deque *dq) {
    return (dq->front == (dq->rear + 1) % CAPACITY);
}

// Insert element at Front
bool insertFront(Deque *dq, int val) {
    if (isFull(dq)) {
        printf("insertFront(%d) -> OVERFLOW! Deque is full.\n", val);
        return false;
    }

    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + CAPACITY) % CAPACITY;
    }

    dq->arr[dq->front] = val;
    printf("insertFront(%d) -> Success (front: %d, rear: %d)\n", val, dq->front, dq->rear);
    return true;
}

// Insert element at Rear
bool insertRear(Deque *dq, int val) {
    if (isFull(dq)) {
        printf("insertRear(%d) -> OVERFLOW! Deque is full.\n", val);
        return false;
    }

    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % CAPACITY;
    }

    dq->arr[dq->rear] = val;
    printf("insertRear(%d) -> Success (front: %d, rear: %d)\n", val, dq->front, dq->rear);
    return true;
}

// Delete element from Front
int deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("deleteFront() -> UNDERFLOW! Deque is empty.\n");
        return -1;
    }

    int val = dq->arr[dq->front];

    if (dq->front == dq->rear) {
        // Only one element was present
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % CAPACITY;
    }

    printf("deleteFront() -> Deleted %d (new front: %d, rear: %d)\n", val, dq->front, dq->rear);
    return val;
}

// Delete element from Rear
int deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("deleteRear() -> UNDERFLOW! Deque is empty.\n");
        return -1;
    }

    int val = dq->arr[dq->rear];

    if (dq->front == dq->rear) {
        // Only one element was present
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + CAPACITY) % CAPACITY;
    }

    printf("deleteRear() -> Deleted %d (new front: %d, rear: %d)\n", val, dq->front, dq->rear);
    return val;
}

// Display Deque contents
void displayDeque(const Deque *dq) {
    if (isEmpty(dq)) {
        printf("Current Deque: [ Empty ]\n\n");
        return;
    }

    printf("Current Deque: [ Front -> ");
    int i = dq->front;
    while (true) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % CAPACITY;
    }
    printf("<- Rear ] (front = %d, rear = %d)\n\n", dq->front, dq->rear);
}

int main(void) {
    printf("=========================================================================\n");
    printf("  QUESTION 20: DEQUE USING CIRCULAR ARRAY (5 MARKS)                      \n");
    printf("=========================================================================\n\n");

    Deque dq;
    initDeque(&dq);

    printf("--- 1. Testing insertRear and insertFront ---\n");
    insertRear(&dq, 10);
    displayDeque(&dq);

    insertRear(&dq, 20);
    displayDeque(&dq);

    insertFront(&dq, 5);
    displayDeque(&dq);

    insertFront(&dq, 1);
    displayDeque(&dq);

    insertRear(&dq, 30);
    displayDeque(&dq);

    printf("--- 2. Attempting to insert into full Deque ---\n");
    insertRear(&dq, 40); // Should overflow
    insertFront(&dq, 99); // Should overflow

    printf("\n--- 3. Testing Deletions from both ends ---\n");
    deleteFront(&dq);
    displayDeque(&dq);

    deleteRear(&dq);
    displayDeque(&dq);

    printf("--- 4. Demonstrating circular wrap-around insertion ---\n");
    insertFront(&dq, 50);
    displayDeque(&dq);

    insertRear(&dq, 60);
    displayDeque(&dq);

    printf("=========================================================================\n");
    printf("COMPLEXITY:\n");
    printf("  - insertFront(): O(1)\n");
    printf("  - insertRear():  O(1)\n");
    printf("  - deleteFront(): O(1)\n");
    printf("  - deleteRear():  O(1)\n");
    printf("  - Space:         O(CAPACITY) in circular buffer\n");
    printf("=========================================================================\n");

    return 0;
}
