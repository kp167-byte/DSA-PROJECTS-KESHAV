# Data Structures & Algorithms in C (DSA Complete Assignment)

This repository contains comprehensive, clean, and robust C implementations for all **24 DSA problems** across **Arrays**, **Stacks**, and **Queues**, written strictly according to modern C standards (C99) with full complexity analyses, detailed dry-run traces, and step-by-step documentation.

Repository URL: [https://github.com/kp167-byte/DSA-PROJECTS-KESHAV.git](https://github.com/kp167-byte/DSA-PROJECTS-KESHAV.git)

---

## Table of Contents

- [Quick Navigation Index](#quick-navigation-index)
- [Part 1: Array Data Structures (Questions 1 – 8)](#part-1-array-data-structures-questions-1--8)
  - [Q1. Insert into Sorted Array](#q1-insert-an-element-into-a-sorted-array-so-that-it-stays-sorted-5-marks)
  - [Q2. Remove Duplicates in-place](#q2-remove-duplicates-from-a-sorted-array-in-place-5-marks)
  - [Q3. Delete All Occurrences in-place](#q3-delete-all-occurrences-of-a-given-value-from-an-array-in-place-5-marks)
  - [Q4. Merge Two Sorted Arrays](#q4-merge-two-sorted-arrays-into-one-sorted-array-5-marks)
  - [Q5. Move Zeroes to End](#q5-move-all-zeroes-to-the-end-of-an-array-5-marks)
  - [Q6. Largest & Second Largest in Single Traversal](#q6-find-largest-and-second-largest-elements-in-a-single-traversal-5-marks)
  - [Q7. Two Sum: Brute Force vs Hashing](#q7-solve-two-sum-using-brute-force-and-hashing-10-marks)
  - [Q8. Kadane's Algorithm & Dry Run](#q8-find-maximum-subarray-sum-using-kadanes-algorithm-with-dry-run-10-marks)
- [Part 2: Stack Data Structures (Questions 9 – 17)](#part-2-stack-data-structures-questions-9--17)
  - [Q9. Decimal to Binary using Stack](#q9-convert-a-decimal-number-to-binary-using-a-stack-5-marks)
  - [Q10. Palindrome Check using Stack](#q10-check-whether-a-string-is-a-palindrome-using-a-stack-5-marks)
  - [Q11. Delete Middle Element of Stack](#q11-delete-the-middle-element-of-a-stack-5-marks)
  - [Q12. Insert at Bottom using Recursion](#q12-insert-an-element-at-the-bottom-of-a-stack-using-recursion-5-marks)
  - [Q13. Sort Stack using Temporary Stack](#q13-sort-a-stack-using-a-temporary-stack-5-marks)
  - [Q14. Two Stacks in a Single Array](#q14-implement-two-stacks-in-a-single-array-space-optimization-10-marks)
  - [Q15. Infix to Prefix with Step-by-Step Table](#q15-convert-infix-to-prefix-with-a-step-by-step-table-10-marks)
  - [Q16. Prefix Expression Evaluation](#q16-evaluate-prefix-expression-using-a-stack-10-marks)
  - [Q17. Stock Span Problem in O(n)](#q17-solve-stock-span-problem-using-a-stack-in-on-10-marks)
- [Part 3: Queue Data Structures (Questions 18 – 24)](#part-3-queue-data-structures-questions-18--24)
  - [Q18. Reverse First k Elements of Queue](#q18-reverse-the-first-k-elements-of-a-queue-5-marks)
  - [Q19. Interleave Queue Halves](#q19-interleave-the-first-half-of-a-queue-with-the-second-half-5-marks)
  - [Q20. Circular Array Deque](#q20-implement-a-deque-using-a-circular-array-5-marks)
  - [Q21. Round Robin CPU Scheduling Simulation](#q21-simulate-round-robin-cpu-scheduling-using-a-queue-10-marks)
  - [Q22. First Non-Repeating Character in Stream](#q22-find-first-non-repeating-character-in-a-stream-using-a-queue-10-marks)
  - [Q23. Josephus Problem using Queue](#q23-solve-josephus-problem-using-a-queue-10-marks)
  - [Q24. Priority Queue via Linked List](#q24-priority-queue-via-linked-list-insert-delete-complexity-10-marks)
- [Compilation and Execution Guide](#compilation-and-execution-guide)

---

## Quick Navigation Index

| # | Topic | Question Description | Marks | File Path | Time | Space |
|---|-------|----------------------|-------|-----------|------|-------|
| 1 | Array | Insert into sorted array staying sorted | 5 | [`Array/01_insert_sorted_array.c`](Array/01_insert_sorted_array.c) | $O(n)$ | $O(1)$ |
| 2 | Array | Remove duplicates from sorted array in-place | 5 | [`Array/02_remove_duplicates_sorted.c`](Array/02_remove_duplicates_sorted.c) | $O(n)$ | $O(1)$ |
| 3 | Array | Delete all occurrences of a value in-place | 5 | [`Array/03_delete_val_inplace.c`](Array/03_delete_val_inplace.c) | $O(n)$ | $O(1)$ |
| 4 | Array | Merge two sorted arrays into one sorted array | 5 | [`Array/04_merge_sorted_arrays.c`](Array/04_merge_sorted_arrays.c) | $O(m+n)$ | $O(m+n)$ |
| 5 | Array | Move all zeroes to end maintaining relative order | 5 | [`Array/05_move_zeroes.c`](Array/05_move_zeroes.c) | $O(n)$ | $O(1)$ |
| 6 | Array | Find largest & second largest in single traversal | 5 | [`Array/06_largest_second_largest.c`](Array/06_largest_second_largest.c) | $O(n)$ | $O(1)$ |
| 7 | Array | Two Sum: Brute Force vs Hashing with complexity comparison | 10 | [`Array/07_two_sum.c`](Array/07_two_sum.c) | $O(n^2)$ vs $O(n)$ | $O(1)$ vs $O(n)$ |
| 8 | Array | Kadane's Algorithm for max subarray sum + Dry Run table | 10 | [`Array/08_kadane_max_subarray.c`](Array/08_kadane_max_subarray.c) | $O(n)$ | $O(1)$ |
| 9 | Stack | Decimal to binary conversion using stack | 5 | [`Stack/09_decimal_to_binary_stack.c`](Stack/09_decimal_to_binary_stack.c) | $O(\log n)$ | $O(\log n)$ |
| 10 | Stack | Palindrome string check using stack | 5 | [`Stack/10_palindrome_check_stack.c`](Stack/10_palindrome_check_stack.c) | $O(n)$ | $O(n)$ |
| 11 | Stack | Delete middle element of stack recursively | 5 | [`Stack/11_delete_middle_stack.c`](Stack/11_delete_middle_stack.c) | $O(n)$ | $O(n)$ |
| 12 | Stack | Insert element at bottom of stack recursively | 5 | [`Stack/12_insert_at_bottom_stack.c`](Stack/12_insert_at_bottom_stack.c) | $O(n)$ | $O(n)$ |
| 13 | Stack | Sort stack using a temporary stack | 5 | [`Stack/13_sort_stack.c`](Stack/13_sort_stack.c) | $O(n^2)$ | $O(n)$ |
| 14 | Stack | Implement two stacks in single array (space optimized) | 10 | [`Stack/14_two_stacks_in_array.c`](Stack/14_two_stacks_in_array.c) | $O(1)$ | $O(n)$ |
| 15 | Stack | Infix to prefix conversion with step-by-step table | 10 | [`Stack/15_infix_to_prefix.c`](Stack/15_infix_to_prefix.c) | $O(n)$ | $O(n)$ |
| 16 | Stack | Evaluate prefix expression with step-by-step trace | 10 | [`Stack/16_evaluate_prefix.c`](Stack/16_evaluate_prefix.c) | $O(n)$ | $O(n)$ |
| 17 | Stack | Stock Span problem using monotonic stack | 10 | [`Stack/17_stock_span.c`](Stack/17_stock_span.c) | $O(n)$ | $O(n)$ |
| 18 | Queue | Reverse first $k$ elements of queue using stack | 5 | [`Queue/18_reverse_first_k_queue.c`](Queue/18_reverse_first_k_queue.c) | $O(n)$ | $O(k)$ |
| 19 | Queue | Interleave first half of queue with second half | 5 | [`Queue/19_interleave_queue.c`](Queue/19_interleave_queue.c) | $O(n)$ | $O(n)$ |
| 20 | Queue | Circular array Deque (insert/delete front & rear) | 5 | [`Queue/20_circular_deque.c`](Queue/20_circular_deque.c) | $O(1)$ | $O(CAP)$ |
| 21 | Queue | Round Robin CPU scheduling simulation with metrics | 10 | [`Queue/21_round_robin_scheduling.c`](Queue/21_round_robin_scheduling.c) | $O(n \cdot \frac{BT}{Q})$ | $O(n)$ |
| 22 | Queue | First non-repeating character in stream | 10 | [`Queue/22_first_non_repeating_stream.c`](Queue/22_first_non_repeating_stream.c) | $O(n)$ | $O(n)$ |
| 23 | Queue | Josephus elimination problem solved using queue | 10 | [`Queue/23_josephus_problem_queue.c`](Queue/23_josephus_problem_queue.c) | $O(n \cdot k)$ | $O(n)$ |
| 24 | Queue | Priority Queue via Linked List (insert & delete) | 10 | [`Queue/24_priority_queue_linked_list.c`](Queue/24_priority_queue_linked_list.c) | $O(n)$ ins, $O(1)$ del | $O(n)$ |

---

## Part 1: Array Data Structures (Questions 1 – 8)

### Q1. Insert an element into a sorted array so that it stays sorted. (5 marks)
- **File:** [`Array/01_insert_sorted_array.c`](Array/01_insert_sorted_array.c)
- **Approach:** Linear scan backwards from `size - 1`; shift elements greater than the key to the right, and place the key at the vacated index.
- **Complexity:**
  - **Time:** Best Case: $\mathcal{O}(1)$ (inserting at the end); Worst & Average Case: $\mathcal{O}(n)$ (shifting up to $n$ elements).
  - **Space:** Auxiliary $\mathcal{O}(1)$ (in-place modification).

### Q2. Remove duplicates from a sorted array in-place. (5 marks)
- **File:** [`Array/02_remove_duplicates_sorted.c`](Array/02_remove_duplicates_sorted.c)
- **Approach:** Two-pointer technique (`k` pointing to the last unique element, `i` scanning the array). When `arr[i] != arr[k]`, increment `k` and write `arr[k] = arr[i]`.
- **Complexity:**
  - **Time:** $\mathcal{O}(n)$ (single traversal).
  - **Space:** $\mathcal{O}(1)$ (in-place).

### Q3. Delete all occurrences of a given value from an array in-place. (5 marks)
- **File:** [`Array/03_delete_val_inplace.c`](Array/03_delete_val_inplace.c)
- **Approach:** Two-pointer overwrite technique (`k` write-pointer, `i` read-pointer). Copies non-target elements forward.
- **Complexity:**
  - **Time:** $\mathcal{O}(n)$ (single pass).
  - **Space:** $\mathcal{O}(1)$ (in-place).

### Q4. Merge two sorted arrays into one sorted array. (5 marks)
- **File:** [`Array/04_merge_sorted_arrays.c`](Array/04_merge_sorted_arrays.c)
- **Approach:** Classic two-pointer merge from Merge Sort. Compares elements from array $A$ and $B$, placing the smaller into $C$.
- **Complexity:**
  - **Time:** $\mathcal{O}(m + n)$.
  - **Space:** $\mathcal{O}(m + n)$ for output storage.

### Q5. Move all zeroes to the end of an array. (5 marks)
- **File:** [`Array/05_move_zeroes.c`](Array/05_move_zeroes.c)
- **Approach:** Stable in-place partition using single pass: swap non-zero elements into index `nonZeroIdx++`. Maintains relative order of non-zero elements.
- **Complexity:**
  - **Time:** $\mathcal{O}(n)$.
  - **Space:** $\mathcal{O}(1)$ (in-place).

### Q6. Find largest and second largest elements in a single traversal. (5 marks)
- **File:** [`Array/06_largest_second_largest.c`](Array/06_largest_second_largest.c)
- **Approach:** Track `first` and `second` initialized to `INT_MIN`. In a single loop, update `first` and cascade old `first` to `second`. Correctly detects duplicate maximums.
- **Complexity:**
  - **Time:** $\mathcal{O}(n)$ in a single traversal.
  - **Space:** $\mathcal{O}(1)$.

### Q7. Solve Two Sum using Brute Force and Hashing. (10 marks)
- **File:** [`Array/07_two_sum.c`](Array/07_two_sum.c)
- **Approaches:**
  1. **Brute Force:** Nested loops testing all pairs $(i, j)$ with $i < j$.
  2. **Hash Table:** Hash table with chaining in C storing `(key = arr[i], value = index)`. Look up `target - arr[i]` in constant expected time.
- **Complexity Comparison Table:**

| Feature | Brute Force Method | Hash Table Method |
|---|---|---|
| **Time Complexity** | $\mathcal{O}(n^2)$ | $\mathcal{O}(n)$ average |
| **Space Complexity** | $\mathcal{O}(1)$ | $\mathcal{O}(n)$ |
| **Comparisons** | $\frac{n(n-1)}{2}$ | Single linear pass |
| **Data Structure** | None | Hash Table (Chaining) |

### Q8. Find maximum subarray sum using Kadane's Algorithm with Dry Run. (10 marks)
- **File:** [`Array/08_kadane_max_subarray.c`](Array/08_kadane_max_subarray.c)
- **Formula:** `curr_max = max(arr[i], curr_max + arr[i])`, `max_so_far = max(max_so_far, curr_max)`.
- **Dry Run Table on Example `[-2, 1, -3, 4, -1, 2, 1, -5, 4]`:**

| Index | Element | `curr_max` | `max_so_far` | Subarray Window | Decision / Action |
|:---:|:---:|:---:|:---:|:---:|:---|
| 0 | -2 | -2 | -2 | [0 .. 0] | Initialized with `arr[0]` |
| 1 | 1 | 1 | 1 | [1 .. 1] | Start new subarray at 1 |
| 2 | -3 | -2 | 1 | [1 .. 1] | Extend current subarray |
| 3 | 4 | 4 | 4 | [3 .. 3] | Start new subarray at 3 |
| 4 | -1 | 3 | 4 | [3 .. 3] | Extend current subarray |
| 5 | 2 | 5 | 5 | [3 .. 5] | Extend current subarray |
| 6 | 1 | 6 | 6 | [3 .. 6] | Extend current subarray |
| 7 | -5 | 1 | 6 | [3 .. 6] | Extend current subarray |
| 8 | 4 | 5 | 6 | [3 .. 6] | Extend current subarray |

**Final Maximum Subarray Sum:** `6` from subarray `[4, -1, 2, 1]` (indices 3 to 6).

---

## Part 2: Stack Data Structures (Questions 9 – 17)

### Q9. Convert a decimal number to binary using a stack. (5 marks)
- **File:** [`Stack/09_decimal_to_binary_stack.c`](Stack/09_decimal_to_binary_stack.c)
- **Approach:** Repeated division by 2; push `num % 2` to stack. Popping prints binary bits in LIFO order (MSB to LSB).
- **Complexity:** Time: $\mathcal{O}(\log_2 n)$, Space: $\mathcal{O}(\log_2 n)$.

### Q10. Check whether a string is a palindrome using a stack. (5 marks)
- **File:** [`Stack/10_palindrome_check_stack.c`](Stack/10_palindrome_check_stack.c)
- **Approach:** Push all characters into stack, then pop and compare with original string characters from left to right.
- **Complexity:** Time: $\mathcal{O}(n)$, Space: $\mathcal{O}(n)$.

### Q11. Delete the middle element of a stack. (5 marks)
- **File:** [`Stack/11_delete_middle_stack.c`](Stack/11_delete_middle_stack.c)
- **Approach:** Recursive unwinding without auxiliary data structures. At recursion depth `floor(n/2)`, pop and discard; push other elements back during call stack rewind.
- **Complexity:** Time: $\mathcal{O}(n)$, Space: $\mathcal{O}(n)$ call stack.

### Q12. Insert an element at the bottom of a stack using recursion. (5 marks)
- **File:** [`Stack/12_insert_at_bottom_stack.c`](Stack/12_insert_at_bottom_stack.c)
- **Approach:** Recursively pop all items until stack is empty; push new element at bottom, then push back popped elements.
- **Complexity:** Time: $\mathcal{O}(n)$, Space: $\mathcal{O}(n)$ call stack.

### Q13. Sort a stack using a temporary stack. (5 marks)
- **File:** [`Stack/13_sort_stack.c`](Stack/13_sort_stack.c)
- **Approach:** Pop `tmp` from input stack. While `tmpStack` is non-empty and `top(tmpStack) > tmp`, pop from `tmpStack` back to input stack. Push `tmp` into `tmpStack`.
- **Complexity:** Time: $\mathcal{O}(n^2)$, Space: $\mathcal{O}(n)$ auxiliary stack.

### Q14. Implement two stacks in a single array (space optimization). (10 marks)
- **File:** [`Stack/14_two_stacks_in_array.c`](Stack/14_two_stacks_in_array.c)
- **Approach:** Stack 1 starts at index 0 and grows rightwards (`top1 = -1`). Stack 2 starts at `CAPACITY - 1` and grows leftwards (`top2 = CAPACITY`). Overflow occurs only when `top1 + 1 == top2`.
- **Complexity:** Push & Pop: $\mathcal{O}(1)$ for both stacks. Space utilization: 100% optimal (no internal fragmentation).

### Q15. Convert infix to prefix with a step-by-step table. (10 marks)
- **File:** [`Stack/15_infix_to_prefix.c`](Stack/15_infix_to_prefix.c)
- **Example Trace for `(A + B) * C - D`:**
  1. Reverse & swap brackets: `D - C * (B + A)`
  2. Step-by-step postfix conversion of reversed expression:

| Step | Symbol Scanned | Operator Stack | Intermediate Output | Action Taken |
|:---:|:---:|:---:|:---:|:---|
| 1 | `D` | `(empty)` | `D` | Operand 'D' added to output |
| 2 | `-` | `-` | `D` | Pushed operator '-' to stack |
| 3 | `C` | `-` | `DC` | Operand 'C' added to output |
| 4 | `*` | `-*` | `DC` | Pushed operator '*' to stack |
| 5 | `(` | `-*(` | `DC` | Pushed '(' onto stack |
| 6 | `B` | `-*(` | `DCB` | Operand 'B' added to output |
| 7 | `+` | `-*(+` | `DCB` | Pushed operator '+' to stack |
| 8 | `A` | `-*(+` | `DCBA` | Operand 'A' added to output |
| 9 | `)` | `-*` | `DCBA+` | Popped operators until '(' discarded |
| 10 | `(end)` | `-` | `DCBA+*` | Popped '*' remaining on stack |
| 11 | `(end)` | `(empty)` | `DCBA+*-` | Popped '-' remaining on stack |

  3. Reverse postfix `DCBA+*-` $\implies$ **Final Prefix:** `-*+ABCD`
- **Complexity:** Time: $\mathcal{O}(n)$, Space: $\mathcal{O}(n)$.

### Q16. Evaluate prefix expression using a stack. (10 marks)
- **File:** [`Stack/16_evaluate_prefix.c`](Stack/16_evaluate_prefix.c)
- **Example:** `- * + 4 3 2 5`
- **Approach:** Scan tokens from right to left:
  - Push operands: `5`, `2`, `3`, `4`.
  - Operator `+`: pop `4` and `3` $\implies 4 + 3 = 7$, push `7`.
  - Operator `*`: pop `7` and `2` $\implies 7 \times 2 = 14$, push `14`.
  - Operator `-`: pop `14` and `5` $\implies 14 - 5 = 9$, push `9`.
- **Result:** `9`
- **Complexity:** Time: $\mathcal{O}(n)$, Space: $\mathcal{O}(n)$.

### Q17. Solve Stock Span problem using a stack in O(n). (10 marks)
- **File:** [`Stack/17_stock_span.c`](Stack/17_stock_span.c)
- **Approach:** Monotonic stack storing indices of days with strictly decreasing prices. Pop indices while `price[stack.top] <= price[i]`. Span is `i + 1` if stack is empty, else `i - stack.top`.
- **Complexity:** Time: $\mathcal{O}(n)$ amortized (each day index pushed and popped at most once). Space: $\mathcal{O}(n)$.

---

## Part 3: Queue Data Structures (Questions 18 – 24)

### Q18. Reverse the first k elements of a queue. (5 marks)
- **File:** [`Queue/18_reverse_first_k_queue.c`](Queue/18_reverse_first_k_queue.c)
- **Approach:** Dequeue first $k$ elements into stack, pop stack back into queue rear, then rotate remaining $n - k$ elements from front to rear.
- **Complexity:** Time: $\mathcal{O}(n)$, Space: $\mathcal{O}(k)$ stack.

### Q19. Interleave the first half of a queue with the second half. (5 marks)
- **File:** [`Queue/19_interleave_queue.c`](Queue/19_interleave_queue.c)
- **Example:** `[11, 12, 13, 14, 15, 16, 17, 18, 19, 20]` $\implies$ `[11, 16, 12, 17, 13, 18, 14, 19, 15, 20]`.
- **Approach:** Push first half to stack, enqueue back, rotate second half, push first half to stack again, then alternately pop stack and dequeue queue.
- **Complexity:** Time: $\mathcal{O}(n)$, Space: $\mathcal{O}(n)$ stack.

### Q20. Implement a deque using a circular array. (5 marks)
- **File:** [`Queue/20_circular_deque.c`](Queue/20_circular_deque.c)
- **Functions:** `insertFront`, `insertRear`, `deleteFront`, `deleteRear`, `isFull`, `isEmpty`, `displayDeque`.
- **Complexity:** All 4 operations take strictly $\mathcal{O}(1)$ time. Space: $\mathcal{O}(CAPACITY)$.

### Q21. Simulate Round Robin CPU scheduling using a queue. (10 marks)
- **File:** [`Queue/21_round_robin_scheduling.c`](Queue/21_round_robin_scheduling.c)
- **Features:** Simulates ready queue with time quantum $Q$, tracks arrival times, outputs Gantt chart execution timeline, calculates Completion Time (CT), Turnaround Time (TAT), and Waiting Time (WT).
- **Complexity:** Time: $\mathcal{O}(n \cdot \frac{\text{max burst}}{Q})$, Space: $\mathcal{O}(n)$ ready queue.

### Q22. Find first non-repeating character in a stream using a queue. (10 marks)
- **File:** [`Queue/22_first_non_repeating_stream.c`](Queue/22_first_non_repeating_stream.c)
- **Approach:** As characters arrive, increment `freq[ch]++` and enqueue `ch`. Discard elements from queue front while `freq[queue.front()] > 1`. Front of queue provides first non-repeating character in $\mathcal{O}(1)$ amortized time.
- **Complexity:** Time: $\mathcal{O}(n)$ total, Space: $\mathcal{O}(n)$ queue + $\mathcal{O}(1)$ 256-size frequency array.

### Q23. Solve Josephus problem using a queue. (10 marks)
- **File:** [`Queue/23_josephus_problem_queue.c`](Queue/23_josephus_problem_queue.c)
- **Approach:** Enqueue $n$ people. In each round, rotate $k-1$ people from front to rear, then dequeue and eliminate the $k$-th person. Repeat until 1 person remains. Verified with mathematical recurrence $J(n, k) = (J(n-1, k) + k - 1) \pmod n + 1$.
- **Complexity:** Time: $\mathcal{O}(n \cdot k)$, Space: $\mathcal{O}(n)$.

### Q24. Priority Queue via Linked List (Insert, Delete, Complexity). (10 marks)
- **File:** [`Queue/24_priority_queue_linked_list.c`](Queue/24_priority_queue_linked_list.c)
- **Design:** Singly linked list sorted in descending order of priority (higher number = higher priority).
- **Complexity Specification:**

| Operation | Time Complexity | Auxiliary Space | Explanation |
|---|---|---|---|
| **Insert (enqueue)** | $\mathcal{O}(n)$ worst/avg, $\mathcal{O}(1)$ best | $\mathcal{O}(1)$ | Traverses list to find correct spot based on priority |
| **Delete (dequeue)** | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | Highest priority element is always at the head of the list |
| **Storage** | $\mathcal{O}(n)$ total | $\mathcal{O}(n)$ | Dynamically allocated linked list nodes |

---

## Compilation and Execution Guide

### Compiling Any Single Program
You can compile any individual file using `gcc`:

```bash
# Example: Question 8 (Kadane's Algorithm)
gcc -Wall -Wextra -std=c99 Array/08_kadane_max_subarray.c -o kadane
./kadane

# Example: Question 15 (Infix to Prefix)
gcc -Wall -Wextra -std=c99 Stack/15_infix_to_prefix.c -o infix_prefix
./infix_prefix

# Example: Question 16 (Prefix Evaluation)
gcc -Wall -Wextra -std=c99 Stack/16_evaluate_prefix.c -o eval_prefix -lm
./eval_prefix

# Example: Question 21 (Round Robin Scheduling)
gcc -Wall -Wextra -std=c99 Queue/21_round_robin_scheduling.c -o round_robin
./round_robin
```

### Compiling All Programs at Once

**In Windows PowerShell:**
```powershell
Get-ChildItem -Recurse -Filter "*.c" | Where-Object { $_.DirectoryName -match "Array|Stack|Queue" } | ForEach-Object {
    $out = [System.IO.Path]::ChangeExtension($_.FullName, ".exe")
    gcc -Wall -Wextra -std=c99 $_.FullName -o $out -lm
    Write-Host "Compiled: $($_.Name)"
}
```

**In Linux / macOS Bash:**
```bash
for file in Array/*.c Stack/*.c Queue/*.c; do
    gcc -Wall -Wextra -std=c99 "$file" -o "${file%.c}.out" -lm
    echo "Compiled: $file"
done
```
