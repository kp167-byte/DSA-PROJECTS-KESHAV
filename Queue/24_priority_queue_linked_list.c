/*
 * Question 24: Insert and delete in a priority queue implemented with a linked list.
 *              State the complexity of each. (10 marks)
 * Language: C (C99 standard)
 * 
 * Priority Queue Design (Descending Priority Order):
 * --------------------------------------------------
 * Convention: Higher integer numerical value indicates HIGHER priority
 *             (e.g., Priority 10 > Priority 5 > Priority 1).
 * 
 * Data Structure:
 *   Singly Linked List sorted in descending order of priority from head to tail.
 *   Each node contains:
 *     - data (payload)
 *     - priority (priority ranking)
 *     - next (pointer to next node)
 * 
 * Complexity Analysis (Mandatory as per question):
 * ------------------------------------------------
 * 1. INSERTION [insert(data, priority)]:
 *    - Time Complexity:
 *        * Best Case:    O(1) - When new item has higher priority than current head.
 *        * Worst Case:   O(n) - When new item has lowest priority, requiring traversal
 *                               to the end of the list.
 *        * Average Case: O(n) - Linear traversal to find insertion slot.
 *    - Auxiliary Space:  O(1) - Single dynamically allocated node.
 * 
 * 2. DELETION [delete() / dequeue()]:
 *    - Time Complexity:  O(1) - Because the linked list is maintained sorted by priority,
 *                               the highest priority element is always at the head.
 *                               Removing the head is an immediate O(1) pointer adjustment!
 *    - Auxiliary Space:  O(1) - Constant memory.
 * 
 * 3. OVERALL STORAGE COMPLEXITY:
 *    - Space Complexity: O(n) - Dynamic storage for n nodes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Priority Queue Node
typedef struct PQNode {
    int data;
    int priority;
    struct PQNode *next;
} PQNode;

// Priority Queue wrapper structure
typedef struct {
    PQNode *head;
    int size;
} PriorityQueue;

// Initialize Priority Queue
void initPriorityQueue(PriorityQueue *pq) {
    pq->head = NULL;
    pq->size = 0;
}

// Check if Priority Queue is empty
bool isEmpty(const PriorityQueue *pq) {
    return pq->head == NULL;
}

/*
 * Insert operation:
 * Places new node in priority-sorted order (descending).
 * Time Complexity: O(n) worst case, O(1) best case.
 */
void insert(PriorityQueue *pq, int data, int priority) {
    PQNode *newNode = (PQNode *)malloc(sizeof(PQNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    // Case 1: Empty list OR new node has higher priority than head
    if (pq->head == NULL || priority > pq->head->priority) {
        newNode->next = pq->head;
        pq->head = newNode;
    } else {
        // Case 2: Traverse list to find correct spot
        PQNode *curr = pq->head;
        while (curr->next != NULL && curr->next->priority >= priority) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    pq->size++;
    printf("Inserted: Data = %-4d | Priority = %-2d  [O(n) search, O(1) link]\n", data, priority);
}

/*
 * Delete operation:
 * Removes and returns data of highest priority element (head of list).
 * Time Complexity: O(1).
 */
int deleteHighest(PriorityQueue *pq, int *deletedPriority) {
    if (isEmpty(pq)) {
        printf("deleteHighest() -> Error: Priority Queue Underflow!\n");
        if (deletedPriority) *deletedPriority = -1;
        return -1;
    }

    PQNode *temp = pq->head;
    int data = temp->data;
    if (deletedPriority) {
        *deletedPriority = temp->priority;
    }

    pq->head = pq->head->next;
    free(temp);
    pq->size--;

    return data;
}

// Display Priority Queue
void displayPriorityQueue(const PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue: [ Empty ]\n\n");
        return;
    }

    printf("\nPriority Queue State (Head/Highest to Tail/Lowest) [Count: %d]:\n", pq->size);
    printf("+-------+---------------+----------+\n");
    printf("| Node  | Value (Data)  | Priority |\n");
    printf("+-------+---------------+----------+\n");

    PQNode *curr = pq->head;
    int pos = 1;
    while (curr != NULL) {
        printf("| #%-4d | %-13d | %-8d |\n", pos++, curr->data, curr->priority);
        curr = curr->next;
    }
    printf("+-------+---------------+----------+\n\n");
}

int main(void) {
    printf("=========================================================================================\n");
    printf("   QUESTION 24: PRIORITY QUEUE VIA LINKED LIST (INSERT & DELETE) (10 MARKS)              \n");
    printf("=========================================================================================\n\n");

    PriorityQueue pq;
    initPriorityQueue(&pq);

    printf("--- Phase 1: Inserting elements with various priorities ---\n");
    printf("(Higher priority number = Higher service precedence)\n\n");

    insert(&pq, 101, 2);
    insert(&pq, 102, 5);
    insert(&pq, 103, 1);
    insert(&pq, 104, 7);
    insert(&pq, 105, 3);
    insert(&pq, 106, 5); // Same priority handled in FIFO order

    displayPriorityQueue(&pq);

    printf("--- Phase 2: Deleting elements (Always removes highest priority first) ---\n\n");

    while (!isEmpty(&pq)) {
        int priority = -1;
        int data = deleteHighest(&pq, &priority);
        printf("Deleted Highest: Data = %-4d with Priority = %-2d  [O(1) time complexity]\n",
               data, priority);
    }

    displayPriorityQueue(&pq);

    printf("=========================================================================================\n");
    printf("COMPLEXITY SPECIFICATION:\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("| Operation           | Time Complexity       | Space Complexity | Explanation           |\n");
    printf("|---------------------|-----------------------|------------------|-----------------------|\n");
    printf("| Insert (enqueue)    | O(n) worst / average  | O(1) auxiliary   | Traverses to maintain |\n");
    printf("|                     | O(1) best case (head) |                  | priority order        |\n");
    printf("| Delete (dequeue)    | O(1)                  | O(1) auxiliary   | Always removes from   |\n");
    printf("|                     |                       |                  | head of linked list   |\n");
    printf("| Overall Data Struct | -                     | O(n) total       | Dynamic nodes memory  |\n");
    printf("=========================================================================================\n");

    return 0;
}
