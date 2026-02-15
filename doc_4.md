# Doubly Linked List Operations


## (a) Data Structures Definition

The program defines a bidirectional linear data structure using a `struct`:

### The Doubly Linked List Node (`Node`)
Unlike a singly linked list, each node here contains two pointers, allowing traversal in both directions.
* `int data`: The integer value stored in the node.
* **`struct Node *prev`**: A pointer to the previous node in the list (or `NULL` if it is the first node).
* **`struct Node *next`**: A pointer to the next node in the list (or `NULL` if it is the last node).



---

## (b) Function Descriptions

| Function | Purpose |
| :--- | :--- |
| `createNode(int value)` | Allocates memory on the heap for a new node, assigns the data, and initializes both `prev` and `next` pointers to `NULL`. |
| `insertAfter(...)` | Inserts a new node immediately after a specified node. It carefully updates four pointers (new node's next/prev and the neighbors' links) to maintain list integrity. |
| `deleteNode(...)` | Removes a specific node from the list. It bridges the gap between the target's predecessor and successor and handles the special case where the `head` node is deleted. |
| `forwTrav(...)` | Iterates through the list starting from the head, printing the values in a bidirectional visual format (`NULL <-> 10 <-> ...`). |




---

## (c) Overview of `main()` Organization

The `main()` method demonstrates the flexibility of a Doubly Linked List through a step-by-step workflow:

1.  **Manual Initialization**: Three nodes (10, 20, 30) are created and manually linked using their `next` and `prev` pointers to establish the initial list structure.
2.  **State Visualization**: Calls `forwTrav()` to display the initial state.
3.  **Middle Insertion**: Demonstrates `insertAfter()` by placing a new value (25) between 20 and 30.
4.  **Targeted Deletion**: Demonstrates `deleteNode()` by removing the node containing the value 20, showing how the list automatically repairs its links (connecting 10 directly to 25).

---

## (d) Sample Output

When you run the program, the output will look like this:

```text
Initial list:
NULL <-> 10 <-> 20 <-> 30 <-> NULL

Insert 25 after node 20:
NULL <-> 10 <-> 20 <-> 25 <-> 30 <-> NULL

Delete node with value 20:
NULL <-> 10 <-> 25 <-> 30 <-> NULL