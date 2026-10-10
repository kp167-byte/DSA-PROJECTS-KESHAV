/*
 * Question 21: Simulate Round Robin CPU scheduling using a queue. (10 marks)
 * Language: C (C99 standard)
 * 
 * Round Robin (RR) Algorithm Description:
 * ---------------------------------------
 * Round Robin is a preemptive CPU scheduling algorithm where each ready process
 * is assigned a fixed time slice called Time Quantum (Q) in cyclic order using a FIFO Queue.
 * 
 * Queue Mechanics:
 *   1. Processes arriving at or before the current time are pushed into the Ready Queue.
 *   2. The CPU dequeues a process from the front and runs it for at most Time Quantum 'Q'.
 *   3. If the process finishes within 'Q':
 *        - Record Completion Time (CT).
 *        - Turnaround Time (TAT) = CT - Arrival Time (AT).
 *        - Waiting Time (WT)    = TAT - Burst Time (BT).
 *   4. While the process was running, any newly arriving processes are enqueued.
 *   5. If the current process has remaining burst time, it is enqueued back at the rear.
 *   6. If ready queue is empty but processes remain, CPU is idle until next arrival.
 * 
 * Complexity:
 *   - Time Complexity:  O(n * (max_burst / Q))
 *   - Space Complexity: O(n) for the ready queue.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 20
#define QUEUE_SIZE 100

typedef struct {
    int pid;          // Process ID
    int arrivalTime;  // Arrival Time (AT)
    int burstTime;    // Original Burst Time (BT)
    int remainingTime;// Remaining Burst Time (RT)
    int completionTime;// Completion Time (CT)
    int turnaroundTime;// Turnaround Time (TAT)
    int waitingTime;  // Waiting Time (WT)
    bool isCompleted; // Completion flag
} Process;

// Queue of process indices
typedef struct {
    int data[QUEUE_SIZE];
    int front;
    int rear;
    int count;
} ReadyQueue;

void initReadyQueue(ReadyQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isQueueEmpty(const ReadyQueue *q) {
    return q->count == 0;
}

void enqueue(ReadyQueue *q, int pIndex) {
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->data[q->rear] = pIndex;
    q->count++;
}

int dequeue(ReadyQueue *q) {
    int pIndex = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;
    return pIndex;
}

// Check if process index is already in ready queue
bool isInQueue(const ReadyQueue *q, int pIndex) {
    int idx = q->front;
    for (int i = 0; i < q->count; i++) {
        if (q->data[idx] == pIndex) return true;
        idx = (idx + 1) % QUEUE_SIZE;
    }
    return false;
}

void simulateRoundRobin(Process proc[], int n, int timeQuantum) {
    ReadyQueue rq;
    initReadyQueue(&rq);

    int currentTime = 0;
    int completedCount = 0;
    bool inQueue[MAX_PROCESSES] = {false};

    // Find first arrived process(es)
    int minArrival = 1e9;
    for (int i = 0; i < n; i++) {
        if (proc[i].arrivalTime < minArrival) {
            minArrival = proc[i].arrivalTime;
        }
    }
    currentTime = minArrival;

    // Enqueue all processes arriving at initial time
    for (int i = 0; i < n; i++) {
        if (proc[i].arrivalTime <= currentTime) {
            enqueue(&rq, i);
            inQueue[i] = true;
        }
    }

    printf("--- GANTT TIMELINE EXECUTION TRACE (Time Quantum = %d) ---\n", timeQuantum);
    printf("+------------+---------+------------------+------------------+-----------------+\n");
    printf("| Time Range | Process | Executed Time    | Remaining Time   | Ready Queue     |\n");
    printf("+------------+---------+------------------+------------------+-----------------+\n");

    while (completedCount < n) {
        if (isQueueEmpty(&rq)) {
            // CPU is idle, advance time to next arrival
            int nextArrival = 1e9;
            for (int i = 0; i < n; i++) {
                if (!proc[i].isCompleted && proc[i].arrivalTime > currentTime && proc[i].arrivalTime < nextArrival) {
                    nextArrival = proc[i].arrivalTime;
                }
            }
            if (nextArrival != 1e9) {
                printf("| [%3d - %3d] | (IDLE)  | %-16s | %-16s | Empty           |\n",
                       currentTime, nextArrival, "-", "-");
                currentTime = nextArrival;
                for (int i = 0; i < n; i++) {
                    if (!proc[i].isCompleted && proc[i].arrivalTime <= currentTime && !inQueue[i]) {
                        enqueue(&rq, i);
                        inQueue[i] = true;
                    }
                }
            }
            continue;
        }

        int currIdx = dequeue(&rq);
        inQueue[currIdx] = false;

        int startTime = currentTime;
        int execTime = (proc[currIdx].remainingTime > timeQuantum) ? timeQuantum : proc[currIdx].remainingTime;

        currentTime += execTime;
        proc[currIdx].remainingTime -= execTime;

        // Check for any newly arrived processes during this time slice
        for (int i = 0; i < n; i++) {
            if (i != currIdx && !proc[i].isCompleted && proc[i].arrivalTime <= currentTime && !inQueue[i] && !isInQueue(&rq, i)) {
                enqueue(&rq, i);
                inQueue[i] = true;
            }
        }

        // Print Gantt entry
        char queueStr[64] = "[ ";
        int qIdx = rq.front;
        for (int k = 0; k < rq.count; k++) {
            char t[16];
            snprintf(t, sizeof(t), "P%d ", proc[rq.data[qIdx]].pid);
            strncat(queueStr, t, sizeof(queueStr) - strlen(queueStr) - 1);
            qIdx = (qIdx + 1) % QUEUE_SIZE;
        }
        strncat(queueStr, "]", sizeof(queueStr) - strlen(queueStr) - 1);

        char remStr[16];
        snprintf(remStr, sizeof(remStr), "%d units", proc[currIdx].remainingTime);
        char execStr[16];
        snprintf(execStr, sizeof(execStr), "%d units", execTime);

        printf("| [%3d - %3d] | P%-6d | %-16s | %-16s | %-15s |\n",
               startTime, currentTime, proc[currIdx].pid, execStr, remStr, queueStr);

        // If current process finished
        if (proc[currIdx].remainingTime == 0) {
            proc[currIdx].completionTime = currentTime;
            proc[currIdx].turnaroundTime = proc[currIdx].completionTime - proc[currIdx].arrivalTime;
            proc[currIdx].waitingTime    = proc[currIdx].turnaroundTime - proc[currIdx].burstTime;
            proc[currIdx].isCompleted    = true;
            completedCount++;
        } else {
            // Re-enqueue current process to back of ready queue
            enqueue(&rq, currIdx);
            inQueue[currIdx] = true;
        }
    }
    printf("+------------+---------+------------------+------------------+-----------------+\n\n");

    // Output final scheduling metrics table
    printf("=========================================================================================\n");
    printf("                           PROCESS SCHEDULING METRICS TABLE                              \n");
    printf("=========================================================================================\n");
    printf("| Process | Arrival Time (AT) | Burst Time (BT) | Completion (CT) | Turnaround (TAT) | Waiting (WT) |\n");
    printf("|---------|-------------------|-----------------|-----------------|------------------|--------------|\n");

    double totalTAT = 0;
    double totalWT = 0;

    for (int i = 0; i < n; i++) {
        printf("| P%-6d | %-17d | %-15d | %-15d | %-16d | %-12d |\n",
               proc[i].pid, proc[i].arrivalTime, proc[i].burstTime,
               proc[i].completionTime, proc[i].turnaroundTime, proc[i].waitingTime);
        totalTAT += proc[i].turnaroundTime;
        totalWT += proc[i].waitingTime;
    }
    printf("=========================================================================================\n");
    printf("Average Turnaround Time (TAT): %.2f ms\n", totalTAT / n);
    printf("Average Waiting Time (WT):    %.2f ms\n", totalWT / n);
    printf("=========================================================================================\n");
}

int main(void) {
    printf("=========================================================================================\n");
    printf("       QUESTION 21: SIMULATE ROUND ROBIN CPU SCHEDULING USING QUEUE (10 MARKS)           \n");
    printf("=========================================================================================\n\n");

    Process proc[] = {
        { .pid = 1, .arrivalTime = 0, .burstTime = 5, .remainingTime = 5, .isCompleted = false },
        { .pid = 2, .arrivalTime = 1, .burstTime = 4, .remainingTime = 4, .isCompleted = false },
        { .pid = 3, .arrivalTime = 2, .burstTime = 2, .remainingTime = 2, .isCompleted = false },
        { .pid = 4, .arrivalTime = 4, .burstTime = 1, .remainingTime = 1, .isCompleted = false }
    };
    int n = sizeof(proc) / sizeof(proc[0]);
    int timeQuantum = 2;

    printf("Process Inputs:\n");
    for (int i = 0; i < n; i++) {
        printf("  Process P%d: Arrival Time = %d, Burst Time = %d\n",
               proc[i].pid, proc[i].arrivalTime, proc[i].burstTime);
    }
    printf("Time Quantum: %d units\n\n", timeQuantum);

    simulateRoundRobin(proc, n, timeQuantum);

    printf("\nCOMPLEXITY:\n");
    printf("  - Time Complexity:  O(n * (max_burst / timeQuantum))\n");
    printf("  - Space Complexity: O(n) for the Ready Queue\n");
    printf("=========================================================================================\n");

    return 0;
}
