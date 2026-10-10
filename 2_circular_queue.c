/**
 * Question 2: Circular Queue Implementation using an Array of Size 5
 * 
 * Operations performed:
 * 5. Insert 10, 20, 30, and 40.
 * 6. Delete two elements from the Front.
 * 7. Insert 50 and 60 into the queue.
 * 8. Display the elements of the Circular Queue.
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int cqueue[SIZE];
int front = -1;
int rear = -1;

// Function to check if the circular queue is full
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == (rear + 1) % SIZE));
}

// Function to check if the circular queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element into the circular queue
void enqueue(int value) {
    if (isFull()) {
        printf("Circular Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    cqueue[rear] = value;
    printf("Inserted %d at index %d (Front: %d, Rear: %d)\n", value, rear, front, rear);
}

// Function to delete an element from the circular queue
int dequeue() {
    if (isEmpty()) {
        printf("Circular Queue Underflow! Queue is empty.\n");
        return -1;
    }
    int deletedValue = cqueue[front];
    printf("Deleted %d from index %d\n", deletedValue, front);
    
    if (front == rear) {
        // Queue becomes empty after deleting the only element
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return deletedValue;
}

// Function to display the elements of the circular queue
void display() {
    if (isEmpty()) {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("Circular Queue elements (Front to Rear): [ ");
    int i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("]\n");
    printf("Front index: %d, Rear index: %d, Total capacity: %d\n", front, rear, SIZE);
}

int main() {
    printf("====================================================\n");
    printf("        QUESTION 2: CIRCULAR QUEUE OPERATIONS        \n");
    printf("====================================================\n\n");

    // Operation 5: Insert 10, 20, 30, and 40
    printf("--- Operation 5: Insert 10, 20, 30, and 40 ---\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    printf("\n");

    // Operation 6: Delete two elements from the Front
    printf("--- Operation 6: Delete two elements from the Front ---\n");
    dequeue();
    dequeue();
    display();
    printf("\n");

    // Operation 7: Insert 50 and 60 into the queue
    printf("--- Operation 7: Insert 50 and 60 into the queue ---\n");
    enqueue(50);
    enqueue(60);
    display();
    printf("\n");

    // Operation 8: Display the elements of the Circular Queue
    printf("--- Operation 8: Final display of Circular Queue elements ---\n");
    display();
    printf("\n");

    printf("====================================================\n");
    printf("      CIRCULAR QUEUE OPERATIONS COMPLETED           \n");
    printf("====================================================\n");

    return 0;
}
