/**
 * Question 1: Linear Queue Implementation using an Array
 * 
 * Operations performed:
 * 1. Insert 10, 20, and 30 into the queue.
 * 2. Delete two elements from the Front.
 * 3. Insert 40 into the Rear.
 * 4. Display the remaining elements.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

// Function to check if queue is full
int isFull() {
    return (rear == MAX - 1);
}

// Function to check if queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Function to insert an element into the queue (at Rear)
void insert(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Inserted %d successfully into the queue.\n", value);
}

// Function to delete an element from the queue (from Front)
int deleteElement() {
    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty.\n");
        return -1;
    }
    int deletedValue = queue[front];
    front++;
    printf("Deleted %d from Front of the queue.\n", deletedValue);
    return deletedValue;
}

// Function to display the elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Current Queue elements (Front to Rear): [ ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("]\n");
    printf("Front index: %d, Rear index: %d\n", front, rear);
}

int main() {
    printf("====================================================\n");
    printf("         QUESTION 1: LINEAR QUEUE OPERATIONS        \n");
    printf("====================================================\n\n");

    // Operation 1: Insert 10, 20, and 30 into the queue
    printf("--- Operation 1: Insert 10, 20, and 30 into the queue ---\n");
    insert(10);
    insert(20);
    insert(30);
    display();
    printf("\n");

    // Operation 2: Delete two elements from the Front
    printf("--- Operation 2: Delete two elements from the Front ---\n");
    deleteElement();
    deleteElement();
    display();
    printf("\n");

    // Operation 3: Insert 40 into the Rear
    printf("--- Operation 3: Insert 40 into the Rear ---\n");
    insert(40);
    display();
    printf("\n");

    // Operation 4: Display the remaining elements
    printf("--- Operation 4: Display the remaining elements ---\n");
    display();
    printf("\n");

    printf("====================================================\n");
    printf("       LINEAR QUEUE OPERATIONS COMPLETED             \n");
    printf("====================================================\n");

    return 0;
}
