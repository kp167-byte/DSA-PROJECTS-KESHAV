/*
 * Question 22: Find the first non-repeating character in a stream of characters
 *              using a queue. (10 marks)
 * Language: C (C99 standard)
 * 
 * Algorithm:
 * ----------
 * 1. Maintain:
 *      - A frequency array 'freq[256]' initialized to 0.
 *      - A FIFO queue 'q' to hold incoming characters in order of their arrival.
 * 2. For each incoming character 'ch' in the stream:
 *      a. Increment its frequency count: freq[(unsigned char)ch]++;
 *      b. Push 'ch' into the queue.
 *      c. While the queue is NOT empty and freq[(unsigned char)q.front()] > 1:
 *             Dequeue the character (it is repeating and can never be the first non-repeating).
 *      d. If the queue is NOT empty:
 *             The front of the queue is the first non-repeating character!
 *         Else:
 *             No non-repeating character exists; output '#' (or -1).
 * 
 * Complexity Analysis:
 * --------------------
 * Time Complexity:  O(n) - Although there is an inner while loop, each character from
 *                          the stream is enqueued once and dequeued at most once.
 * Space Complexity: O(n) for the queue + O(1) for the 256-size frequency array.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STREAM 256

// Queue Structure for Characters
typedef struct {
    char data[MAX_STREAM];
    int front;
    int rear;
    int count;
} CharQueue;

void initCharQueue(CharQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isCharQueueEmpty(const CharQueue *q) {
    return q->count == 0;
}

void enqueueChar(CharQueue *q, char c) {
    q->rear = (q->rear + 1) % MAX_STREAM;
    q->data[q->rear] = c;
    q->count++;
}

char dequeueChar(CharQueue *q) {
    char c = q->data[q->front];
    q->front = (q->front + 1) % MAX_STREAM;
    q->count--;
    return c;
}

char getFrontChar(const CharQueue *q) {
    return q->data[q->front];
}

// Return queue as string
void getQueueString(const CharQueue *q, char *buf, size_t bufSize) {
    if (isCharQueueEmpty(q)) {
        snprintf(buf, bufSize, "(empty)");
        return;
    }
    snprintf(buf, bufSize, "[ ");
    int idx = q->front;
    char temp[8];
    for (int i = 0; i < q->count; i++) {
        snprintf(temp, sizeof(temp), "%c ", q->data[idx]);
        strncat(buf, temp, bufSize - strlen(buf) - 1);
        idx = (idx + 1) % MAX_STREAM;
    }
    strncat(buf, "]", bufSize - strlen(buf) - 1);
}

// Process stream of characters and print step-by-step table
void findFirstNonRepeatingStream(const char *stream) {
    int freq[256] = {0};
    CharQueue q;
    initCharQueue(&q);

    int n = (int)strlen(stream);
    char result[MAX_STREAM];
    int resIdx = 0;

    printf("+------+---------------+-----------+--------------------+----------------------------+\n");
    printf("| Step | Incoming Char | Freq(ch)  | Queue (Candidates) | First Non-Repeating Output |\n");
    printf("+------+---------------+-----------+--------------------+----------------------------+\n");

    for (int i = 0; i < n; i++) {
        char ch = stream[i];
        freq[(unsigned char)ch]++;
        enqueueChar(&q, ch);

        // Discard characters from front of queue that have repeated
        while (!isCharQueueEmpty(&q) && freq[(unsigned char)getFrontChar(&q)] > 1) {
            dequeueChar(&q);
        }

        char firstNonRep;
        if (!isCharQueueEmpty(&q)) {
            firstNonRep = getFrontChar(&q);
        } else {
            firstNonRep = '#'; // '#' signifies no non-repeating character
        }

        result[resIdx++] = firstNonRep;

        char queueState[64];
        getQueueString(&q, queueState, sizeof(queueState));

        printf("| %-4d | %-13c | %-9d | %-18s | %-26c |\n",
               i + 1, ch, freq[(unsigned char)ch], queueState, firstNonRep);
    }
    printf("+------+---------------+-----------+--------------------+----------------------------+\n");

    result[resIdx] = '\0';
    printf("\nStream Input:          \"%s\"\n", stream);
    printf("Resulting Output Flow: \"%s\"\n\n", result);
}

int main(void) {
    printf("=========================================================================================\n");
    printf("   QUESTION 22: FIRST NON-REPEATING CHARACTER IN STREAM USING QUEUE (10 MARKS)           \n");
    printf("=========================================================================================\n\n");

    // Test Case 1: Standard stream
    const char *stream1 = "aabcbd";
    printf("--- STREAM 1: \"%s\" ---\n", stream1);
    findFirstNonRepeatingStream(stream1);

    // Test Case 2: Stream where all characters eventually repeat
    const char *stream2 = "zzxxcc";
    printf("=========================================================================================\n");
    printf("--- STREAM 2: \"%s\" ---\n", stream2);
    findFirstNonRepeatingStream(stream2);

    printf("=========================================================================================\n");
    printf("COMPLEXITY:\n");
    printf("  - Time Complexity:  O(n) overall (each character enqueued and dequeued at most once)\n");
    printf("  - Space Complexity: O(n) for Queue + O(1) for 256-size frequency array\n");
    printf("=========================================================================================\n");

    return 0;
}
