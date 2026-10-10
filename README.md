# Data Structures in C: Queue Programming Implementations

This repository contains robust C implementations for four fundamental queue data structures:
1. **Linear Queue** (`1_linear_queue.c`)
2. **Circular Queue** (`2_circular_queue.c`)
3. **Double Ended Queue (Deque)** (`3_deque.c`)
4. **Priority Queue** (`4_priority_queue.c`)

---

## 1. Linear Queue (`1_linear_queue.c`)

### Description
A **Linear Queue** follows the First-In-First-Out (FIFO) principle where elements are inserted at the **Rear** and removed from the **Front**.

### Operations Performed:
1. Insert `10`, `20`, and `30` into the queue.
2. Delete two elements from the Front.
3. Insert `40` into the Rear.
4. Display the remaining elements.

### Expected Output:
```text
====================================================
         QUESTION 1: LINEAR QUEUE OPERATIONS        
====================================================

--- Operation 1: Insert 10, 20, and 30 into the queue ---
Inserted 10 successfully into the queue.
Inserted 20 successfully into the queue.
Inserted 30 successfully into the queue.
Current Queue elements (Front to Rear): [ 10 20 30 ]
Front index: 0, Rear index: 2

--- Operation 2: Delete two elements from the Front ---
Deleted 10 from Front of the queue.
Deleted 20 from Front of the queue.
Current Queue elements (Front to Rear): [ 30 ]
Front index: 2, Rear index: 2

--- Operation 3: Insert 40 into the Rear ---
Inserted 40 successfully into the queue.
Current Queue elements (Front to Rear): [ 30 40 ]
Front index: 2, Rear index: 3

--- Operation 4: Display the remaining elements ---
Current Queue elements (Front to Rear): [ 30 40 ]
Front index: 2, Rear index: 3

====================================================
       LINEAR QUEUE OPERATIONS COMPLETED             
====================================================
```

---

## 2. Circular Queue (`2_circular_queue.c`)

### Description
A **Circular Queue** overcomes the memory wastage problem of a linear queue by connecting the last position back to the first position in a circular ring of fixed size (`SIZE = 5`).

### Operations Performed:
5. Insert `10`, `20`, `30`, and `40`.
6. Delete two elements from the Front.
7. Insert `50` and `60` into the queue (demonstrates circular wrap-around to index `0`).
8. Display the elements of the Circular Queue.

### Expected Output:
```text
====================================================
        QUESTION 2: CIRCULAR QUEUE OPERATIONS        
====================================================

--- Operation 5: Insert 10, 20, 30, and 40 ---
Inserted 10 at index 0 (Front: 0, Rear: 0)
Inserted 20 at index 1 (Front: 0, Rear: 1)
Inserted 30 at index 2 (Front: 0, Rear: 2)
Inserted 40 at index 3 (Front: 0, Rear: 3)
Circular Queue elements (Front to Rear): [ 10 20 30 40 ]
Front index: 0, Rear index: 3, Total capacity: 5

--- Operation 6: Delete two elements from the Front ---
Deleted 10 from index 0
Deleted 20 from index 1
Circular Queue elements (Front to Rear): [ 30 40 ]
Front index: 2, Rear index: 3, Total capacity: 5

--- Operation 7: Insert 50 and 60 into the queue ---
Inserted 50 at index 4 (Front: 2, Rear: 4)
Inserted 60 at index 0 (Front: 2, Rear: 0)
Circular Queue elements (Front to Rear): [ 30 40 50 60 ]
Front index: 2, Rear index: 0, Total capacity: 5

--- Operation 8: Final display of Circular Queue elements ---
Circular Queue elements (Front to Rear): [ 30 40 50 60 ]
Front index: 2, Rear index: 0, Total capacity: 5

====================================================
      CIRCULAR QUEUE OPERATIONS COMPLETED           
====================================================
```

---

## 3. Double Ended Queue - Deque (`3_deque.c`)

### Description
A **Double Ended Queue (Deque)** allows insertion and deletion from both ends (**Front** and **Rear**).

### Operations Performed:
9. Insert `10` from Front.
10. Insert `20` from Rear.
11. Insert `30` from Front.
12. Delete one element from Front.
13. Delete one element from Rear.
14. Display the remaining elements.

### Expected Output:
```text
====================================================
           QUESTION 3: DEQUE OPERATIONS             
====================================================

--- Operation 9: Insert 10 from Front ---
Inserted 10 at Front (Front: 0, Rear: 0)
Deque elements (Front to Rear): [ 10 ]
Front index: 0, Rear index: 0

--- Operation 10: Insert 20 from Rear ---
Inserted 20 at Rear (Front: 0, Rear: 1)
Deque elements (Front to Rear): [ 10 20 ]
Front index: 0, Rear index: 1

--- Operation 11: Insert 30 from Front ---
Inserted 30 at Front (Front: 9, Rear: 1)
Deque elements (Front to Rear): [ 30 10 20 ]
Front index: 9, Rear index: 1

--- Operation 12: Delete one element from Front ---
Deleted 30 from Front (index 9)
Deque elements (Front to Rear): [ 10 20 ]
Front index: 0, Rear index: 1

--- Operation 13: Delete one element from Rear ---
Deleted 20 from Rear (index 1)
Deque elements (Front to Rear): [ 10 ]
Front index: 0, Rear index: 0

--- Operation 14: Display the remaining elements ---
Deque elements (Front to Rear): [ 10 ]
Front index: 0, Rear index: 0

====================================================
          DEQUE OPERATIONS COMPLETED                
====================================================
```

---

## 4. Priority Queue (`4_priority_queue.c`)

### Description
A **Priority Queue** stores elements along with an associated priority. The element with the highest priority is served/deleted first.
- **Convention:** Max-Priority Queue where a higher number denotes higher priority (`Priority 3 > Priority 2 > Priority 1`).

### Operations Performed:
15. Insert `10` with priority `2`.
16. Insert `20` with priority `1`.
17. Insert `30` with priority `3`.
18. Delete the element having the highest priority (element `30` with priority `3`).
19. Display the remaining elements with their priorities.

### Expected Output:
```text
====================================================
        QUESTION 4: PRIORITY QUEUE OPERATIONS       
====================================================
Note: Standard convention used -> Higher number = Higher priority
      (Priority 3 > Priority 2 > Priority 1)

--- Operation 15: Insert 10 with priority 2 ---
Inserted 10 with priority 2 into Priority Queue.
Priority Queue elements (Total: 1):
----------------------------------------
| Index      | Value (Data) | Priority |
----------------------------------------
| 0          | 10           | 2        |
----------------------------------------

--- Operation 16: Insert 20 with priority 1 ---
Inserted 20 with priority 1 into Priority Queue.
Priority Queue elements (Total: 2):
----------------------------------------
| Index      | Value (Data) | Priority |
----------------------------------------
| 0          | 10           | 2        |
| 1          | 20           | 1        |
----------------------------------------

--- Operation 17: Insert 30 with priority 3 ---
Inserted 30 with priority 3 into Priority Queue.
Priority Queue elements (Total: 3):
----------------------------------------
| Index      | Value (Data) | Priority |
----------------------------------------
| 0          | 10           | 2        |
| 1          | 20           | 1        |
| 2          | 30           | 3        |
----------------------------------------

--- Operation 18: Delete the element having the highest priority ---
Deleted element 30 having highest priority 3 from the Priority Queue.

--- Operation 19: Display remaining elements with their priorities ---
Priority Queue elements (Total: 2):
----------------------------------------
| Index      | Value (Data) | Priority |
----------------------------------------
| 0          | 10           | 2        |
| 1          | 20           | 1        |
----------------------------------------

====================================================
       PRIORITY QUEUE OPERATIONS COMPLETED          
====================================================
```

---

## Compilation and Execution Guide

### Using GCC Compiler:

```bash
# Question 1: Linear Queue
gcc 1_linear_queue.c -o 1_linear_queue
./1_linear_queue

# Question 2: Circular Queue
gcc 2_circular_queue.c -o 2_circular_queue
./2_circular_queue

# Question 3: Double Ended Queue (Deque)
gcc 3_deque.c -o 3_deque
./3_deque

# Question 4: Priority Queue
gcc 4_priority_queue.c -o 4_priority_queue
./4_priority_queue
```
