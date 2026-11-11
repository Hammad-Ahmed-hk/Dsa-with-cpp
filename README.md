# Data Structures & Algorithms in C++

Hands-on C++ implementations of core data structures and algorithms, written while studying DSA. Each file is a small, self-contained program with its own `main()` and an interactive menu or demo.

All 15 programs compile with `g++ -std=c++17`.

## Contents

| Topic | File | What it covers |
|---|---|---|
| **Searching** | [`searching/binary_search.cpp`](searching/binary_search.cpp) | Iterative binary search on a sorted `vector<int>` |
| | [`searching/ternary_search.cpp`](searching/ternary_search.cpp) | Ternary search with a menu-driven program |
| | [`searching/binary_and_ternary_search.cpp`](searching/binary_and_ternary_search.cpp) | Binary and ternary search side by side |
| **Sorting** | [`sorting/bubble_sort.cpp`](sorting/bubble_sort.cpp), [`bubble_sort_v2.cpp`](sorting/bubble_sort_v2.cpp) | Bubble sort (two variations) |
| | [`sorting/selection_sort.cpp`](sorting/selection_sort.cpp) | Selection sort |
| | [`sorting/quick_sort.cpp`](sorting/quick_sort.cpp) | Quick sort |
| **Arrays** | [`arrays/array_insertion.cpp`](arrays/array_insertion.cpp) | Inserting an element into an array |
| **Linked lists** | [`linked_lists/singly_linked_list.cpp`](linked_lists/singly_linked_list.cpp) | Singly linked list |
| | [`linked_lists/doubly_linked_list.cpp`](linked_lists/doubly_linked_list.cpp) | Doubly linked list |
| | [`linked_lists/circular_singly_linked_list.cpp`](linked_lists/circular_singly_linked_list.cpp) | Circular singly linked list |
| | [`linked_lists/circular_doubly_linked_list.cpp`](linked_lists/circular_doubly_linked_list.cpp) | Circular doubly linked list |
| **Stacks & queues** | [`stacks_queues/stack.cpp`](stacks_queues/stack.cpp) | Array-based stack (`BookStack`) |
| | [`stacks_queues/queue.cpp`](stacks_queues/queue.cpp) | Queue (`TicketQueue`) |
| **Trees** | [`trees/binary_search_tree.cpp`](trees/binary_search_tree.cpp) | Binary search tree with insertion and in-order traversal |

## Build and run

Any C++17 compiler works. With `g++`:

```bash
g++ -std=c++17 sorting/quick_sort.cpp -o quick_sort
./quick_sort
```

Replace the path with any file from the table above.

## Notes

- Programs are interactive: they read input from the terminal.
- The code favors clarity over cleverness. Comments explain each step.
- Ideas for later: unit tests, templates for generic types, and complexity notes for each algorithm.

## Author

Hammad Ahmed, [@Hammad-Ahmed-hk](https://github.com/Hammad-Ahmed-hk)
