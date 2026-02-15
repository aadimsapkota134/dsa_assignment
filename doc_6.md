# Min and Max Heap Implementation in C


## (a) Data Structures Definition

Instead of using complex pointers or structs, this program uses a **linear array** to represent a **Complete Binary Tree**. This is an efficient way to store a heap because it avoids the overhead of memory pointers.

The relationships between nodes are defined by their indices:
* **Root Node:** The first element at index $0$.
* **Left Child:** For any node at index $i$, its left child is at $2i + 1$.
* **Right Child:** For any node at index $i$, its right child is at $2i + 2$.
* **Parent Node:** For any node at index $i$, its parent is at $\lfloor (i - 1) / 2 \rfloor$.



---

## (b) Function Descriptions

The program is modular, separating the logic for swapping, visualization, and the heap properties.

| Function | Purpose |
| :--- | :--- |
| `swap(int*, int*)` | A utility function that exchanges the values of two memory locations. |
| `printArray(int[], int)` | Iterates through the array and prints elements in a single line for visualization. |
| `heapifyMax(int[], int, i)` | The core logic for Max Heaps. It compares a node with its children and "sinks" it down if it is smaller than either child to maintain the Max-Heap property. |
| `heapifyMin(int[], int, i)` | The core logic for Min Heaps. It "sinks" a node down if it is larger than its children. |
| `buildMaxHeap(int[], int)` | Starts from the last non-leaf node and calls `heapifyMax` in reverse order to build the heap in $O(n)$ time. |
| `buildMinHeap(int[], int)` | Similar to the Max version, but ensures the smallest element resides at the root. |



---

## (c) Organization of `main()`

The `main()` function acts as a test bench for the heap algorithms:

1.  **Data Initialization:** Defines an unsorted integer array `data[]`.
2.  **Memory Allocation:** Dynamically allocates memory for two separate arrays (`maxHeapArr` and `minHeapArr`) using `malloc()`. This allows us to keep the original data intact while performing two different transformations.
3.  **Data Copying:** Copies the original unsorted data into both allocated arrays.
4.  **Heap Construction:** * Calls `buildMaxHeap()` to organize the first array.
    * Calls `buildMinHeap()` to organize the second array.
5.  **Output & Cleanup:** Prints the results to the console and uses `free()` to release the dynamically allocated memory, preventing memory leaks.

---

## (d) Sample Output

Based on the input array `{12, 11, 13, 5, 6, 7}`, the execution result is:

```text
Original Array: 
12 11 13 5 6 7 

 Building Max Heap: 
13 11 12 5 6 7 

 Building Min Heap:
5 6 7 12 11 13