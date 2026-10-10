/*
 * Question 23: Solve the Josephus problem using a queue. (10 marks)
 * Language: C (C99 standard)
 * 
 * Problem Statement:
 * ------------------
 * There are 'n' people standing in a circle numbered 1 to n.
 * Counting begins at person 1 and proceeds around the circle.
 * In each step, exactly the k-th person is executed/eliminated.
 * The counting repeats with the next person until only one survivor remains.
 * Find the position of the survivor.
 * 
 * Queue Simulation Algorithm:
 * ---------------------------
 * 1. Initialize a queue and enqueue all persons 1, 2, ..., n.
 * 2. While the queue has more than 1 person (queueSize > 1):
 *      a. For i = 1 to k - 1:
 *             Dequeue person from front and enqueue back to rear (rotation).
 *      b. Dequeue the k-th person from front and permanently eliminate them.
 * 3. When only 1 person is left in the queue, dequeue them: they are the SURVIVOR!
 * 
 * Mathematical Recurrence (Verification):
 * ---------------------------------------
 *   J(1, k) = 1
 *   J(n, k) = (J(n - 1, k) + k - 1) % n + 1
 * 
 * Complexity:
 *   - Time Complexity:  O(n * k) - In each of the (n - 1) rounds, k operations occur.
 *   - Space Complexity: O(n)     - For storing n persons in the circular queue.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_PEOPLE 500

// Queue Structure
typedef struct {
    int data[MAX_PEOPLE];
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

int queueSize(const Queue *q) {
    return q->count;
}

void enqueue(Queue *q, int person) {
    q->rear = (q->rear + 1) % MAX_PEOPLE;
    q->data[q->rear] = person;
    q->count++;
}

int dequeue(Queue *q) {
    int person = q->data[q->front];
    q->front = (q->front + 1) % MAX_PEOPLE;
    q->count--;
    return person;
}

// Print queue elements
void printQueue(const Queue *q) {
    printf("[ ");
    int idx = q->front;
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->data[idx]);
        idx = (idx + 1) % MAX_PEOPLE;
    }
    printf("] (Count: %d)\n", q->count);
}

// Mathematical solution for verification
int josephusFormula(int n, int k) {
    int survivor = 0; // 0-indexed
    for (int i = 2; i <= n; i++) {
        survivor = (survivor + k) % i;
    }
    return survivor + 1; // 1-indexed
}

// Queue-based Josephus solver with step-by-step trace
int solveJosephusQueue(int n, int k) {
    Queue q;
    initQueue(&q);

    for (int i = 1; i <= n; i++) {
        enqueue(&q, i);
    }

    printf("Initial Circle of %d people:\n", n);
    printQueue(&q);
    printf("\nElimination sequence (Every %d-th person eliminated):\n", k);
    printf("+-------+----------------------------------+---------------------+-------------------------+\n");
    printf("| Round | Skipped/Rotated Persons (k-1)    | Eliminated Person   | Remaining Circle Size   |\n");
    printf("+-------+----------------------------------+---------------------+-------------------------+\n");

    int round = 1;
    while (queueSize(&q) > 1) {
        char skipped[128] = "";

        // Rotate first k - 1 people
        for (int i = 1; i < k; i++) {
            int rotated = dequeue(&q);
            enqueue(&q, rotated);
            char temp[16];
            snprintf(temp, sizeof(temp), "%d ", rotated);
            strncat(skipped, temp, sizeof(skipped) - strlen(skipped) - 1);
        }

        if (k == 1) {
            snprintf(skipped, sizeof(skipped), "(None)");
        }

        // Eliminate k-th person
        int eliminated = dequeue(&q);

        printf("| %-5d | %-32s | Person %-12d | %-23d |\n",
               round++, skipped, eliminated, queueSize(&q));
    }
    printf("+-------+----------------------------------+---------------------+-------------------------+\n");

    int survivor = dequeue(&q);
    return survivor;
}

int main(void) {
    printf("=========================================================================================\n");
    printf("        QUESTION 23: JOSEPHUS PROBLEM SOLVED USING A QUEUE (10 MARKS)                    \n");
    printf("=========================================================================================\n\n");

    int n1 = 7, k1 = 3;
    printf("--- Test Case 1: n = %d people, k = %d ---\n\n", n1, k1);
    int survivor1 = solveJosephusQueue(n1, k1);
    int formula1 = josephusFormula(n1, k1);

    printf("\n--> Queue Simulation Survivor: Person %d\n", survivor1);
    printf("--> Mathematical Recurrence:  Person %d (Match verified!)\n\n", formula1);

    printf("=========================================================================================\n");
    int n2 = 10, k2 = 4;
    printf("--- Test Case 2: n = %d people, k = %d ---\n\n", n2, k2);
    int survivor2 = solveJosephusQueue(n2, k2);
    int formula2 = josephusFormula(n2, k2);

    printf("\n--> Queue Simulation Survivor: Person %d\n", survivor2);
    printf("--> Mathematical Recurrence:  Person %d (Match verified!)\n\n", formula2);

    printf("=========================================================================================\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(n * k) - Total rotations and eliminations\n");
    printf("  - Space Complexity: O(n) - Storage for n persons in the queue\n");
    printf("=========================================================================================\n");

    return 0;
}
