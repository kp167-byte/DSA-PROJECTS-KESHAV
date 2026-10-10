/**
 * Question 4: Priority Queue Implementation using an Array
 * 
 * Operations performed:
 * 15. Insert 10 with priority 2.
 * 16. Insert 20 with priority 1.
 * 17. Insert 30 with priority 3.
 * 18. Delete the element having the highest priority.
 * 19. Display the remaining elements with their priorities.
 * 
 * Convention:
 * Standard Max-Priority Queue is used where a higher numerical value indicates
 * a higher priority (Priority 3 > Priority 2 > Priority 1).
 * Hence, element 30 with priority 3 is deleted first.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int value;
    int priority;
} Element;

Element pq[MAX];
int size = 0;

// Function to check if Priority Queue is full
int isFull() {
    return (size == MAX);
}

// Function to check if Priority Queue is empty
int isEmpty() {
    return (size == 0);
}

// Function to insert an element with a given priority
void insert(int value, int priority) {
    if (isFull()) {
        printf("Priority Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    pq[size].value = value;
    pq[size].priority = priority;
    size++;
    printf("Inserted %d with priority %d into Priority Queue.\n", value, priority);
}

// Function to get the index of the element with highest priority
// (Higher numerical value = Higher priority)
int getHighestPriorityIndex() {
    if (isEmpty()) {
        return -1;
    }
    int highestIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i].priority > pq[highestIndex].priority) {
            highestIndex = i;
        }
    }
    return highestIndex;
}

// Function to delete the element having the highest priority
Element deleteHighestPriority() {
    Element deletedElement = {-1, -1};
    if (isEmpty()) {
        printf("Priority Queue Underflow! Queue is empty.\n");
        return deletedElement;
    }

    int highestIndex = getHighestPriorityIndex();
    deletedElement = pq[highestIndex];

    printf("Deleted element %d having highest priority %d from the Priority Queue.\n",
           deletedElement.value, deletedElement.priority);

    // Shift subsequent elements left to fill the gap
    for (int i = highestIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;

    return deletedElement;
}

// Function to display remaining elements with their priorities
void display() {
    if (isEmpty()) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue elements (Total: %d):\n", size);
    printf("----------------------------------------\n");
    printf("| %-10s | %-12s | %-8s |\n", "Index", "Value (Data)", "Priority");
    printf("----------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("| %-10d | %-12d | %-8d |\n", i, pq[i].value, pq[i].priority);
    }
    printf("----------------------------------------\n");
}

int main() {
    printf("====================================================\n");
    printf("        QUESTION 4: PRIORITY QUEUE OPERATIONS       \n");
    printf("====================================================\n");
    printf("Note: Standard convention used -> Higher number = Higher priority\n");
    printf("      (Priority 3 > Priority 2 > Priority 1)\n\n");

    // Operation 15: Insert 10 with priority 2
    printf("--- Operation 15: Insert 10 with priority 2 ---\n");
    insert(10, 2);
    display();
    printf("\n");

    // Operation 16: Insert 20 with priority 1
    printf("--- Operation 16: Insert 20 with priority 1 ---\n");
    insert(20, 1);
    display();
    printf("\n");

    // Operation 17: Insert 30 with priority 3
    printf("--- Operation 17: Insert 30 with priority 3 ---\n");
    insert(30, 3);
    display();
    printf("\n");

    // Operation 18: Delete the element having the highest priority
    printf("--- Operation 18: Delete the element having the highest priority ---\n");
    deleteHighestPriority();
    printf("\n");

    // Operation 19: Display the remaining elements with their priorities
    printf("--- Operation 19: Display remaining elements with their priorities ---\n");
    display();
    printf("\n");

    printf("====================================================\n");
    printf("       PRIORITY QUEUE OPERATIONS COMPLETED          \n");
    printf("====================================================\n");

    return 0;
}
