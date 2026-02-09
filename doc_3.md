# Linked List Reverse Traversal 
## (a) Data Structures Definition

The implementation relies on two custom data structures to manage the data and the reversal logic:

### 1. Singly Linked List (`Node`)
Since a singly linked list only has a pointer to the *next* node, we define it as:
* `int data`: The value stored in the node.
* `struct Node* next`: A pointer to the succeeding node in the sequence.

### 2. Explicit Stack (`St`)
To reverse the elements, we implement a stack (LIFO - Last In, First Out) to store the data temporarily:
* `int *arr`: A dynamic array to hold integers.
* `int top`: An index tracking the topmost element.
* `int max_size`: The maximum capacity of the stack.



---

## (b) Function Descriptions

| Function | Purpose |
| :--- | :--- |
| `createNode` | Allocates memory for a new node and initializes its values. |
| `insertEnd` | Navigates to the end of the list to append a new node. Uses a pointer-to-pointer (`Node**`) to handle empty list cases. |
| `forwTrav` | A standard traversal that prints the list from `head` to `NULL`. |
| `createStack` | Initializes the stack structure and allocates memory for the internal array based on the list size. |
| `push` | Adds a node's data onto the top of the stack. |
| `pop` | Retrieves and removes the top element from the stack. |
| **`revTrav`** | **The Core Algorithm:** It traverses the list forward, pushes every value onto the stack, and then pops them one by one to print them in reverse. |

---

## (c) Overview of `main()` Organization

The `main()` function acts as the controller to demonstrate the logic:

1.  **List Initialization:** Sets the initial `head` pointer to `NULL`.
2.  **Data Entry:** Uses a loop to populate the list with five nodes (multiples of 10).
3.  **Visual Verification:** * Calls `forwTrav()` to show the user the original sequence.
    * Calls `revTrav()` to demonstrate the successful reversal using the stack.
4.  **Memory Management:** Though implicit in this specific snippet for the list nodes, the program ensures the stack memory is freed after the reversal is printed.

---

## (d) Sample Output

When the program is executed, the console will display the following:

```bash
10 -> 20 -> 30 -> 40 -> 50 -> NULL LIST
Reverse: 50 -> 40 -> 30 -> 20 -> 10 -> NULL