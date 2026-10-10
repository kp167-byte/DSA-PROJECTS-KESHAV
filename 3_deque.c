/**
 * Question 3: Double Ended Queue (Deque) Implementation using an Array
 * 
 * Operations performed:
 * 9.  Insert 10 from Front.
 * 10. Insert 20 from Rear.
 * 11. Insert 30 from Front.
 * 12. Delete one element from Front.
 * 13. Delete one element from Rear.
 * 14. Display the remaining elements.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int deque[MAX];
int front = -1;
int rear = -1;

// Function to check if Deque is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Function to check if Deque is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element at Front
void insertFront(int value) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d at Front.\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front = front - 1;
    }
    deque[front] = value;
    printf("Inserted %d at Front (Front: %d, Rear: %d)\n", value, front, rear);
}

// Function to insert an element at Rear
void insertRear(int value) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d at Rear.\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear = rear + 1;
    }
    deque[rear] = value;
    printf("Inserted %d at Rear (Front: %d, Rear: %d)\n", value, front, rear);
}

// Function to delete an element from Front
int deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow! Cannot delete from Front.\n");
        return -1;
    }
    int deletedValue = deque[front];
    printf("Deleted %d from Front (index %d)\n", deletedValue, front);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front = front + 1;
    }
    return deletedValue;
}

// Function to delete an element from Rear
int deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow! Cannot delete from Rear.\n");
        return -1;
    }
    int deletedValue = deque[rear];
    printf("Deleted %d from Rear (index %d)\n", deletedValue, rear);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear = rear - 1;
    }
    return deletedValue;
}

// Function to display the elements in the Deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements (Front to Rear): [ ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("]\n");
    printf("Front index: %d, Rear index: %d\n", front, rear);
}

int main() {
    printf("====================================================\n");
    printf("           QUESTION 3: DEQUE OPERATIONS             \n");
    printf("====================================================\n\n");

    // Operation 9: Insert 10 from Front
    printf("--- Operation 9: Insert 10 from Front ---\n");
    insertFront(10);
    display();
    printf("\n");

    // Operation 10: Insert 20 from Rear
    printf("--- Operation 10: Insert 20 from Rear ---\n");
    insertRear(20);
    display();
    printf("\n");

    // Operation 11: Insert 30 from Front
    printf("--- Operation 11: Insert 30 from Front ---\n");
    insertFront(30);
    display();
    printf("\n");

    // Operation 12: Delete one element from Front
    printf("--- Operation 12: Delete one element from Front ---\n");
    deleteFront();
    display();
    printf("\n");

    // Operation 13: Delete one element from Rear
    printf("--- Operation 13: Delete one element from Rear ---\n");
    deleteRear();
    display();
    printf("\n");

    // Operation 14: Display the remaining elements
    printf("--- Operation 14: Display the remaining elements ---\n");
    display();
    printf("\n");

    printf("====================================================\n");
    printf("          DEQUE OPERATIONS COMPLETED                \n");
    printf("====================================================\n");

    return 0;
}
