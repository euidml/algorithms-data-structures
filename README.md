# algorithms-data-structures
Implementations of various algorithms &amp; data structures from coursework in [Algorithms and Data Structures II(CPSC 2150)](https://langara.ca/programs-courses/cpsc-2150) at Langara College.

## Homework Project Summaries

### Wk2HW
- **Focus:** Basic data structures.
- **Contents:** Implementations and tests for Linked List (`LinkedListFull.h`), Stack (`Stack.h`), and Queue (`Queue.h`). Each has a corresponding test file.
- **Purpose:** Practice and demonstrate fundamental linear data structures and their operations.

### Wk3HW
- **Focus:** Advanced linked structures and scheduling.
- **Contents:** 
  - **DoublySkipList:** Skip list implementation and test.
  - **RoundRobin:** Circular linked list and a round-robin process scheduler.
  - **SkipListInsert:** Skip list with insertion logic and test.
- **Purpose:** Explore skip lists, circular lists, and scheduling algorithms.

### Wk3HWCircularListSkipLists
- **Focus:** Variants of skip lists and round-robin scheduling.
- **Contents:** 
  - **DoublySkipList:** Skip list with doubly linked nodes.
  - **RoundRobin:** Circular list and process scheduler.
  - **SkipListInsert:** Skip list with insertion.
  - **Extra:** OS scheduling slides.
- **Purpose:** Compare and contrast different skip list and scheduling implementations.

### Wk4HW
- **Focus:** Priority queues and hotel management.
- **Contents:** 
  - **Question1:** Hotel class and test.
  - **Question2:** Priority queue, skip list, and related node classes with tests.
- **Purpose:** Apply data structures to real-world scenarios (hotel management, priority queues).

### Wk5HW
- **Focus:** Hashing and skip lists.
- **Contents:** 
  - **Question1:** Linear probing hash table and test.
  - **Question2:** Skip list and node classes with test.
  - **Question3:** Duplicate finder, random string generator, merge sort, and hashing demo.
- **Purpose:** Practice hashing, skip lists, and sorting algorithms.

### Wk7HW
- **Focus:** Binary search trees.
- **Contents:** 
  - **Question 1 & 2:** BST implementation and test with sample tree data.
  - **Question 3:** Additional code snippet (likely tree-related).
- **Purpose:** Implement and test binary search trees and related algorithms.

### Wk8HW
- **Focus:** AVL Trees.
- **Contents:** AVL tree implementation (`liangAVLTree.h`), test file, and documentation.
- **Purpose:** Implement and test self-balancing binary search trees (AVL).

### Wk9HW
- **Focus:** Graphs.
- **Contents:** Graph class and test file.
- **Purpose:** Implement and test basic graph data structures and algorithms.

### WK10HW
- **Focus:** Graph pathfinding.
- **Contents:** Graph class and a pathfinding implementation.
- **Purpose:** Explore graph traversal/pathfinding algorithms.

### Wk12HW
- **Focus:** Graph algorithms with weighted edges.
- **Contents:** Graph class, test file, and several distance data files.
- **Purpose:** Implement and test graph algorithms involving distances/weights (possibly shortest path algorithms).

## Project File Structure

```
algorithms-data-structures/
├── src                        # Source code for all homework projects
│   ├── Wk2HW                  # Linked list, stack, and queue implementations and tests
│   │   ├── LinkedListFull.h
│   │   ├── Queue.h
│   │   ├── Stack.h
│   │   ├── testLinkedList.cpp
│   │   ├── testQueue.cpp
│   │   └── testStack.cpp
│   ├── Wk3HW                  # Skip lists, circular lists, and round-robin scheduler
│   │   ├── DoublySkipList/
│   │   │   ├── Node.h
│   │   │   ├── SkipList.h
│   │   │   └── testSkip.cpp
│   │   ├── RoundRobin/
│   │   │   ├── CircularList.h
│   │   │   ├── process.txt
│   │   │   ├── RoundRobinProcessScheduler
│   │   │   ├── RoundRobinProcessScheduler.h
│   │   │   ├── sample input output for round robin process scheduler.txt
│   │   │   └── textRobin.cpp
│   │   └── SkipListInsert/
│   │       ├── Node.h
│   │       ├── SkipList.h
│   │       └── testSkip.cpp
│   ├── Wk3HWCircularListSkipLists # Variants of skip lists and round-robin scheduling
│   │   ├── DoublySkipList/
│   │   │   ├── Node.h
│   │   │   ├── SkipList.h
│   │   │   ├── testSkip
│   │   │   └── testSkip.cpp
│   │   ├── OperatingSystemsProcessScheduling.pptx
│   │   ├── RoundRobin/
│   │   │   ├── CircularList.h
│   │   │   ├── process.txt
│   │   │   ├── RoundRobinProcessScheduler.h
│   │   │   ├── sample input output for round robin process scheduler.txt
│   │   │   └── textRobin.cpp
│   │   └── SkipListInsert/
│   │       ├── Node.h
│   │       ├── SkipList.h
│   │       └── testSkip.cpp
│   ├── Wk4HW                  # Hotel management and priority queue exercises
│   │   ├── Question1/
│   │   │   ├── Hotel
│   │   │   ├── Hotel.h
│   │   │   ├── testHotel
│   │   │   └── testHotel.cpp
│   │   └── Question2/
│   │       ├── abc.h
│   │       ├── Node.h
│   │       ├── PriorityQueue.h
│   │       ├── SkipList.h
│   │       └── testSkip.cpp
│   ├── Wk5HW                  # Hashing, skip lists, and sorting exercises
│   │   ├── Question1/
│   │   │   ├── HashingLinearProbingDemo.h
│   │   │   └── testHashing.cpp
│   │   ├── Question2/
│   │   │   ├── Node.h
│   │   │   ├── SkipList.h
│   │   │   └── testSkip.cpp
│   │   └── Question3/
│   │       ├── FindDuplcate.cpp
│   │       ├── GenerateRandomString.h
│   │       ├── HashingLinearProbingDemo.h
│   │       └── MergeSort.h
│   ├── Wk7HW                  # Binary search tree implementations and tests
│   │   ├── Question 1 & 2/
│   │   │   ├── liangBST.h
│   │   │   ├── testLiangBST.cpp
│   │   │   └── tree.txt
│   │   └── Question 3/
│   │       └── codeSnippet.cpp
│   ├── Wk8HW                  # AVL tree implementation and documentation
│   │   ├── liangAVLTree.h
│   │   ├── TestAVLTree.cpp
│   │   └── Wk8HW_AVLTrees.docx
│   ├── Wk9HW                  # Graph data structure and algorithms
│   │   ├── Graph.h
│   │   └── testGraph.cpp
│   ├── WK10HW                 # Graph pathfinding algorithms
│   │   ├── Graph.h
│   │   └── Wk10HWpathFinder.cpp
│   └── Wk12HW                 # Weighted graph algorithms and distance data
│       ├── distances.txt
│       ├── distances2.txt
│       ├── distances3.txt
│       ├── Graph.h
│       └── testGraph.cpp
```
